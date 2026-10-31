/*

Three digit number is given. Remove one digit from it to get the minimum possible two-digit number.

Input
One three-digit natural number.

Output
Print the minimum possible two-digit number.

Examples
Input #1
123

Answer #1
12

*/

fn main() {
    assert_eq!(solve(123), 12);
    assert_eq!(solve(999), 99);
    assert_eq!(solve(789), 78);
}

fn solve(number: usize) -> usize {
    let mut array = [number % 10, (number / 10) % 10, (number / 100) % 10];
    array.sort();
    (array[0] * 10) + array[1]
}
