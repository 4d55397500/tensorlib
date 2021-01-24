#include "tensor.h"
#include "point.h"
#include "manifold.h"

#ifndef TENSORLIB_TENSORFIELD_H
#define TENSORLIB_TENSORFIELD_H

typedef struct {
    Manifold *mfold; // a tensor field is defined on a manifold
    // a tensor field takes a tensor value at each point on the manifold
    struct tensor *(*tensorAtPoint)(struct point *);
} Tensorfield;

Tensorfield *tensorFieldAlloc(Manifold *, struct tensor *(*)(struct point *));

#endif //TENSORLIB_TENSORFIELD_H
