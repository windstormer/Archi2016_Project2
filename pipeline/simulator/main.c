#include <stdio.h>
#include <string.h>
#include "function.h"
#include "state.h"


int reg[32];
int PC;
int PC_start;
unsigned char ii[1024];
unsigned char di[1024];
int iim[256];
unsigned char dim[1024];
int temp;
FILE *snapshot;
FILE *error;
int count=0;
extern errors[4];


int main(void)
{
    FILE *iimage = fopen("./iimage.bin","rb");
    FILE *dimage = fopen("./dimage.bin","rb");
    error = fopen("./error_dump.rpt","w");
    snapshot = fopen("./snapshot.rpt","w");




    int sdata=0,sins=0;
    int i;


    memset(reg,0,sizeof(reg));
    memset(ii,0,sizeof(ii));
    memset(di,0,sizeof(di));
    memset(iim,0,sizeof(iim));
    memset(dim,0,sizeof(dim));
    PC=0;

    fseek(iimage , 0 , SEEK_END);


    rewind (iimage);

    fread(ii,sizeof(unsigned char),8,iimage);

    fseek(dimage , 0 , SEEK_END);


    rewind (dimage);

    fread(di,sizeof(unsigned char),8,dimage);

    /*
    for(i=0;i<siimage;i++)
    printf("%x\n",ii[i]);
    */
    reg[29]=combine(di[0],di[1],di[2],di[3]);
    sdata=combine(di[4],di[5],di[6],di[7]);



    fread(di,sizeof(unsigned char),sdata*4,dimage);

    for(i=0; i<sdata*4; i++)
    {
        dim[i]=di[i];
    }

    PC=combine(ii[0],ii[1],ii[2],ii[3]);
    PC_start=PC;
    sins=combine(ii[4],ii[5],ii[6],ii[7]);

    fread(ii,sizeof(unsigned char),sins*4,iimage);
    for(i=0; i<sins; i++)
    {
        iim[i]=combine(ii[i*4],ii[1+i*4],ii[2+i*4],ii[3+i*4]);
        //  printf("i=%d %x\n",i,iim[i]);
    }
    /*
    for(i=0;i<sins;i++)
    printf("%x\n",iim[i]);
    */

    /**
    ii : string of all the data int iimage.bin
    di : string of all the data int dimage.bin
    PC : current PC
    reg : int array of all the register
    iim : int array of all the instruction
    dim : unsigned char array of all the data in memory
    sins: int of the number of instruction
    sdata : int of the number of memory (word)
    **/
    int check[5]= {0};
    int flags=0;

    int j=0;
    while(1)
    {
        //    if(count>4)break;

        errors[0]=0;
        errors[1]=0;
        errors[2]=0;
        errors[3]=0;

        fprintf(snapshot,"cycle %d\n",count);
        for(j=0; j<32; j++)
        {
            fprintf(snapshot,"$%02d: 0x%08X\n",j,reg[j]);
        }
        check[0]=WB();
        check[1]=DM();
        check[2]=EX();
        check[3]=ID();
        if(flags==0)
        {
            check[4]=IF(0);
            flags=1;
        }
        else
            check[4]=IF(1);
        fprintf(snapshot,"\n");
        if(check[0]==1 && check[1]==1 && check[2]==1 && check[3]==1 && check[4]==1)
            break;

        if(check[1]==2)
        {
            break;
        }

        count++;

    }



    return 0;
}
