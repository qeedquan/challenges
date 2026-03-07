/*

Create a function that returns the sum of the digits formed from the first and last digits, all the way to the center of the number.

Worked Example
2520 ➞ 72

# The first and last digits are 2 and 0.
# 2 and 0 form 20.
# The second digit is 5 and the second to last digit is 2.
# 5 and 2 form 52.

# 20 + 52 = 72

Examples
121 ➞ 13
# 11 + 2

1039 ➞ 22
# 19 + 3

22225555 ➞ 100
# 25 + 25 + 25 + 25

Notes
If the number has an odd number of digits, simply add on the single-digit number in the center (see example #1).
Any number which is zero-padded counts as a single digit (see example #2).

*/

fn main() {
    assert_eq!(closing_in_sum(121), 13);
    assert_eq!(closing_in_sum(1039), 22);
    assert_eq!(closing_in_sum(22225555), 100);
    assert_eq!(closing_in_sum(2520), 72);
    assert_eq!(closing_in_sum(5332824166496569), 331);
    assert_eq!(closing_in_sum(1979672314137318116), 485);
    assert_eq!(closing_in_sum(1795459644013947776), 548);
    assert_eq!(closing_in_sum(2801980378842185820), 426);
    assert_eq!(closing_in_sum(3440584288422776554), 430);
    assert_eq!(closing_in_sum(1985124000275401986), 342);
}

fn closing_in_sum(number: u128) -> u128 {
    let digits = number_to_array(number);
    let length = digits.len();

    let mut result = 0;
    for index in 0..length / 2 {
        result += (digits[index] * 10) + digits[length - index - 1];
    }
    if length % 2 != 0 {
        result += digits[length / 2];
    }
    result
}

fn number_to_array(mut number: u128) -> Vec<u128> {
    let mut digits = vec![];
    loop {
        digits.push(number % 10);
        number /= 10;
        if number == 0 {
            break;
        }
    }
    digits.reverse();
    digits
}
