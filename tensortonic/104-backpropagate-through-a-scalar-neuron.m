%{

Evaluate a tanh neuron and manually compute the loss gradients for its inputs, weights, and bias from the supplied upstream_gradient.

	a = inputs*weights + bias;
	y = tanh(a);
	sigma = upstream_gradient * (1 - y^2);
	lossx = sigma * weights;
	lossw = sigma * inputs;
	lossb = sigma;


Here n is the vector length, x is inputs, w is weights, i indexes their entries, b is bias, a is the preactivation, and y is the neuron output. L is the loss, g is its supplied gradient with respect to y, and delta is its gradient with respect to a.

Return a tuple of four PyTorch tensors: the scalar output, input-gradient vector, weight-gradient vector, and scalar bias gradient. Vectors have the same shape as inputs; all four tensors preserve the common input dtype and device. Empty vectors still produce an output and bias gradient.

Examples
Input: inputs = [2, 0], weights = [-3, 1], bias = 6.881373587, upstream_gradient = 1

Output: (0.707107, [-1.5, 0.5], [1.0, 0.0], 0.5)

Explanation: The preactivation gradient is approximately 0.5, so the zero input gives a zero weight gradient.

Input: inputs = [-1, 2, 0.5], weights = [0.25, -0.75, 1.5], bias = -0.2, upstream_gradient = -2

Output: (-0.833655, [-0.15251, 0.45753, -0.91506], [0.61004, -1.22008, -0.30502], -0.61004)

Input: inputs = [], weights = [], bias = 0, upstream_gradient = 3

Output: (0.0, [], [], 3.0)

Hint 1
torch.sum reduces an empty vector to a scalar zero.

Hint 2
Tensor.square can reuse the saved tanh output for its local derivative.

Hint 3
A scalar tensor broadcasts across a vector without changing its shape.

Requirements
Use PyTorch and compute gradients manually, without automatic differentiation.
Preserve the supplied float16, float32, or float64 dtype; examples use float64.
Constraints
inputs and weights are finite one-dimensional tensors of equal length, which may be zero.
bias and upstream_gradient are finite zero-dimensional tensors.
All four tensors share one floating-point dtype and device; vectors may be noncontiguous.

%}

function [y, lossx, lossw, lossb] = neuron_backward(inputs, weights, bias, upstream_gradient)
	a = inputs*weights + bias;
	y = tanh(a);
	sigma = upstream_gradient * (1 - y^2);
	lossx = sigma * weights;
	lossw = sigma * inputs;
	lossb = sigma;
	if size(lossb) == 0
		lossb = upstream_gradient;
	end
end

[y, lossx, lossw, lossb] = neuron_backward([2 0], [-3 1]', 6.881373587, 1)
[y, lossx, lossw, lossb] = neuron_backward([-1 2 0.5], [0.25 -0.75 1.5]', -0.2, -2)
[y, lossx, lossw, lossb] = neuron_backward([], []', 0, 3)
