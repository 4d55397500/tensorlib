# tensorlib
A tensor operations library. Work in progress.

### Background and Scope

This is intended to be a library for operations with tensors. Not 'tensors' as multi-dimensional arrays restricted to neural network libraries, but multi-linear maps, tensor fields,
metrics, symplectic forms, all residing on manifolds, with common and (yes, potentially) practical applications to computational geometry, cryptography, machine learning, physical simulation etc.

### Docs

Proper docs to be written. As mentioned in an issue will try to use [Hawkmoth](https://hawkmoth.readthedocs.io/en/latest/).

### Design

Structs defined

* elt: an elementary 1d tensor `e_i`
* term: a higher rank tensor element, `c * e_i e_j e_k...`
* tensor: an arbitrary higher rank tensor, a sum of terms
* point: an array of double of fixed length
* manifold: a function returning if a given point is on the manifold
* tensor field: a function from a point on the manifold to a tensor

Run the main program. Currently, supports creation of elementary unit tensors, their outer product and sum to create higher rank tensors, evaluation on a collection of vectors, symmetrization and antisymmetrization, 
and determinant calculation from the fully antisymmetric unit tensor.

A sample run:

```
Tensor with 2 terms:
---
	(tensor term)|dim: 3|rank: 2|coeff: +1.00|elementary tensors: 1 2|
	(tensor term)|dim: 3|rank: 2|coeff: -4.00|elementary tensors: 0 1|
Input of 2 vectors each of dim 3:
---
	+0.70 +0.30 
	-0.40 -0.20 
	+0.50 +0.20 
Evaluating tensor on input...
Evaluated to 0.48
Symmetrizing tensor...
Tensor with 4 terms:
---
	(tensor term)|dim: 3|rank: 2|coeff: +0.50|elementary tensors: 1 2|
	(tensor term)|dim: 3|rank: 2|coeff: +0.50|elementary tensors: 2 1|
	(tensor term)|dim: 3|rank: 2|coeff: -2.00|elementary tensors: 0 1|
	(tensor term)|dim: 3|rank: 2|coeff: -2.00|elementary tensors: 1 0|
Computing determinant by passing the following input to antisymmetric unit tensor...
Tensor with 6 terms:
---
	(tensor term)|dim: 3|rank: 3|coeff: +1.00|elementary tensors: 0 1 2|
	(tensor term)|dim: 3|rank: 3|coeff: -1.00|elementary tensors: 0 2 1|
	(tensor term)|dim: 3|rank: 3|coeff: +1.00|elementary tensors: 1 0 2|
	(tensor term)|dim: 3|rank: 3|coeff: -1.00|elementary tensors: 1 2 0|
	(tensor term)|dim: 3|rank: 3|coeff: +1.00|elementary tensors: 2 0 1|
	(tensor term)|dim: 3|rank: 3|coeff: -1.00|elementary tensors: 2 1 0|
Input of 3 vectors each of dim 3:
---
	+1.00 +1.00 +0.40 
	+1.00 +0.50 +0.10 
	+0.70 +0.40 +0.40 
Evaluating tensor on input...
Evaluated to 0.33
Computed a determinant of 0.33
```

### To Do

* <s>Support antisymmetrization & symmetrization</s>
* <s>Compute determinants</s>
* Support spaces and tensor fields on those spaces
* Reduction of multiple equivalent basis elements
* Grassmann algebra
* Common practical applications

