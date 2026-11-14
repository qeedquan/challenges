/*

It seems that many people would like to have this, so it's now a sequel to this challenge!
https://codegolf.stackexchange.com/questions/167106/recover-the-prime-from-the-prime-power

Definition: a prime power is a natural number that can be expressed in the form pn where p is a prime and n is a natural number.

Task: Given a prime power pn > 1, return the power n.

Testcases:

input output
9     2
16    4
343   3
2687  1
59049 10
Scoring: This is code-golf. Shortest answer in bytes wins.

*/

fn main() {
    let tab = vec![
        0, 0, 1, 1, 2, 1, 3, 1, 3, 2, 3, 1, 5, 1, 3, 3, 4, 1, 5, 1, 5, 3, 3, 1, 7, 2, 3, 3, 5, 1,
        7, 1, 5, 3, 3, 3, 8, 1, 3, 3, 7, 1, 7, 1, 5, 5, 3, 1, 9, 2, 5, 3, 5, 1, 7, 3, 7, 3, 3, 1,
        11, 1, 3, 5, 6, 3, 7, 1, 5, 3, 7, 1, 11, 1, 3, 5, 5, 3, 7, 1, 9, 4, 3, 1, 11, 3, 3, 3, 7,
        1, 11, 3, 5, 3, 3, 3, 11, 1, 5, 5,
    ];

    assert_eq!(recover(9), 2);
    assert_eq!(recover(16), 4);
    assert_eq!(recover(343), 3);
    assert_eq!(recover(2687), 1);
    assert_eq!(recover(59049), 10);

    for i in 0..tab.len() {
        assert_eq!(recover(i), tab[i]);
    }
}

// https://oeis.org/A032741
fn recover(n: usize) -> usize {
    let mut r = 0;
    for i in 1..n {
        if n % i == 0 {
            r += 1;
        }
    }
    r
}
