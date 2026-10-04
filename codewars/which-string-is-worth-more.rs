/*

You will be given two ASCII strings, a and b. Your task is write a function to determine which one of these strings is "worth" more, and return it.

A string's worth is determined by the sum of its ASCII codepoint indexes. So, for example, the string HELLO has a value of 372: H is codepoint 72, E 69, L 76, and O is 79. The sum of these values is 372.

In the event of a tie, you should return the first string, i.e. a.

*/

fn main() {
    assert_eq!(highest_value("HELLO", "X"), "HELLO");
}

fn highest_value(string0: &'static str, string1: &'static str) -> &'static str {
    let (mut value0, mut value1) = (0, 0);
    for symbol in string0.chars() {
        value0 += symbol as isize;
    }
    for symbol in string1.chars() {
        value1 += symbol as isize;
    }

    if value0 >= value1 {
        string0
    } else {
        string1
    }
}
