
#ifndef TENSORLIB_ELT_H
#define TENSORLIB_ELT_H

// a rank 1 elementary tensor
// in n-dim. vector space
// taking the value 1 on the kth
// basis vector
struct elt {
    int k; // non-zero index
    int n; // dim
};

int eltcalc(struct elt *, int);
struct elt* eltalloc(int, int);


#endif //TENSORLIB_ELT_H
