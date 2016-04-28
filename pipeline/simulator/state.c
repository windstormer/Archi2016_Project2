#include "state.h"

typedef struct _IFID
{
    int instruction;
    int PC;
} IFID;



typedef struct _IDEX
{
    int instruction;
    int read_data1;
    int read_data2;
    int immediate_ext;
    int write_reg;
} IDEX;



typedef struct _EXDM
{
    int instruction;
    int ALU_result;
    int read_data2;
    int write_reg;
} EXDM;



typedef struct _DMWB
{
    int instruction;
    int address;
    int data;
    int write_reg;
} DMWB;

IFID IF_ID;
IDEX ID_EX;
EXDM EX_DM;
DMWB DM_WB;


int WB()
{
    printf("WB: %X\n",DM_WB.instruction);
    int flag=0;
    op=0,funct=0;
    if(DM_WB.instruction==0)	return 0;

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
            reg[DM_WB.write_reg] = DM_WB.address;

            break;
        }
        case 0x21:	///addu
        {
            reg[DM_WB.write_reg] = DM_WB.address;
            break;
        }
        case 0x22:	///sub
        {
            reg[DM_WB.write_reg] = DM_WB.address;
            break;
        }
        case 0x24:	///and
        {
            reg[DM_WB.write_reg] = DM_WB.address;
            break;
        }
        case 0x25:	///or
        {
            reg[DM_WB.write_reg] = DM_WB.address;
            break;
        }
        case 0x26:	///xor
        {
            reg[DM_WB.write_reg] = DM_WB.address;
            break;
        }
        case 0x27:	///nor
        {
            reg[DM_WB.write_reg] = DM_WB.address;
            break;
        }
        case 0x28:	///nand
        {
            reg[DM_WB.write_reg] = DM_WB.address;
            break;
        }
        case 0x2A:	///slt
        {
            reg[DM_WB.write_reg] = DM_WB.address;
            break;
        }
        case 0x00:	///sll
        {
            reg[DM_WB.write_reg] = DM_WB.address;
            break;
        }
        case 0x02:	///srl
        {
            reg[DM_WB.write_reg] = DM_WB.address;
            break;
        }
        case 0x03:	///sra
        {
            reg[DM_WB.write_reg] = DM_WB.address;
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
        reg[DM_WB.write_reg] = DM_WB.address;

        break;
    }
    case 0x09:	///addiu
    {
        reg[DM_WB.write_reg] = DM_WB.address;
        break;
    }
    case 0x23:	///lw
    {
        reg[DM_WB.write_reg] = DM_WB.data;

        break;
    }
    case 0x21:	///lh
    {
        reg[DM_WB.write_reg] = DM_WB.data;
        break;
    }
    case 0x25:	///lhu
    {
        reg[DM_WB.write_reg] = DM_WB.data;
        break;
    }
    case 0x20:	///lb
    {
        reg[DM_WB.write_reg] = DM_WB.data;
        break;
    }
    case 0x24:	///lbu
    {
        reg[DM_WB.write_reg] = DM_WB.data;
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
        reg[DM_WB.write_reg] = DM_WB.address;
        break;
    }
    case 0x0C:	///andi
    {
        reg[DM_WB.write_reg] = DM_WB.address;
        break;
    }
    case 0x0D:	///ori
    {
        reg[DM_WB.write_reg] = DM_WB.address;
        break;
    }
    case 0x0E:	///nori
    {
        reg[DM_WB.write_reg] = DM_WB.address;
        break;
    }
    case 0x0A:	///slti
    {
        reg[DM_WB.write_reg] = DM_WB.address;
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

        flag=1;
        break;
    }


    }

    if(flag==1) return 1;
    else return 0;
}

