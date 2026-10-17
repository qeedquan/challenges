/*

This kata is about converting numbers to their binary or hexadecimal representation:

If a number is even, convert it to binary.
If a number is odd, convert it to hex.
Numbers will be positive. The hexadecimal string should be lowercased.

*/

fn main() {
    assert_eq!(evens_and_odds(2), "10");
    assert_eq!(evens_and_odds(13), "d");
    assert_eq!(evens_and_odds(47), "2f");
    assert_eq!(evens_and_odds(0), "0");
    assert_eq!(evens_and_odds(12800), "11001000000000");
    assert_eq!(evens_and_odds(8172381723), "1e71ca61b");
}

fn evens_and_odds(n: isize) -> String {
    if n % 2 == 0 {
        format!("{:b}", n)
    } else {
        format!("{:x}", n)
    }
}
