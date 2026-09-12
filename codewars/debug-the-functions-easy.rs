/*

Debug the functions
Should be easy, begin by looking at the code. Debug the code and the functions should work.

There are three functions: Multiplication (x) Addition (+) and Reverse (!esreveR)

*/

fn main() {
    assert_eq!(multi(&[1, 2, 3, 4, 5]), 120);
    assert_eq!(add(&[1, 2, 3, 4, 5]), 15);
    assert_eq!(reverse("hello"), "olleh");
}

fn multi(array: &[isize]) -> isize {
    if array.len() == 0 {
        return 0;
    }
    array.into_iter().fold(1, |acc, e| acc * e)
}

fn add(array: &[isize]) -> isize {
    array.into_iter().fold(0, |acc, e| acc + e)
}

fn reverse(string: &'static str) -> String {
    string.chars().rev().collect::<String>()
}
