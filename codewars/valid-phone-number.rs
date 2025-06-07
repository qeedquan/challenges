/*

Write a function that accepts a string, and returns true if it is in the form of a phone number.
Assume that any integer from 0-9 in any of the spots will produce a valid phone number.

Only worry about the following format:
(123) 456-7890   (don't forget the space after the close parentheses)

Examples:

validPhoneNumber("(123) 456-7890")  =>  returns true
validPhoneNumber("(1111)555 2345")  => returns false
validPhoneNumber("(098) 123 4567")  => returns false

*/

fn main() {
    assert_eq!(valid("(123) 456-7890"), true);
    assert_eq!(valid("(1111)555 2345"), false);
    assert_eq!(valid("(098) 123 4567"), false);
}

fn valid(p: &'static str) -> bool {
    let mut s0 = "(xxx) xxx-xxxx".chars();
    let mut s1 = p.chars();
    loop {
        let c0 = s0.next();
        let c1 = s1.next();
        if c0 == None || c1 == None {
            return c0 == c1;
        }

        let c0 = c0.unwrap();
        let c1 = c1.unwrap();
        if c0 == 'x' {
            if !c1.is_digit(10) {
                return false;
            }
        } else if c0 != c1 {
            return false;
        }
    }
}
