#include <stdlib.h>
#include "point.h"


struct point* pointalloc(const double *x, int d) {
    struct point* pnt = (struct point *) malloc(sizeof(struct point));
    pnt->d = d;
    for (int i = 0; i < d; i++) pnt->x[i] = x[i];
    return pnt;
}

