/*

Description

A checksum is an algorithm that scans a packet of data and returns a single number. The idea is that if the packet is changed, the checksum will also change, so checksums are often used for detecting transmission errors, validating document contents, and in many other situations where it is necessary to detect undesirable changes in data.

For this problem, you will implement a checksum algorithm called Quicksum. A Quicksum packet allows only uppercase letters and spaces. It always begins and ends with an uppercase letter. Otherwise, spaces and letters can occur in any combination, including consecutive spaces.

A Quicksum is the sum of the products of each character's position in the packet times the character's value. A space has a value of zero, while letters have a value equal to their position in the alphabet. So, A=1, B=2, etc., through Z=26. Here are example Quicksum calculations for the packets "ACM" and "MID CENTRAL":

        ACM: 1*1  + 2*3 + 3*13 = 46

MID CENTRAL: 1*13 + 2*9 + 3*4 + 4*0 + 5*3 + 6*5 + 7*14 + 8*20 + 9*18 + 10*1 + 11*12 = 650

Input

The input consists of one or more packets followed by a line containing only # that signals the end of the input. Each packet is on a line by itself, does not begin or end with a space, and contains from 1 to 255 characters.

Output

For each packet, output its Quicksum on a separate line in the output.

Sample Input

ACM
MID CENTRAL
REGIONAL PROGRAMMING CONTEST
ACN
A C M
ABC
BBC
#

Sample Output

46
650
4690
49
75
14
15

Source

Mid-Central USA 2006

*/

var assert = require('assert');

function quicksum(s) {
	const A = "A".charCodeAt(0);
	const Z = "Z".charCodeAt(0);
	const SPACE = " ".charCodeAt(0);
	var r = 0;
	for (var i = 0; i < s.length; i++) {
		var c = s.charCodeAt(i);
		if (A <= c && c <= Z) {
			r += (c - A + 1) * (i + 1);
		} else if (c != SPACE)
			return 0;
	}
	return r;
}

function main() {
	assert(quicksum("ACM") == 46);
	assert(quicksum("MID CENTRAL") == 650);
	assert(quicksum("REGIONAL PROGRAMMING CONTEST") == 4690);
	assert(quicksum("ACN") == 49);
	assert(quicksum("A C M") == 75);
	assert(quicksum("ABC") == 14);
	assert(quicksum("BBC") == 15);
	assert(quicksum("AbqTH #5") == 0);
}

main();
