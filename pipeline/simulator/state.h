#include <stdio.h>
#include <stdlib.h>


int WB();
int DM();
int EX();
int ID();
int IF(int);

extern FILE *snapshot;
extern FILE *error;

int stall;



int PCback,branch;
int tempPC;
int changePC;
int change;

extern int reg[32];
extern int PC;
extern int PC_start;
extern int iim[256];
extern unsigned char dim[1024];

int show_IDi;
int show_EXi;
int show_DMi;
int show_WBi;
char * name;

unsigned char op,funct;
