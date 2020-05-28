
#include <stdlib.h>
#include <stdio.h>
#include "inpt.h"

void printinpt(struct inpt *inpt){
    printf("Input of %d vectors each of dim %d:\n---", inpt->rank, inpt->n);
    for (int i = 0; i < inpt->n; i++) {
        for (int j = 0; j < inpt->rank; j++) {
            if (j == 0) {
                printf("\n\t");
            }
            printf("%+.2f ", inpt->x[i][j]);
        }
    }
    printf("\n");
}

struct inpt* inptalloc(const double *x, int rank, int n) {
    struct inpt* ipt = (struct inpt *) malloc(sizeof(struct inpt));
    ipt->rank = rank;
    ipt->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < rank; j++) {
            ipt->x[i][j] = x[i* rank + j];
        }
    }
    return ipt;
}