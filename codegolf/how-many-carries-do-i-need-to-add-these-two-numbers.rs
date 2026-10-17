/*

Task
Given two positive integers, output the number of carries needed to add them together in long addition in base 10.

Examples
¹¹¹   <-- carries
 999
+  1
----
1000
Three carries are needed.

 ¹
 348
+ 91
----
 439
One carry is needed.

Testcases
999,   1 -> 3
398,  91 -> 1
348,  51 -> 0
348,  52 -> 2
  5,  15 -> 1
999, 999 -> 3
505, 505 -> 2

Scoring
This is code-golf. Shortest answer in bytes wins. Standard loopholes apply.

*/

fn main() {
    assert_eq!(carries(999, 1), 3);
    assert_eq!(carries(348, 91), 1);
    assert_eq!(carries(398, 91), 1);
    assert_eq!(carries(348, 51), 0);
    assert_eq!(carries(348, 52), 2);
    assert_eq!(carries(5, 15), 1);
    assert_eq!(carries(999, 999), 3);
    assert_eq!(carries(505, 505), 2);
    assert_eq!(carries(123, 456), 0);
    assert_eq!(carries(555, 555), 3);
    assert_eq!(carries(123, 594), 1);
    assert_eq!(carries(543, 3456), 0);
    assert_eq!(carries(1927, 6426), 2);
    assert_eq!(carries(9999, 1), 4);
}

fn carries(mut x: usize, mut y: usize) -> usize {
    let (mut r, mut c) = (0, 0);
    while x != 0 || y != 0 {
        let v = (x % 10) + (y % 10) + c;
        c = 0;
        if v >= 10 {
            c = 1;
        }
        r += c;
        x /= 10;
        y /= 10;
    }
    r
}
