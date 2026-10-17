/*

Write a function that takes an integer and returns an array [A, B, C], where A is the number of multiples of 3 (but not 5) below the given integer, B is the number of multiples of 5 (but not 3) below the given integer and C is the number of multiples of 3 and 5 below the given integer.

For example, solution(20) should return [5, 2, 1]

*/

fn main() {
    assert_eq!(solution(20), (5, 2, 1));
    for i in 0..10000 {
        assert_eq!(solution(i), solutionbf(i));
    }
}

fn solutionbf(n: usize) -> (usize, usize, usize) {
    let (mut a, mut b, mut c) = (0, 0, 0);
    for i in 1..n {
        if i % 15 == 0 {
            c += 1;
        } else if i % 3 == 0 {
            a += 1;
        } else if i % 5 == 0 {
            b += 1;
        }
    }
    (a, b, c)
}

fn solution(mut n: usize) -> (usize, usize, usize) {
    if n == 0 {
        return (0, 0, 0);
    }

    n -= 1;
    let c = n / 15;
    let a = (n / 3) - c;
    let b = (n / 5) - c;
    (a, b, c)
}
