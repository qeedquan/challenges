/*

Basics - Generators #1
Generators are very useful things in programming, in this series we will learn how to use generators and see how we can apply generators to common programming challenges.

Task
You must complete the generator function that must increment a counter by 1 each time also if the argument is supplied (will always be a number) you must then change the counter to that number.

Important
The counter must start at 1 when the generator is initialized

More Info: Iterators and Generators (JavaScript) ( https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Iterators_and_Generators ), Generators Overview (PHP) ( http://php.net/manual/en/language.generators.overview.php )

*/

function* generator() {
	let counter = 1;
	for (;;) {
		let value = yield counter;
		counter += 1;
		if (value)
			counter = value;
	}
}

for (const value of generator()) {
	if (value >= 10)
		break;
	console.log(value);
}

sequence = generator();
console.log(sequence.next());
console.log(sequence.next());
console.log(sequence.next());
console.log(sequence.next());
console.log(sequence.next(1337));

