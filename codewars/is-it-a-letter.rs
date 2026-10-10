/*

Write a function, isItLetter or is_it_letter, which tells us if a given character is an, uppercase or lowercase, letter.

*/

fn main() {
    assert_eq!(isletter('a'), true);
    assert_eq!(isletter('1'), false);
}

fn isletter(c: char) -> bool {
    let a = 'a' as u32;
    let z = 'z' as u32;
    let c = c.to_ascii_lowercase() as u32;
    a <= c && c <= z
}
