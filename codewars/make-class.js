/*

I don't like writing classes like this:

function Animal(name,species,age,health,weight,color) {
  this.name = name;
  this.species = species;
  this.age = age;
  this.health = health;
  this.weight = weight;
  this.color = color;
}

Give me the power to create a similar class like this:

const Animal = makeClass("name","species","age","health","weight","color") 

*/

function makeclass(...properties) {
	return function(...values) {
		properties.forEach((key, value) => (this[key] = values[value]));
		return this;
	};
}

function main() {
	const animal = makeclass("name", "species", "age", "health", "weight", "color");
	console.log(animal("thing", "none", 10, 100, 20, "red"));
}

main();
