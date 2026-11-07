/*

Task
The function is given a non-empty balanced parentheses string. Each opening '(' has a corresponding closing ')'.
Compute the total score based on the following rules:

Substring s == () has score 1, so "()" should return 1
Substring s1s2 has total score as score of s1 plus score of s2, so "()()" should return 1 + 1 = 2
Substring (s) has total score as two times score of s, so "(())" should return 2 * 1 = 2

Return the total score as an integer.

Examples
eval_parentheses("()") ➞ 1
# 1

eval_parentheses("(())") ➞ 2
# 2 * 1

eval_parentheses("()()") ➞ 2
# 1 + 1

eval_parentheses("((())())") ➞ 6
# 2 * (2 * 1 + 1)

eval_parentheses("(()(()))") ➞ 6
# 2 * (1 + 2 * 1)

eval_parentheses("()(())") ➞ 3
# 1 + 2 * 1

eval_parentheses("()((()))") ➞ 5
# 1 + 2 * 2 * 1

*/

use std::cmp::max;

fn main() {
    assert_eq!(eval("()"), 1);
    assert_eq!(eval("(())"), 2);
    assert_eq!(eval("()()"), 2);
    assert_eq!(eval("((())())"), 6);
    assert_eq!(eval("(()(()))"), 6);
    assert_eq!(eval("()(())"), 3);
    assert_eq!(eval("()((()))"), 5);
}

fn eval(s: &'static str) -> isize {
    let mut p = vec![];
    for c in s.chars() {
        match c {
            '(' => p.push(0),

            ')' => {
                let mut x = 0;
                while p.len() > 0 {
                    let y = p.pop().unwrap();
                    x += y;
                    if y == 0 {
                        break;
                    }
                }
                p.push(max(2 * x, 1));
            }

            _ => (),
        }
    }

    let mut r = 0;
    for x in p {
        r += x;
    }

    r
}
