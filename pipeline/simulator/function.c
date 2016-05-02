#include "function.h"
#include <stdlib.h>

int overflow_detect(int ans,int a,int b)
{


    if((a>0&&b>0&&ans<=0)||(a<0&&b<0&&ans>=0))
        return 1;
    else return 0;

/*
  int x=a>>31;
  int y=b>>31;
  int z=ans>>31;
  if(x==y &&x!=z)
    return 1;
  else return 0;
*/
}
unsigned char cut_rs(int a)
{
    unsigned char back;
    a<<=6;
    back=(unsigned)a>>27;

   // printf("%x ",back);
    return back;
}
unsigned char cut_rt(int a)
{
    unsigned char back;
    a<<=11;
    back=(unsigned)a>>27;

   // printf("%x ",back);
    return back;
}
unsigned char cut_rd(int a)
{
    unsigned char back;
    a<<=16;
    back=(unsigned)a>>27;

   // printf("%x ",back);
    return back;
}
unsigned char cut_shamt(int a)
{
    unsigned char back;
    a<<=21;
    back=(unsigned)a>>27;

    //printf("%x ",back);
    return back;
}
unsigned char cut_func(int a)
{
    unsigned char back;
    a<<=26;
    back=(unsigned)a>>26;

   // printf("%x ",back);
    return back;
}
short cut_immediate(int a)
{
    short back;
    a<<=16;
    back=a>>16;

    //printf("%x ",back);
    return back;
}

unsigned short cut_immediate_unsigned(int a)
{
    unsigned short back;
    a<<=16;
    back=(unsigned)a>>16;

    //printf("%x ",back);
    return back;
}
unsigned int cut_address(int a)
{
    unsigned int back;
    a<<=6;
    back=(unsigned)a>>6;

    //printf("%x ",back);
    return back;
}


unsigned int combine(unsigned char a,unsigned char b,unsigned char c,unsigned char d)
{

    unsigned int back=0;
    back |= a;
    back <<= 8;
    back |= b;
    back <<= 8;
    back |= c;
    back <<= 8;
    back |= d;
    return back;

}
unsigned short combine_two(unsigned char a, unsigned char b)
{
    unsigned short back=0;
    back |= a;
    back <<= 8;
    back |= b;
    return back;
}

unsigned char* seperate(int in)
{
    unsigned char* back;
    back=(unsigned char*)malloc(sizeof(unsigned char)*4);
    int a,b,c,d;
    a=in,b=in,c=in,d=in;

    a=(unsigned)a>>24;
    b=b<<8;
    b=(unsigned)b>>24;
    c=c<<16;
    c=(unsigned)c>>24;
    d=d<<24;
    d=(unsigned)d>>24;
    back[0]=(unsigned char)a;
    back[1]=(unsigned char)b;
    back[2]=(unsigned char)c;
    back[3]=(unsigned char)d;

    return back;
}
unsigned char* seperate_two(int in)
{
    unsigned char* back;
    back=(unsigned char*)malloc(sizeof(char)*2);

    in&=0x0000FFFF;

    int c,d;
    c=in,d=in;

    c=c<<16;
    c=(unsigned)c>>24;
    d=d<<24;
    d=(unsigned)d>>24;
    back[0]=(unsigned char)c;
    back[1]=(unsigned char)d;

    return back;
}

char* toname(int instruction)
{
unsigned char op;
unsigned char funct;
unsigned char shamt;
unsigned char rt;
unsigned char rd;
char* out;
if(instruction==0)
{
        out="NOP";
        return out;
}
op=(unsigned)instruction>>26;




            switch(op)
            {
            case 0x00:
            {
                funct=cut_func(instruction);

                switch(funct)
                {
                case 0x20:	///add
                {
                    out = "ADD";
                    break;
                }
                case 0x21:	///addu
                {
                    out = "ADDU";
                    break;
                }
                case 0x22:	///sub
                {
                    out = "SUB";
                    break;
                }
                case 0x24:	///and
                {
                    out = "AND";
                    break;
                }
                case 0x25:	///or
                {
                    out = "OR";
                    break;
                }
                case 0x26:	///xor
                {
                    out = "XOR";
                    break;
                }
                case 0x27:	///nor
                {
                    out = "NOR";
                    break;
                }
                case 0x28:	///nand
                {
                    out = "NAND";
                    break;
                }
                case 0x2A:	///slt
                {
                    out = "SLT";
                    break;
                }
                case 0x00:	///sll
                {
                    shamt = cut_shamt(instruction);
                    rt = cut_rt(instruction);
                    rd = cut_rd(instruction);
                    if(shamt==0&&rt==0&&rd==0)
                        out = "NOP";
                    else
                        out = "SLL";
                    break;
                }
                case 0x02:	///srl
                {
                    out = "SRL";
                    break;
                }
                case 0x03:	///sra
                {
                    out = "SRA";
                    break;
                }
                case 0x08:	///jr
                {
                    out = "JR";
                    break;
                }

                }
                break;
            }
            case 0x08:	///addi
            {
                out = "ADDI";
                break;
            }
            case 0x09:	///addiu
            {
                out = "ADDIU";
                break;
            }
            case 0x23:	///lw
            {
                out = "LW";
                break;
            }
            case 0x21:	///lh
            {
                out = "LH";
                break;
            }
            case 0x25:	///lhu
            {
                out = "LHU";
                break;
            }
            case 0x20:	///lb
            {
                out = "LB";
                break;
            }
            case 0x24:	///lbu
            {
                out = "LBU";
                break;
            }
            case 0x2B:	///sw
            {
                out = "SW";
                break;
            }
            case 0x29:	///sh
            {
                out = "SH";
                break;
            }
            case 0x28:	///sb
            {
                out = "SB";
                break;
            }
            case 0x0F:	///lui
            {
                out = "LUI";
                break;
            }
            case 0x0C:	///andi
            {
                out = "ANDI";
                break;
            }
            case 0x0D:	///ori
            {
                out = "ORI";
                break;
            }
            case 0x0E:	///nori
            {
                out = "NORI";
                break;
            }
            case 0x0A:	///slti
            {
                out = "SLTI";
                break;
            }
            case 0x04:	///beq
            {
                out = "BEQ";
                break;
            }
            case 0x05:	///bne
            {
                out = "BNE";
                break;
            }
            case 0x07:	///bgtz
            {
                out = "BGTZ";
                break;
            }
            case 0x02:	///j
            {
                out = "J";
                break;
            }
            case 0x03:	///jal
            {
                out = "JAL";
                break;
            }
            case 0x3F:	///halt
            {
                out = "HALT";
                break;
            }


            }

return out;
}
