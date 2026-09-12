/*

Remember the spongebob meme that is meant to make fun of people by repeating what they say in a mocking way?

"Dont use that weird spongebob mocking meme" Me: DonT uSe thAt WeIrd SpoNgEboB MoCkinG MEme

You need to create a function that converts the input into this format, with the output being the same string expect there is a pattern of uppercase and lowercase letters.

Example:

input:  "stop Making spongebob Memes!"
output: "StOp mAkInG SpOnGeBoB MeMeS!"

*/

fn main() {
    assert_eq!(spongebob(""), "");

    assert_eq!(
        spongebob("stop Making spongebob Memes!"),
        "StOp mAkInG SpOnGeBoB MeMeS!"
    );

    assert_eq!(spongebob("abcd"), "AbCd");
    assert_eq!(spongebob("a b c d"), "A B C D");
    assert_eq!(spongebob("AB CD EF"), "Ab cD Ef");
}

fn spongebob(string: &'static str) -> String {
    let mut result = String::new();
    let mut index = 0;
    for character in string.chars() {
        if !character.is_ascii() {
            result.push(character);
        } else if (index & 1) != 0 {
            result.push(character.to_ascii_lowercase());
        } else {
            result.push(character.to_ascii_uppercase());
        }
        index ^= 1;
    }
    result
}
