#include <stdlib.h>
#include "stdio.h"
#include "euclidean.h"
#include "curve.h"
#include "sphere.h"


// Example code/structs for
// f(x) = x^2 as curve in R^2.
// from x = 0 to x = 1.

struct point *quadraticFunc(double x) {
    double out[2] = {x, x*x};
    struct point *pnt = pointalloc(out, 2);
    return pnt;
}

void curveInPlane() {

    printf("-------------------------\n\n");
    printf("Running example computing curve length in R^2 for f(x) = x^2 from x = 0 to x = 1 ... \n");
    int d = 2;
    Manifold *plane = euclideanMFold(d);
    Curve *curve = curveAlloc(0.0, 1.0, plane, quadraticFunc);
    Tensorfield *metric = euclideanMetric(plane);

    double length = curveLength(curve, metric);
    printf("-----------------------\n");
    printf("Computed curve length of %.2f in R^2 for f(x) = x^2 from x = 0 to x = 1. \n", length);
    printf("Approximates analytical expression of integral of sqrt(1+4x^2) from 0 to 1 ~ 1.4789\n");

}


//  curve on 2-sphere from phi = 0 to phi = pi
// w/ theta set to pi (aka half circle around equator)
struct point *simpleSpherePath(double x) {
    double out[2] = {3.1415/2., x};
    struct point *pnt = pointalloc(out, 2);
    return pnt;
}


void curveOnSphere() {

    printf("-------------------------\n\n");
    printf("Running example computing curve length on 2-sphere from theta = 0 to theta = pi \n");
    int d = 2;
    Manifold *sphere = sphereMFold(d);
    Curve *curve = curveAlloc(0.0, 3.14, sphere, simpleSpherePath);
    Tensorfield *metric = sphereMetric(sphere);

    double length = curveLength(curve, metric);
    printf("-----------------------\n");
    printf("Computed curve length of %.2f on 2-sphere from theta = 0 to theta = pi \n", length);
    printf("Approximates expected length of a half-circle around the equator. \n");

}