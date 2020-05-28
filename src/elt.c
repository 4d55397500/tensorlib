#include <stdlib.h>
#include "elt.h"

int eltcalc(struct elt* el, int l) {
    return (el->k == l) ? 1 : 0;
}

struct elt* eltalloc(int k, int n) {
    struct elt* el = (struct elt *) malloc(sizeof(struct elt));
    el->k = k;
    el->n = n;
    return el;
}


