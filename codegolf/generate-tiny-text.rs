/*

Challenge
Your program needs to take an input of a string, where the string has only letters, no special characters, no numbers, and no accents (they look all weird).

Then, your program should output a superscript version.

Example
Input: hello world

Output: ʰᵉᶫᶫᵒ ʷᵒʳᶫᵈ

Test Cases
hello - ʰᵉᶫᶫᵒ
code - ᶜᵒᵈᵉ
golf - ᵍᵒᶫᶠ
asdf - ᵃˢᵈᶠ
qwerty - ᑫʷᵉʳᵗʸ
abcdefghijklmnopqrstuvwxyz - ᵃᵇᶜᵈᵉᶠᵍʰᶦʲᵏᶫᵐᶰᵒᵖᑫʳˢᵗᵘᵛʷˣʸᶻ
Help
If you need help understanding check out this website, it's a translator: http://txtn.us/tiny-text

Code Golf
This is a code golf, so the shortest code wins!

Good luck!

Edits
Edit #1: There will be no caps, since I just realized they look weird.

*/

fn main() {
    assert_eq!(tinytext("hello"), "ʰᵉᶫᶫᵒ");
    assert_eq!(tinytext("code"), "ᶜᵒᵈᵉ");
    assert_eq!(tinytext("golf"), "ᵍᵒᶫᶠ");
    assert_eq!(tinytext("asdf"), "ᵃˢᵈᶠ");
    assert_eq!(tinytext("qwerty"), "ᑫʷᵉʳᵗʸ");
    assert_eq!(
        tinytext("abcdefghijklmnopqrstuvwxyz"),
        "ᵃᵇᶜᵈᵉᶠᵍʰᶦʲᵏᶫᵐᶰᵒᵖᑫʳˢᵗᵘᵛʷˣʸᶻ"
    );
}

fn tinytext(s: &'static str) -> String {
    let tiny = vec![
        'ᵃ', 'ᵇ', 'ᶜ', 'ᵈ', 'ᵉ', 'ᶠ', 'ᵍ', 'ʰ', 'ᶦ', 'ʲ', 'ᵏ', 'ᶫ', 'ᵐ', 'ᶰ', 'ᵒ', 'ᵖ', 'ᑫ', 'ʳ',
        'ˢ', 'ᵗ', 'ᵘ', 'ᵛ', 'ʷ', 'ˣ', 'ʸ', 'ᶻ',
    ];

    let (s0, e0) = ('A' as usize, 'Z' as usize);
    let (s1, e1) = ('a' as usize, 'z' as usize);

    let mut r = format!("");
    for c in s.chars() {
        let i = c as usize;
        if s0 <= i && i <= e0 {
            r = format!("{r}{}", tiny[i - s0]);
        } else if s1 <= i && i <= e1 {
            r = format!("{r}{}", tiny[i - s1]);
        } else {
            r = format!("{r}{c}");
        }
    }
    r
}
