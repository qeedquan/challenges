/*

Write function RemoveExclamationMarks which removes all exclamation marks from a given string.

*/

fn main() {
    assert_eq!(rm("a!!!b"), "ab");
}

fn rm(s: &'static str) -> String {
    format!("{}", s.replace("!", ""))
}
