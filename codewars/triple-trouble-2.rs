/*

Triple Trouble
Create a function that will return a string that combines all of the letters of the three inputed strings in groups. Taking the first letter of all of the inputs and grouping them next to each other. Do this for every letter, see example below!

E.g. Input: "aa", "bb" , "cc" => Output: "abcabc"

Note: You can expect all of the inputs to be the same length.

*/

fn main() {
    assert_eq!(triple_trouble("aa", "bb", "cc"), "abcabc");
    assert_eq!(triple_trouble("aaa", "bbb", "ccc"), "abcabcabc");
    assert_eq!(
        triple_trouble("aaaaaa", "bbbbbb", "cccccc"),
        "abcabcabcabcabcabc"
    );
    assert_eq!(triple_trouble("burn", "reds", "roll"), "brrueordlnsl");
    assert_eq!(triple_trouble("Sea", "urn", "pms"), "Supermans");
    assert_eq!(triple_trouble("LLh", "euo", "xtr"), "LexLuthor");
}

fn triple_trouble(one: &'static str, two: &'static str, three: &'static str) -> String {
    let mut result = String::new();
    let mut streams = [one.chars(), two.chars(), three.chars()];
    'outer: loop {
        for stream in &mut streams {
            let symbol = stream.next();
            if symbol == None {
                break 'outer;
            }
            result.push(symbol.unwrap());
        }
    }
    result
}
