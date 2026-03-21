/*

You have a string. The string consists of words. Before words can be an exclamation mark !. Also some words are marked as one set with square brackets []. You task is to split the string into separate words and sets.
 The set can't be contained in another set.

Input:
 String with words (separated by spaces), ! and [].

Output:
 Array with separated words and sets.

Examples:

('Buy a !car [!red green !white] [cheap or !new]')  =>  ['Buy', 'a', '!car', '[!red green !white]', '[cheap or !new]']
('!Learning !javascript is [a joy]')                =>  ['!Learning', '!javascript', 'is', '[a joy]']
('[Cats and dogs] are !beautiful and [cute]')       =>  ['[Cats and dogs]', 'are', '!beautiful', 'and', '[cute]']

*/

function cleverSplit(string) {
	return string.match(/\[[^\[\]]*?\]|\S+/g);
}

console.log(cleverSplit('Buy a !car [!red green !white] [cheap or !new]'));
console.log(cleverSplit('!Learning !javascript is [a joy]'));
console.log(cleverSplit('[Cats and dogs] are !beautiful and [cute]'));
