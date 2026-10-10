/*

Description
An anagram is a form of word play, where you take a word (or set of words) and form a different word (or different set of words) that use the same letters, just rearranged. All words must be valid spelling, and shuffling words around doesn't count.

Some serious word play aficionados find that some anagrams can contain meaning, like "Clint Eastwood" and "Old West Action", or "silent" and "listen".

Someone once said, "All the life's wisdom can be found in anagrams. Anagrams never lie." How they don't lie is beyond me, but there you go.

Punctuation, spaces, and capitalization don't matter, just treat the letters as you would scrabble tiles.

Input Description
You'll be given two words or sets of words separated by a question mark. Your task is to replace the question mark with information about the validity of the anagram. Example:

"Clint Eastwood" ? "Old West Action"
"parliament" ? "partial man"
Output Description
You should replace the question mark with some marker about the validity of the anagram proposed. Example:

"Clint Eastwood" is an anagram of "Old West Action"
"parliament" is NOT an anagram of "partial man"
Challenge Input
"wisdom" ? "mid sow"
"Seth Rogan" ? "Gathers No"
"Reddit" ? "Eat Dirt"
"Schoolmaster" ? "The classroom"
"Astronomers" ? "Moon starer"
"Vacation Times" ? "I'm Not as Active"
"Dormitory" ? "Dirty Rooms"
Challenge Output
"wisdom" is an anagram of "mid sow"
"Seth Rogan" is an anagram of "Gathers No"
"Reddit" is NOT an anagram of "Eat Dirt"
"Schoolmaster" is an anagram of "The classroom"
"Astronomers" is NOT an anagram of "Moon starer"
"Vacation Times" is an anagram of "I'm Not as Active"
"Dormitory" is NOT an anagram of "Dirty Rooms"

*/

fn main() {
    assert_eq!(
        anagram(r#""Clint Eastwood" ? "Old West Action""#),
        r#""Clint Eastwood" is an anagram of "Old West Action""#
    );
    assert_eq!(
        anagram(r#""parliament" ? "partial man""#),
        r#""parliament" is NOT an anagram of "partial man""#
    );
    assert_eq!(
        anagram(r#""wisdom" ? "mid sow""#),
        r#""wisdom" is an anagram of "mid sow""#
    );
    assert_eq!(
        anagram(r#""Seth Rogan" ? "Gathers No""#),
        r#""Seth Rogan" is an anagram of "Gathers No""#
    );
    assert_eq!(
        anagram(r#""Reddit" ? "Eat Dirt""#),
        r#""Reddit" is NOT an anagram of "Eat Dirt""#
    );
    assert_eq!(
        anagram(r#""Schoolmaster" ? "The classroom""#),
        r#""Schoolmaster" is an anagram of "The classroom""#
    );
    assert_eq!(
        anagram(r#""Astronomers" ? "Moon starer""#),
        r#""Astronomers" is NOT an anagram of "Moon starer""#
    );
    assert_eq!(
        anagram(r#""Vacation Times" ? "I'm Not as Active""#),
        r#""Vacation Times" is an anagram of "I'm Not as Active""#
    );
    assert_eq!(
        anagram(r#""Dormitory" ? "Dirty Rooms""#),
        r#""Dormitory" is NOT an anagram of "Dirty Rooms""#
    );
}

fn anagram(sentence: &'static str) -> String {
    let mut words = vec![];
    let mut sorted = vec![];
    for token in sentence.split("?") {
        let token = token.trim();
        words.push(token);
        sorted.push(sortword(token));
    }
    if words.len() != 2 {
        return format!("Invalid Input");
    }
    if sorted[0] == sorted[1] {
        return format!("{} is an anagram of {}", words[0], words[1]);
    }
    return format!("{} is NOT an anagram of {}", words[0], words[1]);
}

fn sortword(word: &'static str) -> String {
    let word = word.replace(" ", "");
    let word = word.replace("\"", "");
    let word = word.replace("'", "");
    let word = word.replace(",", "");
    let word = word.replace(".", "");
    let word = word.to_lowercase();

    let mut vec: Vec<char> = word.chars().collect();
    vec.sort_unstable();
    vec.into_iter().collect()
}
