
#include "stdio.h"
#include "stdlib.h"
#include "manifold.h"
#include "point.h"
#include "tensorfield.h"
#include "tensor.h"
#include "term.h"
#include "elt.h"
#include "curve.h"




// Example code/structs for
// f(x) = x^2 as curve in R^2.
// from x = 0 to x = 1.

int isPlanePoint(struct point *pnt) {
    return 1;
}

Manifold *makePlane(int d) {
    Manifold *mfold = (Manifold*) malloc(sizeof(Manifold));
    mfold->d = d;
    mfold->ispoint = &isPlanePoint;
    return mfold;
}



// g(e_i, e_j) = delta_ij
struct tensor *euclideanTensor(struct point* pnt) {
    // inefficient to create these object anew for each new point
    // given the metric is constant
    // and add general euclidean metric function to library
    struct elt* elt1 = eltalloc(0, 2);
    struct elt* elt2 = eltalloc(0, 2);
    struct elt* elt3 = eltalloc(1, 2);
    struct elt* elt4 = eltalloc(1, 2);
    struct term *term1 = pairproduct(elt1, elt2, 1);
    struct term *term2 = pairproduct(elt3, elt4, 1);
    struct tensor* eucTensor = addterms(term1, term2);
    return eucTensor;

}

Tensorfield *makeMetric(Manifold *mfold) {
    Tensorfield *metric = (Tensorfield*) malloc(sizeof(Tensorfield));
    metric->mfold = mfold;
    metric->tensorAtPoint = &euclideanTensor;
    return metric;
}


struct point *curveFunction(double x) {
    double out[2] = {x, x*x};
    struct point *pnt = pointalloc(out, 2);
    return pnt;
}

void exampleCurveLength() {

    printf("-------------------------\n\n");
    printf("Running example computing curve length in R^2 for f(x) = x^2 from x = 0 to x = 1 ... \n");

    Manifold *plane = makePlane(2);
    Curve *curve = (Curve*) malloc(sizeof(Curve));
    curve->a = 0.0;
    curve->b = 1.0;
    curve->mfold = plane;
    curve->mp = &curveFunction;

    Tensorfield *euclidean = makeMetric(plane);

    double length = curveLength(curve, euclidean);
    printf("-----------------------\n");
    printf("Computed curve length of %.2f in R^2 for f(x) = x^2 from x = 0 to x = 1. \n", length);
    printf("Approximates analytical expression of integral of sqrt(1+4x^2) from 0 to 1 ~ 1.4789\n");

}

