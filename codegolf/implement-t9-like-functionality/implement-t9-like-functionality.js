/*

Your challenge today is to implement a t9-like functionality.

You will implement a function that will only have 2 parameters.
You will receive 1 phone number in a string and the content of a text file with a list of words (don't assume a specific newline style).
You can use the link https://raw.githubusercontent.com/eneko/data-repository/master/data/words.txt to test the functionality, or use /usr/share/dict/words (check A text file with a list of words [closed] for more information).

You can assume that you will always receive at least 2 numbers.

Given the number, you will read from a list of words and returns the words starting with the letters mapping to those words. This means that the input should be only numbers from 2 to 9.
You can do whatever you want if you receive invalid input.

If no match is found, you can return an empty list, null/nil or 0.

Remember that the cellphone keys are mapped to their equivalent chars:

0 and 1 are invalid
2 matches [abc]
3 matched [def]
4 matches [ghi]
5 matches [jkl]
6 matches [mno]
7 matches [pqrs]
8 matches [tuv]
and 9 matches [wxyz]
Examples:

f('52726')
//returns ["Japan","japan","Japanee","Japanese","Japanesque"...,"larbowlines"]

f('552')
//returns ["Kjeldahl","kjeldahlization","kjeldahlize"...,"Lleu","Llew"]

f('1234')
//makes demons fly out your nose or divide by 0

f('9999')
//returns ["Zyzzogeton"]

f('999999')
//returns [] or null/nil or 0
After you run your function, you can print it in any way you wish.

Rules:

Standard loopholes are INVALID
You must return something, even if it is null/nil
Javascript will return undefined if you don't return something, therefore this rule.
You cannot use or re-implement other's answers or copy my implementation.
You can assume, for Javascript, that the browser will be already opened and that the innerText/textContent of the automatic element will be passed as the 2nd parameter
For compiled languages, you cannot pass special arguments to the compiler
You can receive the file name over compiler arguments
Variables, macros, global variables, constants, non-standard classes and all the sort passing other values inside the function will be considered invalid.
In Javascript, variables without the keyword var render your code invalid
Your function will be named f
You can only and only have 2 arguments on your function
Try to keep your code under 500 seconds to run.
You don't have to worry about whitespace
You must use only ASCII printable characters.
Exceptions are languages that only use non-printable characters (APL and whitespace are 2 examples).
Scoring:

Lowest number of bytes win
Having invalid ASCII printable characters in your answer, will count as the answer being encoded in UTF-32
The exception to the encoding will make your answer be count by characters.
Only the function body counts, don't count anything else you do outside it
Bonus of -30% if you make a prediction system based on the neighborhood or most common words
Bonus of -20% in size if you only return the first 5 matches for each letter corresponding to the first number (e.g.: 245 would returns 5 words starting with 'a', 5 starting with 'b' and 5 starting with 'c').
Here is an example of an implementation, using Javascript:

function f(phone, words)
{
    var keypad=['','','abc','def','ghi','jkl','mno','pqrs','tuv','wxyz'];
    var regex='';

    for(var i=0,l=phone.length;i<l;i++)
    {
        regex+='['+keypad[phone[i]]+']';
    }

    var regexp=new RegExp('\\s('+regex+'[a-z]*)\\s','gi');

    return words.match(regexp);
}
To run it, open the list link and run, for example:

f('9999',document.getElementsByTagName('pre')[0].innerText);
//returns [" Zyzzogeton "]
This example was tested and works under Opera 12.17 64bits on Windows 7 Home Edition 64bits.

*/

const fs = require('fs');

function build(phone) {
	var keypad = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
	var regex = '';

	for (var i = 0; i < phone.length; i++) {
		regex += '[' + keypad[phone[i]] + ']';
	}

	return new RegExp('\\s(' + regex + '[a-z]*)\\s', 'gi');
}

function match(phone, words) {
	var regexp = build(phone);
	console.log(phone);
	console.log(words.match(regexp));
	console.log();
}

function main() {
	words = fs.readFileSync('words.txt').toString();
	words = words.replaceAll('\n', ' ');
	match('52726', words);
	match('1234', words);
	match('552', words);
	match('999', words);
	match('999999', words);
}

main();
