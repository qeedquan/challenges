/*

The task is just the same as Fibonacci Divisibility, however, input values here are greater to prevent you from implementing straightforward calculations using long arithmetics (this allows users in Java or Python to solve the mentioned task easily enough).

You should implement solution which works fast. A second or two is sufficient to run the proper solution (even with not very modern computer).

Hint: you need not long arithmetic for this task.

Input data in the first line will contain the number of test-cases.
Next line will contain exactly this of divisors M for which you should give answers.
Answer should contain indices of members of Fibonacci Sequence, separated by spaces.

Example:

input data:
2
233328 433156

answer:
1620 282
Values will not exceed 2000000.

*/

fn main() {
    let tab = vec![
        1, 3, 4, 6, 5, 12, 8, 6, 12, 15, 10, 12, 7, 24, 20, 12, 9, 12, 18, 30, 8, 30, 24, 12, 25,
        21, 36, 24, 14, 60, 30, 24, 20, 9, 40, 12, 19, 18, 28, 30, 20, 24, 44, 30, 60, 24, 16, 12,
        56, 75, 36, 42, 27, 36, 10, 24, 36, 42, 58, 60, 15, 30, 24, 48, 35, 60, 68, 18, 24, 120,
    ];

    assert_eq!(solve(233328), 1620);
    assert_eq!(solve(433156), 282);

    for i in 0..tab.len() {
        assert_eq!(solve(i + 1), tab[i]);
    }
}

// https://oeis.org/A001177
fn solve(n: usize) -> usize {
    if n < 1 {
        return 0;
    }
    if n == 1 {
        return 1;
    }

    let (mut a, mut b, mut i) = (0, 1, 0);
    loop {
        if i > 0 && a == 0 {
            break;
        }
        (a, b, i) = (b, (a + b) % n, i + 1);
    }
    return i;
}
