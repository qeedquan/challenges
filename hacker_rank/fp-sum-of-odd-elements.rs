/*

You are given a list. Return the sum of odd elements from the given list.
The input and output portions will be handled automatically.
You need to write a function with the recommended method signature.

Constraints

The list will have 1-100 elements.
Each element will be an integer X where -100 <= X <= 100.

Sample Input
3
2
4
6
5
7
8
0
1

Sample Output
16

*/

fn main() {
    assert_eq!(oddsum(&vec![3, 2, 4, 6, 5, 7, 8, 0, 1]), 16);
}

fn oddsum(a: &Vec<isize>) -> isize {
    a.iter().fold(0, |acc, x| acc + (x * (x & 1)))
}
