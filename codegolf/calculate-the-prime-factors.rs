/*

We had a prime factorization challenge a while ago, but that challenge is nearly six years old and barely meets our current requirements, so I believe it's time for a new one.

Challenge
Write a program or function that takes as input an integer greater than 1 and outputs or returns a list of its prime factors.

Rules
Input and output may be given by any standard method and in any standard format.
Duplicate factors must be included in the output.
The output may be in any order.
The input will not be less than 2 or more than 231 - 1.
Built-ins are allowed, but including a non-builtin solution is encouraged.
Test cases
2 -> 2
3 -> 3
4 -> 2, 2
6 -> 2, 3
8 -> 2, 2, 2
12 -> 2, 2, 3
255 -> 3, 5, 17
256 -> 2, 2, 2, 2, 2, 2, 2, 2
1001 -> 7, 11, 13
223092870 -> 2, 3, 5, 7, 11, 13, 17, 19, 23
2147483646 -> 2, 3, 3, 7, 11, 31, 151, 331
2147483647 -> 2147483647
Scoring
This is code-golf, so the shortest code in bytes wins.

*/

fn main() {
    assert_eq!(factor(2), vec![2]);
    assert_eq!(factor(3), vec![3]);
    assert_eq!(factor(4), vec![2, 2]);
    assert_eq!(factor(6), vec![2, 3]);
    assert_eq!(factor(8), vec![2, 2, 2]);
    assert_eq!(factor(12), vec![2, 2, 3]);
    assert_eq!(factor(255), vec![3, 5, 17]);
    assert_eq!(factor(256), vec![2, 2, 2, 2, 2, 2, 2, 2]);
    assert_eq!(factor(1001), vec![7, 11, 13]);
    assert_eq!(factor(223092870), vec![2, 3, 5, 7, 11, 13, 17, 19, 23]);
    assert_eq!(factor(2147483646), vec![2, 3, 3, 7, 11, 31, 151, 331]);
    assert_eq!(factor(2147483647), vec![2147483647]);
}

fn factor(mut n: usize) -> Vec<usize> {
    if n < 2 {
        return vec![];
    }

    let mut r = vec![];
    let mut p = 2;
    let mut s = 1;
    while n > 1 {
        while n % p == 0 {
            r.push(p);
            n /= p;
        }
        p += s;
        s = 2;
    }
    return r;
}
