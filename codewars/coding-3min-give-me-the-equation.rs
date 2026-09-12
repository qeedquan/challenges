/*

This is the simple version of Shortest Code series. If you need some challenges, please try the challenge version

Task:
Give you three numbers:a b c,please return an equation(Operators include +,-,*,/), return type is string.

For example:

sc(1,2,3) should return "1+2=3" or "2+1=3" or "3-2=1" or "3-1=2"

sc(2,2,4) should return "2+2=4" or "2*2=4" or "4/2=2" or "4-2=2"

sc(6,2,3) should return "2*3=6" or "3*2=6" or "6/2=3" or "6/3=2"

Return one of the possible answer, you can pass the test.

If there is no equation between a,b,c, return ""

*/

fn main() {
    assert_eq!(sc(1, 2, 3), "1+2=3");
    assert_eq!(sc(2, 2, 4), "2+2=4");
    assert_eq!(sc(6, 2, 3), "6/2=3");
    assert_eq!(sc(6, 5, 4), "");
    assert_eq!(sc(2, 3, 4), "");
}

fn sc(a: isize, b: isize, c: isize) -> String {
    let ord = vec![
        [a, b, c],
        [a, c, b],
        [b, a, c],
        [b, c, a],
        [c, a, b],
        [c, b, a],
    ];

    for n in ord {
        let (x, y, z) = (n[0], n[1], n[2]);
        if x + y == z {
            return format!("{}+{}={}", x, y, z);
        } else if x - y == z {
            return format!("{}-{}={}", x, y, z);
        } else if x * y == z {
            return format!("{}*{}={}", x, y, z);
        } else if y != 0 && x % y == 0 && x / y == z {
            return format!("{}/{}={}", x, y, z);
        }
    }
    return format!("");
}
