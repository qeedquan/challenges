/*

You will be given a string with sets of characters, (i.e. words), seperated by between one and three spaces (inclusive).

Looking at the first letter of each word (case insensitive-"A" and "a" should be treated the same), you need to determine whether it falls into the positive/first half of the alphabet ("a"-"m") or the negative/second half ("n"-"z").

Return True/true if there are more (or equal) positive words than negative words, False/false otherwise.

"A big brown fox caught a bad rabbit" => True/true
"Xylophones can obtain Xenon." => False/false

*/

var assert = require('assert');

function connotation(str) {
	str = str.trim();
	let words = str.split(/\s+/g);
	let count = 0;
	for (let index = 0; index < words.length; index++) {
		let word = words[index];
		if (word.length > 0 && /[a-m]/i.test(word[0]))
			count++;
		else
			count--;
	}
	return count >= 0;
}

assert(connotation("A big brown fox caught a bad rabbit") == true);
assert(connotation("Xylophones can obtain Xenon.") == false);
assert(connotation("CHOCOLATE MAKES A GREAT SNACK") == true);
assert(connotation("All FOoD tAsTEs NIcE for someONe") == true);
assert(connotation("Is  this the  best  Kata?") == true);
assert(connotation("Coats and jackets make good garments.") == true);
assert(connotation("Cranberries and newly obtained salted caramel tastes wonderful.") == false);
assert(connotation("Water is often required on school trips!") == false);
assert(connotation("Humour intrigues and astounds Data.") == true);

