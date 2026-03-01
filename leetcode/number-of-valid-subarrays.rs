/*

Given an array A of integers, return the number of non-empty continuous subarrays that satisfy the following condition:

Example 1:

Input: [1,4,2,5,3]
Output: 11
Explanation: There are 11 valid subarrays: [1],[4],[2],[5],[3],[1,4],[2,5],[1,4,2],[2,5,3],[1,4,2,5],[1,4,2,5,3].

Example 2:

Input: [3,2,1]
Output: 3
Explanation: The 3 valid subarrays are: [3],[2],[1].

Example 3:

Input: [2,2,2]
Output: 6
Explanation: There are 6 valid subarrays: [2],[2],[2],[2,2],[2,2],[2,2,2].

Note:

1 <= A.length <= 50000
0 <= A[i] <= 100000

*/

fn main() {
    assert_eq!(subarrays(&[1, 4, 2, 5, 3]), 11);
    assert_eq!(subarrays(&[3, 2, 1]), 3);
    assert_eq!(subarrays(&[2, 2, 2]), 6);
}

fn subarrays(numbers: &[isize]) -> usize {
    let mut result = 0;
    let mut stack = vec![];
    for &number in numbers {
        while let Some(&value) = stack.last() {
            if value > number {
                stack.pop();
            } else {
                break;
            }
        }
        stack.push(number);
        result += stack.len();
    }
    result
}
