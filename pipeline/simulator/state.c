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
    int forward[3];
    /*
    forward[0]:
    0:nope
    1:rs
    2:rt
    3:both

    forward[1]:
    reg num of rs,rt

    forward[2]:
    0:EX_DM to EX
    1:EX_DM to ID
    */
    int stall;
} IDEX;



typedef struct _EXDM
{
    int instruction;
    int ALU_result;
    int read_data2;
    int write_reg;
    int can_forward;
    int forward[3];
    /*
    forward[0]:
    0:nope
    1:rs
    2:rt
    3:both

    forward[1]:
    reg num of rs,rt

    forward[2]:
    0:EX_DM to EX
    1:EX_DM to ID
    */
    int stall;
} EXDM;



typedef struct _DMWB
{
    int instruction;
    int ALU_result;
    int data;
    int write_reg;
    int can_forward;
} DMWB;

IFID IF_ID;
IDEX ID_EX;
EXDM EX_DM;
DMWB DM_WB;


int WB()
{
    show_WBi = DM_WB.instruction;
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
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;

            break;
        }
        case 0x21:	///addu
        {
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;
            break;
        }
        case 0x22:	///sub
        {
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;
            break;
        }
        case 0x24:	///and
        {
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;
            break;
        }
        case 0x25:	///or
        {
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;
            break;
        }
        case 0x26:	///xor
        {
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;
            break;
        }
        case 0x27:	///nor
        {
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;
            break;
        }
        case 0x28:	///nand
        {
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;
            break;
        }
        case 0x2A:	///slt
        {
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;
            break;
        }
        case 0x00:	///sll
        {
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;
            break;
        }
        case 0x02:	///srl
        {
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;
            break;
        }
        case 0x03:	///sra
        {
            if(DM_WB.write_reg==0)
            {
                errors[0]=1;
                reg[DM_WB.write_reg]=0;
            }
            else
                reg[DM_WB.write_reg] = DM_WB.ALU_result;
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
        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg] = DM_WB.ALU_result;

        break;
    }
    case 0x09:	///addiu
    {
        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg] = DM_WB.ALU_result;
        break;
    }
    case 0x23:	///lw
    {
        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg] = DM_WB.data;

        break;
    }
    case 0x21:	///lh
    {
        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg] = DM_WB.data;
        break;
    }
    case 0x25:	///lhu
    {
        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg] = DM_WB.data;
        break;
    }
    case 0x20:	///lb
    {
        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg] = DM_WB.data;
        break;
    }
    case 0x24:	///lbu
    {
        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
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

        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg] = DM_WB.ALU_result;
        break;
    }
    case 0x0C:	///andi
    {
        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg] = DM_WB.ALU_result;
        break;
    }
    case 0x0D:	///ori
    {
        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg] = DM_WB.ALU_result;
        break;
    }
    case 0x0E:	///nori
    {
        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg] = DM_WB.ALU_result;
        break;
    }
    case 0x0A:	///slti
    {

        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg] = DM_WB.ALU_result;
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
        if(DM_WB.write_reg==0)
        {
            errors[0]=1;
            reg[DM_WB.write_reg]=0;
        }
        else
            reg[DM_WB.write_reg]=DM_WB.ALU_result;
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

    show_DMi = EX_DM.instruction;
    unsigned char *getting;
    int flag=0;
    int flags=0;
    if(EX_DM.instruction==0)
    {
        DM_WB.instruction=EX_DM.instruction;
        DM_WB.ALU_result=0;
        DM_WB.can_forward=0;
        DM_WB.data=0;
        DM_WB.instruction=0;
        DM_WB.write_reg=0;
        return 0;
    }
    DM_WB.can_forward = EX_DM.can_forward;
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
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x21:	///addu
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x22:	///sub
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x24:	///and
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x25:	///or
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x26:	///xor
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x27:	///nor
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x28:	///nand
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x2A:	///slt
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x00:	///sll
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x02:	///srl
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x03:	///sra
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = EX_DM.ALU_result;
            DM_WB.write_reg = EX_DM.write_reg;
            DM_WB.data = 0;
            break;
        }
        case 0x08:	///jr
        {
            DM_WB.instruction = EX_DM.instruction;
            DM_WB.ALU_result = 0;
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
        DM_WB.ALU_result = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x09:	///addiu
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x23:	///lw
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        if(EX_DM.ALU_result>=1021||EX_DM.ALU_result<0)
        {
            errors[1]=1;
            flags=1;
        }
        if(EX_DM.ALU_result%4!=0)
        {
            errors[2]=1;
            flags=1;
        }
        if(flags==1)
            break;
        DM_WB.data = (int)combine(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1],dim[EX_DM.ALU_result+2],dim[EX_DM.ALU_result+3]);
        break;
    }
    case 0x21:	///lh
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        if(EX_DM.ALU_result>=1023||EX_DM.ALU_result<0)
        {
            errors[1]=1;
            flags=1;
        }
        if(EX_DM.ALU_result%2!=0)
        {
            errors[2]=1;
            flags=1;
        }
        if(flags==1)
            break;
        DM_WB.data = (short)combine_two(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1]);
        break;
    }
    case 0x25:	///lhu
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        if(EX_DM.ALU_result>=1023||EX_DM.ALU_result<0)
        {
            errors[1]=1;
            flags=1;
        }
        if(EX_DM.ALU_result%2!=0)
        {
            errors[2]=1;
            flags=1;
        }
        if(flags==1)
            break;
        DM_WB.data = (unsigned)combine_two(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1]);
        break;
    }
    case 0x20:	///lb
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        if(EX_DM.ALU_result>=1024||EX_DM.ALU_result<0)
        {
            errors[1]=1;
            flags=1;
        }
        if(flags==1)
            break;
        DM_WB.data = (char)dim[EX_DM.ALU_result];
        break;
    }
    case 0x24:	///lbu
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        if(EX_DM.ALU_result>=1024||EX_DM.ALU_result<0)
        {
            errors[1]=1;
            flags=1;
        }
        if(flags==1)
            break;
        DM_WB.data = (unsigned)dim[EX_DM.ALU_result];
        break;
    }
    case 0x2B:	///sw
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        getting = seperate(EX_DM.read_data2);
        if(EX_DM.ALU_result>=1021||EX_DM.ALU_result<0)
        {
            errors[1]=1;
            flags=1;
        }
        if(EX_DM.ALU_result%4!=0)
        {
            errors[2]=1;
            flags=1;
        }
        if(flags==1)
            break;
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
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        getting = seperate_two(EX_DM.read_data2);
        if(EX_DM.ALU_result>=1023||EX_DM.ALU_result<0)
        {
            errors[1]=1;
            flags=1;
        }
        if(EX_DM.ALU_result%2!=0)
        {
            errors[2]=1;
            flags=1;
        }
        if(flags==1)
            break;
        dim[EX_DM.ALU_result]=getting[0];
        dim[EX_DM.ALU_result+1]=getting[1];
        DM_WB.data = 0;
        break;
    }
    case 0x28:	///sb
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        getting = malloc(sizeof(unsigned char));
        getting[0] = (unsigned char)(EX_DM.read_data2&0x000000FF);
        if(EX_DM.ALU_result>=1024||EX_DM.ALU_result<0)
        {
            errors[1]=1;
            flags=1;
        }
        if(flags==1)
            break;

        dim[EX_DM.ALU_result]=getting[0];
        DM_WB.data = 0;
        break;
    }
    case 0x0F:	///lui
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x0C:	///andi
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x0D:	///ori
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x0E:	///nori
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x0A:	///slti
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = EX_DM.ALU_result;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x04:	///beq
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x05:	///bne
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x07:	///bgtz
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x02:	///j
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = 0;
        DM_WB.write_reg = EX_DM.write_reg;
        DM_WB.data = 0;
        break;
    }
    case 0x03:	///jal
    {
        DM_WB.instruction = EX_DM.instruction;
        DM_WB.ALU_result = EX_DM.ALU_result;
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
    if(flags==1)return 2;
    else
    {
        if(flag==1)return 1;
        else return 0;
    }

}

