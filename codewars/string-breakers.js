/*

I will give you an integer (N) and a string. Break the string up into as many substrings of N as you can without spaces. If there are leftover characters, include those as well.

Example: 

N = 5;

String = "This is an example string";

Return value:
Thisi
sanex
ample
strin
g

Return value as a string: 'Thisi'+'\n'+'sanex'+'\n'+'ample'+'\n'+'strin'+'\n'+'g'

*/

function stringBreakers(width, string) {
	let regex = new RegExp(`(.{${width}}|.+$)`, 'g');
	string = string.replace(/\s+/g, '');
	matches = string.match(regex);
	return matches.join('\n');
}

console.log(stringBreakers(5, "This is an example string"));
