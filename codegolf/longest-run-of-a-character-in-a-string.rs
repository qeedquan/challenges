/*

Your challenge: Write a function that takes a string s, a character c, and finds the length of the longest run of c in s. The length of the run will be l.

Rules:

If s is of length 0 or c is empty, l should be 0.
If there are no instances of c in s, l should be 0.
Standard loopholes and Standard I/O Rules apply.
No matter where in s the run of cs is located, l should be the same.
Any printable ASCII characters can appear in s and c.
Test cases:

s,c --> l
"Hello, World!",'l'  -->  2
"Foobar",'o'         -->  2
"abcdef",'e'         -->  1
"three   spaces",' ' -->  3
"xxx xxxx xx",'x'    -->  4
"xxxx xx xxx",'x'    -->  4
"",'a'               -->  0
"anything",''        -->  0
Winner:

As with code-golf the shortest answer in each language wins.

*/

use std::cmp::*;

fn main() {
    assert_eq!(runs("Hello, World!", 'l'), 2);
    assert_eq!(runs("Foobar", 'o'), 2);
    assert_eq!(runs("abcdef", 'e'), 1);
    assert_eq!(runs("three   spaces", ' '), 3);
    assert_eq!(runs("xxx xxxx xx", 'x'), 4);
    assert_eq!(runs("", 'a'), 0);
    assert_eq!(runs("anything", '\0'), 0);
}

fn runs(s: &'static str, c: char) -> usize {
    let (mut r, mut l) = (0, 0);
    for nc in s.chars() {
        if c == nc {
            l += 1;
            r = max(r, l);
        } else {
            l = 0;
        }
    }
    r
}
