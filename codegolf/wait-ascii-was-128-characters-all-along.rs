/*

Challenge
In this challenge, you have to take a nonnegative integer as input, convert it into base-128 bytes (0 → 0x00, 127 → 0x7F, 5,732 → 0x2C 0x64, etc.), and output whether the result only uses printable ASCII (0x20 to 0x7E inclusive).

Test cases
0 --> false (␀)
27 --> false (␛)
32 --> true (␠)
59 --> true (;)
87 --> true (W)
126 --> true (~)
127 --> false (␡)
128 --> false (␁␀)
300 --> false (␂,)
2201 --> false (␑␙)
5732 --> true (,d)
157061374 --> true (Jr!~)
157061375 --> false (Jr!␡)
Specifications
The maximum input you will receive is 4,294,967,295.
You may output any two consistent, distinct values in place of true and false.
You may use a function or a full program.
Standard loopholes and I/O methods apply.

Scoring
This is code-golf, so fewest bytes wins.

*/

fn main() {
    assert_eq!(ascii(0), false);
    assert_eq!(ascii(27), false);
    assert_eq!(ascii(32), true);
    assert_eq!(ascii(59), true);
    assert_eq!(ascii(87), true);
    assert_eq!(ascii(126), true);
    assert_eq!(ascii(127), false);
    assert_eq!(ascii(128), false);
    assert_eq!(ascii(300), false);
    assert_eq!(ascii(2201), false);
    assert_eq!(ascii(5732), true);
    assert_eq!(ascii(157061374), true);
    assert_eq!(ascii(157061375), false);
}

fn ascii(mut n: u128) -> bool {
    loop {
        let c = n % 128;
        if !(0x20 <= c && c <= 0x7e) {
            return false;
        }
        
        n /= 128;
        if n == 0 {
            break;
        }
    }
    return true;
}
