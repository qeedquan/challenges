/*

Write a function

titleToNumber(title) or title_to_number(title) or titleToNb title ...

(depending on the language)

that given a column title as it appears in an Excel sheet, returns its corresponding column number. All column titles will be uppercase.

Examples:

titleTonumber('A') === 1
titleTonumber('Z') === 26
titleTonumber('AA') === 27

Note for Clojure:
Don't use Java Math/pow (even with bigint) because there is a loss of precision
when the length of "title" is growing.
Write your own function "exp [x n]".

*/

fn main() {
    assert_eq!(sheet2num("A"), 1);
    assert_eq!(sheet2num("Z"), 26);
    assert_eq!(sheet2num("AA"), 27);
    assert_eq!(sheet2num("AZ"), 52);
    assert_eq!(sheet2num("BA"), 53);
    assert_eq!(sheet2num("CODEWARS"), 28779382963);
}

fn sheet2num(s: &'static str) -> usize {
    let mut r = 0;
    for c in s.chars() {
        r = (r * 26) + (c as usize - 65) + 1;
    }
    r
}
