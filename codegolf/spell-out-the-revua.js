/*

Actually not inspired neither by Atbash Self Palindromes nor by Generalized Gematria Calculator.

Given a string s of length n, output the Revu'a sequence, which is the first character of s, the first two characters of s, ... the first n–2 characters of s, the first n–1 characters of s, the entire s.

The string will only consist of Unicode (any encoding you want) characters that have strong directionality and are found in the range 0x0000 through 0xFFFF.
However, no directionality control characters will occur. All characters in any given string will have the same directionality.

You may return in array notation ["t","te","tes","test"], as a space-separated string "t te tes test", as multi-line text
t
te
tes
test
, a pre-formatted array

t
te
tes
test
, or anything similar. Amounts of leading, separating, and trailing spacing is not important, and neither are trailing newline. Ask if in doubt.
Right-to-Left input must result in Right-to-Left output in proper order:
Input: "נחמן"
Output: "נ  נח  נחמ  נחמן" or

נ
נח
נחמ
נחמן
, or ["נ","נח","נחמ","נחמן"]. Among invalid results are "נחמן  נחמ  נח  נ" ,"ן  מן  חמן  נחמן", and "נחמן  חמן  מן  ן".

*/

/*

@ETHproductions

Takes advantage of some built-in features of JS's .replace function. Specifically, in the replacement, $`  becomes everything preceding the matched character.
Using the regex /.?/g rather than /./g means it also matches the empty string at the end.

*/

function spellout(s) {
	return s.replace(/.?/g, "$` ");
}

console.log(spellout("test"));
console.log(spellout("נחמן"));

