/*

Haskell has this neat(-looking) feature where you can give it three numbers and it can infer an arithmetic sequence from them. For example, [1, 3..27] is equivalent to [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27].

That's cool and all but arithmetic sequences are fairly limiting. Addition, pfft. Multiplication's where it's at. Wouldn't it be cooler if it did geometric sequences like [1, 3..27] returning [1, 3, 9, 27]?

Challenge
Write a program/function that takes three positive integers a, b, and c and outputs [a, b, b × (b ÷ a), b × (b ÷ a)2, ..., x] where x is the greatest integer ≤ c that can be represented as b × (b ÷ a)n where n is a positive integer.

That is, the output should be r, such that:

r0 = a
r1 = b
rn = b × (b ÷ a)n-1
rlast = greatest integer ≤ c that can be represented as b × (b ÷ a)n
         where n is a positive integer

Specifications
Standard I/O rules apply.
Standard loopholes are forbidden.
b will always be divisible by a.
a < b ≤ c
This challenge is not about finding the shortest approach in all languages, rather, it is about finding the shortest approach in each language.
Your code will be scored in bytes, usually in the encoding UTF-8, unless specified otherwise.
Built-in functions (Mathematica might have one :P) that compute this sequence are allowed but including a solution that doesn't rely on a built-in is encouraged.
Explanations, even for "practical" languages, are encouraged.

Test cases
a   b   c     r

1   2   11    [1, 2, 4, 8]
2   6   100   [2, 6, 18, 54]
3   12  57    [3, 12, 48]
4   20  253   [4, 20, 100]
5   25  625   [5, 25, 125, 625]
6   42  42    [6, 42]
In a few better formats:

1 2 11
2 6 100
3 12 57
4 20 253
5 25 625
6 42 42

1, 2, 11
2, 6, 100
3, 12, 57
4, 20, 253
5, 25, 625
6, 42, 42

*/

fn main() {
    assert_eq!(geometric(1, 2, 11), vec![1, 2, 4, 8]);
    assert_eq!(geometric(2, 6, 100), vec![2, 6, 18, 54]);
    assert_eq!(geometric(3, 12, 57), vec![3, 12, 48]);
    assert_eq!(geometric(4, 20, 253), vec![4, 20, 100]);
    assert_eq!(geometric(5, 25, 625), vec![5, 25, 125, 625]);
    assert_eq!(geometric(6, 42, 42), vec![6, 42]);
}

fn geometric(mut a: isize, b: isize, c: isize) -> Vec<isize> {
    let mut r = vec![];
    let m = b / a;
    while (c / a) > 0 {
        r.push(a);
        a *= m;
    }
    r
}
