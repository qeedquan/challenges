/*

Task
You are given a function that should insert an asterisk (*) between every pair of even digits in the given input, and return it as a string. If the input is a sequence, concat the elements first as a string.

Input
The input can be an integer, a string of digits or a sequence containing integers only.

Output
Return a string.

Examples
5312708     -->  "531270*8"
"0000"      -->  "0*0*0*0"
[1, 4, 64]  -->  "14*6*4"

Have fun!

*/

function asterisk(values) {
	if (typeof values === 'number')
		values = values.toString();
	else if (typeof values === 'object')
		values = values.join('');
	return values.replace(/[02468](?=[02468])/g, (symbol) => symbol + '*');
}

console.log(asterisk(5312708));
console.log(asterisk("0000"));
console.log(asterisk([1, 4, 64]));

