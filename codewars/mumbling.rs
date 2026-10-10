/*

This time no story, no theory. The examples below show you how to write function accum:

Examples:
accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"
The parameter of accum is a string which includes only letters from a..z and A..Z.

*/

fn main() {
    assert_eq!(mumble("abcd"), "A-Bb-Ccc-Dddd");
    assert_eq!(mumble("RqaEzty"), "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy");
    assert_eq!(mumble("cwAt"), "C-Ww-Aaa-Tttt");
}

fn mumble(input: &'static str) -> String {
    let mut output = String::new();
    let mut index = 0;
    for symbol in input.chars() {
        let upper = symbol.to_ascii_uppercase();
        let lower = symbol.to_ascii_lowercase();
        output.push(upper);
        for _ in 0..index {
            output.push(lower);
        }
        output.push('-');
        index += 1;
    }
    if output != "" {
        output.pop();
    }
    output
}
