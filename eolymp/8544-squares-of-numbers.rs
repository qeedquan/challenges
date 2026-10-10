/*

Print the squares of all positive integers not exceeding n in ascending order.

Input
One positive integer n (n≤10^9).

Output
Print the list of squares of all positive integers not exceeding n in ascending order.

Examples

Input #1
10

Answer #1
1 4 9 

Input #2
20

Answer #2
1 4 9 16 

*/

fn main() {
    assert_eq!(solve(10), vec![1, 4, 9]);
    assert_eq!(solve(20), vec![1, 4, 9, 16]);
}

fn solve(n: usize) -> Vec<usize> {
    let mut r = vec![];
    for i in 1..=n {
        if i * i > n {
            break;
        }
        r.push(i * i);
    }
    r
}
