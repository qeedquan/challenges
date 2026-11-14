/*

Task
Consider integer numbers from 0 to n - 1 written down along the circle in such a way that the distance between any two neighbouring numbers is equal (note that 0 and n - 1 are neighbouring, too).

Given n and firstNumber/first_number/first-number, find the number which is written in the radially opposite position to firstNumber.

Example
For n = 10 and firstNumber = 2, the output should be 7

https://codefightsuserpics.s3.amazonaws.com/tasks/circleOfNumbers/img/example.png?_tm=1476003938167

Input/Output
[input] integer n

A positive even integer.

Constraints: 4 ≤ n ≤ 1000.

[input] integer firstNumber/first_number/first-number

Constraints: 0 ≤ firstNumber ≤ n - 1

[output] an integer

*/

fn main() {
    assert_eq!(circle_of_numbers(10, 1), 6);
    assert_eq!(circle_of_numbers(10, 2), 7);
    assert_eq!(circle_of_numbers(10, 3), 8);
    assert_eq!(circle_of_numbers(10, 4), 9);
    assert_eq!(circle_of_numbers(10, 5), 0);
    assert_eq!(circle_of_numbers(10, 6), 1);
    assert_eq!(circle_of_numbers(10, 7), 2);
    assert_eq!(circle_of_numbers(10, 8), 3);
    assert_eq!(circle_of_numbers(10, 9), 4);
}

fn circle_of_numbers(numbers: isize, first: isize) -> isize {
    (first + (numbers / 2)) % numbers
}
