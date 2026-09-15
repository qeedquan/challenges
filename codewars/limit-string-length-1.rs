/*

The function must return the truncated version of the given string up to the given limit followed by "..." if the result is shorter than the original. Return the same string if nothing was truncated.

Example:

solution('Testing String', 3) --> 'Tes...'
solution('Testing String', 8) --> 'Testing ...'
solution('Test', 8)           --> 'Test'

*/

fn main() {
    assert_eq!(solution("Testing String", 3), "Tes...");
    assert_eq!(solution("Testing String", 8), "Testing ...");
    assert_eq!(solution("Test", 8), "Test");
}

fn solution(s: &'static str, n: usize) -> String {
    if n > s.len() {
        return format!("{}", s);
    }
    return format!("{}...", &s[0..n]);
}
