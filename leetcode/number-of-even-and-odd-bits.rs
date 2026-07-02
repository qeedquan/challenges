/*

You are given a positive integer n.

Let even denote the number of even indices in the binary representation of n with value 1.

Let odd denote the number of odd indices in the binary representation of n with value 1.

Note that bits are indexed from right to left in the binary representation of a number.

Return the array [even, odd].

Example 1:

Input: n = 50

Output: [1,2]

Explanation:

The binary representation of 50 is 110010.

It contains 1 on indices 1, 4, and 5.

Example 2:

Input: n = 2

Output: [0,1]

Explanation:

The binary representation of 2 is 10.

It contains 1 only on index 1.

Constraints:

1 <= n <= 1000

Hint 1
Maintain two integer variables, even and odd, to count the number of even and odd indices in the binary representation of integer n.

Hint 2
Divide n by 2 while n is positive, and if n modulo 2 is 1, add 1 to its corresponding variable.

*/

fn main() {
    assert_eq!(even_odd_bit(50), (1, 2));
    assert_eq!(even_odd_bit(2), (0, 1));
}

fn even_odd_bit(n: u32) -> (u32, u32) {
    let x = n & 0b0101010101;
    let y = n & 0b1010101010;
    (x.count_ones(), y.count_ones())
}
