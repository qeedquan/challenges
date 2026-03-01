/*

Your task
In your language of choice: create a program that outputs 1

This 1 may either be a string or value equivalent to the number one.

The shifting catch
If you take the unicode codepoint (or whatever codepoint encoding your languages uses if not UTF) for each character in your program, and shift each of those values by the same non-zero amount, then the result will be another program (potentially executable in different language) that also outputs 1.

Find the unicode codepoint of a character: here.

E.g;

If your program looked like: X?$A, and somehow output 1, and it also miraculously outputs 1 after shifting all of it's Unicode indices up by, say, 10; then that process of shifting looks like this:

original program: X?$A

letter    codepoint  shift   new-codepoint   new-letter

X            88       +10        98          b   
 ?           63                  73          I
  $          36                  46          .
   A         65                  75          K

new program: BI.K
Note: The Unicode codepoint will often be represented in the form similar to U+0058. 58 is the hexadecimal codepoint . In decimal, that's 88. The link above will list 88 under the UTF (decimal) encoding section. That is the number you want to increment or decrement!

Examples of valid outputs
1
"1"
'1'
[1]
(1)
1.0
00000001
one
Note: If your language only supports the output of true as an equivalent to 1, that is acceptable. Exit-codes are also valid outputs.

Scoring
This is code-golf, so lowest bytes wins!
Brownie points for creativity & if the two programs are in separate languages.

*/

print(1)
