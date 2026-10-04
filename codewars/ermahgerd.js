/*

Ermahgerd girl ( http://www.vanityfair.com/culture/2015/10/ermahgerd-girl-true-story ) wants you to write a function that translates english into ermahgerd language!! There are many different subtleties to the translation but for this Kata we'll focus on just a few core ones:

For this specific translation it's probably best to implement these features in the order below:

Ermahgerd girl is ALWAYS very excited so everything needs to be in UPPERCASE!

Each vowel should be replaced with: 'ER'

Double "ER"s --->'ERER' and the letters 'ERH' should be replaced with just 'ER'

The letters 'MY' (as a word or part of a word) should be replaced with: 'MAH'

And to help with readability:

Duplicate 'RR's should become a single 'R'

After these steps are complete words longer than 4 letters that end in "ER" should have the "ER" trimmed off (the tricky bit is to make sure it can handle commas or spaces)

Ermahgerd girl is VERY excited to see your solutions!

*/

var assert = require('assert');

let isUpperCase = text => text === text.toUpperCase();

function ermahgerd(s) {
	s = s.toUpperCase();
	s = s.replace(/[AEIOU]/g, 'ER');
	s = s.replace(/ER(ER|H)/g, 'ER');
	s = s.replace(/MY/g, 'MAH');
	s = s.replace(/RR/g, 'R');
	t = s.split(' ');
	t = t.map((w) => (w.length > 4 ? w.replace(/ER([.,])?$/, '$1') : w));
	return t.join(' ');
}

assert(isUpperCase(ermahgerd('coDeWars')) == true);
assert(isUpperCase(ermahgerd('ohmygod I LOVE codewars!')) == true);

assert(ermahgerd('regexp') == 'RERGERXP');
assert(ermahgerd('Javascript') == 'JERVERSCRERPT');
assert(ermahgerd('Haskell') == 'HERSKERLL');
assert(ermahgerd('Python') == 'PYTHERN');
assert(ermahgerd('Ruby') == 'RERBY');

assert(ermahgerd('oh') == 'ER');
assert(ermahgerd('ae') == 'ER');

assert(ermahgerd('my') == 'MAH');
assert(ermahgerd('ohmygod oh my!') == 'ERMAHGERD ER MAH!');

assert(ermahgerd('girl') == 'GERL');
assert(ermahgerd('algorithm') == 'ERLGERERTHM');
assert(ermahgerd('ohmygod my function works') == 'ERMAHGERD MAH FERNCTERN WERKS');

assert(ermahgerd('my name is ohmygod girl and I love codewars!') == 'MAH NERM ERS ERMAHGERD GERL ERND ER LERV CERDERWERS!');
assert(ermahgerd('ohmygod my favourite pokemon!') == 'ERMAHGERD MAH FERVERERT PERKERMERN!');
assert(ermahgerd('grumpy cat!! my favourite cat!') == 'GRERMPY CERT!! MAH FERVERERT CERT!');
assert(ermahgerd('ohmygod javascript, haskell, python, ruby, java, c sharp, clojure, coffeescript!! I love them all!!') == 'ERMAHGERD JERVERSCRERPT, HERSKERLL, PYTHERN, RERBY, JERV, C SHERP, CLERJER, CERFFERSCRERPT!! ER LERV THERM ERLL!!');

