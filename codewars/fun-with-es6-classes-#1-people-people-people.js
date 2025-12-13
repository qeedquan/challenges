/*

Time for some OOP fun!

Define a class Person with the following properties:

A constructor that accepts 4 arguments: firstName/FirstName (defaults to "John" if not set), lastName/LastName (defaults to "Doe" if not set), age/Age (defaults to 0 if not set) and gender/Gender (defaults to "Male" if not set). These should be stored in this.firstName/this.FirstName, this.lastName/this.LastName, this.age/this.Age and this.gender/this.Gender respectively.
A method sayFullName/SayFullName that accepts no arguments and returns the full name (e.g. "John Doe")
A class/static method greetExtraTerrestrials/GreetExtraTerrestrials that accepts one parameter raceName and returns "Welcome to Planet Earth raceName". For example, if the race name is "Martians", it should say "Welcome to Planet Earth Martians"
You may use any valid syntax you like; however, it is highly recommended that you complete this Kata using ES6 syntax and features.

Have fun! :D

*/

class Person {
	constructor(firstName, lastName, age, gender) {
		if (firstName === undefined)
			firstName = "John";
		if (lastName === undefined)
			lastName = "Doe";
		if (age === undefined)
			age = 0;
		if (gender === undefined)
			gender = "Male";

		this.firstName = firstName;
		this.lastName = lastName;
		this.age = age;
		this.gender = gender;
	}

	sayFullName() {
		return `${this.firstName} ${this.lastName}`
	}

	static greetExtraTerrestrials(raceName) {
		return `Welcome to Planet Earth ${raceName}`;
	}
}

let john = new Person();
console.log(john);
console.log(john.sayFullName());

let jane = new Person("Jane", "Doe", 25, "Female");
console.log(jane);
console.log(jane.sayFullName());

console.log(Person.greetExtraTerrestrials("Martians"));
