%{

Matrix factorization is the backbone of modern recommender systems (popularized by the Netflix Prize). It approximates the user-item rating matrix as a product of two low-rank matrices: user factors U and item factors V. Each user and item is represented by a latent vector, and the predicted rating is their dot product.

Given a user latent vector U, an item latent vector V, a known rating r, a learning rate lr, and a regularization strength reg, perform one step of stochastic gradient descent to update both vectors.

Algorithm
1. Compute the prediction error:
e = r U*V

2. Update both vectors simultaneously using the old values:
U_new = U + lr*(e*V - reg*U)
V_new = V + lr*(e*U - reg*V)

Both U and V must be updated using their original (pre-update) values.

Return [U_new, V_new], with both vectors rounded to four decimals.

Examples
Input: U = [1, 0], V = [0, 1], r = 5, lr = 0.1, reg = 0

Output: [[1.0, 0.5], [0.5, 1.0]]

Explanation: The zero dot product gives error 5, and both vectors are updated from their original values.

Input: U = [0.5, 0.3], V = [0.4, 0.6], r = 4, lr = 0.01, reg = 0.02

Output: [[0.5144, 0.3217], [0.418, 0.6107]]

Hint 1
Compute the rating error from the original vectors before either update.

Hint 2
Build both new vectors from the original U and V, then round each coordinate.

Requirements
Compute the prediction error as r minus the dot product of U and V
Update U and V simultaneously using original (pre-update) values
Apply L2 regularization with strength reg to prevent overfitting
Return [U_new, V_new] where each item is a list of floats
Round numeric outputs to 4 decimal places.
Constraints
U and V have the same length (latent dimension k >= 1)
lr > 0, reg >= 0
r is a number
Return a two-item list containing two lists of floats
Time limit: 300 ms

%}

function R = matrix_factorization_sgd_step(U, V, r, lr, reg)
	e = r - U*V';
	U_new = U + lr*(e*V - reg*U);
	V_new = V + lr*(e*U - reg*V);
	R = [U_new, V_new];
end

matrix_factorization_sgd_step([1 0], [0 1], 5, 0.1, 0)
matrix_factorization_sgd_step([0.5 0.3], [0.4 0.6], 4, 0.01, 0.02)