int DM()
{
    printf("DM: %X\n",EX_DM.instruction);
    unsigned char *getting;
    int flag=0;
    if(EX_DM.instruction==0)
    {
        DM_WB.instruction=0;
        return 0;
    }

    op=(unsigned)EX_DM.instruction>>26;


    switch(op)
    {
    case 0x00:
    {
        funct=cut_func(EX_DM.instruction);

        switch(funct)
        {
        case 0x20:	///add
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x21:	///addu
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x22:	///sub
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x24:	///and
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x25:	///or
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x26:	///xor
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x27:	///nor
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x28:	///nand
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x2A:	///slt
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x00:	///sll
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x02:	///srl
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x03:	///sra
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.address = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x08:	///jr
        {
            DM_WB.instruction = EX_DM.instruction;
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
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x09:	///addiu
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x23:	///lw
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = (int)combine(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1],dim[EX_DM.ALU_result+2],dim[EX_DM.ALU_result+3]);
        break;
    }
    case 0x21:	///lh
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = (short)combine_two(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1]);
        break;
    }
    case 0x25:	///lhu
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = (short)combine_two(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1]);
        break;
    }
    case 0x20:	///lb
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = (char)dim[EX_DM.ALU_result];
        break;
    }
    case 0x24:	///lbu
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = (unsigned)dim[EX_DM.ALU_result];
        break;
    }
    case 0x2B:	///sw
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
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
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        getting = seperate_two(EX_DM.read_data2);
        dim[EX_DM.ALU_result]=getting[0];
        dim[EX_DM.ALU_result+1]=getting[1];
        DM_WB.data = 0;
        break;
    }
    case 0x28:	///sb
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        getting = malloc(sizeof(unsigned char));
        getting[0] = (unsigned char)(EX_DM.read_data2&0x000000FF);
        dim[EX_DM.ALU_result]=getting[0];
        DM_WB.data = 0;
        break;
    }
    case 0x0F:	///lui
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x0C:	///andi
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x0D:	///ori
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x0E:	///nori
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x0A:	///slti
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x04:	///beq
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x05:	///bne
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x07:	///bgtz
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x02:	///j
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x03:	///jal
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.address = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x3F:	///halt
    {
        DM_WB.instruction = EX_DM.instruction;
        flag=1;
        break;
    }


    }
    if(flag==1)return 1;
    else return 0;
}

