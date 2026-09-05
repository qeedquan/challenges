/*

In this kata, your job is to create a class Dictionary which you can add words to and their entries. Example:

>>> let d = new Dictionary();

>>> d.newEntry("Apple", "A fruit that grows on trees");

>>> console.log(d.look("Apple"));
A fruit that grows on trees

>>> console.log(d.look("Banana"));
Can't find entry for Banana

Good luck and happy coding!

*/

class Dictionary {
	constructor() {
		this.dict = {};
	}

	newEntry(key, value) {
		this.dict[key] = value;
	}

	look(key) {
		if (this.dict[key])
			return this.dict[key];
		return `Can\'t find entry for ${key}`;
	}
}

let d = new Dictionary();
d.newEntry("Apple", "A fruit that grows on trees");
console.log(d.look("Apple"));
console.log(d.look("Banana"));

