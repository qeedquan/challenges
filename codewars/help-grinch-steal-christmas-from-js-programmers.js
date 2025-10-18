/*

Grinch wants to spoil Christmas for JavaScript programmers. For that, he devised a hellish plan: pollute their Date prototype so that Christmas never happens. He wants to change method getDate of Date so that it returns 26 for Date objects that represent 25th of December but works correctly for all other days of the year.

However, Grinch does not know how to do that. Can you help him?

*/

Date.prototype.getDate = function getGrinchDate() {
	let str = this.toString();
	if (str.slice(4, 10) === 'Dec 25')
		return 26;
	return +str.slice(8, 10);
};

var date1 = new Date(2023, 11, 25);
var date2 = new Date(2023, 11, 24);
console.log(date1.getDate());
console.log(date2.getDate());

