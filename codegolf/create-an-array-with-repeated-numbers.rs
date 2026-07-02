/*

Challenge
Your task in this question is to write a program or a named function which takes a positive integer n (greater than 0) as input via STDIN, ARGV or function arguments and outputs an array via STDOUT or function returned value.

Sounds simple enough ? Now here are the rules

The array will only contain integers from 1 to n
Each integer from 1 to n should be repeated x times where x is the value of each integer.
For example:

Input:

5
Output:

[1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5]
The array may or may not be sorted.

This is code-golf so winner is shortest code in bytes.

Bonus

Multiply your score by 0.5 if no two adjacent integers in your output array are same.

For example for n = 5, one such configuration would be

[5, 4, 5, 4, 3, 4, 5, 2, 5, 3, 1, 2, 3, 4, 5]

*/

fn main() {
    println!("{:?}", sitrep(6));
}

fn sitrep(n: isize) -> Vec<isize> {
    let mut r = vec![];
    for i in (1..n + 1).rev() {
        for j in 1..i + 1 {
            r.push(j);
        }
    }
    r
}
