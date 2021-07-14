%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Absyn.h"
#define initialize_lexer machine_initialize_lexer
extern int yyparse(void);
extern int yylex(void);
int yy_mylinenumber;
extern int initialize_lexer(FILE * inp);
void yyerror(const char *str)
{
  extern char *machinetext;
  fprintf(stderr,"error: line %d: %s at %s\n",
    yy_mylinenumber + 1, str, machinetext);
}

Prog YY_RESULT_Prog_ = 0;
Prog pProg(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Prog_;
  }
}

PrsList YY_RESULT_PrsList_ = 0;
PrsList pPrsList(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_PrsList_;
  }
}

Pragma YY_RESULT_Pragma_ = 0;
Pragma pPragma(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Pragma_;
  }
}

InstrList YY_RESULT_InstrList_ = 0;
InstrList pInstrList(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_InstrList_;
  }
}

Instr YY_RESULT_Instr_ = 0;
Instr pInstr(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Instr_;
  }
}

R YY_RESULT_R_ = 0;
R pR(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_R_;
  }
}

A YY_RESULT_A_ = 0;
A pA(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_A_;
  }
}

S YY_RESULT_S_ = 0;
S pS(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_S_;
  }
}

V YY_RESULT_V_ = 0;
V pV(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_V_;
  }
}



%}

%union
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

}

%token _ERROR_
%token _SYMB_0    /*   $pragmas   */
%token _SYMB_1    /*   $instructions   */
%token _SYMB_2    /*   ;   */
%token _SYMB_3    /*   @alloc   */
%token _SYMB_4    /*   @set   */
%token _SYMB_5    /*   ,   */
%token _SYMB_6    /*   DEC   */
%token _SYMB_7    /*   INC   */

%type <prog_> Prog
%type <prslist_> PrsList
%type <pragma_> Pragma
%type <instrlist_> InstrList
%type <instr_> Instr
%type <r_> R
%type <a_> A
%type <s_> S
%type <v_> V

%token<int_> _INTEGER_

%start Prog
%%
Prog : _SYMB_0 PrsList _SYMB_1 InstrList { $$ = make_Program($2, $4); YY_RESULT_Prog_= $$; } 
;
PrsList : /* empty */ { $$ = make_PLNone(); YY_RESULT_PrsList_= $$; } 
  | Pragma _SYMB_2 PrsList { $$ = make_PLElem($1, $3); YY_RESULT_PrsList_= $$; }
;
Pragma : _SYMB_3 S { $$ = make_Alloc($2); YY_RESULT_Pragma_= $$; } 
  | _SYMB_4 R _SYMB_5 V { $$ = make_Set($2, $4); YY_RESULT_Pragma_= $$; }
;
InstrList : /* empty */ { $$ = make_ILNone(); YY_RESULT_InstrList_= $$; } 
  | Instr _SYMB_2 InstrList { $$ = make_ILElem($1, $3); YY_RESULT_InstrList_= $$; }
;
Instr : _SYMB_7 R { $$ = make_Inc($2); YY_RESULT_Instr_= $$; } 
  | _SYMB_6 R _SYMB_5 A { $$ = make_Dec($2, $4); YY_RESULT_Instr_= $$; }
;
R : _INTEGER_ { $$ = make_Reg($1); YY_RESULT_R_= $$; } 
;
A : _INTEGER_ { $$ = make_Addr($1); YY_RESULT_A_= $$; } 
;
S : _INTEGER_ { $$ = make_Size($1); YY_RESULT_S_= $$; } 
;
V : _INTEGER_ { $$ = make_Value($1); YY_RESULT_V_= $$; } 
;

