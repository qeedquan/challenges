/*

Given an integer, write a function to determine if it is a power of two.

*/

fn main() {
    for i in 1..(1 << 20) + 1 {
        if is_power_of_two(i) {
            println!("{}", i);
        }
    }
}

fn is_power_of_two(n: usize) -> bool {
    n > 0 && (n & (n - 1)) == 0
}
