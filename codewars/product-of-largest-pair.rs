/*

Rick wants a faster way to get the product of the largest pair in an array. Your task is to create a performant solution to find the product of the largest two integers in a unique array of positive numbers.
All inputs will be valid.

Passing [2, 6, 3] should return 18, the product of [6, 3].

Disclaimer: only accepts solutions that are faster than his, which has a running time O(nlogn).

maxProduct([2, 1, 5, 0, 4, 3])              // 20
maxProduct([7, 8, 9])                       // 72
maxProduct([33, 231, 454, 11, 9, 99, 57])   // 104874

*/

fn main() {
    assert_eq!(max_product(&[2, 1, 5, 0, 4, 3]), 20);
    assert_eq!(max_product(&[7, 8, 9]), 72);
    assert_eq!(max_product(&[33, 231, 454, 11, 9, 99, 57]), 104874);
}

fn max_product(array: &[usize]) -> usize {
    let mut first = 0;
    let mut second = 0;
    for &value in array {
        if value >= first {
            second = first;
            first = value;
        } else if value > second {
            second = value;
        }
    }
    first * second
}
