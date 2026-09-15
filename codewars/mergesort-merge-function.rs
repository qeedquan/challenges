/*

In this excercise, we will implement the "merge" function from MergeSort.

MergeSort is often taught in Computer Science as the canonical example of the "Divide and Conquer" algorithm. The strategy of MergeSort is both simple and profound, leveraging two simple-to-prove mathematical facts (1. That every list of 1 element is "sorted" ... and 2. It is much easier to combine two already-sorted lists into 1 sorted list than it is to sort a big list all at once) to yield an algorithm with a worst-case complexity of O(n log n).

Basically, MergeSort works like this:

If we get a list of size 1, then it's already sorted: we're done. Just return that value.
Otherwise; break the list you have to sort in half: 2a. MergeSort the first half. 2b. MergeSort the second half. 2c. "Merge" the two sorted lists for 2a and 2b together. Voila: sorted.
2c is where the MergeSort "merge" function comes in. It takes two already-sorted lists (arrays, in this example) and returns one large sorted list.

The name of the function in this example is "mergesorted". It should return a big sorted array from two smaller sorted arrays: e.g.

mergesorted([1,2],[3,4]) //should: [1,2,3,4]

mergesorted([1,2],[3]) //should: [1,2,3]

mergesorted([1],[2, 3]) //should: [1,2,3]

*/

fn main() {
    assert_eq!(mergesorted(&[1, 2], &[3, 4]), vec![1, 2, 3, 4]);
    assert_eq!(mergesorted(&[1, 2], &[3]), vec![1, 2, 3]);
    assert_eq!(mergesorted(&[1], &[2, 3]), vec![1, 2, 3]);
    assert_eq!(mergesorted(&[], &[]), vec![]);
    assert_eq!(mergesorted(&[1], &[]), vec![1]);
    assert_eq!(mergesorted(&[1], &[1]), vec![1, 1]);
    assert_eq!(mergesorted(&[1, 2, 3], &[4]), vec![1, 2, 3, 4]);
    assert_eq!(mergesorted(&[4], &[1, 2, 3]), vec![1, 2, 3, 4]);
    assert_eq!(mergesorted(&[1, 1, 1], &[2, 2, 2]), vec![1, 1, 1, 2, 2, 2]);
    assert_eq!(mergesorted(&[2, 2, 2], &[1, 1, 1]), vec![1, 1, 1, 2, 2, 2]);
    assert_eq!(mergesorted(&[1, 2, 3], &[1, 2, 3]), vec![1, 1, 2, 2, 3, 3]);
    assert_eq!(mergesorted(&[1, 3, 5], &[2, 4, 6]), vec![1, 2, 3, 4, 5, 6]);
    assert_eq!(mergesorted(&[2, 4, 6], &[1, 3, 5]), vec![1, 2, 3, 4, 5, 6]);
}

fn mergesorted(a: &[isize], b: &[isize]) -> Vec<isize> {
    let (mut r, n, m, mut i, mut j) = (vec![], a.len(), b.len(), 0, 0);
    while i < n && j < m {
        if a[i] < b[j] {
            r.push(a[i]);
            i += 1;
        } else {
            r.push(b[j]);
            j += 1;
        }
    }
    if i < n {
        r.extend_from_slice(&a[i..]);
    }
    if j < m {
        r.extend_from_slice(&b[j..]);
    }
    r
}
