/*

The string consists of lowercase Latin letters and spaces. Double all the vowels in the string, specifically the letters a,e,i,o,u and y.

Input
One line containing only lowercase Latin letters and spaces. The length of the string does not exceed 1000 characters.

Output
Print the string with all the vowels doubled.

Examples

Input #1
welcome to python

Answer #1
weelcoomee too pyythoon

*/

fn main() {
    assert_eq!(solve("welcome to python"), "weelcoomee too pyythoon");
}

fn solve(input: &'static str) -> String {
    let mut output = String::new();
    for symbol in input.chars() {
        output.push(symbol);
        if isvowel(symbol) {
            output.push(symbol);
        }
    }
    output
}

fn isvowel(symbol: char) -> bool {
    match symbol {
        'a' | 'e' | 'i' | 'o' | 'u' | 'y' => true,
        _ => false,
    }
}
