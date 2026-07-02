/*

Your task is to write a regular expression that will match only numbers whose digits are all unique, i.e. they are not repeated anywhere within the number.

The input will be a positive integer, given as a string. You should assign your expression to the regex variable, which will be tested using RegExp.prototype.test(). The test should return true if all digits of the number are unique, and false otherwise.

Examples:

regex.test('1234')
// --> true

regex.test('1232')
// --> false
// because digit 2 is repeated

Note: The kata includes anti-cheat code to prevent you from submitting non-regex solutions.qeed@desktop:~/codewars-tasks/Regex Ninja Unique Digits$ cat *
Your task is to write a regular expression that will match only numbers whose digits are all unique, i.e. they are not repeated anywhere within the number.

The input will be a positive integer, given as a string. You should assign your expression to the regex variable, which will be tested using RegExp.prototype.test(). The test should return true if all digits of the number are unique, and false otherwise.

Examples:

regex.test('1234')
// --> true

regex.test('1232')
// --> false
// because digit 2 is repeated

Note: The kata includes anti-cheat code to prevent you from submitting non-regex solutions.

*/

var assert = require('assert');

const regex = /^(?!.*(.).*\1)\d+$/;

assert(regex.test('1234') == true);
assert(regex.test('1232') == false);