int EX()
{

    printf("EX: %X\n",ID_EX.instruction);
int temp=0;
int flag=0;
if(ID_EX.instruction==0)
{
    EX_DM.instruction=0;
    return 0;
}

op=(unsigned)ID_EX.instruction>>26;




            switch(op)
            {
            case 0x00:
            {
                funct=cut_func(ID_EX.instruction);

                switch(funct)
                {
                case 0x20:	///add
                {
                    EX_DM.instruction=ID_EX.instruction;
                    temp=ID_EX.read_data1+ID_EX.read_data2;

                    EX_DM.ALU_result=temp;
                    EX_DM.write_reg=ID_EX.write_reg;
                    break;
                }
                case 0x21:	///addu
                {
                    EX_DM.instruction=ID_EX.instruction;
                    temp=ID_EX.read_data1+ID_EX.read_data2;

                    EX_DM.ALU_result=temp;
                    EX_DM.write_reg=ID_EX.write_reg;
                    break;
                }
                case 0x22:	///sub
                {
                    EX_DM.instruction=ID_EX.instruction;
                    temp=ID_EX.read_data1+(-1)*ID_EX.read_data2;

                    EX_DM.ALU_result=temp;
                    EX_DM.write_reg=ID_EX.write_reg;
                    break;
                }
                case 0x24:	///and
                {
                    EX_DM.instruction=ID_EX.instruction;
                    temp=ID_EX.read_data1&ID_EX.read_data2;

                    EX_DM.ALU_result=temp;
                    EX_DM.write_reg=ID_EX.write_reg;
                    break;
                }
                case 0x25:	///or
                {
                    EX_DM.instruction=ID_EX.instruction;
                    temp=ID_EX.read_data1|ID_EX.read_data2;

                    EX_DM.ALU_result=temp;
                    EX_DM.write_reg=ID_EX.write_reg;
                    break;
                }
                case 0x26:	///xor
                {
                    EX_DM.instruction=ID_EX.instruction;
                    temp=ID_EX.read_data1^ID_EX.read_data2;

                    EX_DM.ALU_result=temp;
                    EX_DM.write_reg=ID_EX.write_reg;
                    break;
                }
                case 0x27:	///nor
                {
                    EX_DM.instruction=ID_EX.instruction;
                    temp=~(ID_EX.read_data1|ID_EX.read_data2);

                    EX_DM.ALU_result=temp;
                    break;
                }
                case 0x28:	///nand
                {
                    EX_DM.instruction=ID_EX.instruction;
                    temp=~(ID_EX.read_data1&ID_EX.read_data2);

                    EX_DM.ALU_result=temp;
                    EX_DM.write_reg=ID_EX.write_reg;
                    break;
                }
                case 0x2A:	///slt
                {
                    EX_DM.instruction=ID_EX.instruction;
                    if(ID_EX.read_data1<ID_EX.read_data2)
                        temp=1;
                    else temp=0;

                    EX_DM.ALU_result=temp;
                    EX_DM.write_reg=ID_EX.write_reg;
                    break;
                }
                case 0x00:	///sll
                {
                    EX_DM.instruction=ID_EX.instruction;
                    temp=ID_EX.read_data1<<ID_EX.immediate_ext;

                    EX_DM.ALU_result=temp;
                    EX_DM.write_reg=ID_EX.write_reg;
                    break;
                }
                case 0x02:	///srl
                {
                    EX_DM.instruction=ID_EX.instruction;
                    temp=(unsigned)ID_EX.read_data1>>ID_EX.immediate_ext;

                    EX_DM.ALU_result=temp;
                    EX_DM.write_reg=ID_EX.write_reg;
                    break;
                }
                case 0x03:	///sra
                {
                    EX_DM.instruction=ID_EX.instruction;
                    temp=ID_EX.read_data1>>ID_EX.immediate_ext;

                    EX_DM.ALU_result=temp;
                    EX_DM.write_reg=ID_EX.write_reg;
                    break;
                }
                case 0x08:	///jr
                {
                    EX_DM.instruction=ID_EX.instruction;
                    break;
                }

                }
                break;
            }
            case 0x08:	///addi
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1+ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x09:	///addiu
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1+ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x23:	///lw
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1+ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x21:	///lh
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1+ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x25:	///lhu
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1+ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x20:	///lb
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1+ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x24:	///lbu
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1+ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x2B:	///sw
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1+ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.read_data2=ID_EX.read_data2;
                break;
            }
            case 0x29:	///sh
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1+ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.read_data2=ID_EX.read_data2;
                break;
            }
            case 0x28:	///sb
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1+ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.read_data2=ID_EX.read_data2;
                break;
            }
            case 0x0F:	///lui
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.immediate_ext<<16;

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x0C:	///andi
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1&ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x0D:	///ori
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=ID_EX.read_data1|ID_EX.immediate_ext;

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x0E:	///nori
            {
                EX_DM.instruction=ID_EX.instruction;
                temp=~(ID_EX.read_data1|ID_EX.immediate_ext);

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x0A:	///slti
            {
                EX_DM.instruction=ID_EX.instruction;
                if(ID_EX.read_data1<ID_EX.immediate_ext)
                temp =1;
                else temp=0;

                EX_DM.ALU_result=temp;
                EX_DM.write_reg=ID_EX.write_reg;
                break;
            }
            case 0x04:	///beq
            {
                EX_DM.instruction=ID_EX.instruction;
                break;
            }
            case 0x05:	///bne
            {
                EX_DM.instruction=ID_EX.instruction;
                break;
            }
            case 0x07:	///bgtz
            {
                EX_DM.instruction=ID_EX.instruction;
                break;
            }
            case 0x02:	///j
            {
                EX_DM.instruction=ID_EX.instruction;
                break;
            }
            case 0x03:	///jal
            {
                EX_DM.instruction=ID_EX.instruction;
                break;
            }
            case 0x3F:	///halt
            {
                EX_DM.instruction=ID_EX.instruction;
                //  printf("halt\n");
                flag=1;
                break;
            }


            }

			if(flag==1) return 1;
			else return 0;

}

