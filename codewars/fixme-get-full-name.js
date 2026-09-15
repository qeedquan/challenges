/*

The code provided is supposed return a person's Full Name given their first and last names.

But it's not working properly.

Notes
The first and/or last names are never null, but may be empty.

Task
Fix the bug so we can all go home early.

*/

class Person {
	constructor(firstName, lastName) {
		this.firstName = firstName;
		this.lastName = lastName;
	}

	getFullName() {
		return (this.firstName + ' ' + this.lastName).trim();
	}
}

function main() {
	let person = new Person("John", "Doe");
	console.log(person.getFullName());
}

main();
