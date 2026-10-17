/*

Preamble:
You were cleaning your virtual pantry and accidentally found a folder with a label on it: "Automaton v1.9".

Part 2:
After you're done with cleaning you noticed Manual.txt right next to Automaton's folder.

Manual for Automaton v1.9:
If automaton accepts "string" it will tell you the amount of vowels that string contains. Example:

automaton("String") // 1

If automaton accepts "number" it will tell you if this is a prime number. Example:

automaton(3); // true
automaton(3.5); // false
automaton(4); // false

If automaton accepts "object" it will give you another object with swapped keys / values. Example:

automaton({"a": "b"}); // {"b": "a"}
automaton([1, 0]); // {"0": "1", "1": "0"}
automaton([]); // {}

You checked the results that Automaton gave you and saw that the data was inaccurate. So you decided to fix it.

*/

function isprime(n) {
	for (let i = 2; i*i <= n; i++) {
		if (n%i === 0)
			return false;
	}
	return true;
}

function automaton(input) {
	if (typeof input === 'string')
		return input.replace(/[^aeiouAEIOU]/g, '').length;
	
	if (typeof input === 'number') {
		if (!Number.isInteger(input) || input < 2)
			return false;
		return isprime(input);
	}

	if (typeof input === 'object' && input !== null) {
		const table = {};

		for (const key in input)
			table[input[key]] = String(key);
		return table;
	}

	return null;
}

console.log(automaton("String"));

console.log(automaton(3));
console.log(automaton(3.5));
console.log(automaton(4));

console.log(automaton({"a": "b"}));
console.log(automaton([1, 0]));
console.log(automaton([]));

