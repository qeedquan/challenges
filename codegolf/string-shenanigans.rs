/*

Challenge
In this challenge, you are to code in any language a program or function that will take a string and replace certain characters within it with different characters.

Input
The input is the same for both functions and full programs:

[string] [char1] [char2]
string will be an indefinite line of characters surrounded by quotation mars, such as "Hello, World!" or "1 plus 2 = 3".

char1 will be a single character within string.

char2 will be a single character not necessarily in string.
Output
[modified string]
Your output will take string and replace all instances of char1 with char2, then output the result as modified string. Case should be ignored, so the input "yolO" o u should output yulu.

Examples
Input

"Hello, World!" l r
Output

Herro, Worrd!
Input

"Slithery snakes slurp Smoothies through Silly Straws" s z
Output

zlithery znakez zlurp zmoothiez through zilly ztrawz
Input

"Grant Bowtie: Only the best future bass artist ever" : -
Output

Grant Bowtie- Only the best future bass artist ever
Input

"019 + 532 * 281 / ? = waht/?" / !
Output

019 + 532 * 281 ! ? = waht!?
Other details
This is code golf, so the shortest answer (in bytes) at the end of the week (the 14th of September) wins. Also, anything not specified in this challenge is fair game, meaning that stuff I don't explain is up to you.

*/

fn main() {
    assert_eq!(replace("Hello, World!", 'l', 'r'), "Herro, Worrd!");
    assert_eq!(
        replace(
            "Slithery snakes slurp Smoothies through Silly Straws",
            's',
            'z'
        ),
        "zlithery znakez zlurp zmoothiez through zilly ztrawz"
    );
    assert_eq!(
        replace(
            "Grant Bowtie: Only the best future bass artist ever",
            ':',
            '-'
        ),
        "Grant Bowtie- Only the best future bass artist ever"
    );
    assert_eq!(
        replace("019 + 532 * 281 / ? = waht/?", '/', '!'),
        "019 + 532 * 281 ! ? = waht!?"
    );
}

fn replace(s: &'static str, a: char, b: char) -> String {
    let mut p = String::new();
    for c in s.chars() {
        if c.to_lowercase().eq(a.to_lowercase()) {
            p.push(b);
        } else {
            p.push(c);
        }
    }
    p
}
