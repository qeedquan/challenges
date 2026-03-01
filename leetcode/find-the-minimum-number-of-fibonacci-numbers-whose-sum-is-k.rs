/*

Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.

The Fibonacci numbers are defined as:

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 for n > 2.
It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.

Example 1:

Input: k = 7
Output: 2
Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ...
For k = 7 we can use 2 + 5 = 7.

Example 2:

Input: k = 10
Output: 2
Explanation: For k = 10 we can use 2 + 8 = 10.

Example 3:

Input: k = 19
Output: 3
Explanation: For k = 19 we can use 1 + 5 + 13 = 19.

Constraints:

1 <= k <= 10^9

Hint 1
Generate all Fibonacci numbers up to the limit (they are few).

Hint 2
Use greedy solution, taking at every time the greatest Fibonacci number which is smaller than or equal to the current number.
Subtract this Fibonacci number from the current number and repeat again the process.

*/

fn main() {
    let tab = vec![
        0, 1, 1, 1, 2, 1, 2, 2, 1, 2, 2, 2, 3, 1, 2, 2, 2, 3, 2, 3, 3, 1, 2, 2, 2, 3, 2, 3, 3, 2,
        3, 3, 3, 4, 1, 2, 2, 2, 3, 2, 3, 3, 2, 3, 3, 3, 4, 2, 3, 3, 3, 4, 3, 4, 4, 1, 2, 2, 2, 3,
        2, 3, 3, 2, 3, 3, 3, 4, 2, 3, 3, 3, 4, 3, 4, 4, 2, 3, 3, 3, 4, 3, 4, 4, 3, 4, 4, 4, 5, 1,
        2, 2, 2, 3, 2, 3, 3, 2, 3, 3, 3, 4, 2, 3, 3,
    ];

    for i in 0..tab.len() {
        assert_eq!(minfib(i as isize), tab[i]);
    }

    assert_eq!(minfib(7), 2);
    assert_eq!(minfib(10), 2);
    assert_eq!(minfib(19), 3);
}

// https://oeis.org/A007895
fn minfib(mut n: isize) -> isize {
    if n < 0 {
        return 0;
    }

    let (mut r, mut a, mut b) = (0, 1, 1);
    while b <= n {
        (b, a) = (a + b, b);
    }
    
    while n != 0 {
        if a <= n {
            n -= a;
            r += 1;
        }
        (a, b) = (b - a, a);
    }
    return r;
}
