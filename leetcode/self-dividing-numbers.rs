/*

A self-dividing number is a number that is divisible by every digit it contains.

    For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

A self-dividing number is not allowed to contain the digit zero.

Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right].

Example 1:

Input: left = 1, right = 22
Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]

Example 2:

Input: left = 47, right = 85
Output: [48,55,66,77]

Constraints:

    1 <= left <= right <= 10^4

*/

fn main() {
    assert_eq!(gen(1, 22), vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]);
    assert_eq!(gen(47, 85), vec![48, 55, 66, 77]);
}

fn gen(left: usize, right: usize) -> Vec<usize> {
    let mut r = vec![];
    for i in left..right + 1 {
        if issfd(i) {
            r.push(i);
        }
    }
    return r;
}

fn issfd(n: usize) -> bool {
    let mut m = n;
    while m > 0 {
        let d = m % 10;
        if d == 0 {
            return false;
        }

        if n % d != 0 {
            return false;
        }

        m /= 10;
    }
    return true;
}
