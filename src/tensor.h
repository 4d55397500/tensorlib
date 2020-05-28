#include "constants.h"
#include "term.h"
#include "inpt.h"

#ifndef TENSORLIB_TENSOR_H
#define TENSORLIB_TENSOR_H


struct tensor {
    struct term terms[MAXTERMS];
    int nterms; // number of terms of given rank to add together
    int rank;
    int n; // dim
};

struct tensor* tensalloc(struct term *, int);
struct tensor* addterms(struct term *, struct term *);
struct tensor* tensorperms(struct tensor *, int);
double evaluate(struct tensor *, struct inpt *);
struct tensor* symmetrize(struct tensor *);
struct tensor* antisymmetrize(struct tensor *);
void printtensor(struct tensor *);
double determinant(struct inpt *);

#endif //TENSORLIB_TENSOR_H
