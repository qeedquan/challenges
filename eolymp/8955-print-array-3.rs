/*

Array of n integers is given. Print all its positive elements, do not change their initial order.

Input
First line contains number n (1≤n≤100). Second line contains n integers, each no more than 100 by absolute value.

Output
In the first line print the number of positive elements in array. In the second line print the positive elements. If there are no positive elements in the array, print "NO".

Examples

Input #1
7
-2 5 4 -3 7 -3 0

Answer #1
3
5 4 7

Input #2
5
-2 -1 0 -1 -5

Answer #2
NO

*/

fn main() {
    solve(&[-2, 5, 4, -3, 7, -3, 0]);
    solve(&[-2, -1, 0, -1, -5]);
}

fn solve(a: &[isize]) {
    let mut c = 0;
    for i in 0..a.len() {
        if a[i] > 0 {
            c += 1;
        }
    }
    if c == 0 {
        println!("NO");
        return;
    }

    println!("{}", c);
    for i in 0..a.len() {
        if a[i] > 0 {
            print!("{}", a[i]);
            c -= 1;
            if c != 0 {
                print!(" ");
            }
        }
    }
    println!();
}
