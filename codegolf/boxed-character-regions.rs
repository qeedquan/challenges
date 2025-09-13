/*

Given an input string, determine the number of regions that a page will be split into.

Consider the letter P. It has one enclosed region within the letter. Assume that each letter splits the page by one or more regions (i.e. a box is drawn around the character).

Input
A string of 0 or more characters. You may assume that the string contains only characters from the following sets:

+0 regions: Spaces , tabs \t, and new lines \n
+1 region: CEFGHIJKLMNSTUVWXYZcfhijklmnrstuvwxyz12357~!^*()-_=+[]{}\'|:;",.?/<>
+2 regions:ADOPQRabdeopq469@#
+3 regions: Bg08$%&
You may take the input as a function argument, standard input, command-line argument, whatever works best for your language.

Output
An integer representing the number of regions split by the given input. Output can be a return value or standard output (but not stderr).

This is code-golf, so shortest solution in bytes win.

Test cases
(empty string or only whitespace) === 1
-1 === 3
100% === 11
Hello world! === 16
May the force be with you === 28
do {$busTickets-=2;} while ($transit != false) === 54
return @$_GET['foo'] ?? $$var % $var || $g8 << ; //# Syntax error === 80
Feel free to use the demo in my JavaScript answer (with a compatible browser of course) to run test cases.

Visual representation
Note: The visual representation for the characters g and 0 (zero) may not be entirely correct depending on the monospaced font that your computer has installed.

For the purposes of this challenge, assume that the bottom of the g has a closed loop and the 0 has a slash through it.

*/

fn main() {
    assert_eq!(regions(""), 1);
    assert_eq!(regions("-1"), 3);
    assert_eq!(regions("100%"), 11);
    assert_eq!(regions("Hello world!"), 16);
    assert_eq!(regions("May the force be with you"), 28);
    assert_eq!(
        regions("do {$busTickets-=2;} while ($transit != false)"),
        54
    );
    assert_eq!(
        regions("return @$_GET['foo'] ?? $$var % $var || $g8 << ; //# Syntax error"),
        80
    );
}

fn regions(s: &'static str) -> isize {
    let r1 = r#"CEFGHIJKLMNSTUVWXYZcfhijklmnrstuvwxyz12357~!^*()-_=+[]{}\'|:;",.?/<>"#;
    let r2 = "ADOPQRabdeopq469@#";
    let r3 = "Bg08$%&";

    let mut r = 1;
    for c in s.chars() {
        if r1.contains(c) {
            r += 1;
        } else if r2.contains(c) {
            r += 2;
        } else if r3.contains(c) {
            r += 3;
        }
    }
    r
}
