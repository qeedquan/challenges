/*

Given a string, return the minimal number of parenthesis reversals needed to make balanced parenthesis.

For example:

solve(")(") = 2 Because we need to reverse ")" to "(" and "(" to ")". These are 2 reversals. 
solve("(((())") = 1 We need to reverse just one "(" parenthesis to make it balanced.
solve("(((") = -1 Not possible to form balanced parenthesis. Return -1.
Parenthesis will be either "(" or ")".

More examples in the test cases.

Good luck.

*/

fn main() {
    assert_eq!(solve(")("), 2);
    assert_eq!(solve("(((())"), 1);
    assert_eq!(solve("((("), -1);
    assert_eq!(solve("())((("), 3);
    assert_eq!(solve("())()))))()()("), 4);
}

fn solve(input: &'static str) -> isize {
    if input.len() % 2 != 0 {
        return -1;
    }

    let (mut open, mut close) = (0, 0);
    for symbol in input.chars() {
        if symbol == '(' {
            close += 1;
        } else if close > 0 {
            close -= 1;
        } else {
            (open, close) = (open + 1, close + 1);
        }
    }
    return open + (close / 2);
}
