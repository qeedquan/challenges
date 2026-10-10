/*

Description
Given two integers n and k, construct a list answer that contains n different positive integers ranging from 1 to n and obeys the following requirement:

Suppose this list is answer = [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
Return the list answer. If there multiple valid answers, return any of them.

Example 1:

Input: n = 3, k = 1
Output: [1,2,3]
Explanation: The [1,2,3] has three different positive integers ranging from 1 to 3, and the [1,1] has exactly 1 distinct integer: 1

Example 2:

Input: n = 3, k = 2
Output: [1,3,2]
Explanation: The [1,3,2] has three different positive integers ranging from 1 to 3, and the [2,1] has exactly 2 distinct integers: 1 and 2.

Constraints:

1 <= k < n <= 10^4

*/

fn main() {
    assert_eq!(construct(3, 1), vec![1, 2, 3]);
    assert_eq!(construct(3, 2), vec![1, 3, 2]);
}

fn construct(n: isize, k: isize) -> Vec<isize> {
    let (mut v, mut l, mut r) = (vec![], 1, n);
    for i in 0..k {
        if i % 2 == 0 {
            v.push(l);
            l += 1;
        } else {
            v.push(r);
            r -= 1;
        }
    }

    for _ in k..n {
        if k % 2 == 0 {
            v.push(r);
            r -= 1;
        } else {
            v.push(l);
            l += 1;
        }
    }
    
    v
}
