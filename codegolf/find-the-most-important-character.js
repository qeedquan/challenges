/*

Find the most important character
The challenge is to write a program that outputs the most occurrent character in the input string, excluding these bracketing characters ()[]{}. Each submission should consist only of non-trivial* characters. Each solution is scored using the formula in the scoring section. Bracketing characters are allowed in the program, but may not be selected by the program as the most occurrent character. In cases where letters occur with the same frequency, any or all of the characters may be returned.

*Non-trivial is defined in this case to be a character that contributes to the functionality of the program. If the character can be removed without influencing how the program runs, it is a trivial character.

Scoring
Score is determined as follows:

(nchar / ntotal) ∗ 100(%)

With nchar being the number of occurrences of the most frequent character in the input, and ntotal being the total number of non-trivial characters in the input. With this scoring criteria, all scores should be within the range [0,100]

Highest scoring solution per language wins.

Input
Solutions should take in any valid string as input. A convenient method of determining the most occurrent character in the program itself would be to use the program's source code as input to the program itself. The program does not have to check for non-trivial characters, as they should not be included in the program source.

Output
A single character with the highest percentage occurrence. Each solution should be capable of outputting standard ASCII, as well as the language's codepage (if applicable).

Errata
Creative solutions are encouraged. Boring solutions with long padded strings substituted in for numbers are discouraged. Standard loopholes are disallowed.

Examples
Program:

aabbbc

Output:

b

Program:

aabb

Output:

a or b or ab

*/

var assert = require('assert');

function important(string) {
	const brackets = "()[]{}";
	let counts = new Map();
	let result = 0;
	let maximum = 0;
	for (const character of string) {
		if (!counts.has(character)) {
			counts.set(character, 0);
		}
		
		let value = counts.get(character) + 1;
		if (value > maximum && !brackets.includes(character)) {
			result = character;
			maximum = value;
		}

		counts.set(character, value);
	}
	return result;
}

function main() {
	assert(important("aabbbc") == 'b');
	assert(important("aabb") == 'a');
}

main();
