/*

I'm a big music fan, and I'm quite proud of my collection, but it seems some kind of sickness is going around the house, and all my vinyls have gotten quite ill. Can you help me find which ones have gotten sick, so I can quarantine them from the other ones?

Some of the albums, however, are false positives, and thus there is no point in quarantining them. An album is a false positive if:

"Ill" does not come at the beginning of any of the words it's featured in
A vowel besides "e" comes after the word "Ill" in all of the words it's featured in (y counts as a vowel)
If an album name contains a word that starts with "Ill", as well as meeting the vowel requirements shown above (aiouy cannot come after "Ill"), then output a truthy value. Otherwise, output a falsy value. The input string does not have to be case-sensitive, so Illmatic would be just as valid as illmatic or ILLMATIC, and you may choose whatever input case you please.

Additionally, there are no requirements or restrictions for the type of string that you handle (Ex: ASCII or utf-8), and there will never be adjacent spaces within a given album name (Ex: "Ill  Communication").

Test cases:

"Illmatic" -> True

"Licensed to Ill" -> True

"Ill Communication" -> True

"The ILLEST Villains" -> True

"Illumination of the ill man" -> True

"Madvillainy" -> False

"Music Inspired by Illumination & Dr. Seuss' The Grinch" -> False

"The Illyiad" -> False

"Villains are Illuminated" -> False

"Exmilitary" -> False

This is code-golf, so shortest answer wins!

*/

/*

@Arnauld

Explanation
We look for ...

/             //
  \b          // a word boundary
  ill         // followed by "ill"
  (?![aiouy]) // not immediately followed by a, i, o, u or y
/i            // in case-insensitive mode

*/

function check(string) {
	let pattern = /\bill(?![aiouy])/i;
	return pattern.test(string);
}

let tests = [
	"Illmatic",
	"Licensed to Ill",
	"Ill Communication",
	"The ILLEST Villains",
	"Illumination of the Ill Man",
	"Madvillainy",
	"Music Inspired by Illumination & Dr. Seuss' The Grinch",
	"The Illyiad",
	"Villains are Illuminated"
];

for (let i = 0; i < tests.length; i++) {
	console.log(tests[i], check(tests[i]));
}
