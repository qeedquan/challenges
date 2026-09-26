/*

Your challenge today is to output a given term of a sequence enumerating all of the integers.
The sequence is as follows: If we have a 0-indexed function generating the sequence f(n) and ceil(x) is the ceiling function, then f(0) = 0; abs(f(n)) = ceil(n/2); sign(f(n)) is positive when n and ceil(n/2) are either both even or both odd.

To help understand this sequence, the first few terms are as follows: 0 1 -1 -2 2 3 -3 -4 4 5 -5 -6 6 7 -7...

Your task is to write a program to that takes an integer n and outputs the nth term of the sequence. Input may be 0 or 1-indexed only.

Test cases (0-indexed):

0  =>  0
1  =>  1
2  => -1
3  => -2
4  =>  2
5  =>  3

This is code-golf, fewest bytes wins!

*/

fn main() {
    assert_eq!(f(0), 0);
    assert_eq!(f(1), 1);
    assert_eq!(f(2), -1);
    assert_eq!(f(3), -2);
    assert_eq!(f(4), 2);
    assert_eq!(f(5), 3);
}

// @Halvard Hummel
fn f(x: isize) -> isize {
    ((x + 1) / 2) / (1 - (x & 2))
}
