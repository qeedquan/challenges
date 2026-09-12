/*

The sequence is composed of natural numbers and concludes with the number 0. There are no more than 10000 numbers provided (not counting the terminating 0). Your task is to find out how many elements in this sequence are equal to the largest element. Numbers that appear after the 0 should not be considered.

Input
A sequence of natural numbers that ends with the number 0.

Output
Print the count of elements in the sequence that are equal to its largest element.

Examples

Input #1
1
7
9
0

Answer #1
1

Input #2
1
3
3
1
0

Answer #2
2

*/

fn main() {
    assert_eq!(solve(&[1, 7, 9, 0]), 1);
    assert_eq!(solve(&[1, 3, 3, 1, 0]), 2);
}

fn solve(array: &[usize]) -> usize {
    if array.len() == 0 {
        return 0;
    }

    let mut maximum = array[0];
    let mut count = 0;
    for &value in array {
        if value == 0 {
            break;
        }
        if maximum < value {
            maximum = value;
            count = 1;
        } else if value == maximum {
            count += 1;
        }
    }
    return count;
}