int EX()
{

    show_EXi = ID_EX.instruction;
    int temp=0;
    int flag=0;
    EX_DM.forward[0] = ID_EX.forward[0];
    EX_DM.forward[1] = ID_EX.forward[1];
    EX_DM.forward[2] = ID_EX.forward[2];
    EX_DM.ALU_result=0;

    if(ID_EX.instruction==0)
    {
        EX_DM.instruction=ID_EX.instruction;
        EX_DM.ALU_result==0;
        EX_DM.read_data2=0;
        EX_DM.write_reg=0;
        EX_DM.can_forward=0;
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
            if(overflow_detect(temp,ID_EX.read_data1,ID_EX.read_data2))
                errors[3]=1;
            EX_DM.can_forward=1;

            EX_DM.ALU_result=temp;
            EX_DM.write_reg=ID_EX.write_reg;
            break;
        }
        case 0x21:	///addu
        {

            EX_DM.instruction=ID_EX.instruction;
            temp=ID_EX.read_data1+ID_EX.read_data2;
            EX_DM.can_forward=1;

            EX_DM.ALU_result=temp;
            EX_DM.write_reg=ID_EX.write_reg;
            break;
        }
        case 0x22:	///sub
        {

            EX_DM.instruction=ID_EX.instruction;
            temp=ID_EX.read_data1+(-1)*ID_EX.read_data2;
            if(overflow_detect(temp,ID_EX.read_data1,(-1)*ID_EX.read_data2))
                errors[3]=1;
            EX_DM.can_forward=1;

            EX_DM.ALU_result=temp;
            EX_DM.write_reg=ID_EX.write_reg;
            break;
        }
        case 0x24:	///and
        {
            EX_DM.instruction=ID_EX.instruction;
            temp=ID_EX.read_data1&ID_EX.read_data2;
            EX_DM.can_forward=1;

            EX_DM.ALU_result=temp;
            EX_DM.write_reg=ID_EX.write_reg;
            break;
        }
        case 0x25:	///or
        {
            EX_DM.instruction=ID_EX.instruction;
            temp=ID_EX.read_data1|ID_EX.read_data2;
            EX_DM.can_forward=1;

            EX_DM.ALU_result=temp;
            EX_DM.write_reg=ID_EX.write_reg;
            break;
        }
        case 0x26:	///xor
        {
            EX_DM.instruction=ID_EX.instruction;
            temp=ID_EX.read_data1^ID_EX.read_data2;
            EX_DM.can_forward=1;

            EX_DM.ALU_result=temp;
            EX_DM.write_reg=ID_EX.write_reg;
            break;
        }
        case 0x27:	///nor
        {
            EX_DM.instruction=ID_EX.instruction;
            temp=~(ID_EX.read_data1|ID_EX.read_data2);
            EX_DM.can_forward=1;

            EX_DM.ALU_result=temp;
            EX_DM.write_reg = ID_EX.write_reg;
            break;
        }
        case 0x28:	///nand
        {
            EX_DM.instruction=ID_EX.instruction;
            temp=~(ID_EX.read_data1&ID_EX.read_data2);
            EX_DM.can_forward=1;

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
            EX_DM.can_forward=1;

            EX_DM.ALU_result=temp;
            EX_DM.write_reg=ID_EX.write_reg;
            break;
        }
        case 0x00:	///sll
        {
            EX_DM.instruction=ID_EX.instruction;
            temp=ID_EX.read_data1<<ID_EX.immediate_ext;
            EX_DM.can_forward=1;

            EX_DM.ALU_result=temp;
            EX_DM.write_reg=ID_EX.write_reg;
            break;
        }
        case 0x02:	///srl
        {
            EX_DM.instruction=ID_EX.instruction;
            temp=(unsigned)ID_EX.read_data1>>ID_EX.immediate_ext;
            EX_DM.can_forward=1;

            EX_DM.ALU_result=temp;
            EX_DM.write_reg=ID_EX.write_reg;
            break;
        }
        case 0x03:	///sra
        {
            EX_DM.instruction=ID_EX.instruction;
            temp=ID_EX.read_data1>>ID_EX.immediate_ext;
            EX_DM.can_forward=1;

            EX_DM.ALU_result=temp;
            EX_DM.write_reg=ID_EX.write_reg;
            break;
        }
        case 0x08:	///jr
        {
            EX_DM.instruction=ID_EX.instruction;
            EX_DM.can_forward=2;
            break;
        }

        }
        break;
    }
    case 0x08:	///addi
    {

        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1+ID_EX.immediate_ext;
        if(overflow_detect(temp,ID_EX.read_data1,ID_EX.immediate_ext))
            errors[3]=1;
        EX_DM.can_forward=1;

        EX_DM.ALU_result=temp;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
    }
    case 0x09:	///addiu
    {
        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1+ID_EX.immediate_ext;
        EX_DM.can_forward=1;

        EX_DM.ALU_result=temp;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
    }
    case 0x23:	///lw
    {

        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1+ID_EX.immediate_ext;
        if(overflow_detect(temp,ID_EX.read_data1,ID_EX.immediate_ext))
            errors[3]=1;

        EX_DM.can_forward=0;

        EX_DM.ALU_result=temp;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
    }
    case 0x21:	///lh
    {

        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1+ID_EX.immediate_ext;
        if(overflow_detect(temp,ID_EX.read_data1,ID_EX.immediate_ext))
            errors[3]=1;

        EX_DM.can_forward=0;

        EX_DM.ALU_result=temp;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
    }
    case 0x25:	///lhu
    {

        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1+ID_EX.immediate_ext;
        if(overflow_detect(temp,ID_EX.read_data1,ID_EX.immediate_ext))
            errors[3]=1;

        EX_DM.can_forward=0;

        EX_DM.ALU_result=temp;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
        break;
    }
    case 0x20:	///lb
    {

        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1+ID_EX.immediate_ext;
        if(overflow_detect(temp,ID_EX.read_data1,ID_EX.immediate_ext))
            errors[3]=1;

        EX_DM.can_forward=0;

        EX_DM.ALU_result=temp;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
        break;
    }
    case 0x24:	///lbu
    {

        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1+ID_EX.immediate_ext;
        if(overflow_detect(temp,ID_EX.read_data1,ID_EX.immediate_ext))
            errors[3]=1;

        EX_DM.can_forward=0;

        EX_DM.ALU_result=temp;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
        break;
    }
    case 0x2B:	///sw
    {
        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1+ID_EX.immediate_ext;
        if(overflow_detect(temp,ID_EX.read_data1,ID_EX.immediate_ext))
            errors[3]=1;

        EX_DM.can_forward=0;
        EX_DM.ALU_result=temp;
        EX_DM.read_data2=ID_EX.read_data2;
        EX_DM.write_reg=0;
        break;
    }
    case 0x29:	///sh
    {
        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1+ID_EX.immediate_ext;
        if(overflow_detect(temp,ID_EX.read_data1,ID_EX.immediate_ext))
            errors[3]=1;

        EX_DM.can_forward=0;
        EX_DM.ALU_result=temp;
        EX_DM.read_data2=ID_EX.read_data2;
        EX_DM.write_reg=0;
        break;
    }
    case 0x28:	///sb
    {
        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1+ID_EX.immediate_ext;
        if(overflow_detect(temp,ID_EX.read_data1,ID_EX.immediate_ext))
            errors[3]=1;

        EX_DM.can_forward=0;
        EX_DM.ALU_result=temp;
        EX_DM.read_data2=ID_EX.read_data2;
        EX_DM.write_reg=0;
        break;
    }
    case 0x0F:	///lui
    {

        EX_DM.instruction=ID_EX.instruction;

        temp=ID_EX.immediate_ext<<16;
        EX_DM.can_forward=1;
        EX_DM.ALU_result=temp;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
    }
    case 0x0C:	///andi
    {

        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1&ID_EX.immediate_ext;
        EX_DM.can_forward=1;
        EX_DM.ALU_result=temp;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
    }
    case 0x0D:	///ori
    {

        EX_DM.instruction=ID_EX.instruction;
        temp=ID_EX.read_data1|ID_EX.immediate_ext;
        EX_DM.can_forward=1;
        EX_DM.ALU_result=temp;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
    }
    case 0x0E:	///nori
    {

        EX_DM.instruction=ID_EX.instruction;
        temp=~(ID_EX.read_data1|ID_EX.immediate_ext);
        EX_DM.can_forward=1;
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
        EX_DM.can_forward=1;
        EX_DM.ALU_result=temp;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
    }
    case 0x04:	///beq
    {
        EX_DM.can_forward=2;
        EX_DM.instruction=ID_EX.instruction;
        break;
    }
    case 0x05:	///bne
    {
        EX_DM.can_forward=2;
        EX_DM.instruction=ID_EX.instruction;
        break;
    }
    case 0x07:	///bgtz
    {
        EX_DM.can_forward=2;
        EX_DM.instruction=ID_EX.instruction;
        break;
    }
    case 0x02:	///j
    {
        EX_DM.can_forward=2;
        EX_DM.instruction=ID_EX.instruction;
        break;
    }
    case 0x03:	///jal
    {
        EX_DM.can_forward=1;
        EX_DM.instruction=ID_EX.instruction;
        EX_DM.ALU_result=ID_EX.immediate_ext;
        EX_DM.write_reg=ID_EX.write_reg;
        break;
    }
    case 0x3F:	///halt
    {
        EX_DM.can_forward=0;
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

    unsigned char rs=0;
    unsigned char rt=0;
    unsigned char rd=0;
    unsigned char shamt=0;

    show_IDi = IF_ID.instruction;
    int flag=0;
    op=(unsigned)IF_ID.instruction>>26;
    shamt = cut_shamt(IF_ID.instruction);
    rt = cut_rt(IF_ID.instruction);
    rd = cut_rd(IF_ID.instruction);


    short immediate=0;
    unsigned short unsigned_immediate=0;
    unsigned int address=0;
    ID_EX.forward[0] = 0;
    ID_EX.forward[1] = 0;
    ID_EX.forward[2] = 0;
    ID_EX.stall = 0;

    if(IF_ID.instruction==0)
    {
        ID_EX.instruction=IF_ID.instruction;
        ID_EX.immediate_ext=0;
        ID_EX.read_data1=0;
        ID_EX.read_data2=0;
        ID_EX.write_reg = 0;
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

            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }

            if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 =EX_DM.ALU_result;
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0]=3;
                ID_EX.forward[1]=rs;
                ID_EX.forward[2] = 0;
            }
            else
            {
                if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
                {
                    ID_EX.read_data1 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 1;
                    ID_EX.forward[1] = rs;
                    ID_EX.forward[2] = 0;

                }
                else
                    ID_EX.read_data1 = reg[rs];
                if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
                {
                    ID_EX.read_data2 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 2;
                    ID_EX.forward[1] = rt;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data2 = reg[rt];
            }
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
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 =EX_DM.ALU_result;
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0]=3;
                ID_EX.forward[1]=rs;
                ID_EX.forward[2] = 0;
            }
            else
            {
                if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
                {
                    ID_EX.read_data1 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 1;
                    ID_EX.forward[1] = rs;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data1 = reg[rs];
                if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
                {
                    ID_EX.read_data2 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 2;
                    ID_EX.forward[1] = rt;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data2 = reg[rt];
            }
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
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 =EX_DM.ALU_result;
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0]=3;
                ID_EX.forward[1]=rs;
                ID_EX.forward[2] = 0;
            }
            else
            {
                if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
                {
                    ID_EX.read_data1 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 1;
                    ID_EX.forward[1] = rs;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data1 = reg[rs];
                if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
                {
                    ID_EX.read_data2 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 2;
                    ID_EX.forward[1] = rt;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data2 = reg[rt];
            }
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
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 =EX_DM.ALU_result;
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0]=3;
                ID_EX.forward[1]=rs;
                ID_EX.forward[2] = 0;
            }
            else
            {
                if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
                {
                    ID_EX.read_data1 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 1;
                    ID_EX.forward[1] = rs;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data1 = reg[rs];
                if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
                {
                    ID_EX.read_data2 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 2;
                    ID_EX.forward[1] = rt;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data2 = reg[rt];
            }
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
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }


            if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 =EX_DM.ALU_result;
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0]=3;
                ID_EX.forward[1]=rs;
                ID_EX.forward[2] = 0;
            }
            else
            {
                if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
                {
                    ID_EX.read_data1 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 1;
                    ID_EX.forward[1] = rs;
                }
                else
                    ID_EX.read_data1 = reg[rs];
                if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
                {
                    ID_EX.read_data2 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 2;
                    ID_EX.forward[1] = rt;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data2 = reg[rt];
            }
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
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 =EX_DM.ALU_result;
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0]=3;
                ID_EX.forward[1]=rs;
                ID_EX.forward[2] = 0;
            }
            else
            {
                if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
                {
                    ID_EX.read_data1 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 1;
                    ID_EX.forward[1] = rs;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data1 = reg[rs];
                if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
                {
                    ID_EX.read_data2 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 2;
                    ID_EX.forward[1] = rt;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data2 = reg[rt];
            }
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
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 =EX_DM.ALU_result;
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0]=3;
                ID_EX.forward[1]=rs;
                ID_EX.forward[2] = 0;
            }
            else
            {
                if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
                {
                    ID_EX.read_data1 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 1;
                    ID_EX.forward[1] = rs;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data1 = reg[rs];
                if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
                {
                    ID_EX.read_data2 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 2;
                    ID_EX.forward[1] = rt;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data2 = reg[rt];
            }

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
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 =EX_DM.ALU_result;
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0]=3;
                ID_EX.forward[1]=rs;
                ID_EX.forward[2] = 0;
            }
            else
            {
                if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
                {
                    ID_EX.read_data1 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 1;
                    ID_EX.forward[1] = rs;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data1 = reg[rs];
                if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
                {
                    ID_EX.read_data2 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 2;
                    ID_EX.forward[1] = rt;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data2 = reg[rt];
            }
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
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
                {

                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 =EX_DM.ALU_result;
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0]=3;
                ID_EX.forward[1]=rs;
                ID_EX.forward[2] = 0;
            }
            else
            {
                if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
                {
                    ID_EX.read_data1 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 1;
                    ID_EX.forward[1] = rs;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data1 = reg[rs];
                if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
                {
                    ID_EX.read_data2 = EX_DM.ALU_result;
                    ID_EX.forward[0] = 2;
                    ID_EX.forward[1] = rt;
                    ID_EX.forward[2] = 0;
                }
                else
                    ID_EX.read_data2 = reg[rt];
            }
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
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
            {
                ID_EX.read_data1 = EX_DM.ALU_result;
                ID_EX.forward[0] = 2;
                ID_EX.forward[1] = rt;
                ID_EX.forward[2] = 0;
            }
            else
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

            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
            {
                ID_EX.read_data1 = EX_DM.ALU_result;
                ID_EX.forward[0] = 2;
                ID_EX.forward[1] = rt;
                ID_EX.forward[2] = 0;
            }
            else
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

            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }
            if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
            {
                ID_EX.read_data1 = EX_DM.ALU_result;
                ID_EX.forward[0] = 2;
                ID_EX.forward[1] = rt;
                ID_EX.forward[2] = 0;
            }
            else
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
            if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
                if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
                {
                    ID_EX.stall=1;
                    ID_EX.instruction=0;

                    break;
                }


            if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
            {
                PCback = EX_DM.ALU_result;
                ID_EX.forward[0] = 1;
                ID_EX.forward[1] = rs;
                ID_EX.forward[2] = 0;
            }
            else
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }


        if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 = EX_DM.ALU_result;
            ID_EX.forward[0] = 1;
            ID_EX.forward[1] = rs;
            ID_EX.forward[2] = 0;
        }
        else
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }


        if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 = EX_DM.ALU_result;
            ID_EX.forward[0] = 1;
            ID_EX.forward[1] = rs;
            ID_EX.forward[2] = 0;
        }
        else
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }


        if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 = EX_DM.ALU_result;
            ID_EX.forward[0] = 1;
            ID_EX.forward[1] = rs;
            ID_EX.forward[2] = 0;
        }
        else
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }


        if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 = EX_DM.ALU_result;
            ID_EX.forward[0] = 1;
            ID_EX.forward[1] = rs;
            ID_EX.forward[2] = 0;
        }
        else
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }


        if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 = EX_DM.ALU_result;
            ID_EX.forward[0] = 1;
            ID_EX.forward[1] = rs;
            ID_EX.forward[2] = 0;
        }
        else
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }


        if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 = EX_DM.ALU_result;
            ID_EX.forward[0] = 1;
            ID_EX.forward[1] = rs;
            ID_EX.forward[2] = 0;
        }
        else
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }


        if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 = EX_DM.ALU_result;
            ID_EX.forward[0] = 1;
            ID_EX.forward[1] = rs;
            ID_EX.forward[2] = 0;
        }
        else
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }
        if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 =EX_DM.ALU_result;
            ID_EX.read_data2 = EX_DM.ALU_result;
            ID_EX.forward[0]=3;
            ID_EX.forward[1]=rs;
            ID_EX.forward[2] = 0;
        }
        else
        {
            if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 = EX_DM.ALU_result;
                ID_EX.forward[0] = 1;
                ID_EX.forward[1] = rs;
                ID_EX.forward[2] = 0;
            }
            else
                ID_EX.read_data1 = reg[rs];
            if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
            {
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0] = 2;
                ID_EX.forward[1] = rt;
                ID_EX.forward[2] = 0;
            }
            else
                ID_EX.read_data2 = reg[rt];
        }
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }
        if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 =EX_DM.ALU_result;
            ID_EX.read_data2 = EX_DM.ALU_result;
            ID_EX.forward[0]=3;
            ID_EX.forward[1]=rs;
            ID_EX.forward[2] = 0;
        }
        else
        {
            if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 = EX_DM.ALU_result;
                ID_EX.forward[0] = 1;
                ID_EX.forward[1] = rs;
                ID_EX.forward[2] = 0;
            }
            else
                ID_EX.read_data1 = reg[rs];
            if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
            {
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0] = 2;
                ID_EX.forward[1] = rt;
                ID_EX.forward[2] = 0;
            }
            else
                ID_EX.read_data2 = reg[rt];
        }
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rt==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rt==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rt!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }
        if(rs==rt&&rs==EX_DM.write_reg&&EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 =EX_DM.ALU_result;
            ID_EX.read_data2 = EX_DM.ALU_result;
            ID_EX.forward[0]=3;
            ID_EX.forward[1]=rs;
            ID_EX.forward[2] = 0;
        }
        else
        {
            if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
            {
                ID_EX.read_data1 = EX_DM.ALU_result;
                ID_EX.forward[0] = 1;
                ID_EX.forward[1] = rs;
                ID_EX.forward[2] = 0;
            }
            else
                ID_EX.read_data1 = reg[rs];
            if(rt==EX_DM.write_reg && EX_DM.can_forward==1&&rt!=0)
            {
                ID_EX.read_data2 = EX_DM.ALU_result;
                ID_EX.forward[0] = 2;
                ID_EX.forward[1] = rt;
                ID_EX.forward[2] = 0;
            }
            else
                ID_EX.read_data2 = reg[rt];
        }
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }


        if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 = EX_DM.ALU_result;
            ID_EX.forward[0] = 1;
            ID_EX.forward[1] = rs;
            ID_EX.forward[2] = 0;
        }
        else
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }


        if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 = EX_DM.ALU_result;
            ID_EX.forward[0] = 1;
            ID_EX.forward[1] = rs;
            ID_EX.forward[2] = 0;
        }
        else
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }


        if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 = EX_DM.ALU_result;
            ID_EX.forward[0] = 1;
            ID_EX.forward[1] = rs;
            ID_EX.forward[2] = 0;
        }
        else
            ID_EX.read_data1 = reg[rs];
        ID_EX.read_data2 = 0;
        ID_EX.write_reg = rt;
        break;
    }
    case 0x0A:	///slti
    {
        immediate = cut_immediate(IF_ID.instruction);
        rs = cut_rs(IF_ID.instruction);
        rt = cut_rt(IF_ID.instruction);
        ID_EX.immediate_ext = immediate;
        ID_EX.instruction = IF_ID.instruction;
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
            if(((rs==DM_WB.write_reg&&DM_WB.can_forward!=2)||(rs==EX_DM.write_reg&&EX_DM.can_forward==0&&ID_EX.instruction!=0))&&rs!=0)
            {
                ID_EX.stall=1;
                ID_EX.instruction=0;

                break;
            }


        if(rs==EX_DM.write_reg && EX_DM.can_forward==1&&rs!=0)
        {
            ID_EX.read_data1 = EX_DM.ALU_result;
            ID_EX.forward[0] = 1;
            ID_EX.forward[1] = rs;
            ID_EX.forward[2] = 0;
        }
        else
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
        if(((rs==DM_WB.write_reg&&DM_WB.can_forward==0)||(rs==EX_DM.write_reg&&ID_EX.instruction!=0))&&rs!=0)
        {

            ID_EX.stall=1;
            ID_EX.instruction=0;

            break;
        }
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
        if(((rt==DM_WB.write_reg&&DM_WB.can_forward==0)||(rt==EX_DM.write_reg&&ID_EX.instruction!=0))&&rt!=0)
        {

            ID_EX.stall=1;
            ID_EX.instruction=0;

            break;
        }


        if(rs==DM_WB.write_reg && DM_WB.can_forward==1&&rs!=0)
        {
            if(rt==DM_WB.write_reg && DM_WB.can_forward==1&&rt!=0)
            {
                if(DM_WB.ALU_result==DM_WB.ALU_result)
                {
                    branch = 1;
                    PCback = IF_ID.PC + 4 + immediate*4;

                }
                ID_EX.forward[0] = 3;
                ID_EX.forward[1] = rs;
                ID_EX.forward[2] = 1;
            }
            else
            {

                if(DM_WB.ALU_result==reg[rt])
                {

                    branch = 1;
                    PCback = IF_ID.PC + 4 + immediate*4;

                }
                ID_EX.forward[0] = 1;
                ID_EX.forward[1] = rs;
                ID_EX.forward[2] = 1;
            }

        }
        else
        {

            if(rt==DM_WB.write_reg && DM_WB.can_forward==1&&rt!=0)
            {

                if(DM_WB.ALU_result==reg[rs])
                {

                    branch = 1;
                    PCback = IF_ID.PC + 4 + immediate*4;


                }
                ID_EX.forward[0] = 2;
                ID_EX.forward[1] = rt;
                ID_EX.forward[2] = 1;
            }
            else
            {
                if(reg[rs]==reg[rt])
                {
                    branch = 1;
                    PCback = IF_ID.PC + 4 + immediate*4;

                }
                ID_EX.forward[0] = 0;
                ID_EX.forward[1] = 0;
                ID_EX.forward[2] = 0;

            }

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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
        if(((rs==DM_WB.write_reg&&DM_WB.can_forward==0)||(rs==EX_DM.write_reg&&ID_EX.instruction!=0))&&rs!=0)
        {
            ID_EX.stall=1;
            ID_EX.instruction=0;

            break;
        }
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
        if(((rt==DM_WB.write_reg&&DM_WB.can_forward==0)||(rt==EX_DM.write_reg&&ID_EX.instruction!=0))&&rt!=0)
        {
            ID_EX.stall=1;
            ID_EX.instruction=0;

            break;
        }

        if(EX_DM.stall!=1)
        {
            if(rs==DM_WB.write_reg && DM_WB.can_forward==1&&rs!=0)
            {
                if(rt==DM_WB.write_reg && DM_WB.can_forward==1&&rt!=0)
                {
                    if(DM_WB.ALU_result!=reg[rs])
                    {
                        branch = 1;
                        PCback = IF_ID.PC + 4 + immediate*4;

                    }
                    ID_EX.forward[0] = 3;
                    ID_EX.forward[1] = rs;
                    ID_EX.forward[2] = 1;
                }
                else
                {
                    if(DM_WB.ALU_result!=reg[rt])
                    {
                        branch = 1;
                        PCback = IF_ID.PC + 4 + immediate*4;

                    }
                    ID_EX.forward[0] = 1;
                    ID_EX.forward[1] = rs;
                    ID_EX.forward[2] = 1;
                }

            }
            else
            {
                if(rt==DM_WB.write_reg && DM_WB.can_forward==1&&rt!=0)
                {
                    if(DM_WB.ALU_result!=reg[rs])
                    {
                        branch = 1;
                        PCback = IF_ID.PC + 4 + immediate*4;

                    }
                    ID_EX.forward[0] = 2;
                    ID_EX.forward[1] = rt;
                    ID_EX.forward[2] = 1;
                }
                else
                {
                    if(reg[rs]!=reg[rt])
                    {
                        branch = 1;
                        PCback = IF_ID.PC + 4 + immediate*4;

                    }
                    ID_EX.forward[0] = 0;
                    ID_EX.forward[1] = 0;
                    ID_EX.forward[2] = 0;

                }

            }
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
        if(!((EX_DM.write_reg==DM_WB.write_reg)&&(EX_DM.can_forward==1)))
        if(((rs==DM_WB.write_reg&&DM_WB.can_forward==0)||(rs==EX_DM.write_reg&&ID_EX.instruction!=0))&&rs!=0)
        {
            ID_EX.stall=1;
            ID_EX.instruction=0;

            break;
        }


        if(EX_DM.stall!=1)
        {
            if(rs == DM_WB.write_reg && DM_WB.can_forward==1&&rs!=0)
            {
                if(DM_WB.ALU_result>0)
                {
                    branch = 1;
                    PCback = IF_ID.PC + 4 + immediate*4;
                }
                ID_EX.forward[0] = 1;
                ID_EX.forward[1] = rs;
                ID_EX.forward[2] = 1;
            }
            else
            {
                if(reg[rs]>0)
                {

                    branch = 1;
                    PCback = IF_ID.PC + 4 + immediate*4;

                }
            }
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

        branch=1;
        IF_ID.PC+=4;
        address=address<<2;
        PCback = (unsigned) IF_ID.PC>>28;
        PCback = PCback<<28;
        PCback = (unsigned)PCback|address;
        break;
    }
    case 0x03:	///jal
    {
        ID_EX.instruction = IF_ID.instruction;
        address = cut_address(IF_ID.instruction);
        branch=1;
        address=address<<2;
        ID_EX.write_reg=31;
        IF_ID.PC+=4;
        ID_EX.immediate_ext = IF_ID.PC;
        PCback = (unsigned) IF_ID.PC>>28;
        PCback = PCback<<28;
        PCback = (unsigned)PCback|address;
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

    if(errors[0]==1)fprintf(error,"In cycle %d: Write $0 Error\n",count+1);
    if(errors[1]==1)fprintf(error,"In cycle %d: Address Overflow\n",count+1);
    if(errors[2]==1)fprintf(error,"In cycle %d: Misalignment Error\n",count+1);
    if(errors[3]==1)fprintf(error,"In cycle %d: Number Overflow\n",count+1);
    unsigned char rt=0;
    unsigned char rd=0;
    unsigned char shamt=0;
    unsigned char funct=0;

    int i=0;
    int j=0;


    if(flags==0)
    {
        tempPC = PC;
        change = 0;
        branch = 0;
        stalls=0;
    }
    else
    {
        if(stalls==1)
        {
            tempPC = tempPC;
            stalls=0;
        }
        else
        {
            if(change==1)
            {
                tempPC=changePC;
                change=0;
            }
            else
            {
                tempPC+=4;


            }

        }


    }
    //printf("\nflags = %d, bramch = %d, change = %d\n\n",flags,branch,change);
    if(branch==1)
    {
        changePC = PCback;

        change=1;
    }


    if(ID_EX.stall==1)
    {
        stalls=1;
    }

    if(tempPC>=PC_start)
    {
        if(ID_EX.stall==1)
        {
            i = (tempPC-PC_start)/4;
            IF_ID.instruction = IF_ID.instruction;
        }
        else
        {

            i=(tempPC-PC_start)/4;
            IF_ID.instruction=iim[i];
            IF_ID.PC=tempPC;

        }

 fprintf(snapshot,"PC: 0x%08X\n",tempPC);
    if(branch == 0&& ID_EX.stall==0)
        fprintf(snapshot,"IF: 0x%08X",iim[i]);
    else if(branch==1&&ID_EX.stall==0)
        fprintf(snapshot,"IF: 0x%08X to_be_flushed",iim[i]);
    else
        fprintf(snapshot,"IF: 0x%08X to_be_stalled",iim[i]);

    }
    else
    {
        if(ID_EX.stall==1)
            IF_ID.instruction=IF_ID.instruction;
        else
            IF_ID.instruction=0;

        fprintf(snapshot,"PC: 0x%08X\n",tempPC);
    if(branch == 0&& ID_EX.stall==0)
        fprintf(snapshot,"IF: 0x00000000");
    else if(branch==1&&ID_EX.stall==0)
        fprintf(snapshot,"IF: 0x%00000000 to_be_flushed");
    else
        fprintf(snapshot,"IF: 0x%00000000 to_be_stalled");

    }


    fprintf(snapshot,"\n");
    name = toname(show_IDi);
    fprintf(snapshot,"ID: %s",name);
    if(ID_EX.stall==1)
        fprintf(snapshot," to_be_stalled");
    else
    {
        if(ID_EX.forward[2]==1&&ID_EX.forward[0]!=0)
        {
            if(ID_EX.forward[0]==1)
            {
                fprintf(snapshot," fwd_EX-DM_rs_$%d",ID_EX.forward[1]);
            }
            else if(ID_EX.forward[0]==2)
            {
                fprintf(snapshot," fwd_EX-DM_rt_$%d",ID_EX.forward[1]);
            }
            else
            {
                fprintf(snapshot," fwd_EX-DM_rs_$%d fwd_EX-DM_rt_$%d",ID_EX.forward[1],ID_EX.forward[1]);
            }
        }
    }

    fprintf(snapshot,"\n");
    name = toname(show_EXi);
    fprintf(snapshot,"EX: %s",name);


    if(EX_DM.forward[2]==0&&EX_DM.forward[0]!=0)
    {
        if(EX_DM.forward[0]==1)
        {
            fprintf(snapshot," fwd_EX-DM_rs_$%d",EX_DM.forward[1]);
        }
        else if(EX_DM.forward[0]==2)
        {
            fprintf(snapshot," fwd_EX-DM_rt_$%d",EX_DM.forward[1]);
        }
        else
        {
            fprintf(snapshot," fwd_EX-DM_rs_$%d fwd_EX-DM_rt_$%d",EX_DM.forward[1],EX_DM.forward[1]);
        }
    }

    fprintf(snapshot,"\n");
    name = toname(show_DMi);
    fprintf(snapshot,"DM: %s",name);
    fprintf(snapshot,"\n");
    name = toname(show_WBi);
    fprintf(snapshot,"WB: %s",name);
    fprintf(snapshot,"\n");
    fprintf(snapshot,"\n");
    if(branch == 1 && ID_EX.stall!=1)
    {
        IF_ID.instruction = 0;  ///flush
        branch =0;
    }
    op=(unsigned)iim[i]>>26;
    shamt = cut_shamt(iim[i]);
    rt = cut_rt(iim[i]);
    rd = cut_rd(iim[i]);
    funct = cut_func(iim[i]);

    if(op==0&&shamt==0&&rt==0&&rd==0&&funct==0&&(ID_EX.stall!=1))
        IF_ID.instruction=0;

    if(op==0x3F)
    {
        return 1;
    }
    else
        return 0;
}
