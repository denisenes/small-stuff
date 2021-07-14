#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include "Absyn.h"

typedef union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Prog prog_;
  PrsList prslist_;
  Pragma pragma_;
  InstrList instrlist_;
  Instr instr_;
  R r_;
  A a_;
  S s_;
  V v_;
} YYSTYPE;

#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _INTEGER_ 267

extern YYSTYPE yylval;
Prog pProg(FILE *inp);
PrsList pPrsList(FILE *inp);
Pragma pPragma(FILE *inp);
InstrList pInstrList(FILE *inp);
Instr pInstr(FILE *inp);
R pR(FILE *inp);
A pA(FILE *inp);
S pS(FILE *inp);
V pV(FILE *inp);


#endif
