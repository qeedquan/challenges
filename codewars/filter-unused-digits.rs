/*

Given a varying number of integer arguments, return the digits that are not present in any of them.

Example:

[12, 34, 56, 78]  =>  "09"
[2015, 8, 26]     =>  "3479"

Note: the digits in the resulting string should be sorted.

*/

fn main() {
    assert_eq!(unused_digits(&[12, 34, 56, 78]), "09");
    assert_eq!(unused_digits(&[2015, 8, 26]), "3479");
}

fn unused_digits(numbers: &[usize]) -> String {
    let mut seen = [false; 10];
    for &(mut number) in numbers {
        while number > 0 {
            seen[number % 10] = true;
            number /= 10;
        }
    }

    let mut result = format!("");
    for index in 0..seen.len() {
        if !seen[index] {
            result = format!("{result}{index}");
        }
    }
    result
}
