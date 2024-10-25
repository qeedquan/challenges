/*

Write a function f(a,b) that returns a mod b given the constraints:

you can't use division in any way
f(a,b) is always positive, eg: f(-1,5) = 4
it performs reasonably well for values of ~10e50 for a and b

*/

fn main() {
    let n = 10000;
    for x in 0..n {
        for y in 1..n {
            assert_eq!(x % y, modulo(x, y));
        }
    }
}

fn modulo(mut x: isize, y: isize) -> isize {
    if x < 0 {
        x = -(x * y - x);
    }
    while x >= y {
        x -= y;
    }
    x
}
