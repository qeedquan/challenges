/*

Sona is in her house with her 10 year old daughter. She needs to go to school to bring back another child from school, as school is over at 2 pm. It's hot outside, so she wants to leave her younger child at home.

She gave a bunch of strings to her child to keep her busy while she is gone. She asked her to reverse the words in the string. There are lot of strings, so you need to help her daughter in solving this huge task.

So, given a string that contains words separated by single space, reverse the words in the string. You can assume that no leading or trailing spaces are there.

The string will only contain [a-zA-z ], so you don't need to handle punctuation.

You will be given a string as an input, and you should output a string.

Sample Test Cases:
Input:
Man bites dog

Output:
dog bites Man


Input:
The quick brown fox jumps over the lazy dog

Output:
dog lazy the over jumps fox brown quick The


Input:
Hello world

Output:
world Hello
Scoring
This is code-golf. Shortest answer in bytes wins.

*/

fn main() {
    assert_eq!(reverse_words("Man bites dog"), "dog bites Man");
    assert_eq!(
        reverse_words("The quick brown fox jumps over the lazy dog"),
        "dog lazy the over jumps fox brown quick The"
    );
    assert_eq!(reverse_words("Hello world"), "world Hello");
}

fn reverse_words(text: &'static str) -> String {
    let mut result = format!("");
    let mut space = "";
    for word in text.split(" ") {
        result = format!("{word}{space}{result}");
        space = " ";
    }
    result
}
