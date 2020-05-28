#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "term.h"
#include "helper.h"
#include "elt.h"
#include "inpt.h"


struct term* termalloc(struct elt* elts, int rank, double coeff) {
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

// pairwise outerproduct
struct term* pairproduct(struct elt* elt1, struct elt* elt2, int coeff) {
    if (elt1->n != elt2->n) return NULL;
    struct elt* elts = (struct elt*) malloc(sizeof(struct elt) * 2);
    elts[0] = *elt1;
    elts[1] = *elt2;
    return termalloc(elts, 2, coeff);
};


struct term* termpermute(struct term* tm, const int *permutation) {
    struct elt* elts = (struct elt*) malloc(sizeof(struct elt) * tm->rank);
    for (int l = 0; l < tm->rank; l++) elts[l] = tm->elts[permutation[l]];
    return termalloc(elts, tm->rank, tm->coeff);
}

// all permutations, each with 1/rank! coeff factor
struct term* termperms(struct term* tm, int antisym) {
    int nperms = factorial(tm->rank);
    int n = tm->rank;
    struct term *perms = (struct term *) malloc(sizeof(struct term) * nperms);
    int p[nperms];
    for (int i= 0; i < tm->rank; i++) p[i] = i;
    int stop = 0;
    int l = 0;
    int sgn = 1;
    while (1) {
        perms[l] = *termpermute(tm, p);
        perms[l].coeff = tm->coeff * 1. / nperms;
        if (antisym) perms[l].coeff *= sgn;
        sgn *= -1;
        l++;
        int k = n - 1;
        while (p[k-1] >= p[k]) {
            if (--k == 0) stop = 1;
        }
        if (stop) break;
        int j = n - 1;
        while (j > k && p[j] <= p[k - 1]) j--;
        swap(p, k - 1, j);
        reverse(p, k, n - 1);
    }
    return perms;
}

void printterm(struct term* tm) {
    struct elt el;
    printf("(tensor term)|dim: %d|rank: %d|coeff: %+.2f|elementary tensors:", tm->n, tm->rank,
           tm->coeff);
    for (int i = 0; i < tm->rank; i++) {
        el = tm->elts[i];
        printf(" %d", el.k);
    }
    printf("|\n");
}


double evaluateterm(struct term* tm, struct inpt* ipt) {
    double termresult = 1.0;
    double elterm;
    int i;
    for (int j = 0; j < tm->rank; j++) {
        i = tm->elts[j].k;
        elterm = ipt->x[i][j];
        termresult *= elterm;
    }
    termresult *= tm->coeff;
    return termresult;
}