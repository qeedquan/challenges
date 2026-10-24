/*

Task
Your task is to write as short as possible program preferably in Brainf**k which determines the last digit of given number after it's conversion from decimal to binary system.

Input
An integer in decimal system consisting of up to 200 digits. There is a newline character (ASCII 10) after the given number

Output
One digit (1 or 0) which is the last digit of given number after it's conversion to binary system.

Example
4372667135165131576213 -> 1

*/

fn main() {
    assert_eq!(lsb("4372667135165131576213"), 1);
    for i in 0..10000000 {
        assert_eq!(lsb(&format!("{i}")), i & 1);
    }
}

fn lsb(s: &str) -> isize {
    let mut r = -1;
    for c in s.chars() {
        match c {
            '1' | '3' | '5' | '7' | '9' => r = 1,
            '0' | '2' | '4' | '6' | '8' => r = 0,
            _ => return -1,
        };
    }
    r
}
