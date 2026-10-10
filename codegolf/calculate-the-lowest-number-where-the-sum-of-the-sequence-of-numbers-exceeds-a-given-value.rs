/*

Given you have an infinite sequence of numbers defined as follows:

1: 1 = 1
2: 1 + 2 = 3
3: 1 + 3 = 4
4: 1 + 2 + 4 = 7
5: 1 + 5 = 6
6: 1 + 2 + 3 + 6 = 12
7: 1 + 7 = 8
...
The sequence is the sum of the divisors of n, including 1 and n.

Given a positive integer x as input, calculate the lowest number n which will produce a result greater than x.

Test cases

f(100) = 48, ∑ = 124
f(25000) = 7200, ∑ = 25389
f(5000000) = 1164240, ∑ = 5088960
Expected Output

Your program should return both n and the sum of its divisors, like so:

$ ./challenge 100
48,124
Rules

This is code-golf so the shortest code in bytes, in each language wins.

*/

fn main() {
    assert_eq!(solve(100), (48, 124));
    assert_eq!(solve(25000), (7200, 25389));
    assert_eq!(solve(5000000), (1164240, 5088960));
}

fn solve(x: usize) -> (usize, usize) {
    for n in 1..=x {
        let s = divisor_sum(n);
        if s > x {
            return (n, s);
        }
    }
    panic!("unreachable");
}

// https://oeis.org/A000203
fn divisor_sum(n: usize) -> usize {
    if n == 0 {
        return 0;
    }
    if n == 1 {
        return 1;
    }

    let mut r = n;
    for i in 1..=n.isqrt() {
        if n % i == 0 {
            r += i;
            let m = n / i;
            if m != i && m != n {
                r += m;
            }
        }
    }
    return r;
}
