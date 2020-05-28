#include "constants.h"

#ifndef TENSORLIB_INPT_H
#define TENSORLIB_INPT_H

struct inpt {
    double x[MAXDIM][MAXRANK]; // input matrix
    int rank; // number of input vectors
    int n; // dim
};

void printinpt(struct inpt *);
struct inpt* inptalloc(const double *, int, int);



#endif //TENSORLIB_INPT_H
