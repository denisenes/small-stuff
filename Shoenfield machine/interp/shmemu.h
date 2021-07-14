#ifndef SHMEMU_VECTOR_HEADER
#define SHMEMU_VECTOR_HEADER

#include <stdint.h>

#pragma pack(1)
typedef struct Instr_m {
    uint8_t code;
    uint32_t operand1;
    uint32_t operand2; 
} Instr;

typedef struct vector_m {
    int cnt;
    int cap;
    Instr * arr;
} vector;

void add_elem(vector * vec, uint8_t code, uint32_t o1, uint32_t o2);

#endif