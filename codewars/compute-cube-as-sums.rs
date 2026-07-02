/*

Can you compute a cube as a sum?

In this Kata, you will be given a number n (where n >= 1) and your task is to find n consecutive odd numbers whose sum is exactly the cube of n.

Mathematically:
cube = n ** 3
sum = a1 + a2 + a3 + ..... + an
sum == cube
a2 == a1 + 2, a3 == a2 + 2, .......

For example:

findSummands(3) = [7,9,11] // because 7 + 9 + 11 = 27, the cube of 3. Note that there are only n = 3 elements in the array.
Write function findSummands(n) which will return an array of n consecutive odd numbers with the sum equal to the cube of n (n*n*n).

*/

fn main() {
    assert_eq!(summands(1), vec![1]);
    assert_eq!(summands(2), vec![3, 5]);
    assert_eq!(summands(3), vec![7, 9, 11]);
    assert_eq!(summands(4), vec![13, 15, 17, 19]);
}

fn summands(n: usize) -> Vec<usize> {
    let mut r = vec![];
    for i in 0..n {
        r.push(n * (n - 1) + 1 + 2 * i);
    }
    r
}
