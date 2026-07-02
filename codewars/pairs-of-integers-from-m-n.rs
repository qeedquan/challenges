/*

Implement a function that receives two integers m and n and generates a sorted list of pairs (a, b) such that m <= a <= b <= n.

The input m will always be smaller than or equal to n (e.g., m <= n)

Example
m = 2
n = 4

result = [(2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (4, 4)]

*/

fn main() {
    assert_eq!(
        pairs(2, 4),
        [[2, 2], [2, 3], [2, 4], [3, 3], [3, 4], [4, 4]]
    );
}

fn pairs(m: isize, n: isize) -> Vec<[isize; 2]> {
    let mut r = vec![];
    for i in m..n + 1 {
        for j in i..n + 1 {
            r.push([i, j]);
        }
    }
    r
}
