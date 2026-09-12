/*

Four Seven
Simple kata, simple rules: your function should accept the inputs 4 and 7. If 4 is entered, the function should return 7. If 7 is entered, the function should return 4. Anything else entered as input should return a false-y value such as False, 0, [], "". There's only one catch, your function cannot include if statements (or the eval function due to the fact that you can get around the if requirement using it).

There are some very simple ways of answering this problem, but I encourage you to try and be as creative as possible.

Good Luck!

*/

fn main() {
    assert_eq!(f(4), Ok(7));
    assert_eq!(f(7), Ok(4));
    assert_eq!(f(1), Err(false));
}

fn f(x: isize) -> Result<isize, bool> {
    match x {
        4 => Ok(7),
        7 => Ok(4),
        _ => Err(false),
    }
}
