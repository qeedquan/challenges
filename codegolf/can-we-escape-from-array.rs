/*

Can we escape from the array?
Input: A non-empty array of non-negative integers (without nesting1).

Output: A boolean value2 indicating whether we can reach the end of the array when starting from the first element and moving n positions forward, where n is the value of the current cell. Upon reaching a new cell, the same rule is applied.

True: Following this rule allows us to reach the end of the array.
False: Following this rule results in an infinite loop, preventing us from reaching the end.
Tip: Reaching an element with a value of 0 prevents progress since moving 0 positions forward keeps us at the same element indefinitely.

Example #1
Input: [1]

Output: true3

Why: The first element is 1, meaning we move 1 step forward and immediately reach the end of the array.

Example #2
Input: [1,4,0]

Output: true3

Why:

We start at first cell which is 1, moving 1 step forward.

We're now on next cell, and after moving 4 steps forward—this goes beyond the array, meaning we have successfully escaped.

Example #3
Input: [0,4,1,78,2]

Output: false3

Why: The first element is 0, meaning we move 0 steps forward and remain in the same position, a infinite loop.

Rules
This is code-golf, shortest code4 per language wins!
You don't need to handle empty loops.
Markup (e.g., HTML) languages, or languages without output/input support are banned.
Cheating languages for zero-size programs like MetaGolfScript and is banned.
If a language includes a built-in function that can directly solve this problem, you must implement it manually instead.
All loopholes forbidden by default is included (banned) in this question.
The code runs without internet connection. Thus you cannot cheat by fetching to a site does it for you.
Programs must not use self-modifying code or undefined behaviors to shorten the solution artificially.
Programs must have clear input-output behavior. Solutions cannot rely on hidden side effects or unusual language behavior5 to compute results.
You cannot use tricks to compress your code6.
No depending on execution time or system date/time to manipulate the result.
Example: Using System.currentTimeMillis() % 2 == 0 as your answer is not valid.
Never use AI (e.g., ChatGPT) to create code. AIs are always rarely clear, and an AI-generated code is extremely likely to be invalid.
Answer Header Format
Normally, make your answer start with:

# <lang-name>, <byte-count> bytes

Where <lang-name> is the name of language and <byte-count> is number of bytes your code used.

If you have multiple files for correct code execution, you must to sum the number of bytes in all files you need and use this sum instead of length of code in answer header.

If you improved this answer (decreased code length), you can keep old scores in header, by using strikeouted old scores in header with <s> and </s> HTML tags.
For example, if old code was 156 bytes and new improved code is 133 bytes, you can use this header if want:
# <lang-name>, <s>156</s> 133 bytes

If your code requires a compiler flag or footer/header, you need to add your code length (plus other files length if need) with length of entire compiler flags and header and footer of code. So if your code needs -s flag and foo() footer, you add your code length by 7 bytes, since -s is 2 bytes, foo() is 5 bytes and 2+5 = 7.

1: Nesting means creating arrays inside array (or "array of arrays"), or even more nested. In this challenge, we won't provide a nested array like [3,[[5],2],4] for example.

2: You're free to use any boolean type, for example you can use true/false, 0/1, yes/no, or anything else you want. If you use a boolean type other than true/false, 0/1 or yes/no, please include what printed for true and false in your answer.

3: This is a example output, you can use a boolean type other than true/false.

4: Rankings are based on number of bytes, not characters. Ultragolf is a good example which number of bytes in a ultragolf code is more than characters.

5: It's allowed to use language errors (e.g., Maximum Recursion Limit Reached), but not using unusual effects and language bugs.

6: Unless your language uses golfing syntax like GolfScript. But if you first decode zipped data then execute it, this is banned.

*/

fn main() {
    assert_eq!(escape(&[1]), true);
    assert_eq!(escape(&[1, 4, 0]), true);
    assert_eq!(escape(&[0, 4, 1, 78, 2]), false);
}

fn escape(a: &[usize]) -> bool {
    let mut i = 0;
    while i < a.len() {
        if a[i] == 0 {
            return false;
        }
        i += a[i];
    }
    return true;
}
