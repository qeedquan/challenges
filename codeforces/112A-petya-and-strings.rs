/*

Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.

Input
Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It is guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.

Output
If the first string is less than the second one, print "-1". If the second string is less than the first one, print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when the strings are compared.

Examples

input
aaaa
aaaA
output
0

input
abs
Abz
output
-1

input
abcdefg
AbCdEfF
output
1

Note
If you want more formal information about the lexicographical order (also known as the "dictionary order" or "alphabetical order"), you can visit the following site:

http://en.wikipedia.org/wiki/Lexicographical_order

*/

fn main() {
    assert_eq!(compare("aaaa", "aaaA"), 0);
    assert_eq!(compare("abs", "Abz"), -1);
    assert_eq!(compare("abcdefg", "AbCdEfF"), 1);
    assert_eq!(compare("hello", "hellox"), -1);
    assert_eq!(compare("helloy", "hello"), 1);
}

fn compare(s: &str, t: &str) -> isize {
    let mut a = s.to_string();
    let mut b = t.to_string();

    a.make_ascii_lowercase();
    b.make_ascii_lowercase();

    if a.eq(&b) {
        0
    } else if a.le(&b) {
        -1
    } else {
        1
    }
}
