%{

Evaluate the exponential and constant-power functions at x, and compute each input-gradient contribution for the supplied upstream_gradient.

Here x is the scalar input, n is exponent, u is the upstream gradient, y denotes a function's output, and g denotes its input-gradient contribution. For a zero exponent, define the power output as 1.0 and its gradient as 0.0, including when x is zero.

	y_exp = exp(x);
	g_exp = upstream_gradient * y_exp;
	y_power = x^exponent;
	g_power = upstream_gradient * exponent * x^(exponent - 1);

Return a tuple of four 64-bit floating-point numbers in this order: exponential output, exponential gradient, power output, power gradient.

Examples
Input: x = 2, exponent = 0, upstream_gradient = 3

Output: (7.389056, 22.167168, 1.0, 0.0)

Explanation: The zero power is constant, so its gradient contribution is zero.

Input: x = 2, exponent = -2, upstream_gradient = -0.5

Output: (7.389056, -3.694528, 0.25, 0.125)

Input: x = -2, exponent = 3, upstream_gradient = 2

Output: (0.135335, 0.270671, -8.0, 24.0)

Hint 1
np.exp evaluates the exponential for a scalar.

Hint 2
np.power supports fractional exponents for positive bases.

Hint 3
Handle exponent zero before evaluating a negative power of the base.

Requirements
Use 64-bit floating-point arithmetic; NumPy is available.
Compute both gradient contributions manually for the supplied upstream gradient.
Constraints
x, exponent, and upstream_gradient are finite real numbers.
A negative x has an integer-valued exponent.
When x is zero, exponent is zero or at least one.
Inputs keep all four results finite and real in 64-bit floating point.

%}

function r = exp_power_backward(x, exponent, upstream_gradient)
	y_exp = exp(x);
	g_exp = upstream_gradient * y_exp;
	y_power = x^exponent;
	g_power = upstream_gradient * exponent * x^(exponent - 1);
	r = [y_exp, g_exp, y_power, g_power];
end

exp_power_backward(2, 0, 3)
exp_power_backward(2, -2, -0.5)
exp_power_backward(-2, 3, 2)
