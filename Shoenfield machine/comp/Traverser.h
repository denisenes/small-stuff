#ifndef TRAVERSER_HEADER
#define TRAVERSER_HEADER

#include <stdint.h>
#include <stdio.h>
#include "Absyn.h"
#include "Vector.h"

extern int ALLOC_SIZE;
extern vector SET_REGS;
extern FILE * output;


void traverseProg(Prog node);
void traversePrsList(PrsList node);
void traversePragma(Pragma node);
void traverseInstrList(InstrList node);
void traverseInstr(Instr node);
uint32_t traverseR(R node);
uint32_t traverseA(A node);
uint32_t traverseS(S node);
uint32_t traverseV(V node);

#endif

