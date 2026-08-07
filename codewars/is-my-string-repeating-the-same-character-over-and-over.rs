/*

Your task is very simple:
Write a function hasOneChar returning:

true if the given string contains the same character repeated all along the string
false otherwise.

For instance:

hasOneChar('aaaaa'); //true
hasOneChar('aaaab'); //false
hasOneChar('bbbbb'); //true
hasOneChar('bbabb'); //false

Of course, what comes in mind first is a loop. But the purpose of this Kata is to test your creativity.
You have to achieve it without using any loops.

Corner cases: the function hasOneChar should return true if the string contains one single character.

Be creative!

*/

fn main() {
    assert_eq!(has_one_char("aaaaa"), true);
    assert_eq!(has_one_char("aaaab"), false);
    assert_eq!(has_one_char("bbbbb"), true);
    assert_eq!(has_one_char("bbabb"), false);
    assert_eq!(has_one_char(""), true);
    assert_eq!(has_one_char("x"), true);
}

fn has_one_char(s: &'static str) -> bool {
    let mut l = s.chars();
    let c = l.next();
    loop {
        let nc = l.next();
        if c == None || nc == None {
            break;
        }
        if c != nc {
            return false;
        }
    }
    return true;
}
