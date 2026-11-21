/*

Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: left = 5, right = 7
Output: 4

Example 2:
Input: left = 0, right = 0

Output: 0

Example 3:

Input: left = 1, right = 2147483647
Output: 0


Constraints:

0 <= left <= right <= 2^31 - 1

*/

#![allow(non_snake_case)]

fn main() {
    assert_eq!(range_bitwise_and(5, 7), 4);
    assert_eq!(range_bitwise_and(0, 0), 0);
    assert_eq!(range_bitwise_and(1, 2147483647), 0);

    let N = 2000;
    for m in 0usize..N {
        for n in 0..N {
            assert_eq!(range_bitwise_and(m, n), range_bitwise_and_bf(m, n));
        }
    }
}

/*

The solution is to check how many left bits are same for m and n based on two observations:

1. When a number adds one, some of the right bits changes from 0->1 or 1->0
2. If a bit is 0, then AND will cause this bit to 0 eventually

*/

fn range_bitwise_and(m: usize, n: usize) -> usize {
    if m > n {
        return 0;
    }

    let mut mask = usize::MAX;
    while mask != 0 {
        if (m & mask) == (n & mask) {
            break;
        }
        mask <<= 1;
    }
    m & mask
}

fn range_bitwise_and_bf(m: usize, n: usize) -> usize {
    if m > n {
        return 0;
    }

    let mut r = usize::MAX;
    for i in m..=n {
        r &= i;
    }
    r
}
