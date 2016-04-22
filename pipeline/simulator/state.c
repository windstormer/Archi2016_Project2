#include "state.h"
#include "state_reg.h"

void DM(){
	unsigned char *getting;

		op=(unsigned)EX_DM.instruction>>26;


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

                DM_WB.address = 0;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = (int)combine(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1],dim[EX_DM.ALU_result+2],dim[EX_DM.ALU_result+3]);
                break;
            }
            case 0x21:	///lh
            {
				DM_WB.address = 0;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = (short)combine_two(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1]);
                break;
            }
            case 0x25:	///lhu
            {
                DM_WB.address = 0;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = (short)combine_two(dim[EX_DM.ALU_result],dim[EX_DM.ALU_result+1]);
                break;
            }
            case 0x20:	///lb
            {
                DM_WB.address = 0;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = (char)dim[EX_DM.ALU_result];
                break;
            }
            case 0x24:	///lbu
            {
                DM_WB.address = 0;
				DM_WB.write_reg = EX_DM.write_reg;
				DM_WB.data = (unsigned)dim[EX_DM.ALU_result];
                break;
            }
            case 0x2B:	///sw
            {
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
                DM_WB.address = 0;
				DM_WB.write_reg = EX_DM.write_reg;
				getting[0] = (unsigned char)(EX_DM.read_data2&0x000000FF);
				dim[EX_DM.ALU_result]=getting[0];
				DM_WB.data = 0;
                break;
            }
            case 0x0F:	///lui
            {
                DM_WB.address = 0;
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