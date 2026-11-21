/*

Kushim, the Sumerian farmer's accountant, has noted down on his clay tablet who owes the farmer for barley, and who has made an advance payment. He wants you to use the modern power of computing to sum all of the values to see the overall balance of the farmer's books. To help you he has supplied his notes in text form, and has put a currency symbol before each account value.

Note:

each account value includes the '$' symbol and is followed by a space or punctuation. For example: $300 , or -$300..
you should only sum the account values.
your output should be a positive or negative integer; it should not have the '$' symbol.
Example:

sumAccounts("Hashim the greengrocer: $200. Prince Enki -$300. Barley Bee:-$100, promised to pay next week.")
//returns: -200.
Sometimes Kushim writes in code so the input string may look as below; note that the account values still have their '$' symbol and a space.

"$173 ketqUYVOmE-$71 Kjc8da u 3$857 7M4fOvmV7 -$0   DWJ:q6N9$943 3: tnSTqe!-$38 xf2Psn9mz $850 T6kqNLwnzY-$460 GljNB Z  T$912 hrB PETpUN-$506 N;iwSZ45"

*/

var assert = require('assert');

function sumAccounts(text) {
	let matches = text.match(/-?\$\d+/g);
	return matches.reduce(function(total, value) {
		return total + parseInt(value.replace('$', ''));
	}, 0)
}

assert(sumAccounts("Gal-Sal's Greengrocer -$200. Kesh Village Store, as of last week $400; promised to pay soon. Sumer's Giant 100X supermarket -$600. Sukalgir's veg delivery service -$200. Eridu 10 a Day store: $300. Isin's Greens Greens Greens health store: -$100. My mate Abu: $0. Alulim the First King of Eridu -$1000.") ==  -1400);
assert(sumAccounts("Hashim the greengrocer: $200. Prince Enki -$300. Barley Bee:-$100, promised to pay next week.") == -200);
