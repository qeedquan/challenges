/*

Write an algorithm that will identify valid IPv4 addresses in dot-decimal format. IPs should be considered valid if they consist of four octets, with values between 0 and 255, inclusive.

Valid inputs examples:
Examples of valid inputs:
1.2.3.4
123.45.67.89

Invalid input examples:
1.2.3
1.2.3.4.5
123.456.78.90
123.045.067.089

Notes:
Leading zeros (e.g. 01.02.03.04) are considered invalid
Inputs are guaranteed to be a single string

*/

fn main() {
    assert_eq!(validip("1.2.3.4"), true);
    assert_eq!(validip("123.45.67.89"), true);
    assert_eq!(validip("123.45.67.90"), true);
    assert_eq!(validip("0.0.0.0"), true);
    assert_eq!(validip("255.255.255.255"), true);

    assert_eq!(validip("1.2.3"), false);
    assert_eq!(validip("1.2.3.4.5"), false);
    assert_eq!(validip("123.456.78.90"), false);
    assert_eq!(validip("123.045.067.089"), false);
    assert_eq!(validip("123123.145.2222222222222222222222.9284824"), false);
}

fn validip(ip: &'static str) -> bool {
    let mut fields = 0;
    for string in ip.split(".") {
        let value = parse(string, 255);
        if !(0 <= value && value <= 255) {
            return false;
        }
        fields += 1;
    }
    return fields == 4;
}

fn parse(string: &'static str, limit: isize) -> isize {
    if string == "0" {
        return 0;
    }

    let mut value = 0;
    let mut once = false;
    for ch in string.chars() {
        if !ch.is_ascii_digit() || (ch == '0' && !once) || value > limit {
            return -1;
        }

        value = (value * 10) + (ch as isize - 0x30);
        once = true;
    }
    return value;
}
