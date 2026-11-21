%{

Turn standard Gaussian noise into samples from a diagonal Gaussian with a given mean and log variance, using the reparameterization trick.

z = mean + exp(0.5 * log_variance) * noise

Here mean holds the means mu, log_variance holds the natural logarithm log(sigma^2)
of each coordinate's variance, and noise holds the standard Gaussian values ϵ.
The factor exp(1/2 * log(σ^2)) is the standard deviation σ, and ⊙ is elementwise multiplication.
The operation is purely elementwise, and the arrays follow NumPy broadcasting rules, so a single mean of shape (D,)
can be combined with a batch of noise of shape (N, D) to give N samples at once.

Return a NumPy array of dtype float64 whose shape is the broadcast shape of mean, log_variance and noise.

Examples
Input: mean = [0.0,1.0,-2.0], log_variance = [0.0,1.386294,-1.386294], noise = [1.0,-0.5,2.0]

Output: [1.0,0.0,-1.0]

Explanation: The three log variances are log 1, log 4 and log 0.25 to six decimals, so the standard deviations are 1, 2 and 0.5. The noise values 1, -0.5 and 2 then move the means 0, 1 and -2 to 1, 0 and -1.

Input: mean = [1.0,-1.0], log_variance = [-0.6931,0.6931], noise = [[0.0,0.0],[1.0,1.0],[-2.0,0.5]]

Output: [[1.0,-1.0],[1.707123,0.41418],[-0.414247,-0.29291]]

Input: mean = [[0.5,0.25]], log_variance = [[-20.0,-20.0]], noise = [[3.0,-3.0]]

Output: [[0.500136,0.249864]]

Hint 1
np.exp(0.5 * log_variance) turns a log variance into a standard deviation.

Hint 2
A (D,) array broadcasts against an (N, D) array without reshaping.

Hint 3
Avoid += on an input array so the inputs stay unchanged.

Requirements
Use NumPy array operations.
Leave the inputs unchanged.
Constraints
mean and log_variance are float64 NumPy arrays of the same shape, with at least one dimension.
noise is a float64 NumPy array whose shape broadcasts with the shape of mean.
log_variance values lie in [-20, 5], so every standard deviation is positive and finite.
All values are finite.

%}

function reparameterized_sample(mean, log_variance, noise)
	mean + exp(0.5 * log_variance).*noise
end

reparameterized_sample([0 1 -2], [0.0 1.386294 -1.386294], [1.0 -0.5 2.0])
reparameterized_sample([1 -1], [-0.6931 0.6931], [0.0 0.0; 1.0 1.0; -2.0,0.5])
reparameterized_sample([0.5 0.25], [-20 -20], [3 -3])
