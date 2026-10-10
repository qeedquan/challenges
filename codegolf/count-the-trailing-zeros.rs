/*

Given two positive integers n and b, such that n>2 and n>b>1, count the trailing zeros when converting n to base b. Your program should be able to handle any value of b within your integer maximum.

The digits of n=18, b=3 are [2,0,0], so the correct output is 2.
The digits of n=107, b=43 are [2,42], so the correct output is 0

This is code-golf, so the shortest code in bytes wins

Test cases
  n   b  out
512   2   9
248   2   3
364 265   0
764   2   2
336 284   0
517 422   0
554  37   0
972   3   5
 12   6   1
 72   2   3
 44   2   2
 51  16   0
 32   2   5
 56   7   1
 60   2   2
  8   3   0
 18   3   2
107  43   0

Credit to Anush for the inspiration

There is a one byte answer in Jelly. Can you find it?

*/

fn main() {
    assert_eq!(trailing_zeros(512, 2), 9);
    assert_eq!(trailing_zeros(248, 2), 3);
    assert_eq!(trailing_zeros(364, 265), 0);
    assert_eq!(trailing_zeros(764, 2), 2);
    assert_eq!(trailing_zeros(336, 284), 0);
    assert_eq!(trailing_zeros(517, 422), 0);
    assert_eq!(trailing_zeros(554, 37), 0);
    assert_eq!(trailing_zeros(972, 3), 5);
    assert_eq!(trailing_zeros(12, 6), 1);
    assert_eq!(trailing_zeros(72, 2), 3);
    assert_eq!(trailing_zeros(44, 2), 2);
    assert_eq!(trailing_zeros(51, 16), 0);
    assert_eq!(trailing_zeros(32, 2), 5);
    assert_eq!(trailing_zeros(56, 7), 1);
    assert_eq!(trailing_zeros(60, 2), 2);
    assert_eq!(trailing_zeros(8, 3), 0);
    assert_eq!(trailing_zeros(18, 3), 2);
    assert_eq!(trailing_zeros(107, 43), 0);
}

fn trailing_zeros(mut n: usize, b: usize) -> usize {
    if b == 0 {
        return 0;
    }
    if n == 0 {
        return 1;
    }

    let mut c = 0;
    while n > 0 {
        if n % b != 0 {
            break;
        }
        c += 1;
        n /= b;
    }
    return c;
}
