/*

This simple challenge is very similar to this one: How many days in a month? The only difference is you yield the number of days in a month given the index of the month instead of its name.

The reason I ask this near-duplicate is curiosity about mathematical patterns in the sequence of numbers.
For example, a simple observation is that even-indexed months have 31 until August and then it flips — but golf that observation and/or make better ones that yield better strokes...

INPUT: Integer indicating the month; 1 through 12. (Optionally, you can accept 0-indexed month numbers from 0 to 11.)

OUTPUT: Number of days in that month. February can return 28 or 29.

Complete I/O table:

INPUT   :   OUTPUT
  1          31
  2          28 or 29 
  3          31
  4          30
  5          31
  6          30
  7          31
  8          31
  9          30
 10          31
 11          30
 12          31

*/

fn main() {
    for i in 1..13 {
        println!("{} {}", i, days(i));
    }
}

fn days(m: usize) -> isize {
    let tab = vec![31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    if m > tab.len() {
        -1
    } else {
        tab[m - 1]
    }
}
