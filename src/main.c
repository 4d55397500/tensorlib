#include "elt.h"
#include "term.h"
#include "tensor.h"
#include "exampleCurve.c"

int main() {

    struct elt* elt1 = eltalloc(1, 3);
    struct elt* elt2 = eltalloc(2, 3);
    struct term* eltp1 = pairproduct(elt1, elt2, 1);

    struct elt* elt3 = eltalloc(0, 3);
    struct elt* elt4 = eltalloc(1, 3);
    struct term* eltp2 = pairproduct(elt3, elt4, -4);

    struct tensor* t = addterms(eltp1, eltp2);
    printtensor(t);

    const double x[3][2] = {
            {0.7, 0.3},
            {-0.4, -0.2},
            {0.5, 0.2}
    };
    struct inpt* ipt = inptalloc((const double *) x, 2, 3);

    evaluate(t, ipt);

    struct tensor* symt = symmetrize(t);
    printtensor(symt);


    const double x2[3][3] = {
            {1., 1., 0.4},
            {1., .5, 0.1},
            {0.7, 0.4, 0.4}
    };
    struct inpt* ipt2 = inptalloc((const double *) x2, 3, 3);
    determinant(ipt2);


    exampleCurveLength();

    return 0;
}
