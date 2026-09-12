/*

Your function fizznotbuzz is given a set of strings. Return True if the set contains the string fizz and does not contain the string buzz. Otherwise return False.

*/

fn main() {
    assert_eq!(fizznotbuzz(&vec!["fizz", "buzz"]), false);
    assert_eq!(fizznotbuzz(&vec!["fizz"]), true);
    assert_eq!(fizznotbuzz(&vec!["x", "y", "z"]), false);
}

fn fizznotbuzz(words: &Vec<&'static str>) -> bool {
    let mut found = false;
    for &word in words {
        match word {
            "fizz" => found = true,
            "buzz" => return false,
            _ => (),
        }
    }
    found
}
