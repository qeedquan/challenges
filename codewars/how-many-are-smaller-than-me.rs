/*

Write a function that given, an array arr, returns an array containing at each index i the amount of numbers that are smaller than arr[i] to the right.

For example:

* Input [5, 4, 3, 2, 1] => Output [4, 3, 2, 1, 0]
* Input [1, 2, 0] => Output [1, 1, 0]

*/

fn main() {
    assert_eq!(smaller(&vec![5, 4, 3, 2, 1]), vec![4, 3, 2, 1, 0]);
    assert_eq!(smaller(&vec![1, 2, 0]), vec![1, 1, 0]);
}

fn smaller(a: &Vec<isize>) -> Vec<isize> {
    let mut r = vec![];
    let n = a.len();
    for i in 0..n {
        let mut c = 0;
        for j in i + 1..n {
            if a[i] >= a[j] {
                c += 1;
            }
        }
        r.push(c);
    }
    r
}
