/*

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in non-descending order,
return the researcher's h-index.

According to the definition of h-index on Wikipedia:
The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

You must write an algorithm that runs in logarithmic time.

Example 1:

Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had received 0, 1, 3, 5, 6 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Example 2:

Input: citations = [1,2,100]
Output: 2

Constraints:

n == citations.length
1 <= n <= 10^5
0 <= citations[i] <= 1000
citations is sorted in ascending order.

Hint 1
Expected runtime complexity is in O(log n) and the input is sorted.

*/

fn main() {
    assert_eq!(hindex(&[0, 1, 3, 5, 6]), 3);
    assert_eq!(hindex(&[1, 2, 100]), 2);
}

fn hindex(citations: &[usize]) -> usize {
    let length = citations.len();
    if length == 0 {
        return 0;
    }

    let mut left = 0;
    let mut right = length - 1;
    while left <= right {
        let mid = left + (right - left) / 2;
        if citations[mid] >= length - mid {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    length - left
}
