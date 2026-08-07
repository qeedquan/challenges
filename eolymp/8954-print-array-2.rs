/*

Given an array of n integers, print its elements in a single line in reverse order.

Input
The first line contains the integer n (1≤n≤100). The next n lines contain the elements of the array, one number per line. The absolute value of each element does not exceed 100.

Output
Print the elements of the array in a single line in reverse order.

Examples

Input #1
7
0
4
7
-4
0
3
-2

Answer #1
-2 3 0 -4 7 4 0

*/

fn main() {
    solve(&[0, 4, 7, -4, 0, 3, -2]);
}

fn solve(a: &[isize]) {
    for i in (0..a.len()).rev() {
        print!("{}", a[i]);
        if i > 0 {
            print!(" ");
        }
    }
    println!();
}
