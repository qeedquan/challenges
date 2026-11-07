/*

Input: A string, can be multi-line. The newlines must to be real newline (e.g., you cannot request that each newline be (n)). There is another input, a number (not a string of repeated spaces) of spaces for indentation.

Output: Exactly the same text, however each line must be indented only the specified number of spaces - not less and not more.

Example #1
Input:

            This line is too much indented.
This isn't indented at all.
  This is a little bit indented.
                                         Too much indention!
and 4

Output:

    This line is too much indented.
    This isn't indented at all.
    This is a little bit indented.
    Too much indention!
In this example, every line must start with only 4 spaces.

Example #2
Input:

    function greet(user) {
// Poorly indented
            if (!user) {throw "There is no username input."} else
        {return 'Hello, '+user+'!`}
 }
and 2

Output:

  function greet(user) {
  // Poorly indented
  if (!user) {throw "There is no username input."} else
  {return 'Hello, '+user+'!`}
  }
Rules
This is code-golf, shortest code1 per language wins!
Markup (e.g., HTML) languages, or languages without output/input support are banned.
This can be a full program, a function or a function expression4.
Cheating languages for zero-size programs like MetaGolfScript are banned.
If a language includes a built-in function that can directly solve this problem, you must implement it manually instead.
All loopholes forbidden by default are included (banned) in this question.
The code should run without internet connection. You cannot cheat by fetching from a site that does this for you.
Programs must not use self-modifying code or undefined behaviors to shorten the solution artificially.
Programs must have clear input-output behavior. Solutions cannot rely on hidden side effects or unusual language behavior to compute results.
You cannot use tricks to compress your code2.
No depending on execution time or system date/time to manipulate the result.
Example: Using System.currentTimeMillis() % 2 == 0 as your answer is not valid.
Never use AI (e.g., ChatGPT) to create code. LLMs are rarely clear. AI-generated code is extremely likely to be invalid.
You should only trim the left side of string. You cannot trim the right side.
Answer Header Format
Normally, make your answer start with:

# <lang-name>, <byte-count> bytes

Where <lang-name> is the name of language and <byte-count> is number of bytes your code used.

If you have multiple files for correct code execution, you must sum the number of bytes in all files you need and use this sum instead of length of code in the answer header.

If you improved this answer (decreased code length), you can keep old scores in header, by using striking out the old scores in header with <s> and </s> HTML tags.
For example, if old code was 156 bytes and new improved code is 133 bytes, you can use this header if want:
# <lang-name>, <s>156</s> 133 bytes

If your code requires a compiler flag or footer/header, you need to add your code's length (plus other files' lengths, if need) to the length of entire compiler flags, header, and footer of the code. So if your code needs -s flag and foo() footer, you add your code length by 7 bytes, since -s is 2 bytes, foo() is 5 bytes and 2+5 = 7.

1: Rankings are based on number of bytes, not characters. Ultragolf is a good example which number of bytes in an ultragolf code is more than characters.

2: Unless your language uses golfing syntax like GolfScript. But if you first decode zipped data then execute it, this is banned.

3: You can use your language unicode format or codepage.

4: For example, on JavaScript a function could be something like function G(t,s){...} while a function expression could be something like (t,s)=>{...}.

*/

function flatten(string, indent) {
	return string.replace(/^ */gm, "".padEnd(indent));
}

console.log(flatten(`
            This line is too much indented.
This isn't indented at all.
  This is a little bit indented.
                                         Too much indention!
`, 4));

console.log(flatten(`
    function greet(user) {
// Poorly indented
            if (!user) {throw "There is no username input."} else
        {return 'Hello, '+user+'!'}
 }`, 2));
