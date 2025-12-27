/*

Draw an ASCII-art rainbow!

Input
An integer between 0 and 1000, inclusive.

Examples
Input 0:


/\
||
Input 1:

 _
/ \
| |
Input 2:

 __
/  \
|  |
Input 3:

 ___
/   \
|   |
The first row is a space followed by n underscores.

The second row is a slash followed by n spaces, and a backslash.

The third row is a pipe followed by n spaces, and a pipe.

Trailing spaces are allowed.

This is code-golf. Shortest code wins.

*/

fn main() {
    for i in 0..11 {
        println!("n={}", i);
        println!("{}", rainbow(i));
        println!();
    }
}

fn rainbow(n: usize) -> String {
    let mut r = String::new();
    r.push_str(" ");
    r.push_str(&"_".repeat(n));
    r.push_str("\n/");
    r.push_str(&" ".repeat(n));
    r.push_str("\\\n|");
    r.push_str(&" ".repeat(n));
    r.push_str("|");
    r
}
