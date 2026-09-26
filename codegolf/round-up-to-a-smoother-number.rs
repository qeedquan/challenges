/*

Input

Two positive integers a > b

Output

The smallest integer c >= a so that c can be factored into two parts with one part an integer power of two (that is at least two) and the other part no larger than b.

Examples

If b = 100 and a = 101 , then the output should be 102 as 102 is 2 times 51.

For the same b, if a = 201 then the output should be 204 as that equals 4 times 51.

For the same b, if a = 256 then the output should be 256.

*/

fn main() {
    assert_eq!(smoother(101, 100), 102);
    assert_eq!(smoother(201, 100), 204);
    assert_eq!(smoother(256, 100), 256);
    assert_eq!(smoother(384, 3), 384);
    assert_eq!(smoother(138534, 200), 139264);
}

/*

@Arnauld

How?

We recursively increment a while a / (a & -a) is greater than b.

The bitwise trick a & -a isolates the least significant 1 in the binary representation of a, i.e. the largest divisor or a which is a power of 2.

*/

fn smoother(mut a: isize, b: isize) -> isize {
    while (a / (a & -a)) > b {
        a += 1;
    }
    return a;
}
