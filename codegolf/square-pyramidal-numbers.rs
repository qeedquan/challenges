/*

Task
Your task is simple, generate a sequence that, given index i, the value on that position is the sum of squares from 0 upto i where i >= 0.

Example:
Input: 0
Output: 0           (0^2)

Input: 4
Output: 30          (0^2 + 1^2 + 2^2 + 3^2 + 4^2)

Input: 5
Output: 55          (0^2 + 1^2 + 2^2 + 3^2 + 4^2 + 5^2)
Specification:
You may take no input and output the sequence indefinitely;
You may take input N and output the Nth element of the sequence;
You may take input N and output the first N elements of the sequence.

*/

fn main() {
    assert_eq!(square_pyramidal(0), 0);
    assert_eq!(square_pyramidal(4), 30);
    assert_eq!(square_pyramidal(5), 55);
}

// https://oeis.org/A000330
fn square_pyramidal(n: isize) -> isize {
    n * (n + 1) * (2 * n + 1) / 6
}
