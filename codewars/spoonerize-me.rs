/*

A spoonerism is a spoken phrase in which the first letters of two of the words are swapped around, often with amusing results.

In its most basic form a spoonerism is a two word phrase in which only the first letters of each word are swapped:

"not picking" --> "pot nicking"

Your task is to create a function that takes a string of two words, separated by a space: words and returns a spoonerism of those words in a string, as in the above example. A "word" in the context of this kata can contain any of the letters A through Z in upper or lower case, and the numbers 0 to 9. Though spoonerisms are about letters in words in the domain of written and spoken language, numbers are included in the inputs for the random test cases and they require no special treatment.

NOTE: All input strings will contain only two words. Spoonerisms can be more complex. For example, three-word phrases in which the first letters of the first and last words are swapped: "pack of lies" --> "lack of pies" or more than one letter from a word is swapped: "flat battery --> "bat flattery" You are NOT expected to account for these, or any other nuances involved in spoonerisms.

*/

fn main() {
    assert_eq!(spoonerize("not picking"), "pot nicking");
}

fn spoonerize(string: &'static str) -> String {
    let mut fields = string.split(' ');
    let word0 = fields.next();
    let word1 = fields.next();
    if word0 == None || word1 == None {
        return format!("{string}");
    }

    let word0 = word0.unwrap();
    let word1 = word1.unwrap();

    let mut chars0 = word0.chars();
    let mut chars1 = word1.chars();
    let char0 = chars0.next();
    let char1 = chars1.next();
    if char0 == None || char1 == None {
        return format!("{string}");
    }

    let char0 = char0.unwrap();
    let char1 = char1.unwrap();

    format!("{}{} {}{}", char1, chars0.as_str(), char0, chars1.as_str())
}
