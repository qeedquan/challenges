/*

The race participants were assigned numbers from a to b inclusive, and this information was entered into the computer. Print the athletes' numbers.

Input
Two positive integers a and b (a≤b≤1000).

Output
Print the athletes' numbers in ascending order.

Examples

Input #1
3 7

Answer #1
3 4 5 6 7

*/

fn main() {
    solve(3, 7);
}

fn solve(a: usize, b: usize) {
    for i in a..=b {
        print!("{i}");
        if i + 1 <= b {
            print!(" ");
        }
    }
    println!();
}
