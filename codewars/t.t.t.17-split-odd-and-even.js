/*

Task
Complete function splitOddAndEven, accept a number n(n>0), return an array that contains the continuous parts of odd or even digits.

Please don't worry about digit 0, it won't appear ;-)

Examples
splitOddAndEven(123)  ===  [1,2,3]

splitOddAndEven(223)  ===  [22,3]

splitOddAndEven(111)  ===  [111]

splitOddAndEven(13579)  ===  [13579]

splitOddAndEven(135246)  ===  [135,246]

splitOddAndEven(123456)  ===  [1,2,3,4,5,6]

*/

function splitOddAndEven(number) {
	let string = number.toString();
	let groups = string.match(/[13579]+|[2468]+/g);
	return groups.map(Number);
}

console.log(splitOddAndEven(123));
console.log(splitOddAndEven(223));
console.log(splitOddAndEven(111));
console.log(splitOddAndEven(13579));
console.log(splitOddAndEven(135246));
console.log(splitOddAndEven(123456));

