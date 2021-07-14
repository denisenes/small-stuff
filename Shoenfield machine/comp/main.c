#include <stdio.h>
#include <stdlib.h>

#include "Traverser.h"
#include "Parser.h"
#include "Absyn.h"
#include "Vector.h"

// default number of allocated registers is 100
int ALLOC_SIZE;
// list of registers that machine has to set before execution
vector SET_REGS;
// target bytecode file
FILE * output;

int main(int argc, char ** argv)
{
  FILE * input;
  Prog AST_tree;

  if (argc > 1) 
  {
    input = fopen(argv[1], "r");
    if (!input)
    {
      fprintf(stderr, "Error opening input file.\n");
      exit(1);
    }
  }
  else input = stdin;

  output = fopen("out.byte", "wb");
  if (!output)
  {
    fprintf(stderr, "Error opening output file.\n");
    exit(1);
  }

  AST_tree = pProg(input);
  if (AST_tree)
  {
    traverseProg(AST_tree);
    return 0;
  }
  fprintf(stderr, "Parsing error.\n");
  return 1;
}

