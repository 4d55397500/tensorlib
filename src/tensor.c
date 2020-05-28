
#include <stdio.h>
#include <stdlib.h>
#include "term.h"
#include "tensor.h"
#include "helper.h"


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


struct tensor* tensorperms(struct tensor *t, int antisym) {
    struct term* perms;
    int m = factorial(t->rank);
    int nterms = t->nterms * m;
    struct term* allterms = (struct term *) malloc(sizeof(struct term) * nterms);
    for (int k = 0; k < t->nterms; k++) {
        // add all permutations of the given term to the terms array for the tensor
        perms = termperms(&t->terms[k], antisym);
        for (int l = 0; l < m; l++) {
            allterms[k * m + l] = perms[l];
        }
    }
    return tensalloc(allterms, nterms);
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

struct tensor *symmetrize(struct tensor *t) {
    printf("Symmetrizing tensor...\n");
    return tensorperms(t, 0);
}

struct tensor *antisymmetrize(struct tensor *t) {
    return tensorperms(t, 1);
}

void printtensor(struct tensor* t) {
    printf("Tensor with %d terms:\n---\n", t->nterms);
    for (int i = 0; i < t->nterms; i++) {
        printf("\t");
        printterm(&t->terms[i]);
    }
}

double determinant(struct inpt* ipt) {
    printf("Computing determinant by passing the following input to antisymmetric unit tensor...\n");
    int n = ipt->n;
    struct elt* el = (struct elt *) malloc(sizeof(struct elt) * n);

    for (int i = 0; i < n; i++) {
        el[i] = *eltalloc(i, n);
    }
    struct term* tm = termalloc(el, n, 1);

    struct tensor* dmtensor = antisymmetrize(tensalloc(tm, 1));
    for (int i = 0; i < dmtensor-> nterms; i++) {
        dmtensor->terms[i].coeff = 2. * (((i+1) % 2) - 0.5);
    }
    printtensor(dmtensor);
    double det = evaluate(dmtensor, ipt);

    printf("Computed a determinant of %.2f\n", det);
    return det;

}
