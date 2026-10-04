/*

Create a function that returns the CSV representation of a two-dimensional numeric array.

Example:

input:
   [[ 0, 1, 2, 3, 4 ],
    [ 10,11,12,13,14 ],
    [ 20,21,22,23,24 ],
    [ 30,31,32,33,34 ]] 
    
output:
     '0,1,2,3,4\n'
    +'10,11,12,13,14\n'
    +'20,21,22,23,24\n'
    +'30,31,32,33,34'

Array's length > 2.

More details here: https://en.wikipedia.org/wiki/Comma-separated_values

Note: you shouldn't escape the \n, it should work as a new line.

*/

use std::fmt::Write;

fn main() {
    println!(
        "{}",
        num2csv(&[
            &[0, 1, 2, 3, 4],
            &[10, 11, 12, 13, 14],
            &[20, 21, 22, 23, 24],
            &[30, 31, 32, 33, 34],
        ])
    );
}

fn num2csv(m: &[&[isize]]) -> String {
    let mut s = String::new();
    for i in 0..m.len() {
        for j in 0..m[i].len() {
            _ = write!(s, "{}", m[i][j]);
            if j + 1 < m[i].len() {
                s.push_str(",");
            }
        }
        if i + 1 < m.len() {
            s.push_str("\n");
        }
    }
    s
}
