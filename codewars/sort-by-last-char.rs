/*

Given a string of words (x), you need to return an array of the words, sorted alphabetically by the final character in each.

If two words have the same last letter, they returned array should show them in the order they appeared in the given string.

All inputs will be valid.

*/

fn main() {
    assert_eq!(
        last("man i need a taxi up to ubud"),
        vec!["a", "need", "ubud", "i", "taxi", "man", "to", "up"]
    );
    assert_eq!(
        last("what time are we climbing up the volcano"),
        vec!["time", "are", "we", "the", "climbing", "volcano", "up", "what"]
    );
    assert_eq!(
        last("take me to semynak"),
        vec!["take", "me", "semynak", "to"]
    );
}

fn last(string: &'static str) -> Vec<&'static str> {
    let mut words = vec![];
    for word in string.split(" ") {
        words.push(word);
    }
    words.sort_by(|word0, word1| {
        let char0 = word0.chars().last().unwrap();
        let char1 = word1.chars().last().unwrap();
        char0.cmp(&char1)
    });
    words
}
