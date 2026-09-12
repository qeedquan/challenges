/*

Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.

The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.  

Example 1:

Input: n = 4
Output: "pppz"
Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z' occurs once. Note that there are many other valid strings such as "ohhh" and "love".
Example 2:

Input: n = 2
Output: "xy"
Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many other valid strings such as "ag" and "ur".
Example 3:

Input: n = 7
Output: "holasss"
 

Constraints:

1 <= n <= 500

Hint 1
If n is odd, return a string of size n formed only by 'a', else return string formed with n-1 'a' and 1 'b''.

*/

fn main() {
    assert_eq!(gen(4), "aaab");
    assert_eq!(gen(2), "ab");
    assert_eq!(gen(7), "aaaaaaa");
}

fn gen(n: usize) -> String {
    if n == 0 {
        return String::new();
    }

    let mut s = "a".repeat(n - 1);
    if n % 2 != 0 {
        s.push('a');
    } else {
        s.push('b');
    }
    s
}
