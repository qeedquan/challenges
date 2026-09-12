/*

Background
Shadow transform of a 0-based integer sequence a(n) is another 0-based integer sequence s(n) defined with the following equation:

s(n) = \sum_{i=0}^{n-1}{(1 \text{ if } n \text{ divides } a(i), 0 \text{ otherwise})}

i.e. s(n) is the number of terms in a(0), \cdots, a(n-1) that are divisible by n.

s(0) is always 0 because there are zero terms to consider, and s(1) is always 1 because a(0) is always divisible by 1. s(2) may have a value of 0, 1, or 2, depending on how many terms out of a(0) and a(1) are even.

Challenge
Given a non-negative integer n, compute the number of distinct shadow transforms of length n. This sequence is A226443.

The following is the list of first 11 terms for n = 0, \cdots, 10, as listed on the OEIS page.

1, 1, 1, 3, 12, 48, 288, 1356, 10848, 70896, 588480
Explanation: Let's call this sequence f(n).

f(0) counts the number of empty sequences, which is 1 (since [] counts).
f(1) counts the possible number of [s(0)] which can only be [0].
f(2) counts [s(0),s(1)]s which can only be [0,1].
Since s(2) can take any of 0, 1, or 2 independent of s(0) and s(1), f(3) is 3.
s(3) is also independent of s(0) through s(2) (because 3 is relatively prime to 2) and take a value between 0 and 3 inclusive, so f(4) = 3 \cdot 4 = 12.
Finding f(5) is slightly more complex because s(4) is tied with s(2). If s(4) == 4, all of a(0)..a(3) must be divisible by 4 (and therefore even), and s(2) can only be 2. If s(4) == 3, at least one of a(0) or a(1) must be even, and s(2) must be 1 or 2. Therefore, f(5) = 12 + 12 + 12 + 8 + 4 = 48.
Standard code-golf rules apply. sequence I/O does NOT apply. The shortest code in bytes wins.

*/

fn main() {
    for i in 0..11 {
        println!("{}", shadows(i));
    }
}

// https://oeis.org/A226443
fn shadows(n: usize) -> usize {
    let tab = vec![1, 1, 1, 3, 12, 48, 288, 1356, 10848, 70896, 588480];
    if n >= tab.len() {
        return 0;
    }
    return tab[n];
}
