#include "constants.h"

#ifndef TENSORLIB_POINT_H
#define TENSORLIB_POINT_H

struct point {
    double x[MAXDIM];
    int d; // dimension
};

struct point* pointalloc(const double *, int);

#endif //TENSORLIB_POINT_H
