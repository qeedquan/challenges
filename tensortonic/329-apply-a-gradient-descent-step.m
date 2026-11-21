%{

Apply one gradient-descent update to the Python lists values and gradients:

	values_p = values - learning_rate*gradients;
	loss = sum(gradients .* (values_p - values));
	[values_p, loss];

L_pred is a local prediction, not a measured change in loss. Empty input lists produce an empty updated list and 0.0. Return a two-item tuple: a fresh list of updated Python floats, followed by the predicted change as a Python float.

Examples
Input: values=[2.0,-3.0,10.0], gradients=[-3.0,2.0,1.0], learning_rate=0.1

Output: ([2.3,-3.2,9.9],-1.4)

Explanation: Each value moves opposite its gradient, and the local prediction is -0.1 times the squared gradient norm.

Input: values=[1.0,-2.0], gradients=[0.0,0.0], learning_rate=0.5

Output: ([1.0,-2.0],0.0)

Input: values=[1.5,-4.0], gradients=[2.0,-3.0], learning_rate=0.0

Output: ([1.5,-4.0],0.0)

Hint 1
np.asarray with dtype=np.float64 prepares vectors for elementwise arithmetic.

Hint 2
np.dot reduces the gradient and update vector to a scalar.

Requirements
Use 64-bit floating-point arithmetic; NumPy is available.
Compute the predicted change from the actual updated values.
Leave both input lists unchanged.
Constraints
values and gradients are equal-length Python lists, possibly empty, of finite numbers.
learning_rate is a finite nonnegative number.
Updated values and the predicted change must be finite.

%}

function [values_p, loss] = gradient_descent_step(values, gradients, learning_rate)
	values_p = values - learning_rate*gradients;
	loss = sum(gradients .* (values_p - values));
	[values_p, loss];
end

[values_p, loss] = gradient_descent_step([2 -3 10], [-3 2 1], 0.1)
[values_p, loss] = gradient_descent_step([1 -2], [0 0], 0.5)
[values_p, loss] = gradient_descent_step([1.5 -4], [2 -3], 0)
