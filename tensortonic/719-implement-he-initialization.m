%{

He (Kaiming) initialization is designed for networks using ReLU activations. Since ReLU zeros out negative values (roughly half the distribution), He initialization uses a larger variance than Xavier to compensate, depending only on the fan-in.

Given a raw weight matrix W with values in [0, 1] and fan_in (number of input units), scale the weights to He uniform initialization.

Algorithm
Compute the He uniform bound:

1. L = sqrt(6 / fin)

2. Map each raw weight from [0, 1] to [-L, L]:
W[i, j] = W[i, j]*2*L - L

Return a matrix of four-decimal floats with the same shape as W.

Examples
Input: W = [[0.5, 0.5]], fan_in = 2

Output: [[0.0, 0.0]]

Explanation: A raw midpoint of 0.5 maps to the center of the symmetric He range.

Input: W = [[0], [1]], fan_in = 2

Output: [[-1.7321], [1.7321]]

Hint 1
Compute the symmetric limit from fan_in only.

Hint 2
Map each raw value from [0, 1] into the interval from negative limit to positive limit.

Requirements
Scale raw uniform [0, 1] weights to He uniform range [-limit, limit]
Use the He uniform formula: limit = sqrt(6 / fan_in)
Return the scaled weight matrix as a list of lists of floats
Round numeric outputs to 4 decimal places.
Constraints
W has at least 1 row and 1 column with values in [0, 1]
fan_in >= 1
Return a list of lists of floats with the same shape as W
Time limit: 300 ms

%}

function R = he(W, fin)
	L = sqrt(6 / fin);
	R = W*2*L - L;
end

he([0.5 0.5], 2)
he([0; 1], 2)
