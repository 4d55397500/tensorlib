#include "sphere.h"
#include "stdlib.h"
#include "math.h"

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


Manifold *sphereMFold(int d) {
    return manimalloc(d, &isSpherePoint);
}


// metric on n-sphere
// need to convert euclidean to spherical coordinates
// on unit n-sphere
// or if can figure out a numerical pullback can
// do this numerically starting with the euclidean metric
// for R^n+1
// in terms of angular coordinates (phi, theta_0, .... theta_n-2)
// g_00 = 1, else g_ij = prod_{k=0}^{i-1} sin^2 theta_k
// pnt presumed given in angular coordinates
// !! note: this phi, theta notation is the opposite of the conventional one
// here phi is the vertical angle (0 to pi), theta the horizontal one (0 to 2pi)
struct tensor *sphereMetricMap(struct point *pnt) {
    struct term terms[pnt->d];
    // ... fill terms ...
    double coeff = 1.;
    for (int i = 0; i < pnt->d; i++) {
        if (i == 0) {
            double snvsq = pow(sin(pnt->x[i]), 2); // sin^2 phi
            coeff *= snvsq;
            struct term* phiTerm = pairproduct(
                    eltalloc(i, pnt->d),
                    eltalloc(i, pnt->d),
                    1);
            terms[0] = *phiTerm;
        } else {
            double snvsq = pow(sin(pnt->x[i]), 2); // sin^2 theta_k
            terms[i] = *pairproduct(
                            eltalloc(i, pnt->d),
                            eltalloc(i, pnt->d),
                            coeff);
            coeff *= snvsq;
        }
    }
    return tensalloc(terms, pnt->d);
}


Tensorfield *sphereMetric(Manifold *mfold) {
    return tensorFieldAlloc(mfold, sphereMetricMap);
}