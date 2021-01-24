#include <stdlib.h>
#include "stdio.h"
#include "euclidean.h"
#include "curve.h"


// Example code/structs for
// f(x) = x^2 as curve in R^2.
// from x = 0 to x = 1.

struct point *curveFunction(double x) {
    double out[2] = {x, x*x};
    struct point *pnt = pointalloc(out, 2);
    return pnt;
}

void exampleCurveLength() {

    printf("-------------------------\n\n");
    printf("Running example computing curve length in R^2 for f(x) = x^2 from x = 0 to x = 1 ... \n");
    int d = 2;
    Manifold *plane = euclideanMFold(d);
    Curve *curve = curveAlloc(0.0, 1.0, plane, curveFunction);
    Tensorfield *metric = euclideanMetric(plane);

    double length = curveLength(curve, metric);
    printf("-----------------------\n");
    printf("Computed curve length of %.2f in R^2 for f(x) = x^2 from x = 0 to x = 1. \n", length);
    printf("Approximates analytical expression of integral of sqrt(1+4x^2) from 0 to 1 ~ 1.4789\n");

}

