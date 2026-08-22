/*

Write a function that takes a string and an an integer n as parameters and returns a list of all words that are longer than n.

Example:

* With input "The quick brown fox jumps over the lazy dog", 4
* Return ['quick', 'brown', 'jumps']

*/

fn main() {
    assert_eq!(
        filter_long_words("The quick brown fox jumps over the lazy dog", 4),
        vec!["quick", "brown", "jumps"]
    );
}

fn filter_long_words(sentence: &'static str, length: usize) -> Vec<&'static str> {
    let mut result = vec![];
    for string in sentence.split(" ") {
        if string.len() > length {
            result.push(string);
        }
    }
    result
}
