/*

Find two different minimal elements in the given sequence of numbers.

Input
First line contains the number of elements n (3 ≤ n ≤ 1000) in the sequence.
Then given n integers, each of them is no more than 2*10^9 by absolute value.

Output
Print in increasing order two different minimal elements from the given sequence. It is known that they always exist.

Examples

Input #1
7
2 10 2 3 -1 5 -1

Answer #1
-1 2

*/

fn main() {
    assert_eq!(solve(&mut [2, 10, 2, 3, -1, 5, -1]), [-1, 2]);
}

fn solve(array: &mut [isize]) -> [isize; 2] {
    let mut result = [0; 2];
    if array.len() == 0 {
        return result;
    }

    array.sort();
    result[0] = array[0];
    result[1] = array[0];
    for i in 1..array.len() {
        if array[i] != result[1] {
            result[1] = array[i];
            break;
        }
    }
    result
}
