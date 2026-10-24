/*

Let us define the degree of symmetry of a natural number as the number of pairs of its decimal digits that are equal and positioned symmetrically with
respect to the center of the number's decimal representation.
If a digit stands exactly in the center, it should also be counted as a pair with itself.
Find the degree of symmetry of the given number n.

https://static.e-olymp.com/content/33/336c5993b57c1430557b158144fe11c7d4f6d250.gif

Input
The only input line contains a single natural number n (n<2*10^9).

Output
Print a single integer: the degree of symmetry of n.

Examples

Input #1
123322

Answer #1
2

*/

fn main() {
    assert_eq!(solve("123322"), 2);
}

fn solve(input: &'static str) -> usize {
    let input = input.as_bytes();
    let length = input.len();

    let mut degree = length & 1;
    for index in 0..length / 2 {
        if input[index] == input[length - index - 1] {
            degree += 1;
        }
    }
    return degree;
}
