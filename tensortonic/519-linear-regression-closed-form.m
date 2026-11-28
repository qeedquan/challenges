%{

Linear regression finds the weight vector that minimizes the sum of squared errors between predictions and targets.
The closed-form solution (the normal equation) computes the optimal weights directly using matrix algebra, without iterative optimization.

Given a feature matrix X and a target vector y, compute the weight vector w using the normal equation.

Formula

w = (X^T*X)^-1 * X^T * y

Where X is the nxd feature matrix (n samples, d features), is the n-dimensional target vector,
and w is the d-dimensional weight vector.

Return the weight vector as a list of floats with one value per feature column.

Examples
Input: X = [[1], [2], [3]], y = [2, 4, 6]

Output: [2.0]

Explanation: The single weight 2 exactly maps each feature value to its target.

Input: X = [[1, 1], [1, 2], [1, 3]], y = [3, 5, 7]

Output: [1.0, 2.0]

Hint 1
Convert X and y to float64 NumPy arrays.

Hint 2
Apply matrix multiplication in the same order as the normal equation.

Requirements
Use numpy to convert X and y to arrays
Compute the transpose X^T
Compute the products X^T*X and X^T*y
Compute the inverse (X^T*X)^-1
Multiply the inverse by X^T*y to get w
Return a list of floats or a numpy array

Constraints
X has at least as many rows as columns (n >= d)
X^T*X is always invertible
Return length must equal d, the number of columns in X
numpy is available as np
Time limit: 300 ms

%}

function w = linear_regression_closed_form(X, Y)
	w = (X'*X)^-1 * X' * Y;
end

linear_regression_closed_form([1; 2; 3], [2 4 6]')
linear_regression_closed_form([1 1; 1 2; 1 3], [3 5 7]')
