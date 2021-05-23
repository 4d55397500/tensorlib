#include "euclidean.h"

int isEuclideanPoint(struct point *pnt) {
    return 1;
}

Manifold *euclideanMFold(int d) {
    return manimalloc(d, &isEuclideanPoint);
}

struct tensor *euclideanTensor(int d) {
    struct term terms[d];
    for (int i = 0; i < d; i++) {
        struct term* euclideanTerm = pairproduct(
                eltalloc(i, d), eltalloc(i, d), 1);
        terms[i] = *euclideanTerm;
    }
    return tensalloc(terms, d);
}

struct tensor *euclideanTensorMap(struct point *pnt) {
    return euclideanTensor(pnt->d);
}

Tensorfield *euclideanMetric(Manifold *mfold) {
    return tensorFieldAlloc(mfold, euclideanTensorMap);
}


