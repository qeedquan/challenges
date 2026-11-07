/*

What if we need the length of the words separated by a space to be added at the end of that same word and have it returned as an array?

Example(Input --> Output)

"apple ban" --> ["apple 5", "ban 3"]
"you will win" -->["you 3", "will 4", "win 3"]
Your task is to write a function that takes a String and returns an Array/list with the length of each word added to each element .

Note: String will have at least one element; words will always be separated by a space.

*/

fn main() {
    assert_eq!(add_length("apple ban"), vec!["apple 5", "ban 3"]);
    assert_eq!(add_length("you will win"), vec!["you 3", "will 4", "win 3"]);
}

fn add_length(words: &'static str) -> Vec<String> {
    let mut output = vec![];
    for word in words.split(" ") {
        output.push(format!("{} {}", word, word.len()));
    }
    output
}
