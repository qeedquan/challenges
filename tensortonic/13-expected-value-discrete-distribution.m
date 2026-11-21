%{

Compute the expected value of a discrete random variable from its possible values and their probabilities:

E[x] = Sum[i=0, N-1] x[i]*p[i]

Here, N is the number of possible outcomes, x[i] is outcome i, and p[i] is its probability.
The two input lists have the same length, and the probabilities sum to 1.
Return the expected value as a Python float.

Examples
Input: x = [1, 2, 3], p = [0.2, 0.5, 0.3]

Output: 2.1

Explanation: The weighted sum is 1(0.2) + 2(0.5) + 3(0.3) = 2.1.

Input: x = [1, 2, 3, 4], p = [0.25, 0.25, 0.25, 0.25]

Output: 2.5

Hint 1
np.asarray(values, dtype=float) prepares a list for vectorized arithmetic.

Hint 2
np.dot(x, p) computes the weighted sum directly.

Requirements
Convert x and p to NumPy arrays for the computation
Compute the probability-weighted sum of the outcomes
Return a Python float
Constraints
x and p are one-dimensional lists with the same length
1≤N≤10,000
Every probability is non-negative and the probabilities sum to 1
Use NumPy only

%}

x1 = [1 2 3];
p1 = [0.2 0.5 0.3];

x2 = [1 2 3 4];
p2 = [0.25 0.25 0.25 0.25];

dot(x1, p1)
dot(x2, p2)
