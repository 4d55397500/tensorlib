#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include "string.h"

#define MAXRANK 100
#define MAXTERMS 50
#define MAXDIM 20

struct determinant {

};

struct elt {
    int k; // non-zero index
    int n; // dim
};

struct elt* eltalloc(int k, int n) {
    struct elt* el = (struct elt *) malloc(sizeof(struct elt));
    el->k = k;
    el->n = n;
    return el;
}

struct inpt {
    double x[MAXDIM][MAXRANK]; // input matrix
    int rank; // number of input vectors
    int n; // dim
};


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

struct term {
    struct elt elts[MAXRANK];
    int rank;
    int n; // dim
    int coeff; // a possible coefficient
};

struct tensor {
    struct term terms[MAXTERMS];
    int nterms; // number of terms of given rank to add together
    int rank;
    int n; // dim
};

struct tensor* tensalloc(struct term* terms, int nterms) {
    struct tensor* t = (struct tensor *) malloc(sizeof(struct tensor));
    t->nterms = nterms;
    for (int i = 0; i < nterms; i++) {
        if (nterms > 1 && i < nterms - 1 &&
        (terms[i].n != terms[i+1].n || terms[i].rank != terms[i+1].rank)) {
            return NULL;
        }
        t->terms[i] = terms[i];
    }
    t->rank = terms[0].rank;
    t->n = terms[0].n;
    return t;
}

struct tensor* addterms(struct term* tm1, struct term* tm2) {
    if (tm1->rank != tm2->rank || tm1->n!= tm2->n) return NULL;
    struct term* terms = (struct term *) malloc(sizeof(struct term) * 2);
    terms[0] = *tm1;
    terms[1] = *tm2;
    return tensalloc(terms, 2);
}

struct term* termalloc(struct elt* elts, int rank, int coeff) {
    for (int i = 0; i < rank - 1; i++) {
        if (elts[i].n != elts[i+1].n) return NULL;
    }
    struct term* tm = (struct term *) malloc(sizeof(struct term));
    tm->coeff = coeff;
    tm->rank = rank;
    tm->n = elts[0].n;
    memcpy(tm->elts, elts, sizeof(struct elt) * tm->rank);
    return tm;
}

void printterm(struct term* tm) {
    struct elt el;
    printf("(tensor term)|dim: %d|rank: %d|coeff: %+d|elementary tensors:", tm->n, tm->rank,
            tm->coeff);
    for (int i = 0; i < tm->rank; i++) {
        el = tm->elts[i];
        printf(" %d", el.k);
    }
    printf("|\n");
}


void printtensor(struct tensor* t) {
    printf("Tensor with %d terms:\n---\n", t->nterms);
    for (int i = 0; i < t->nterms; i++) {
        printf("\t");
        printterm(&t->terms[i]);
    }
}

// pairwise outerproduct
struct term* pairproduct(struct elt* elt1, struct elt* elt2, int coeff) {
    if (elt1->n != elt2->n) return NULL;
    struct elt* elts = (struct elt*) malloc(sizeof(struct elt) * 2);
    elts[0] = *elt1;
    elts[1] = *elt2;
    return termalloc(elts, 2, coeff);
};

double evaluateterm(struct term* tm, struct inpt* ipt) {
    double termresult = 1.0;
    double elterm;
    int i;
    for (int j = 0; j < tm->rank; j++) {
        i = tm->elts[j].k;
        elterm = tm->coeff * ipt->x[i][j];
        termresult *= elterm;
    }
    return termresult;
}

double evaluate(struct tensor* t, struct inpt* ipt) {
    printinpt(ipt);
    printf("Evaluating tensor on input...\n");
    double result = 0.0;
    for (int i = 0; i < t->nterms; i++) {
        result += evaluateterm(&t->terms[i], ipt);
    }
    printf("Evaluated to %.2f\n", result);
    return result;
}


int eltcalc(struct elt* el, int l) {
    return (el->k == l) ? 1 : 0;
}

int main() {
    struct elt* elt1 = eltalloc(1, 3);
    struct elt* elt2 = eltalloc(2, 3);
    struct term* eltp1 = pairproduct(elt1, elt2, 1);

    struct elt *elt3 = eltalloc(0, 3);
    struct elt* elt4 = eltalloc(1, 3);
    struct term* eltp2 = pairproduct(elt3, elt4, -4);

    struct tensor* t = addterms(eltp1, eltp2);
    printtensor(t);

    double x[3][2] = {
            {0.1, 0.3},
            {-0.4, -0.2},
            {0.5, 0.2}
    };
    struct inpt* ipt = inptalloc(x, 2, 3);

    evaluate(t, ipt);

    return 0;
}
