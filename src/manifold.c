#include <stdlib.h>
#include "manifold.h"


Manifold *manimalloc(int d, int (*ispoint)(struct point*)) {
    Manifold *mfold = (Manifold*) malloc(sizeof(Manifold));
    mfold->d = d;
    mfold->ispoint = ispoint;
    return mfold;
}