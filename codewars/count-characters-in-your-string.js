/*

The main idea is to count all the occurring characters in a string. If you have a string like aba, then the result should be {'a': 2, 'b': 1}.

What if the string is empty? Then the result should be empty object literal, {}.

*/

function count(string) {
	seen = {};
	for (let index = 0; index < string.length; index++) {
		let ch = string[index];
		if (seen.hasOwnProperty(ch))
			seen[ch]++;
		else
			seen[ch] = 1;
	}
	return seen;
}

console.log(count("aba"));
console.log(count(""));
