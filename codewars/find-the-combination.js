/*

Your objective is to count how many times a certain word or combination of letters or symbols appears inside a string. The key is case insensitive and can occur as many or as few times in the string. The function declaration is provided for you and there should be two arguments with one return variable that returns the count. Overlapping words should not be counted more than once! An empty string cannot be a key. The function should also be able to count the number of integers and characters. Think hard!

Example:

countCombinations('my name is billy and billy is awesome', 'billy'); // 2
countCombinations('abcdefghijklmonopolymonorailqrstuv', 'mono'); // 2
countCombinations('GrEggreGGREGgREG', 'greg'); // 4
countCombinations('@#$##@@@','@'); // 4
countCombinations('wow nothing', 'yeah'); // 0
countCombinations('lololololol', 'lol'); // 3
countCombinations('93049', '\\d'); // 5
countCombinations('Five ', '\.'); // 5

Please give feedback and rank! That would be amazing!q

*/

var assert = require('assert');

function countCombinations(string, key) {
	let regex = new RegExp(key, 'ig');
	let matches = string.match(regex);
	if (!matches)
		return 0;
	return matches.length;
}


assert(countCombinations('my name is billy and billy is awesome', 'billy') == 2);
assert(countCombinations('abcdefghijklmonopolymonorailqrstuv', 'mono') == 2);
assert(countCombinations('GrEggreGGREGgREG', 'greg') == 4);
assert(countCombinations('@#$##@@@','@') == 4);
assert(countCombinations('wow nothing', 'yeah') == 0);
assert(countCombinations('lololololol', 'lol') == 3);
assert(countCombinations('93049', '\\d') == 5);
assert(countCombinations('Five ', '\.') == 5);

