/*

You need count how many valleys you will pass.

Start is always from zero level.

Every time you go down below 0 level counts as an entry of a valley, and as you go up to 0 level from valley counts as an exit of a valley.

One passed valley is equal one entry and one exit of a valley.

s='FUFFDDFDUDFUFUF'
U=UP
F=FORWARD
D=DOWN

To represent string above

(level 1)  __
(level 0)_/  \         _(exit we are again on level 0)
(entry-1)     \_     _/
(level-2)       \/\_/

So here we passed one valley

*/

var assert = require('assert');

function count(map) {
	let valleys = 0;
	let level = 0;
	for (let index = 0; index < map.length; index++) {
		switch (map[index]) {
		case 'U':
			level += 1;
			break;
		case 'D':
			level -= 1;
			break;
		}

		if (level == 0 && map[index] == 'U')
			valleys += 1;
	}
	return valleys;
}

function main() {
	assert(count("FUFFDDFDUDFUFUF") == 1);
}

main();
