#include "manifold.h"
#include "tensorfield.h"

#ifndef TENSORLIB_SPHERE_H
#define TENSORLIB_SPHERE_H


int isSpherePoint(struct point *);
Manifold *makeSphere(int);
struct tensor *sphereMetricMap(struct point *);
Tensorfield *sphereMetric(Manifold *);


#endif //TENSORLIB_SPHERE_H
