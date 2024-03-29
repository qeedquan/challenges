/*

Vasya plays the sleuth with his friends. The rules of the game are as follows: those who play for the first time, that is Vasya is the sleuth, he should investigate a "crime" and find out what is happening. He can ask any questions whatsoever that can be answered with "Yes" or "No". All the rest agree beforehand to answer the questions like that: if the question’s last letter is a vowel, they answer "Yes" and if the last letter is a consonant, they answer "No". Of course, the sleuth knows nothing about it and his task is to understand that.

Unfortunately, Vasya is not very smart. After 5 hours of endless stupid questions everybody except Vasya got bored. That’s why Vasya’s friends ask you to write a program that would give answers instead of them.

The English alphabet vowels are: A, E, I, O, U, Y

The English alphabet consonants are: B, C, D, F, G, H, J, K, L, M, N, P, Q, R, S, T, V, W, X, Z

Input
The single line contains a question represented by a non-empty line consisting of large and small Latin letters, spaces and a question mark. The line length does not exceed 100. It is guaranteed that the question mark occurs exactly once in the line — as the last symbol and that the line contains at least one letter.

Output
Print answer for the question in a single line: YES if the answer is "Yes", NO if the answer is "No".

Remember that in the reply to the question the last letter, not the last character counts. I. e. the spaces and the question mark do not count as letters.

Examples

input
Is it a melon?
output
NO

input
Is it an apple?
output
YES

input
  Is     it a banana ?
output
YES

input
Is   it an apple  and a  banana   simultaneouSLY?
output
YES

*/

package main

import (
	"unicode"
)

func main() {
	assert(reply("Is it a melon?") == "NO")
	assert(reply("Is it an apple?") == "YES")
	assert(reply("  Is     it a banana ?") == "YES")
	assert(reply("Is   it an apple  and a  banana   simultaneouSLY?") == "YES")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reply(s string) string {
	for i := len(s) - 1; i >= 0; i-- {
		c := unicode.ToUpper(rune(s[i]))
		switch c {
		case 'A', 'E', 'I', 'O', 'U', 'Y':
			return "YES"
		case 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z':
			return "NO"
		}
	}
	return "INVALID"
}
