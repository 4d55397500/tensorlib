# tensorlib
A tensor and differential geometry library. Work in progress.


### Background and Scope

Library for tensors (multilinear maps, not arbitrary arrays as used for say Tensorflow) and numerical differential geometry applications.
Applications (tbd) in computational geometry/computer graphics, cryptography, machine learning, physical simulation. 

### Docs

These will be written eventually with [Hawkmoth](https://hawkmoth.readthedocs.io/en/latest/).

### Design

Structs defined

* `inpt`: a collection of input vectors 
* `elt`: an elementary 1d tensor `e_i`
* `term`: a higher rank tensor element, `c * e_i e_j e_k...`
* `tensor`: an arbitrary higher rank tensor, a sum of terms
* `point`: an array of double of fixed length
* `Manifold`: a function returning if a given point is on the manifold
* `Tensorfield`: a function from a point on the manifold to a tensor
* `Curve`: a function from an interval of doubles to a point on a manifold

Currently supports a collection of tensor operations, as well as computing a curve length directly from the metric given a Riemannian manifold.

### Example Uses

More applications forthcoming. The following are run in [main.c](https://github.com/redwrasse/tensorlib/blob/master/src/main.c) 
with examples written in [examples.c](https://github.com/redwrasse/tensorlib/blob/master/src/examples.c).


Take the outer product of two elementary tensors `e_1 e_2`, forming a rank 2 tensor.

```c
struct elt* elt1 = eltalloc(1, 3);
struct elt* elt2 = eltalloc(2, 3);
struct term* eltp1 = pairproduct(elt1, elt2, 1);

```

Create a more complex rank 2 tensor `t = e_1 e_2  - 4 e_0 e_1`

```c
struct elt* elt3 = eltalloc(0, 3);  
struct elt* elt4 = eltalloc(1, 3);
struct term* eltp2 = pairproduct(elt3, elt4, -4);
struct tensor* t = addterms(eltp1, eltp2);

```

Evaluate the tensor `t` on vectors `x`.

```c
const double x[3][2] = {
            {0.7, 0.3},
            {-0.4, -0.2},
            {0.5, 0.2}
};
struct inpt* ipt = inptalloc((const double *) x, 2, 3);
evaluate(t, ipt);

```

Symmetrize the tensor `t`.

```c
struct tensor* symt = symmetrize(t);

```

Calculate the determinant, implemented as antisymmetric product of elementary tensors, on vector `x2`.

```c
struct inpt* ipt2 = inptalloc((const double *) x2, 3, 3);
determinant(ipt2);

```

Build the n-dim. plane as a `Manifold`, with Euclidean metric as a `Tensorfield`. Define a `Curve` as f(x) = x^2, and estimate its length by a Riemann sum.

```c
int d = 2;
Manifold *plane = euclideanMFold(d);
Curve *curve = curveAlloc(0.0, 1.0, plane, curveFunction);
Tensorfield *metric = euclideanMetric(plane);
double length = curveLength(curve, metric);

...

(printout)
Computed curve length of 1.48 in R^2 for f(x) = x^2 from x = 0 to x = 1. 
Approximates analytical expression of integral of sqrt(1+4x^2) from 0 to 1 ~ 1.4789

```


Build an n-sphere and corresponding metric, and estimate the length along a curve given in spherical coordinates. This simple
example is a half circle around the equator.

```c

//  curve on 2-sphere from phi = 0 to phi = pi
// w/ theta set to pi (aka half circle around equator)
struct point *simpleSpherePath(double x) {
    double out[2] = {3.1415/2., x};
    struct point *pnt = pointalloc(out, 2);
    return pnt;
}

int d = 2;
Manifold *sphere = sphereMFold(d);
Curve *curve = curveAlloc(0.0, 3.14, sphere, simpleSpherePath);
Tensorfield *metric = sphereMetric(sphere);
double length = curveLength(curve, metric);

...

(printout)
Computed curve length of 3.14 on 2-sphere from theta = 0 to theta = pi 
Approximates expected length of a half-circle around the equator. 

```

### To Do

* <s>Support antisymmetrization & symmetrization</s>
* <s>Compute determinants</s>
* <s>Support spaces and tensor fields on those spaces</s>
* Reduction of multiple equivalent basis elements
* Grassmann algebra
* Common practical applications

### References

* [Discrete Differential Geometry](https://www.cs.cmu.edu/~kmcrane/Projects/DGPDEC/paper.pdf)
* [Notes](https://www.redwrasse.io/notes/tensoralgorithms)
