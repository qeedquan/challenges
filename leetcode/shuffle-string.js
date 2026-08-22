/*

You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

Example 1:

4 5 6 7 0 2 1 3
c o d e l e e t
---------------
l e e t c o d e

Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
 

Constraints:

s.length == indices.length == n
1 <= n <= 100
s consists of only lowercase English letters.
0 <= indices[i] < n
All values of indices are unique.

*/

var assert = require('assert');

function shuffle(s, i) {
	var r = new Array(s.length + 1);
	for (var n = 0; n < s.length; n++)
		r[i[n]] = s[n];
	return r.join('');
}

function main() {
	assert(shuffle("codeleet", [4, 5, 6, 7, 0, 2, 1, 3]) == "leetcode");
	assert(shuffle("abc", [0, 1, 2]) == "abc");
}

main();
