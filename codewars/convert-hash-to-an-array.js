/*

Convert a hash into an array. Nothing more, Nothing less.

{name: 'Jeremy', age: 24, role: 'Software Engineer'}
should be converted into

[["age", 24], ["name", "Jeremy"], ["role", "Software Engineer"]]
Note: The output array should be sorted alphabetically by key name.

Good Luck!

*/

function hash2array(hash) {
	let keys = Object.keys(hash);
	keys.sort();
	return keys.map((key) => [key, hash[key]]);
}

console.log(hash2array({name: 'Jeremy', age: 24, role: 'Software Engineer'}));

