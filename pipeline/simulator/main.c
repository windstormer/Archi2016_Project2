#include <stdio.h>
#include <string.h>
#include "function.h"
#include "state.h"
#include "state_reg.h"


int reg[32];
int PC;
int PC_start;
unsigned char ii[1024];
unsigned char di[1024];
int iim[256];
unsigned char dim[1024];
int temp;

void WB(){
	op=(unsigned)DM_WB.instruction>>26;




            switch(op)
            {
            case 0x00:
            {
                funct=cut_func(DM_WB.instruction);

                switch(funct)
                {
                case 0x20:	///add
                {

                    
                    break;
                }
                case 0x21:	///addu
                {
                    
                    break;
                }
                case 0x22:	///sub
                {
                    
                    break;
                }
                case 0x24:	///and
                {
                   
                    break;
                }
                case 0x25:	///or
                {
                    
                    break;
                }
                case 0x26:	///xor
                {
                    
                    break;
                }
                case 0x27:	///nor
                {
                    
                    break;
                }
                case 0x28:	///nand
                {
                    
                    break;
                }
                case 0x2A:	///slt
                {
                    
                    break;
                }
                case 0x00:	///sll
                {
               
                    break;
                }
                case 0x02:	///srl
                {
                    
                    break;
                }
                case 0x03:	///sra
                {
                    
                    break;
                }
                case 0x08:	///jr
                {

                    
                    break;
                }

                }
                break;
            }
            case 0x08:	///addi
            {

                
                break;
            }
            case 0x09:	///addiu
            {
                
                break;
            }
            case 0x23:	///lw
            {

                
                break;
            }
            case 0x21:	///lh
            {
               
                break;
            }
            case 0x25:	///lhu
            {
                
                break;
            }
            case 0x20:	///lb
            {
                
                break;
            }
            case 0x24:	///lbu
            {
                
                break;
            }
            case 0x2B:	///sw
            {
                
                break;
            }
            case 0x29:	///sh
            {
                
                break;
            }
            case 0x28:	///sb
            {
                
                break;
            }
            case 0x0F:	///lui
            {
                
                break;
            }
            case 0x0C:	///andi
            {
               
                break;
            }
            case 0x0D:	///ori
            {

                
                break;
            }
            case 0x0E:	///nori
            {
                
                break;
            }
            case 0x0A:	///slti
            {
                
                break;
            }
            case 0x04:	///beq
            {
               
                break;
            }
            case 0x05:	///bne
            {
                
                break;
            }
            case 0x07:	///bgtz
            {
               
                break;
            }
            case 0x02:	///j
            {
                
                break;
            }
            case 0x03:	///jal
            {
               
                break;
            }
            case 0x3F:	///halt
            {
                //  printf("halt\n");
                flag=1;
                break;
            }


            }
}

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
	WB();
	DM();
	EX();
	ID();
	IF();


    return 0;
}
