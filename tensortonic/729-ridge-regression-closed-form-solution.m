%{

Ridge regression (L2 regularization) adds a penalty term to the ordinary least squares objective to prevent overfitting. The regularization term shrinks the weights toward zero, which is especially useful when features are correlated or when the number of features is large relative to the number of samples.

Given a feature matrix X, a target vector y, and a regularization parameter lambda, compute the ridge regression weights using the closed-form solution.

Formula
w = (X^T*X + lambda*I)^-1 * X^T * y

Where I is the d x d identity matrix and lambda controls the regularization strength.

Return one float weight for each feature column.

Examples
Input: X = [[1, 0], [0, 1]], y = [3, 5], lam = 1

Output: [1.5, 2.5]

Explanation: Adding the identity matrix doubles the diagonal before solving for the weights.

Input: X = [[1, 1], [1, 2], [1, 3]], y = [3, 5, 7], lam = 0

Output: [1.0, 2.0]

Hint 1
Create an identity matrix with the same width as X.

Hint 2
Apply NumPy matrix multiplication in the same order as the closed-form equation.

Requirements
Compute X^T X and add lambda * I (identity matrix) to get the regularized matrix
Compute the inverse of the regularized matrix
Multiply by X^T y to get the weight vector
Return a list of floats
Constraints
X has at least one row and one column
lambda >= 0
Return a list of floats with length equal to the number of columns in X
Time limit: 300 ms

%}

function w = ridge(X, Y, lam)
	P = X'*X;
	N = size(P);
	w = (P + lam*eye(N))^-1 * X' * Y;
end

ridge([1 0; 0 1], [3 5]', 1)
ridge([1 1; 1 2; 1 3], [3 5 7]', 0)