int ID()
{

printf("ID: %X\n",IF_ID.instruction);
    int flag=0;
    op=(unsigned)IF_ID.instruction>>26;

    unsigned char rs=0;
    unsigned char rt=0;
    unsigned char rd=0;
    unsigned char shamt=0;
    short immediate=0;
    unsigned short unsigned_immediate=0;
    unsigned int address=0;

    if(IF_ID.instruction==0)
    {
        ID_EX.instruction = 0;
        return 0;
    }




        switch(op)
        {
        case 0x00:
        {
            funct=cut_func(IF_ID.instruction);

            switch(funct)
            {
            case 0x20:	///add
            {
                rs = cut_rs(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = 0;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rs];
                ID_EX.read_data2 = reg[rt];
                ID_EX.write_reg = rd;

                break;
            }
            case 0x21:	///addu
            {
                rs = cut_rs(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = 0;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rs];
                ID_EX.read_data2 = reg[rt];
                ID_EX.write_reg = rd;
                break;
            }
            case 0x22:	///sub
            {
                rs = cut_rs(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = 0;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rs];
                ID_EX.read_data2 = reg[rt];
                ID_EX.write_reg = rd;
                break;
            }
            case 0x24:	///and
            {
                rs = cut_rs(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = 0;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rs];
                ID_EX.read_data2 = reg[rt];
                ID_EX.write_reg = rd;
                break;
            }
            case 0x25:	///or
            {
                rs = cut_rs(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = 0;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rs];
                ID_EX.read_data2 = reg[rt];
                ID_EX.write_reg = rd;
                break;
            }
            case 0x26:	///xor
            {
                rs = cut_rs(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = 0;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rs];
                ID_EX.read_data2 = reg[rt];
                ID_EX.write_reg = rd;
                break;
            }
            case 0x27:	///nor
            {
                rs = cut_rs(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = 0;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rs];
                ID_EX.read_data2 = reg[rt];
                ID_EX.write_reg = rd;
                break;
            }
            case 0x28:	///nand
            {
                rs = cut_rs(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = 0;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rs];
                ID_EX.read_data2 = reg[rt];
                ID_EX.write_reg = rd;
                break;
            }
            case 0x2A:	///slt
            {
                rs = cut_rs(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = 0;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rs];
                ID_EX.read_data2 = reg[rt];
                ID_EX.write_reg = rd;
                break;
            }
            case 0x00:	///sll
            {
                shamt = cut_shamt(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = shamt;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rt];
                ID_EX.read_data2 = 0;
                ID_EX.write_reg = rd;
                break;
            }
            case 0x02:	///srl
            {
                shamt = cut_shamt(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = shamt;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rt];
                ID_EX.read_data2 = 0;
                ID_EX.write_reg = rd;
                break;
            }
            case 0x03:	///sra
            {
                shamt = cut_shamt(IF_ID.instruction);
                rt = cut_rt(IF_ID.instruction);
                rd = cut_rd(IF_ID.instruction);
                ID_EX.immediate_ext = shamt;
                ID_EX.instruction = IF_ID.instruction;
                ID_EX.read_data1 = reg[rt];
                ID_EX.read_data2 = 0;
                ID_EX.write_reg = rd;
                break;
            }
            case 0x08:	///jr
            {
				ID_EX.instruction = IF_ID.instruction;
                rs = cut_rs(IF_ID.instruction);
                branch = 1;
                PCback = reg[rs];
                break;
            }

            }
            break;
        }
        case 0x08:	///addi
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x09:	///addiu
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x23:	///lw
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x21:	///lh
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x25:	///lhu
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x20:	///lb
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x24:	///lbu
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x2B:	///sw
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = reg[rt];
            ID_EX.write_reg = 0;
            break;
        }
        case 0x29:	///sh
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = reg[rt];
            ID_EX.write_reg = 0;
            break;
        }
        case 0x28:	///sb
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = reg[rt];
            ID_EX.write_reg = 0;
            break;
        }
        case 0x0F:	///lui
        {
            immediate = cut_immediate(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = 0;
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x0C:	///andi
        {
            unsigned_immediate = cut_immediate_unsigned(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = unsigned_immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x0D:	///ori
        {
            unsigned_immediate = cut_immediate_unsigned(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = unsigned_immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x0E:	///nori
        {
            unsigned_immediate = cut_immediate_unsigned(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = unsigned_immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x0A:	///slti
        {
            unsigned_immediate = cut_immediate_unsigned(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            ID_EX.immediate_ext = unsigned_immediate;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = reg[rs];
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = rt;
            break;
        }
        case 0x04:	///beq
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            if(reg[rs]==reg[rt])
            {
                branch = 1;
                PCback = IF_ID.PC + 4 + immediate*4;
            }

            ID_EX.immediate_ext = 0;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = 0;
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = 0;


            break;
        }
        case 0x05:	///bne
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);
            rt = cut_rt(IF_ID.instruction);
            if(reg[rs]!=reg[rt])
            {
                branch = 1;
                PCback = IF_ID.PC + 4 + immediate*4;
            }

            ID_EX.immediate_ext = 0;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = 0;
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = 0;
            break;
        }
        case 0x07:	///bgtz
        {
            immediate = cut_immediate(IF_ID.instruction);
            rs = cut_rs(IF_ID.instruction);

            if(reg[rs]>0)
            {
                branch = 1;
                PCback = IF_ID.PC + 4 + immediate*4;
            }

            ID_EX.immediate_ext = 0;
            ID_EX.instruction = IF_ID.instruction;
            ID_EX.read_data1 = 0;
            ID_EX.read_data2 = 0;
            ID_EX.write_reg = 0;
            break;
        }
        case 0x02:	///j
        {
			ID_EX.instruction = IF_ID.instruction;
            address = cut_address(IF_ID.instruction);
            address=address<<2;
            PCback = (unsigned) IF_ID.PC>>28;
            PCback = PCback<<28;
            PCback = (unsigned)PC|address;
            break;
        }
        case 0x03:	///jal
        {
			ID_EX.instruction = IF_ID.instruction;
            address = cut_address(IF_ID.instruction);
            address=address<<2;
            reg[31] = IF_ID.PC;
            PCback = (unsigned) IF_ID.PC>>28;
            PCback = PCback<<28;
            PCback = (unsigned)PC|address;
            break;
        }
        case 0x3F:	///halt
        {
            //  printf("halt\n");
            ID_EX.instruction = IF_ID.instruction;
            flag=1;
            break;
        }


        }

    if(flag==1) return 1;
    else return 0;

}

int IF(int flags)
{

    int i=0;


    if(flags==0)
    {
        tempPC = PC;
        change = 0;
        branch = 0;
    }
    else
    {
        if(change==1)
        {
            tempPC = changePC;
            change = 0;
        }
        else
        {
            if(branch==1)
            {
                tempPC +=4;
                branch=0;
                change=1;
                changePC = PCback;
            }
            else
            {
                 tempPC+=4;

            }


        }

    }
   // printf("flags = %d, bramch = %d, change = %d\n",flags,branch,change);

    if(tempPC>=PC_start)
    {
        if(branch == 1)
        {
            i=(tempPC-PC_start)/4;
            IF_ID.instruction = 0;  ///flush
        }
        else
        {
            i=(tempPC-PC_start)/4;
            IF_ID.instruction=iim[i];
            IF_ID.PC=tempPC;
        }

    }
    else
    {
        IF_ID.instruction=0;
    }

    printf("PC: %d\n",tempPC);
    printf("IF: %X\n",IF_ID.instruction);
    op=(unsigned)iim[i]>>26;
    if(op==0x3F)
    {
        return 1;
    }
    else
        return 0;
}
