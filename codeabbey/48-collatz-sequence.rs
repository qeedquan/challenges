/*

This is one of the most mysterious math problems of the last century - both because its statement is extremely simple - and because the proof is still unknown. However it offers good programming exercise for beginners.

Suppose we select some initial number X and then build the sequence of values by the following rules:

if X is even (i.e. X modulo 2 = 0) then
    Xnext = X / 2
else
    Xnext = 3 * X + 1
I.e. if X is odd, sequence grows - and if it is even, sequence decreases. For example, with X = 15 we have sequence:

15 46 23 70 35 106 53 160 80 40 20 10 5 16 8 4 2 1
After the sequence reaches 1 it enters the loop 1 4 2 1 4 2 1....

The intrigue is in the fact that any starting number X gives the sequence which sooner or later reaches 1 - however though this Collatz Conjecture was expressed in 1937, up to now no one could find a proof that it is really so for any X or could not find a counterexample (i.e. number for which sequence did not end with 1 - either entering some bigger loop or growing infinitely).

Your task is for given numbers to calculate how many steps are necessary to come to 1.

Input data contains number of test-cases in the first line.
Second line contains the test-cases - i.e. the values for which calculations should be performed.
Answer should contain the same amount of results, each of them being the count of steps for getting Collatz Sequence to 1.

For example:

input data:
3
2 15 97

answer:
1 17 118

*/

fn main() {
    let tab = vec![
        0, 1, 7, 2, 5, 8, 16, 3, 19, 6, 14, 9, 9, 17, 17, 4, 12, 20, 20, 7, 7, 15, 15, 10, 23, 10,
        111, 18, 18, 18, 106, 5, 26, 13, 13, 21, 21, 21, 34, 8, 109, 8, 29, 16, 16, 16, 104, 11,
        24, 24, 24, 11, 11, 112, 112, 19, 32, 19, 32, 19, 19, 107, 107, 6, 27, 27, 27, 14, 14, 14,
        102, 22,
    ];

    for i in 0..tab.len() {
        assert_eq!(collatz(i + 1), tab[i]);
    }
    assert_eq!(collatz(2), 1);
    assert_eq!(collatz(15), 17);
    assert_eq!(collatz(97), 118);
}

// https://oeis.org/A006577
fn collatz(mut n: usize) -> usize {
    if n < 1 {
        return 0;
    }

    let mut c = 0;
    while n > 1 {
        if (n % 2) != 0 {
            n = (3 * n) + 1;
        } else {
            n = n / 2;
        }
        c += 1;
    }
    return c;
}
