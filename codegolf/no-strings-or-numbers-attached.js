/*

If you like this, consider participating in:

The Official Dyalog APL 2016 Year Game

The monthly Dyalog APL 2017 Code Golf Challenge

Make 12 snippets/expressions, in the same language, that result in the numbers 0 through 10, and 42 respectively, but without writing any literal numeric, string, or character data.

Build-in data, like PI() and ALPHABET(), are fine, and so are e.g. CJam's U, X, Y, Z, and A constants, and Processing's BLEND, CHORD, CENTER, BREAK, and LINES.

Every snippet must be able to stand on its own, i.e. they may not be interdependent. However, inside a single snippet, you may assign a variable and use it freely, as long as you refer to it directly by name, and not through a string containing its name.

All the snippets must be valid on the submitter’s computer at the time of submission (as reported by SE), but may not rely on unusual local conditions like number of files in a directory, the exact date or time, or specific input from the user.

Examples of valid snippets
3: INT(LOG10(YEAR(TODAY()))) because it remains true in the foreseeable future
4: SQRT(SQRT(LEN(CHARACTERSET()))) because a 256 letter character set is very common
8: SQRT(SYSTEMTYPE()) because 64-bit systems are very common

Examples of invalid snippets
5: LEN(USERNAME()) because most people do not use “Admin” as login :-)
9: LOG10(SYSTEMMEMORY()) because it only works on systems with exactly 1 GB of memory
42: CODE("*") because it contains a string/character literal

The result of each snippet must result in an actual number (value, int, float, etc.) that can be used for further calculations using the same language as the snippet, i.e not a text string representing that number.

Only character based languages allowed.

Score is total byte count of all the 12 snippets combined. Newlines separating the snippets are not counted in.

Note that the above rules may prevent some languages from participating, even if they are Turing complete.

FAQ
Q Can the programs accept any input?
A Yes, but you may not just ask for input and enter the relevant number.

Q Are physical digits (non-data) digits allowed?
A Yes, e.g. LOG10().

Q Do Symbols in Ruby count as literals?
A Yes.

Q Does score include newlines between each snippet?
A No.

Q Is TI-BASIC "character based" enough to be valid?
A Yes.

Q Do false and true count as number literals?
A No, they are acceptable.

Q Can we use a number literal to call a function if that's the only way and the number doesn't influence the output of the function?
A Yes, if that is the normal way to write code in your language.

Q My language assumes there is a [something] at the start of each program/expression. Must I include it, or should my snippets just work if placed in the middle of a program/expression?
A They should just work in the middle of a program/expression.

Q What about regex literals?
A Forbidden, except for languages that only do regexes.

Q Is one piece of code that could print all the specified numbers acceptable?
A No, they have to be separate and mutually independent.

Q May I assume a boilerplate like int main() {}... or equivalent?
A Yes.

Q What output datatypes are allowed?
A Any numeric datatype, like int, float, etc.

Q Do I need to print the result of each snippet?
A No, making the result available for subsequent use is enough.

Q Are pre-set variables allowed?
A Yes, and they become reset (if changed) for every snippet.

Q Are π and e considered number literals?
A No, you may use them.

Q May I return 4 and 2 in different cells for 42?
A No, they must be connected as one number.

Q Bytes or characters?
A Bytes, but you may choose any desired codepage.

Q May constant functions and preset variables like J's 9:, Actually's 9, and Pretzel's 9 be used?
A Yes, if the vocabulary is finite (19 for J, 10 for Actually and Pretzel).

*/

// ported from @user81655 solution
console.log(+[]);
console.log(-~[]);
console.log(-~-~[]);
console.log(-~-~-~[]);
console.log(-~Math.PI);
console.log(-~-~Math.PI);
console.log(-~-~-~Math.PI);
console.log(Date.length);
console.log((a=-~-~[])<<a);
console.log((a=~Math.E)*a);
console.log((a=-~-~[])<<a|a);
console.log((a=Date.length)*--a);

