/*

Description

Inexperienced in the digital arts, the cows tried to build a calculating engine (yes, it's a cowmpouter) using binary numbers (base 2) but instead built one based on base negative 2! They were quite pleased since numbers expressed in base −2 do not have a sign bit.

You know number bases have place values that start at 1 (base to the 0 power) and proceed right-to-left to base^1, base^2, and so on. In base −2, the place values are 1, −2, 4, −8, 16, −32, ... (reading from right to left). Thus, counting from 1 goes like this: 1, 110, 111, 100, 101, 11010, 11011, 11000, 11001, and so on.

Eerily, negative numbers are also represented with 1's and 0's but no sign. Consider counting from −1 downward: 11, 10, 1101, 1100, 1111, and so on.

Please help the cows convert ordinary decimal integers (range -2,000,000,000..2,000,000,000) to their counterpart representation in base −2.
Input

Line 1: A single integer to be converted to base −2
Output

Line 1: A single integer with no leading zeroes that is the input integer converted to base −2. The value 0 is expressed as 0, with exactly one 0.

Sample Input

-13

Sample Output

110111
Hint

Explanation of the sample:

Reading from right-to-left:
1*1 + 1*-2 + 1*4 + 0*-8 +1*16 + 1*-32 = -13

Source

USACO 2006 February Bronze

*/

fn main() {
    assert_eq!(negabinary(-13), 110111);
    assert_eq!(negabinary(-15), 110001);
    assert_eq!(negabinary(0), 0);
    assert_eq!(negabinary(9), 11001);
    assert_eq!(negabinary(15), 10011);
    assert_eq!(negabinary(18), 10110);
}

// https://oeis.org/A039724
fn negabinary(mut n: isize) -> isize {
    let mut p = vec![];
    while n != 0 {
        let mut q = n / -2;
        let mut r = n % -2;
        if r < 0 {
            r += 2;
            q += 1;
        }
        p.push(r);
        n = q;
    }

    let mut x = 0;
    let mut i = p.len();
    while i > 0 {
        x = (x * 10) + p[i - 1];
        i -= 1;
    }
    x
}
