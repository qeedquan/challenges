/*

Read input of up to 8 characters presented as hexadecimal number and print this number as decimal number. In case that input can not be presented as hexadecimal input it has to print 0

Rules:
It is not allowed to use any function that takes or returns strings/characters, beside function that reads string/char from input and return strings/char as-is,
function that takes integer and prints that integer to output as decimal number and function (if needed) that takes character and return its ASCII/UNICODE represented integer.

Shortest code wins

Example input
C0cAc01a

output
3234512922

*/

fn main() {
    assert_eq!(hex2dec("C0cAc01a"), 3234512922);
}

fn hex2dec(hex: &'static str) -> isize {
    match isize::from_str_radix(hex, 16) {
        Ok(x) => x,
        _ => 0,
    }
}
