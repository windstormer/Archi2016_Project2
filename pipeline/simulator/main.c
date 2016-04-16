#include <stdio.h>
#include <string.h>
#include "function.h"


typedef struct _IFID{
	int instruction;
	int PC;
}IF_ID;

typedef struct _IDEX{
	int instruction;
	int PC;
	int read_data1;
	int read_data2;
	int immediate_ext;
}ID_EX;

typedef struct _EXDM{
	int instruction;
	int PC;
	int ALU_result;
	int read_data2;
}EX_DM;

typedef struct _DMWB{
	int instruction;
	unsigned int address;
	int data;
}DM_WB;




int reg[32];
int PC;
int PC_start;
unsigned char ii[1024];
unsigned char di[1024];
int iim[256];
unsigned char dim[1024];
int temp;

int main(void)
{
    FILE *iimage = fopen("./iimage.bin","rb");
    FILE *dimage = fopen("./dimage.bin","rb");
    FILE *error = fopen("./error_dump.rpt","w");
    FILE *snapshot = fopen("./snapshot.rpt","w");




    int sdata=0,sins=0;
    int i,j;


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
	
	{
		
	}


    return 0;
}
