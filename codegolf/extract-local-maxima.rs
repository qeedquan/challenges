/*

Given an array of positive integers, output an array of all the elements that are greater than or equal to the adjacent ones. Most elements will have two adjacent elements; the first and last element are special cases, as they only have one adjacent element.

You may assume that the array contains at least two elements.

Test cases:

Input               | Output
[4,2,6,12,4,5,4,3]  | [4,12,5]
[1,2]               | [2]
[1,2,3,2,1]         | [3]
[3,2,1,2,3]         | [3,3]
[4,4]               | [4,4]
[2,4,4,4,1]         | [4,4,4]
[2,3,3,4]           | [3,4]
[4,3,3,4]           | [4,4]
This is code-golf, shortest code wins!

*/

fn main() {
    assert_eq!(maxima(&vec![4, 2, 6, 12, 4, 5, 4, 3]), vec![4, 12, 5]);
    assert_eq!(maxima(&vec![1, 2]), vec![2]);
    assert_eq!(maxima(&vec![1, 2, 3, 2, 1]), vec![3]);
    assert_eq!(maxima(&vec![3, 2, 1, 2, 3]), vec![3, 3]);
    assert_eq!(maxima(&vec![4, 4]), vec![4, 4]);
    assert_eq!(maxima(&vec![2, 4, 4, 4, 1]), vec![4, 4, 4]);
    assert_eq!(maxima(&vec![2, 3, 3, 4]), vec![3, 4]);
    assert_eq!(maxima(&vec![4, 3, 3, 4]), vec![4, 4]);
}

fn maxima(a: &Vec<isize>) -> Vec<isize> {
    let n = a.len();
    if n < 1 {
        return vec![];
    }

    if n == 1 {
        return vec![a[0]];
    }

    let mut r = vec![];
    if a[0] >= a[1] {
        r.push(a[0]);
    }
    for i in 1..n - 1 {
        if a[i] >= a[i - 1] && a[i] >= a[i + 1] {
            r.push(a[i]);
        }
    }
    if a[n - 1] >= a[n - 2] {
        r.push(a[n - 1]);
    }

    return r;
}
