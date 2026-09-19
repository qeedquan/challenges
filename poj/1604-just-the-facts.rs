/*

Description

The expression N!, read as "N factorial," denotes the product of the first N positive integers, where N is nonnegative. So, for example,
 N       N!

 0       1

 1       1

 2       2

 3       6

 4      24

 5     120

10 3628800

For this problem, you are to write a program that can compute the last non-zero digit of any factorial for (0 <= N <= 10000). For example, if your program is asked to compute the last nonzero digit of 5!, your program should produce "2" because 5! = 120, and 2 is the last nonzero digit of 120.

Input

Input to the program is a series of nonnegative integers not exceeding 10000, each on its own line with no other letters, digits or spaces. For each integer N, you should read the value and compute the last nonzero digit of N!.

Output

For each integer input, the program should print exactly one line of output. Each line of output should contain the value N, right-justified in columns 1 through 5 with leading blanks, not leading zeroes. Columns 6 - 9 must contain " -> " (space hyphen greater space). Column 10 must contain the single last non-zero digit of N!.
Sample Input

1
2
26
125
3125
9999

Sample Output

    1 -> 1
    2 -> 2
   26 -> 4
  125 -> 8
 3125 -> 2
 9999 -> 8

 Source

South Central USA 1997

*/

fn main() {
    assert_eq!(lnzdf(1), 1);
    assert_eq!(lnzdf(2), 2);
    assert_eq!(lnzdf(26), 4);
    assert_eq!(lnzdf(125), 8);
    assert_eq!(lnzdf(3125), 2);
    assert_eq!(lnzdf(9999), 8);
}

// https://oeis.org/A008904
fn lnzdf(n: usize) -> usize {
    let tab = vec![1, 1, 2, 6, 4, 4, 4, 8, 4, 6];
    if n <= 1 {
        return 1;
    }
    let a = 6 * tab[n % 10];
    let b = usize::pow(3, ((n / 5) % 4) as u32);
    let c = lnzdf(n / 5);
    return (a * b * c) % 10;
}
