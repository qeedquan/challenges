%{

Compute the mean squared error between predicted and target values:

MSE = 1/N * Sum[i=1, N] (yh[i] - y[i])

Here, N is the number of values, yh[i] is prediction i, and y[i] is its target.
Return the result as a python float.

Examples
Input: y_pred = [1.1, 2.1, 2.9, 4.2, 4.8], y_true = [1, 2, 3, 4, 5]

Output: 0.022

Explanation: The five squared errors sum to 0.11, which gives a mean of 0.022.

Input: y_pred = [1, 2, 3, 4], y_true = [1, 2, 3, 4]

Output: 0

Input: y_pred = [10.5, 19.5, 30.2], y_true = [10, 20, 30]

Output: 0.18

Hint 1
Convert both inputs with np.asarray(..., dtype=float).

Hint 2
Use np.mean((predictions - targets) ** 2) for the reduction.

Requirements
Compute the elementwise prediction errors
Square every error before averaging
Return a Python float
Constraints
y_pred and y_true are nonempty lists of equal length
Values may be integers or floating-point numbers
Use NumPy only

%}

function mean_squared_error(y_pred, y_true)
	sum((y_pred - y_true).^2) / length(y_pred)
end

mean_squared_error([1.1 2.1 2.9 4.2 4.8], [1 2 3 4 5])
mean_squared_error([1 2 3 4], [1 2 3 4])
mean_squared_error([10.5 19.5 30.2], [10 20 30])
