#include <stdlib.h>
#include <stdio.h>

#include "Traverser.h"

static void writeHeader() {
  fwrite(&ALLOC_SIZE, sizeof(uint32_t), 1, output);
  fwrite(&SET_REGS.cnt, sizeof(uint32_t), 1, output);
  for (int i = 0; i < SET_REGS.cnt; i++) {
    fwrite(&SET_REGS.arr[i], sizeof(pair), 1, output);
  }
}

void  traverseProg(Prog node) {
  switch(node->kind) {
    case is_Program:
      traversePrsList(node->u.program_.prslist_);
      writeHeader();
      traverseInstrList(node->u.program_.instrlist_);
      break;
    default:
      fprintf(stderr, "Error in AST-node Prog!\n");
      exit(1);
  }
}

void  traversePrsList(PrsList node) {
  switch(node->kind) {
    case is_PLNone:
      break;
    case is_PLElem: 
      traversePragma(node->u.plelem_.pragma_);
      traversePrsList(node->u.plelem_.prslist_);
      break;
    default:
      fprintf(stderr, "Error in AST-node PrsList!\n");
      exit(1);
  }
}

void  traversePragma(Pragma node) {
  switch(node->kind) {
    case is_Alloc:
      ALLOC_SIZE = traverseS(node->u.alloc_.s_);
      break;
    case is_Set: {
        uint32_t reg = traverseR(node->u.set_.r_);
        uint32_t val = traverseV(node->u.set_.v_);
        add_elem(&SET_REGS, reg, val);
        break;
      }
    default:
      fprintf(stderr, "Error in AST-node Pragma!\n");
      exit(1);
  }
}

void  traverseInstrList(InstrList node) {
  switch(node->kind) {
    case is_ILNone:
      break;
    case is_ILElem:
      traverseInstr(node->u.ilelem_.instr_);
      traverseInstrList(node->u.ilelem_.instrlist_);
      break;
    default:
      fprintf(stderr, "Error in AST-node InstrList!\n");
      exit(1);
  }
}

void  traverseInstr(Instr node) {
  switch(node->kind) {
    case is_Inc: {
        uint32_t reg = traverseR(node->u.inc_.r_);
        fwrite(&node->kind, sizeof(uint8_t), 1, output);
        fwrite(&reg, sizeof(uint32_t), 1, output);
        fwrite(&reg, sizeof(uint32_t), 1, output); // this is dummy byte
      }
      break;  
    case is_Dec: {
        uint32_t reg = traverseR(node->u.dec_.r_);
        uint32_t addr = traverseA(node->u.dec_.a_);
        fwrite(&node->kind, sizeof(uint8_t), 1, output);
        fwrite(&reg, sizeof(uint32_t), 1, output);
        fwrite(&addr, sizeof(uint32_t), 1, output);
      }
      break;
    default:
      fprintf(stderr, "Error in AST-node Instr!\n");
      exit(1);
  }
}

uint32_t  traverseR(R node) {
  switch(node->kind) {
    case is_Reg:
      return node->u.reg_.integer_;
    default:
      fprintf(stderr, "Error in AST-node R!\n");
      exit(1);
  }
}

uint32_t  traverseA(A node) {
  switch(node->kind) {
    case is_Addr:
      return node->u.addr_.integer_;
    default:
      fprintf(stderr, "Error in AST-node A!\n");
      exit(1);
  }
}

uint32_t  traverseS(S node) {
  switch(node->kind) {
    case is_Size:
      return node->u.size_.integer_;
    default:
      fprintf(stderr, "Error in AST-node S!\n");
      exit(1);
    }
}

uint32_t traverseV(V node) {
  switch(node->kind) {
    case is_Value:
      return node->u.value_.integer_;
    default:
      fprintf(stderr, "Error in AST-node V!\n");
      exit(1);
  }
}