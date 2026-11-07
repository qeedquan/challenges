/*

Almost equivalent to Project Euler's first question:

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

Challenge:
Given a positive integer N and a set of at least one positive integer A, output the sum of all positive integers less than N that are multiples of at least one member of A.

For example, for the Project Euler case, the input would be:

1000
3
5
Test cases:
Input : 50, [2]
Output: 600

Input : 10, [3, 5]
Output: 23

Input : 28, [4, 2]
Output: 182

Input : 19, [7, 5]
Output: 51

Input : 50, [2, 3, 5]
Output: 857

*/

fn main() {
    assert_eq!(solve(50, &[2]), 600);
    assert_eq!(solve(10, &[3, 5]), 23);
    assert_eq!(solve(28, &[4, 2]), 182);
    assert_eq!(solve(19, &[7, 5]), 51);
    assert_eq!(solve(50, &[2, 3, 5]), 857);
}

fn solve(limit: usize, numbers: &[usize]) -> usize {
    let mut result = 0;
    for iterator in 1..limit {
        for &number in numbers {
            if number != 0 && iterator % number == 0 {
                result += iterator;
                break;
            }
        }
    }
    result
}
