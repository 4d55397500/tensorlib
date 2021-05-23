#include "constants.h"
#include "inpt.h"
#include "elt.h"

#ifndef TENSORLIB_TERM_H
#define TENSORLIB_TERM_H

struct term {
    struct elt elts[MAXRANK];
    int rank;
    int n; // dim
    double coeff; // a possible coefficient
};

struct term* termalloc(struct elt *, int, double);
struct term* pairproduct(struct elt *, struct elt *, double);
struct term* termpermute(struct term *, const int *);
struct term* termperms(struct term *, int);
void printterm(struct term *);
double evaluateterm(struct term *, struct inpt *);

#endif //TENSORLIB_TERM_H
