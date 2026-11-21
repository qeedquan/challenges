%{

Xavier (Glorot) initialization sets initial weights to maintain roughly the same variance of activations and gradients across layers. This prevents the vanishing or exploding gradient problem in networks using sigmoid or tanh activations.

Given a raw weight matrix W with values in [0, 1], fan_in (number of input units), and fan_out (number of output units), scale the weights to Xavier uniform initialization.

Algorithm
Compute the Xavier uniform bound:

1. L = sqrt(6 / (fin + fout))

2. Map each raw weight from [0, 1] to [-L, L]:
   W[i, j] = W[i, j]*2*L - L

Return a matrix of four-decimal floats with the same shape as W.

Examples
Input: W = [[0.5, 0.5], [0.5, 0.5]], fan_in = 2, fan_out = 2

Output: [[0.0, 0.0], [0.0, 0.0]]

Explanation: A raw midpoint of 0.5 maps to the center of the symmetric Xavier range.

Input: W = [[0, 1], [1, 0]], fan_in = 2, fan_out = 2

Output: [[-1.2247, 1.2247], [1.2247, -1.2247]]

Hint 1
Compute the symmetric limit from fan_in plus fan_out.

Hint 2
Map each raw value v with v times two limits minus one limit.

Requirements
Scale raw uniform [0, 1] weights to Xavier uniform range [-limit, limit]
Use the Xavier uniform formula: limit = sqrt(6 / (fan_in + fan_out))
Return the scaled weight matrix as a list of lists of floats
Round numeric outputs to 4 decimal places.
Constraints
W has at least 1 row and 1 column with values in [0, 1]
fan_in >= 1, fan_out >= 1
Return a list of lists of floats with the same shape as W
Time limit: 300 ms

%}

function R = xavier(W, fin, fout)
	L = sqrt(6 / (fin + fout));
	R = W*2*L - L;
end

xavier([0.5 0.5; 0.5 0.5], 2, 2)
xavier([0 1; 1 0], 2, 2)
