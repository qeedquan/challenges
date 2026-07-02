/*

Given an array of n integers, your task is to find the largest even number in the array. If there are no even numbers, output NO.

Input
The first line contains the integer n (1≤n≤100), representing the number of elements in the array.
The second line contains n integers, each with an absolute value not exceeding 100.

Output
Print the largest even number, or NO if no even numbers are present.

Examples

Input #1
5
2 3 5 6 1

Answer #1
6

Input #2
5
-1 -3 -5 5 1

Answer #2
NO

*/

use std::cmp::max;

fn main() {
    assert_eq!(solve(&[2, 3, 5, 6, 1]), (6, true));
    assert_eq!(solve(&[-1, -3, -5, 5, 1]), (0, false));
}

fn solve(numbers: &[isize]) -> (isize, bool) {
    let (mut result, mut found) = (isize::MIN, false);
    for &number in numbers {
        if (number & 1) == 0 {
            (result, found) = (max(result, number), true);
        }
    }
    if !found {
        return (0, false);
    }
    return (result, found);
}
