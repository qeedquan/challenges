/*

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"

Constraints:

    1 <= num1.length, num2.length <= 10^4
    num1 and num2 consist of only digits.
    num1 and num2 don't have any leading zeros except for the zero itself.

*/

fn main() {
    assert_eq!(add("11", "123"), "134");
    assert_eq!(add("456", "77"), "533");
    assert_eq!(add("0", "0"), "0");
}

fn add(a: &str, b: &str) -> String {
    return format!("{}", atoi(a) + atoi(b));
}

fn atoi(s: &str) -> usize {
    let mut r = 0;
    for c in s.chars() {
        let v = match c {
            '9' => 9,
            '8' => 8,
            '7' => 7,
            '6' => 6,
            '5' => 5,
            '4' => 4,
            '3' => 3,
            '2' => 2,
            '1' => 1,
            '0' => 0,
            _ => panic!("encountered a non-digit character"),
        };
        r = (r * 10) + v;
    }
    r
}
