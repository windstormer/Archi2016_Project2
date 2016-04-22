#include <stdio.h>
#include <stdlib.h>

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