#include "Vector.h"

void add_elem(vector * vec, unsigned int l, unsigned int r) {
    if (vec->cnt >= vec->cap) {
        if (vec->cap == 0) {
            vec->arr = malloc(sizeof(pair));
            vec->cap = 1;
        } else {
            vec->cap *= 2;
            vec->arr = realloc(vec->arr, (vec->cap) * sizeof(pair));
        }
    }
    vec->arr[vec->cnt].l = l;
    vec->arr[vec->cnt].r = r;
	vec->cnt += 1;
}