/*

Write a program that finds and displays all pairs of integers s1 and s2 such that:
1. neither s1 nor s2 have any digits repeated; and
2. s1/s2 = N, where N is a given integer;

Input
The input file consist a integer at the beginning indicating the number of test case followed by a blank
line. Each test case consists of one line of input containing N.
Two input are separated by a blank line.

Output
For each input the output consists of a sequence of zero or more lines each containing fi ‘s1 / s2 = N’,
where s1, s2 and Nfi are the integers described above. When there are two or more solutions, sort them
by increasing numerator values.
Two consecutive output set will separated by a blank line.

Sample Input
1
1234567890

Sample Output
1234567890 / 1 = 1234567890
2469135780 / 2 = 1234567890
4938271560 / 4 = 1234567890
6172839450 / 5 = 1234567890
8641975230 / 7 = 1234567890
9876543120 / 8 = 1234567890

*/

fn main() {
    solve(1234567890);
}

fn solve(n: u128) {
    let mut i = 1;
    while i * n <= 9876543210 {
        let j = i * n;
        if valid(j) && valid(i) {
            println!("{} / {} = {}", j, i, n);
        }
        i += 1;
    }
    println!();
}

fn valid(mut n: u128) -> bool {
    let mut d = [false; 10];
    while n > 0 {
        let i = (n % 10) as usize;
        if d[i] {
            return false;
        }
        d[i] = true;
        n /= 10;
    }
    return true;
}
