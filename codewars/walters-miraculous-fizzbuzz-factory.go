/*

The FizzBuzz factory
Walter was a normal engineer. He built FizzBuzz functions every day. You might have heard of them. They return "Fizz", if your number is divisible by 3, "Buzz", if your number is divisible by 5, and "FizzBuzz" if your number is divisible by, well, both. For all other, boring numbers, the number itself was returned (but as a string, since Walter cared about types).

However, those machines were so practical and beneficial to the whole society, that everyone copied Walter's machines. So he came up with a new idea: he would sell a personal FizzBuzz factory! That would bring his competitors out of business!

Task
In this kata, you will get an array of unique numbers, paired with strings, like

[(3, "Fizz"), (5, "Buzz"), (15, "FizzBuzz")]
Depending on the language, that's either a list/array of tuples or an array of arrays. It's always sorted.

Your job is to return another function, that—given a number n—returns the appropriate string. How do you know the correct string? Well, it's the one paired with the largest key that still divides the number n!

Examples
var myFizz = fizzBuzzFactory([[3, "Fizz"], [5, "Buzz"], [15, "FizzBuzz"]])
myFizz(3)  === "Fizz"
myFizz(4)  === "4"
myFizz(5)  === "Buzz"
myFizz(15) === "FizzBuzz"

var myFooBar = fizzBuzzFactory([[2, "Foo"], [4, "Bar"], [6, "FooBar"]])
myFooBar(1)  === "1"
myFooBar(2)  === "Foo"
myFooBar(4)  === "Bar"
myFooBar(6)  === "FooBar"
myFooBar(8)  === "Bar"
myFooBar(10) === "Foo"
myFooBar(12) === "FooBar"

*/

package main

import "fmt"

type Pair struct {
	modulus int
	value   string
}

func main() {
	var myFizz = fizzBuzzFactory([]Pair{{3, "Fizz"}, {5, "Buzz"}, {15, "FizzBuzz"}})
	assert(myFizz(3) == "Fizz")
	assert(myFizz(4) == "4")
	assert(myFizz(5) == "Buzz")
	assert(myFizz(15) == "FizzBuzz")

	var myFooBar = fizzBuzzFactory([]Pair{{2, "Foo"}, {4, "Bar"}, {6, "FooBar"}})
	assert(myFooBar(1) == "1")
	assert(myFooBar(2) == "Foo")
	assert(myFooBar(4) == "Bar")
	assert(myFooBar(6) == "FooBar")
	assert(myFooBar(8) == "Bar")
	assert(myFooBar(10) == "Foo")
	assert(myFooBar(12) == "FooBar")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fizzBuzzFactory(pairs []Pair) func(int) string {
	return func(number int) string {
		for index := len(pairs) - 1; index >= 0; index-- {
			pair := &pairs[index]
			if number%pair.modulus == 0 {
				return pair.value
			}
		}
		return fmt.Sprint(number)
	}
}
