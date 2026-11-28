/*

Given an array of numbers, return the difference between the largest and smallest values.

For example:

[23, 3, 19, 21, 16] should return 20 (i.e., 23 - 3).

[1, 434, 555, 34, 112] should return 554 (i.e., 555 - 1).

The array will contain a minimum of two elements. Input data range guarantees that max-min will cause no integer overflow.

*/

fn main() {
    assert_eq!(between_extremes(&[23, 3, 19, 21, 16]), 20);
    assert_eq!(between_extremes(&[1, 434, 555, 34, 112]), 554);
}

fn between_extremes(array: &[isize]) -> isize {
    if array.len() == 0 {
        return 0;
    }

    let mut minimum = isize::MAX;
    let mut maximum = isize::MIN;
    for &value in array {
        minimum = minimum.min(value);
        maximum = maximum.max(value);
    }
    maximum - minimum
}
