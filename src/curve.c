#include <math.h>
#include "curve.h"
#include "stdio.h"
#include "inpt.h"

double curveLength(Curve *curve, Tensorfield *metric) {

    // approximate integral by Riemann sum
    int nSteps = 100;
    struct point *pnt;
    struct point *nextPnt;
    struct tensor *tsr;
    double stepSize = (curve->b - curve->a) / nSteps;
    double t = curve->a;
    int d = metric->mfold->d; // dimension
    double curveVelocity[d][2]; // really this is just copied twice (gamma dot, gamma dot)
    struct inpt *ipt;
    double riemannSm = 0.0;

    while (t < curve->b) {

        pnt = curve->mp(t);
        nextPnt = curve->mp(t + stepSize);
        for (int i = 0; i < d; i ++) {
            // hack duplicate to feed to metric
            curveVelocity[i][0] = (nextPnt->x[i] - pnt->x[i]) / stepSize;
            curveVelocity[i][1] = (nextPnt->x[i] - pnt->x[i]) / stepSize;

        }
        tsr = (metric->tensorAtPoint)(pnt);
        ipt = inptalloc((const double *) curveVelocity, 2, d);
        riemannSm += sqrt(evaluate(tsr, ipt)) * stepSize; // sqrt(g(gamma dot, gamma dot)) * stepSize
        t += stepSize;
    }

    return riemannSm;
}

