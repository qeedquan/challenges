/*

Get the number n to return the sequence from n to 1. The number n can be negative and also large number. (See the range as the following)

Example : 
n=5  >> [5,4,3,2,1]
n=-1 >> [-1,0,1]

Range :
Python     -9999 < n < 9999
Javascript -9999 < n < 9999
c++        -9999 < n < 9999
Crystal    -9999 < n < 9999
Ruby       -9999 < n < 9999

*/

fn main() {
    assert_eq!(seq(5), vec![5, 4, 3, 2, 1]);
    assert_eq!(seq(-1), vec![-1, 0, 1]);
}

fn seq(mut n: isize) -> Vec<isize> {
    let mut d = -1;
    if n < 1 {
        d = -d;
    }

    let mut r = vec![];
    loop {
        r.push(n);
        if n == 1 {
            break;
        }
        n += d;
    }
    r
}
