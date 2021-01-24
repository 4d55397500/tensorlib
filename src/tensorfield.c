#include <stdlib.h>
#include "tensorfield.h"
#include "stdlib.h"


Tensorfield *tensorFieldAlloc(Manifold *mfold,
        struct tensor *(*tensorAtPoint)(struct point *)) {
    Tensorfield *tfield = (Tensorfield *)malloc(sizeof(Tensorfield));
    tfield->mfold = mfold;
    tfield->tensorAtPoint = tensorAtPoint;
    return tfield;
}