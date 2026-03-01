/*

Convert a number to a binary coded decimal (BCD).

You can assume input will always be an integer. If it is a negative number then simply place a minus sign in front of the output string. Output will be a string with each digit of the input represented as 4 bits (0 padded) with a space between each set of 4 bits.

Ex.

n =  10 -> "0001 0000"
n = -10 -> "-0001 0000"

*/

fn main() {
    assert_eq!(bcd(10), "0001 0000");
    assert_eq!(bcd(-10), "-0001 0000");
    assert_eq!(bcd(5), "0101");
    assert_eq!(bcd(91), "1001 0001");
}

fn bcd(mut value: isize) -> String {
    let mut sign = "";
    if value < 0 {
        sign = "-";
        value = -value;
    }

    let mut result = format!("");
    loop {
        result = format!("{:04b} {result}", value % 10);
        value /= 10;
        if value == 0 {
            break;
        }
    }
    result = format!("{sign}{}", result.trim());
    result
}
