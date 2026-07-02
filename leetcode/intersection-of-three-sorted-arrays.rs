/*

Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.

Example 1:

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.

Constraints:

    1 <= arr1.length, arr2.length, arr3.length <= 1000
    1 <= arr1[i], arr2[i], arr3[i] <= 2000

*/

use std::cmp::max;

fn main() {
    assert_eq!(
        intersect(&[1, 2, 3, 4, 5], &[1, 2, 5, 7, 9], &[1, 3, 4, 5, 8]),
        vec![1, 5]
    );
}

fn intersect(a: &[isize], b: &[isize], c: &[isize]) -> Vec<isize> {
    let (mut r, mut i, mut j, mut k) = (vec![], 0, 0, 0);
    while i < a.len() && j < b.len() && k < c.len() {
        if a[i] == b[j] && b[j] == c[k] {
            r.push(a[i]);
            (i, j, k) = (i + 1, j + 1, k + 1);
            continue;
        }

        let x = max(a[i], max(b[j], c[k]));
        while i < a.len() && a[i] < x {
            i += 1;
        }
        while j < b.len() && b[j] < x {
            j += 1;
        }
        while k < c.len() && c[k] < x {
            k += 1;
        }
    }
    return r;
}
