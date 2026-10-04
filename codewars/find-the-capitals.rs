/*

Instructions
Write a function that takes a single string (word) as argument. The function must return an ordered list containing the indexes of all capital letters in the string.

Example
Test.assertSimilar( capitals('CodEWaRs'), [0,3,4,6] );

*/

fn main() {
    assert_eq!(capitals("CodEWaRs"), vec![0, 3, 4, 6]);
}

fn capitals(word: &'static str) -> Vec<usize> {
    let mut result = vec![];
    let mut index = 0;
    for ch in word.chars() {
        if ch.is_ascii_uppercase() {
            result.push(index);
        }
        index += 1;
    }
    result
}
