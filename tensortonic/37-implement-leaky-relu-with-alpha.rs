/*

Implement the Leaky ReLU activation function:

f(x) = x      x >= 0
       a*x    x < 0

Here, α is the slope applied to negative inputs. Return a NumPy array for a scalar, list, or NumPy-array input.

Examples
Input: x = [-2, -1, 0, 1, 2], alpha = 0.1

Output: [-0.2, -0.1, 0.0, 1.0, 2.0]

Explanation: Nonnegative values remain unchanged, while negative values are multiplied by 0.1.

Input: x = [-5, 5], alpha = 0.01

Output: [-0.05, 5.0]

Hint 1
np.asarray(x, dtype=float) preserves the input shape as an array.

Hint 2
np.where(x >= 0, x, alpha * x) applies both branches elementwise.

Requirements
Accept a scalar, list, or NumPy array
Apply the activation without a Python element loop
Support the supplied alpha value
Always return a NumPy array
Constraints
alpha is non-negative
Use NumPy only

*/

fn main() {
    println!("{:?}", solve(&mut [-2.0, -1.0, 0.0, 1.0, 2.0], 0.1));
    println!("{:?}", solve(&mut [-5.0, 5.0], 0.01));
}

fn solve(x: &mut [f64], alpha: f64) -> &[f64] {
    for i in 0..x.len() {
        x[i] = leaky_relu(x[i], alpha);
    }
    x
}

fn leaky_relu(x: f64, a: f64) -> f64 {
    if x >= 0.0 {
        return x;
    }
    return a * x;
}
