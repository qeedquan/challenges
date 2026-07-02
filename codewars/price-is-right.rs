/*

Given an array of integers, and a target integer, return the largest integer from the array that is less than or equal to the target.

If there is no number that is less than or equal to the target number then return undefined.

The array of integers may be empty, but will always be an array.

*/

fn main() {
    assert_eq!(price_is_right(&vec![1, 2, 3, 4], 1), Some(1));
    assert_eq!(price_is_right(&vec![1, 2, 3, 4], 2), Some(2));
    assert_eq!(price_is_right(&vec![1, 2, 3, 4], 3), Some(3));
    assert_eq!(price_is_right(&vec![1, 2, 3, 4], 4), Some(4));
    assert_eq!(price_is_right(&vec![1, 2, 3, 4], 0), None);
}

fn price_is_right(numbers: &Vec<isize>, target: isize) -> Option<isize> {
    let mut max = isize::MIN;
    let mut found = false;
    for &value in numbers {
        if value <= target && max < value {
            (max, found) = (value, true);
        }
    }
    if !found {
        return None;
    }
    return Some(max);
}
