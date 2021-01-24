#include "manifold.h"
#include "tensorfield.h"

#ifndef TENSORLIB_EUCLIDEAN_H
#define TENSORLIB_EUCLIDEAN_H

Manifold *euclideanMFold(int);
struct tensor *euclideanTensor(int);
Tensorfield *euclideanMetric(Manifold *);

#endif //TENSORLIB_EUCLIDEAN_H
