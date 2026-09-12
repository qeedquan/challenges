/*

For the given value of n, compute the sum

S = 1/(1*2) + 1/(2*3) + ... + 1/(n*(n+1))

Input
One positive integer n (n≤1000).

Output
Print the sum with 6 decimal places.

Examples

Input #1
5

Answer #1
0.833333

Input #2
12

Answer #2
0.923077

*/

fn main() {
    for i in 0..1000 {
        assert_eq!((solve(i) - solvebf(i)).abs() < 1e-12, true);
    }

    println!("{:.6}", solve(5));
    println!("{:.6}", solve(12));
}

// https://math.stackexchange.com/questions/1027110/infinite-series-sum-1-nn1
fn solve(n: usize) -> f64 {
    1.0 - (1.0 / (n + 1) as f64)
}

fn solvebf(n: usize) -> f64 {
    let mut r = 0.0;
    for i in 1..=n {
        r += 1.0 / (i * (i + 1)) as f64;
    }
    r
}
