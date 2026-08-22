/*

Classy Extensions
Classy Extensions with Super, this kata is mainly aimed at the new JS ES6 Update introducing class extends

Task
Your task is to complete the Cat class which Extends Animal, we want to go to use the original speak method as well, so you must use the super method so the speak method for Cat now returns e.g. 'Mr Whiskers makes a noise, Mr Whiskers goes meow.'

Reference: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes

*/

package main

import "fmt"

func main() {
	cat := Cat{Animal{"Mr Whiskers"}}
	fmt.Println(cat.Speak())
}

type Animal struct {
	Name string
}

func (a *Animal) Speak() string {
	return fmt.Sprintf("%s makes a a noise, ", a.Name)
}

type Cat struct {
	Animal
}

func (c *Cat) Speak() string {
	return fmt.Sprintf("%s%s goes meow.", c.Animal.Speak(), c.Name)
}
