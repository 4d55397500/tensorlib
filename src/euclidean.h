#include "manifold.h"
#include "tensorfield.h"

#ifndef TENSORLIB_EUCLIDEAN_H
#define TENSORLIB_EUCLIDEAN_H

int isEuclideanPoint(struct point *);
Manifold *euclideanMFold(int);
struct tensor *euclideanTensor(int);
struct tensor *euclideanTensorMap(struct point *);
Tensorfield *euclideanMetric(Manifold *);

#endif //TENSORLIB_EUCLIDEAN_H
