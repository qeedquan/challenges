/*

Check if it is a vowel(a, e, i, o, u,) on the n position in a string (the first argument). Don't forget about uppercase.

A few cases:

{
checkVowel('cat', 1)  ->   true // 'a' is a vowel
checkVowel('cat', 0)  ->   false // 'c' is not a vowel
checkVowel('cat', 4)  ->   false // this position doesn't exist
}

P.S. If n < 0, return false

*/

fn main() {
    assert_eq!(check_vowel("cat", 1), true);
    assert_eq!(check_vowel("cat", 0), false);
    assert_eq!(check_vowel("cat", 4), false);
}

fn check_vowel(string: &'static str, position: usize) -> bool {
    let mut chars = string.chars();
    if let Some(symbol) = chars.nth(position) {
        match symbol {
            'a' | 'e' | 'i' | 'o' | 'u' | 'A' | 'E' | 'I' | 'O' | 'U' => return true,
            _ => (),
        }
    }
    return false;
}
