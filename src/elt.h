
#ifndef TENSORLIB_ELT_H
#define TENSORLIB_ELT_H

struct elt {
    int k; // non-zero index
    int n; // dim
};

int eltcalc(struct elt *, int);
struct elt* eltalloc(int, int);


#endif //TENSORLIB_ELT_H
