%{

Implement one step of a tanh recurrent neural network:

a[t] = x[t]*Wx + h[t-1]*Wh + b
h[t] = tanh(a[t])

Here, x is a vector in R^d is the current input,
h[t-1] in R^d is the previous hidden state,
Wx in R^(DxH) maps inputs,
Wh in R^(HxH) maps the previous state,
and b in R^H is the bias.
Return h[t] as a one-dimensional NumPy array.

Examples
Input: x_t = [1.0, 0.0], h_prev = [0.0, 0.0], Wx = [[1.0, 0.0], [0.0, 1.0]], Wh = [[0.0, 0.0], [0.0, 0.0]], b = [0.0, 0.0]

Output: [0.761594, 0.0]

Explanation: Only the first input coordinate reaches the pre-activation, so tanh is applied to [1, 0].

Input: x_t = [0.0, 0.0], h_prev = [1.0, -1.0], Wx = [[0.0, 0.0], [0.0, 0.0]], Wh = [[1.0, 0.0], [0.0, 1.0]], b = [0.0, 0.0]

Output: [0.761594, -0.761594]

Hint 1
Compute the pre-activation with x_t @ Wx + h_prev @ Wh + b.

Hint 2
Pass the complete pre-activation array to np.tanh.

Requirements
Compute both affine contributions and add the bias
Apply np.tanh elementwise
Do not modify any input array
Return a one-dimensional NumPy array of length H
Constraints
All arrays contain finite floating-point values
Matrix and vector shapes follow the stated dimensions
Use NumPy only

%}

function h = rnn_step_forward(x_t, h_prev, Wx, Wh, b)
	a = x_t*Wx + h_prev*Wh + b;
	h = tanh(a);
end

rnn_step_forward([1 0], [0 0], [1 0; 0 1], [0 0; 0 0], [0 0])
rnn_step_forward([0 0], [1 -1], [0 0; 0 0], [1 0; 0 1], [0 0])
