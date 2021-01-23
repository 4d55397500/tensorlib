#include "point.h"
#include "manifold.h"
#include "tensorfield.h"

#ifndef TENSORLIB_CURVE_H
#define TENSORLIB_CURVE_H

typedef struct {
    // a map from an interval
    // to a point (on a manifold)
    double a;
    double b;
    Manifold *mfold;
    struct point* (*mp)(double);
} Curve;

// a curve has a length corresponding
// to a given metric on the manifold
double length(Curve *curve, Tensorfield *metric);

#endif //TENSORLIB_CURVE_H
