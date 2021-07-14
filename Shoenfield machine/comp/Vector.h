#ifndef VECTOR_HEADER
#define VECTOR_HEADER

#include  <stdlib.h>

typedef struct pair_m {
    unsigned int l;
    unsigned int r;
} pair;

typedef struct vector_m {
    int cnt;
    int cap;
    pair * arr;
} vector;

void add_elem(vector * vec, unsigned int l, unsigned int r);

#endif
