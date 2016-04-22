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
	int write_reg;
}ID_EX;

typedef struct _EXDM{
	int instruction;
	int PC;
	int ALU_result;
	int read_data2;
	int write_reg;
}EX_DM;

typedef struct _DMWB{
	int instruction;
	int address;
	int data;
	int write_reg;
}DM_WB;




int reg[32];
int PC;
int PC_start;
unsigned char ii[1024];
unsigned char di[1024];
int iim[256];
unsigned char dim[1024];
int temp;

void DM(){
	unsigned char *getting;

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
					DM_WB.address = EX_DM.ALU_result;
                    DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }
                case 0x21:	///addu
                {
                    DM_WB.address = EX_DM.ALU_result;
					DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }
                case 0x22:	///sub
                {
                    DM_WB.address = EX_DM.ALU_result;
					DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }
                case 0x24:	///and
                {
                   DM_WB.address = EX_DM.ALU_result;
				   DM_WB.write_reg = EX_DM.write_reg;
				   DM_WB.data = 0;
                    break;
                }
                case 0x25:	///or
                {
                    DM_WB.address = EX_DM.ALU_result;
					DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }
                case 0x26:	///xor
                {
                    DM_WB.address = EX_DM.ALU_result;
					DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }
                case 0x27:	///nor
                {
                    DM_WB.address = EX_DM.ALU_result;
					DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }
                case 0x28:	///nand
                {
                    DM_WB.address = EX_DM.ALU_result;
					DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }
                case 0x2A:	///slt
                {
                    DM_WB.address = EX_DM.ALU_result;
					DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }
                case 0x00:	///sll
                {
					DM_WB.address = EX_DM.ALU_result;
					DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }
                case 0x02:	///srl
                {
                    DM_WB.address = EX_DM.ALU_result;
					DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }
                case 0x03:	///sra
                {
                    DM_WB.address = EX_DM.ALU_result;
					DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }
                case 0x08:	///jr
                {
					DM_WB.address = 0;
					DM_WB.write_reg = EX_DM.write_reg;
					DM_WB.data = 0;
                    break;
                }

                }
                break;
            }
            case 0x08:	///addi
            {

                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
                break;
            }
            case 0x09:	///addiu
            {
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
                break;
            }
            case 0x23:	///lw
            {

                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = (int)combine(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1],dim[EX_DM.ALU_result+2],dim[EX_DM.ALU_result+3]);
                break;
            }
            case 0x21:	///lh
            {
				DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = (short)combine_two(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1]);
                break;
            }
            case 0x25:	///lhu
            {
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = (short)combine_two(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1]);
                break;
            }
            case 0x20:	///lb
            {
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = (char)dim[EX_DM.ALU_result];
                break;
            }
            case 0x24:	///lbu
            {
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = (unsigned)dim[EX_DM.ALU_result];
                break;
            }
            case 0x2B:	///sw
            {
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				getting = seperate(EX_DM.read_data2);
				dim[EX_DM.ALU_result]=getting[0];
				dim[EX_DM.ALU_result+1]=getting[1];
				dim[EX_DM.ALU_result+2]=getting[2];
				dim[EX_DM.ALU_result+3]=getting[3];
				DM_WB.data = 0;
                break;
            }
            case 0x29:	///sh
            {
				
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				getting = seperate_two(EX_DM.read_data2);
				dim[EX_DM.ALU_result]=getting[0];
				dim[EX_DM.ALU_result+1]=getting[1];
				DM_WB.data = 0;
                break;
            }
            case 0x28:	///sb
            {
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				getting[0] = (unsigned char)(EX_DM.read_data2&0x000000FF);
				dim[EX_DM.ALU_result]=getting[0];
				DM_WB.data = 0;
                break;
            }
            case 0x0F:	///lui
            {
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
                break;
            }
            case 0x0C:	///andi
            {
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
                break;
            }
            case 0x0D:	///ori
            {
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
                break;
            }
            case 0x0E:	///nori
            {
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
                break;
            }
            case 0x0A:	///slti
            {
                DM_WB.address = EX_DM.ALU_result;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
                break;
            }
            case 0x04:	///beq
            {
				DM_WB.address = 0;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
                break;
            }
            case 0x05:	///bne
            {
                DM_WB.address = 0;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
                break;
            }
            case 0x07:	///bgtz
            {
				DM_WB.address = 0;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
                break;
            }
            case 0x02:	///j
            {
                DM_WB.address = 0;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
                break;
            }
            case 0x03:	///jal
            {
				DM_WB.address = 0;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = 0;
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


    return 0;
}
