/*

Description
In English we often use "neutral vowel sounds" such as "umm", "err", "ahh" as fillers in conversations to help them run smoothly.

Bob always finds himself saying "err". Infact he adds an "err" to every single word he says that ends in a consonant! Because Bob is odd, he likes to stick to this habit even when emailing.

Task
Bob is begging you to write a function that adds "err" to the end of every word whose last letter is a consonant (not a vowel, y counts as a consonant).

The input is a string that can contain upper and lowercase characters, some punctuation but no numbers. The solution should be returned as a string.

NOTE: If the word ends with an uppercase consonant, the following "err" will be uppercase --> "ERR".

eg:

"Hello, I am Mr Bob" --> "Hello, I amerr Mrerr Boberr"

"THIS IS CRAZY!"  --> "THISERR ISERR CRAZYERR!"

Good luck!

*/

var assert = require('assert');

function errbob(string) {
	let pattern = /[qwrtypsdfghjklzxcbnm]\b/gi;
	let result = string.replace(pattern, (character) => (character.toUpperCase() == character) ? character + 'ERR' : character + 'err');
	return result;
}

assert(errbob("Hello, I am Mr Bob") == "Hello, I amerr Mrerr Boberr");
assert(errbob("THIS IS CRAZY!") == "THISERR ISERR CRAZYERR!");
assert(errbob("Hello, I am Mr Bob") == "Hello, I amerr Mrerr Boberr");
assert(errbob("THIS, is crazy!") == "THISERR, iserr crazyerr!");
assert(errbob("r r r r r r r r") == "rerr rerr rerr rerr rerr rerr rerr rerr");
assert(errbob("hI, hi. hI hi skY! sky? skY sky") == "hI, hi. hI hi skYERR! skyerr? skYERR skyerr");
assert(errbob("This, is. another! test? case to check your beautiful code.") == "Thiserr, iserr. anothererr! testerr? case to checkerr yourerr beautifulerr code.");

