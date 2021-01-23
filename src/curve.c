#include "curve.h"


double length(Curve *curve, Tensorfield *metric) {
    // approximate integral by Riemann sum
    int nSteps = 10000;
    double stepSize = (curve.b - curve.a) / nSteps;
    double t = curve.a;
    while (t < curve.b) {

        t += stepSize;
    }

    return -1.0
}

