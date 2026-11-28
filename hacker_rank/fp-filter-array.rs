/*

Filter a given array of integers and output only those values that are less than a specified value X.
The output integers should be in the same sequence as they were in the input.
You need to write a function with the recommended method signature for the languages mentioned below.
For the rest of the languages, you have to write a complete code.

Input Format
The first line contains the delimiter X.
The next B lines each contain an integer, which represents the elements of the list/array.
You have to read the input to the End-Of-File.

Output Format
Print all the integers from the array that are less than the given upper limit X in value on separate lines.
The sequence should be the same as it was in the original array.


Constraints
1 <= B <= 100
For any element, Y in the array,
-100 <= Y <= 100
-100 <= X <= 100

Note
The purpose of this challenge is to learn how to write your own implementation of a filter function. We recommend not using the inbuilt library function.

Sample Input
3
10
9
8
2
7
5
1
3
0

Sample Output
2
1
0

*/

fn main() {
    assert_eq!(filter(3, vec![10, 9, 8, 2, 7, 5, 1, 3, 0]), vec![2, 1, 0]);
}

fn filter(threshold: isize, numbers: Vec<isize>) -> Vec<isize> {
    numbers.into_iter().filter(|&x| x < threshold).collect()
}
