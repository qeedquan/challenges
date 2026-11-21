/*

A set of whole numbers (0-) will be given separated by a space. Some numbers will be missing between certain numbers in the set. Your job is to find the missing odd numbers between them.

Conditions
The input will be a one line string.
Your code must left out a variable for inserting the input case string.
The output should be a string containing all the missing odd numbers in the set of numbers given as input.
The numbers of the output must be separated by a comma - ,.
No extra characters should be included in the output.
If there are no odd numbers missing, the code should print out null or a blank line.
Here are some sample inputs and outputs according to its order :

Input
4 6 8 10
5 15 18 21 26
2 15 6
1 20
1 3 5 7 9
Output
5,7,9
7,9,11,13,17,19,23,25
3,5,7,9,11,13
3,5,7,9,11,13,15,17,19
null
The winner will be decided by the Code length.

The calculation of code length won't include the variable that is left for the test case.

*/

fn main() {
    assert_eq!(missing(&[4, 6, 8, 10]), vec![5, 7, 9]);
    assert_eq!(
        missing(&[5, 15, 18, 21, 26]),
        vec![7, 9, 11, 13, 17, 19, 23, 25]
    );
    assert_eq!(missing(&[2, 15, 6]), vec![3, 5, 7, 9, 11, 13]);
    assert_eq!(missing(&[1, 20]), vec![3, 5, 7, 9, 11, 13, 15, 17, 19]);
    assert_eq!(missing(&[1, 3, 5, 7, 9]), vec![]);
}

fn missing(a: &[isize]) -> Vec<isize> {
    let mut r = vec![];
    for i in 1..a.len() {
        let mut j = (a[i - 1] + 1) + (a[i - 1] & 1);
        while j < a[i] {
            r.push(j);
            j += 2;
        }
    }
    r
}
