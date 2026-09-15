/*

If you have not ever heard the term Arithmetic Progression, refer to: http://www.codewars.com/kata/find-the-missing-term-in-an-arithmetic-progression/python

And here is an unordered version. Try if you can survive lists of MASSIVE numbers (which means time limit should be considered). :D

Note: Don't be afraid that the minimum or the maximum element in the list is missing, e.g. [4, 6, 3, 5, 2] is missing 1 or 7, but this case is excluded from the kata.

Example:

find([3, 9, 1, 11, 13, 5]) # => 7

*/

use std::cmp::*;

fn main() {
    assert_eq!(find(&[3, 9, 1, 11, 13, 5]), 7);
    assert_eq!(find(&[1, 2, 3, 4, 6, 7, 8, 9]), 5);
    assert_eq!(find(&[1, 3, 4, 5, 6, 7, 8, 9]), 2);
}

fn find(sequence: &[usize]) -> usize {
    let length = sequence.len();
    if length == 0 {
        return 0;
    }

    let mut minimum = sequence[0];
    let mut maximum = sequence[0];
    let mut sum = sequence[0];
    for index in 1..length {
        minimum = min(minimum, sequence[index]);
        maximum = max(maximum, sequence[index]);
        sum += sequence[index];
    }
    return ((minimum + maximum) * (length + 1)) / 2 - sum;
}
