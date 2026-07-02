/*

Find out how many times the maximum digit appears in the positive integer n.

Input
One positive integer n(n<10^18).

Output
Print how many times the maximum digit appears in the positive integer n.

Examples

Input #1
2354

Answer #1
1

Input #2
606432232464626

Answer #2
5

*/

fn main() {
    assert_eq!(solve(2354), 1);
    assert_eq!(solve(606432232464626), 5);
}

fn solve(mut n: usize) -> usize {
    let mut d = vec![0; 10];
    loop {
        d[n % 10] += 1;
        n /= 10;
        if n == 0 {
            break;
        }
    }

    for i in (0..10).rev() {
        if d[i] != 0 {
            return d[i];
        }
    }
    return 0;
}
