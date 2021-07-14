#include <stdio.h>
#include <stdlib.h>

#include "shmemu.h"

uint32_t * mem;
vector program;
uint32_t PC;


void prepare(FILE * input) {
    // allocate memory
    uint32_t mem_size;
    fread(&mem_size, sizeof(uint32_t), 1, input);
    mem = calloc(mem_size, sizeof(uint32_t));

    // set registers
    uint32_t n;
    fread(&n, sizeof(uint32_t), 1, input);
    for (int i = 0; i < n; i++) {
        uint32_t reg, val;
        fread(&reg, sizeof(uint32_t), 1, input);
        fread(&val, sizeof(uint32_t), 1, input);
        mem[reg] = val;
    }

    // copy instructions from file to heap
    Instr current_instr;
    while (fread(&current_instr, sizeof(Instr), 1, input) == 1) {
        add_elem(&program, current_instr.code, current_instr.operand1, current_instr.operand2);
    }
}

void execute() {
    PC = 0;
    while(1) {
        // machine stops when program counter contains number > number of last instruction
        if (PC >= program.cnt) {
            break;
        }

        Instr * current_instr = &program.arr[PC];
        switch (current_instr->code)
        {
        //INC
        case 0:
            mem[current_instr->operand1]++;
            PC++;
            break;
        //DEC
        case 1:
            if (mem[current_instr->operand1] > 0) {
                mem[current_instr->operand1]--;
                PC = current_instr->operand2;
            } else {
                PC++;
            }
            break;
        // Error
        default:
            fprintf(stderr, "Error: unknown instruction code\n");
            exit(1);
            break;
        }
    }
}

int main(int argc, char ** argv) {
    FILE * input;

    if (argc > 1) {
        input = fopen(argv[1], "rb");
        if (!input) {
            fprintf(stderr, "Error opening input file.\n");
            exit(1);
        }
    }

    prepare(input);
    fclose(input);

#ifdef DEBUG
    printf("number: %d\n", program.cnt);
    for (int i = 0; i < program.cnt; i++) {
        printf("Instruction: %d, oper1: %d, oper2: %d\n", program.arr[i].code, program.arr[i].operand1, program.arr[i].operand2);
    }
#endif

    execute();
    printf("Machine finished execution\n");
    printf("r0 contains: %u\n", mem[0]);
    return 0;
}

void add_elem(vector * vec, uint8_t code, uint32_t o1, uint32_t o2) {
    if (vec->cnt >= vec->cap) {
        if (vec->cap == 0) {
            vec->arr = malloc(sizeof(Instr));
            vec->cap = 1;
        } else {
            vec->cap *= 2;
            vec->arr = realloc(vec->arr, (vec->cap) * sizeof(Instr));
        }
    }
    vec->arr[vec->cnt].code = code;
    vec->arr[vec->cnt].operand1 = o1;
    vec->arr[vec->cnt].operand2 = o2;
	vec->cnt += 1;
}