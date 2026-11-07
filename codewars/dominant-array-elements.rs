/*

An element in an array is dominant if it is greater than all elements to its right. You will be given an array and your task will be to return a list of all dominant elements. For example:

solve([1,21,4,7,5]) = [21,7,5] because 21, 7 and 5 are greater than elments to their right. 
solve([5,4,3,2,1]) = [5,4,3,2,1]

Notice that the last element is always included. All numbers will be greater than 0.
More examples in the test cases.

Good luck!

*/

use std::cmp::max;

fn main() {
    assert_eq!(dominant(&vec![1, 21, 4, 7, 5]), vec![21, 7, 5]);
    assert_eq!(dominant(&vec![5, 4, 3, 2, 1]), vec![5, 4, 3, 2, 1]);
    assert_eq!(dominant(&vec![16, 17, 14, 3, 14, 5, 2]), vec![17, 14, 5, 2]);
    assert_eq!(dominant(&vec![92, 52, 93, 31, 89, 87, 77, 105]), vec![105]);
    assert_eq!(dominant(&vec![75, 47, 42, 56, 13, 55]), vec![75, 56, 55]);
    assert_eq!(
        dominant(&vec![67, 54, 27, 85, 66, 88, 31, 24, 49]),
        vec![88, 49]
    );
    assert_eq!(dominant(&vec![76, 17, 25, 36, 29]), vec![76, 36, 29]);
}

fn dominant(array: &Vec<isize>) -> Vec<isize> {
    let (mut result, mut maximum) = (vec![], isize::MIN);
    for &value in array.into_iter().rev() {
        if value > maximum {
            result.push(value);
        }
        maximum = max(maximum, value);
    }
    result.reverse();
    result
}
