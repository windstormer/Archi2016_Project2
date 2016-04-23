#include <stdio.h>
#include <stdlib.h>


int WB();
int DM();
int EX();
int ID();
int IF(int);


int PCback,branch;

extern int reg[32];
extern int PC;
extern int PC_start;
extern int iim[256];
extern unsigned char dim[1024];

unsigned char op,funct;
