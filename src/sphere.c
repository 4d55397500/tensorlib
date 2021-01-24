#include "sphere.h"
#include "stdlib.h"


int isSpherePoint(struct point *pnt) {
    double tol = 1e-3;
    double sm = 0.0;
    for (int i = 0; i < pnt->d; i++) {
        sm += pnt->x[i] * pnt->x[i];
    }
    if (sm >= 1.0 - tol && sm <= 1.0 + tol) {
        return 1;
    }
    return 0;
}

Manifold *makeSphere(int d) {
    return manimalloc(d, &isSpherePoint);
}
