# tensorlib
A tensor operations library. Work in progress.

### Run

Run the main program. Currently, supports creation of elementary unit tensors, their outer product and sum to create higher rank tensors, and evaluation on a collection of vectors.

A sample run:

```

Tensor with 2 terms:
---
	(tensor term)|dim: 3|rank: 2|coeff: +1|elementary tensors: 1 2|
	(tensor term)|dim: 3|rank: 2|coeff: -4|elementary tensors: 0 1|
Input of 2 vectors each of dim 3:
---
	+0.10 +0.30 
	-0.40 -0.20 
	+0.50 +0.20 
Evaluating tensor on input...
Evaluated to -0.40
```

### To Do

* <s>Support antisymmetrization & symmetrization</s>
* Compute determinants
* Support spaces and tensor fields on those spaces
* Reduction of multiple equivalent basis elements
* Grassmann algebra
* Common practical applications

