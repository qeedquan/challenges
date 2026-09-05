/*

The shortest reliable password testing code
Introduction

I started playing Empire of Code recently, and there was some challenge. The player is supposed to write a piece of Python or Javascript code to detect if the string passed to it is reliable password, that is, it contains at least one lowercase Latin letter, one uppercase Latin letter and one digit and has at least 10 characters.

It was quite easy for me to fit within the 130 characters limit for rank 3 using Javascript, however, I spent a lot of time trying to fit within the 100 characters limit for rank 3 using Python. Some guy said that he has managed to fit in 71 characters for Python. I tried hard but still couldn't reduce the code to less than 90 characters. Is it possible to use even less than 71 characters?

Winning condition: The shortest Python code (or Javascript), which solves given problem, wins. You may assume whatever was assumed in the original problem description in the game, given below.

Remark: The solution should define a function or method called "golf" which takes the password as the first parameter and returns a boolean value indicating whether the given password satisfies the criterion.

Challenge Vault Password
[The following description is merged from two versions of the problem description (for Python and for Javascript), copied from the game site https://empireofcode.com/ ]

We've installed a new vault to contain our valuable resources and treasures, but before we can put anything into it, we need a suitable password for our new vault. One that should be as safe as possible.

The password will be considered strong enough if its length is greater than or equal to 10 characters, it contains at least one digit, as well as at least one uppercase letter and one lowercase letter. The password may only contain ASCII latin letters or digits, no punctuation symbols.

You are given a password. We need your code to verify if it meets the conditions for a secure password.

In this mission the main goal to make your code as short as possible. The shorter your code, the more points you earn. Your score for this mission is dynamic and directly related to the length of your code.

Input: A password as a string.

Output: A determination if the password safe or not as a boolean, or any data type that can be converted and processed as a boolean. When the results process, you will see the converted results.

Example:

golf('A1213pokl') === false

golf('bAse730onE') === true

golf('asasasasasasasaas') === false

golf('QWERTYqwerty') === false

golf('123456123456') === false

golf('QwErTy911poqqqq') === true

Precondition:

0 < |password| ≤ 64

The password matches the regexp expression "[a-zA-Z0-9]+"

Scoring:

Scoring in this mission is based on the number of characters used in your code (comment lines are not counted).

Rank1:

Any code length.

Rank2:

Your code should be shorter than 230 characters for Javascript code or shorter than 200 characters for Python code.

Rank3:

Your code should be shorter than 130 characters for Javascript code or shorter than 100 characters for Python code.

*/

fn main() {
    assert_eq!(safe("A1213pokl"), false);
    assert_eq!(safe("bAse730onE"), true);
    assert_eq!(safe("asasasasasasasaas"), false);
    assert_eq!(safe("QWERTYqwerty"), false);
    assert_eq!(safe("123456123456"), false);
    assert_eq!(safe("QwErTy911poqqqq"), true);
}

fn safe(password: &'static str) -> bool {
    let mut mask = 0;
    let mut length = 0;
    for symbol in password.chars() {
        match symbol {
            '0'..='9' => mask |= 0x1,
            'a'..='z' => mask |= 0x2,
            'A'..='Z' => mask |= 0x4,
            _ => (),
        }
        length += 1;
    }
    mask == 0x7 && length >= 10
}
