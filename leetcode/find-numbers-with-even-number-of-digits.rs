/*

Given an array nums of integers, return how many of them contain an even number of digits. 

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.

Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.

Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 10^5

Hint 1
How to compute the number of digits of a number ?

Hint 2
Divide the number by 10 again and again to get the number of digits.

*/

fn main() {
    assert_eq!(find_numbers(&[12, 345, 2, 6, 7896]), 2);
    assert_eq!(find_numbers(&[555, 901, 482, 1771]), 1);
}

fn find_numbers(numbers: &[usize]) -> usize {
    let mut count = 0;
    for &number in numbers {
        if digit_count(number) % 2 == 0 {
            count += 1;
        }
    }
    count
}

fn digit_count(mut number: usize) -> usize {
    let mut digits = 0;
    loop {
        digits += 1;
        number /= 10;
        if number == 0 {
            break;
        }
    }
    digits
}
