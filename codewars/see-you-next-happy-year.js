/*

Scenario
You're saying good-bye your best friend , See you next happy year .

Happy Year is the year with only distinct digits , (e.g) 2018

Task
Given a year, Find The next happy year or The closest year You'll see your best friend!alt!alt

Notes
Year Of Course always Positive .
Have no fear , It is guaranteed that the answer exists .
It's not necessary that the year passed to the function is Happy one .

Input Year with in range (1000  ≤  y  ≤  9000)

Input >> Output Examples:
nextHappyYear (7712) ==> return (7801)

Explanation:
As the Next closest year with only distinct digits is 7801 .

nextHappyYear (8989) ==> return (9012)

Explanation:
As the Next closest year with only distinct digits is 9012 .

nextHappyYear (1001) ==> return (1023)

Explanation:
As the Next closest year with only distinct digits is 1023 .

*/

var assert = require('assert');

function nextHappyYear(year) {
	for (;;) {
		year += 1;
		let string = year.toString();
		let set = new Set(string);
		if (string.length == set.size)
			break;
	}
	return year;
}

function main() {
	assert(nextHappyYear(7712) == 7801);
	assert(nextHappyYear(8989) == 9012);
	assert(nextHappyYear(1001) == 1023);
}

main();
