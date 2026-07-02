/*

You are given two arrays arr1 and arr2, where arr2 always contains integers.

Write the function find_array(arr1, arr2) such that:

For arr1 = ['a', 'a', 'a', 'a', 'a'], arr2 = [2, 4] find_array returns ['a', 'a']

For arr1 = [0, 1, 5, 2, 1, 8, 9, 1, 5], arr2 = [1, 4, 7] find_array returns [1, 1, 1]

For arr1 = [0, 3, 4], arr2 = [2, 6] find_array returns [4]

For arr1=["a","b","c","d"] , arr2=[2,2,2], find_array returns ["c","c","c"]

For arr1=["a","b","c","d"], arr2=[3,0,2] find_array returns ["d","a","c"]

If either arr1 or arr2 is empty, you should return an empty arr (empty list in python, empty vector in c++). Note for c++ use std::vector arr1, arr2.

*/

fn main() {
    assert_eq!(find(&['a', 'a', 'a', 'a', 'a'], &[2, 4]), vec!['a', 'a']);
    assert_eq!(
        find(&[0, 1, 5, 2, 1, 8, 9, 1, 5], &[1, 4, 7]),
        vec![1, 1, 1]
    );
    assert_eq!(find(&[0, 3, 4], &[2, 6]), vec![4]);
    assert_eq!(find(&["a", "b", "c", "d"], &[2, 2, 2]), vec!["c", "c", "c"]);
    assert_eq!(find(&["a", "b", "c", "d"], &[3, 0, 2]), vec!["d", "a", "c"]);
}

fn find<T: Copy>(array1: &[T], array2: &[usize]) -> Vec<T> {
    let mut result = vec![];
    for &index in array2 {
        if index < array1.len() {
            result.push(array1[index]);
        }
    }
    result
}
