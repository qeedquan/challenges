/*

Friday 13th or Black Friday is considered as unlucky day. Calculate how many unlucky days are in the given year.

Find the number of Friday 13th in the given year.

Input: Year in Gregorian calendar as integer.

Output: Number of Black Fridays in the year as an integer.

Examples:

unluckyDays(2015) == 3
unluckyDays(1986) == 1

*/

var assert = require('assert');

// https://oeis.org/A101312
function unluckydays(year) {
	let date = new Date(year, 0, 13);
	let count = 0;
	for (let month = 0; month < 12; month++) {
		date.setMonth(month);
		if (date.getDay() == 5)
			count += 1;
	}
	return count;
}

function main() {
	assert(unluckydays(2015) == 3);
	assert(unluckydays(1986) == 1);
}

main();
