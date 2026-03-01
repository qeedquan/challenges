/*

Your job is to implement a function which returns the last D digits of an integer N as a list.

Special cases:
If D > (the number of digits of N), return all the digits.
If D <= 0, return an empty list.
Examples:
N = 1
D = 1
result = [1]

N = 1234
D = 2
result = [3, 4]

N = 637547
D = 6
result = [6, 3, 7, 5, 4, 7]

*/

fn main() {
    assert_eq!(lastdigits(1, 1), vec![1]);
    assert_eq!(lastdigits(1234, 2), vec![3, 4]);
    assert_eq!(lastdigits(637547, 6), vec![6, 3, 7, 5, 4, 7]);
}

fn lastdigits(mut n: usize, mut d: usize) -> Vec<usize> {
    let mut r = vec![];
    while d > 0 {
        r.push(n % 10);
        n /= 10;
        if n == 0 {
            break;
        }
        d -= 1;
    }
    r.reverse();
    r
}
