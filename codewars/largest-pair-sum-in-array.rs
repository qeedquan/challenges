/*

Given a sequence of numbers, find the largest pair sum in the sequence.

For example

[10, 14, 2, 23, 19] -->  42 (= 23 + 19)
[99, 2, 2, 23, 19]  --> 122 (= 99 + 23)

Input sequence contains minimum two elements and every element is an integer.

*/

fn main() {
    assert_eq!(largest_pair_sum(&[10, 14, 2, 23, 19]), 42);
    assert_eq!(largest_pair_sum(&[99, 2, 2, 23, 19]), 122);
}

fn largest_pair_sum(array: &[isize]) -> isize {
    let mut pair = [isize::MIN, isize::MIN];
    for &value in array {
        if value >= pair[0] {
            (pair[0], pair[1]) = (value, pair[0]);
        } else if value > pair[1] {
            pair[1] = value;
        }
    }
    pair[0] + pair[1]
}
