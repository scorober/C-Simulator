#ifndef COMP
#define COMP

#include "bstr.h"



#define MAXMEM 50

struct compType {
	BitString reg[8];
    BitString mem[MAXMEM];
	BitString pc;
    BitString ir;
	BitString cc;  /* condition code */
};

typedef struct compType Computer;

/* initialized the computer  */
void COMP_Init(Computer*);

/* displays its current contents - register and memory */
void COMP_Display(Computer);

/* put a word (either data or instruction) into the computer's */
/* memory at address addr */
void COMP_LoadWord(Computer* comp, int addr, BitString word);

/* execute the computer's stored program */
/* starting at PC = 0 */
/* and until the program executes a HALT */
void COMP_Execute(Computer* comp);

/* Performs Not operation */
void COMP_ExecuteNot(Computer *comp);

/* Performs Add operation. */
void COMP_ExecuteAdd(Computer *comp);

/* Performs LD operation. */
void COMP_ExecuteLD(Computer *comp);

/* Performs BR operation. */
void COMP_ExecuteBR(Computer *comp);

/* Performs Out operation. */
void COMP_ExecuteOut(Computer *comp);

/* Grabs trap vector from a Trap instruction. */
int COMP_GetTrapVector(BitString trapVect8);

/* Updates the nzp condition code. */
void COMP_SetConditionCode(BitString* nzp, int value);

#endif

