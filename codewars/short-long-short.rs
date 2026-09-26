/*

Given 2 strings, a and b, return a string of the form short+long+short, with the shorter string on the outside
and the longer string on the inside. The strings will not be the same length, but they may be empty ( zero length ).

For example: **(Input1, Input2) --> output**

(\"1\", \"22\") --> \"1221\"
(\"22\", \"1\") --> \"1221\"

ShortLongShort.solution(\"1\", \"22\"); // returns \"1221\"
ShortLongShort.solution(\"22\", \"1\"); // returns \"1221\"

*/

fn main() {
    assert_eq!(solution("a", "bb"), "abba");
    assert_eq!(solution("aa", "b"), "baab");
    assert_eq!(solution("", "aa"), "aa");
    assert_eq!(solution("bb", ""), "bb");
}

fn solution(a: &'static str, b: &'static str) -> String {
    if a.len() < b.len() {
        return format!("{a}{b}{a}");
    }
    return format!("{b}{a}{b}");
}
