/*

For a given DNA genetic code represented by a string, count the number of times the letters A (adenine), C (cytosine), G (guanine) and T (thymine) appears and return and object.

The input string may contain both upper and lower case characters.

For example:


var genCode = 'aCCggT';

getCountedNucleotides(genCode); // return {A: 1, C: 2, G: 2, T: 1}
Also, should a nucleotide type not be present within the string, it should still be present in the object returned with it's value as 0. For example:


var genCode = 'ACG';

getCountedNucleotides(genCode); // return {A: 1, C: 1, G: 1, T: 0}

*/

function nucleotides(code) {
	let count = { A: 0, C: 0, G: 0, T: 0 };
	for (let i = 0; i < code.length; i++) {
		let symbol = code[i].toUpperCase();
		count[symbol] += 1;
	}
	return count;
}

console.log(nucleotides("aCCggT"));
console.log(nucleotides("ACG"));
