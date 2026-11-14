/*

If you like Taco Bell, you will be familiar with their signature doritos locos taco. They're very good.

Why can't everything be a taco? We're going to attempt that here, turning every word we find into the taco bell recipe with each ingredient.

We want to input a word as a string, and return a list representing that word as a taco.

Key

all vowels (except 'y') = beef

t = tomato

l = lettuce

c = cheese

g = guacamole

s = salsa

NOTE
We do not care about case here. 'S' is therefore equivalent to 's' in our taco.

Ignore all other letters; we don't want our taco uneccesarily clustered or else it will be too difficult to eat.

Note that no matter what ingredients are passed, our taco will always have a shell.

*/

package main

import (
	"reflect"
	"unicode"
)

func main() {
	test("", []string{"shell", "shell"})
	test("a", []string{"shell", "beef", "shell"})
	test("ogl", []string{"shell", "beef", "guacamole", "lettuce", "shell"})
	test("alel", []string{"shell", "beef", "lettuce", "beef", "lettuce", "shell"})
	test("MaXwElL", []string{"shell", "beef", "beef", "lettuce", "lettuce", "shell"})
	test("ggg", []string{"shell", "guacamole", "guacamole", "guacamole", "shell"})
	test("ydjkpwqrzto", []string{"shell", "tomato", "beef", "shell"})
	test("abtlcgs", []string{"shell", "beef", "tomato", "lettuce", "cheese", "guacamole", "salsa", "shell"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(word string, expected []string) {
	assert(reflect.DeepEqual(tacofy(word), expected))
}

func tacofy(word string) []string {
	dictionary := map[rune]string{
		'a': "beef",
		'c': "cheese",
		'e': "beef",
		'g': "guacamole",
		'i': "beef",
		'l': "lettuce",
		'o': "beef",
		's': "salsa",
		't': "tomato",
		'u': "beef",
	}

	result := []string{"shell"}
	for _, symbol := range word {
		symbol = unicode.ToLower(symbol)
		if ingredient, found := dictionary[symbol]; found {
			result = append(result, ingredient)
		}
	}
	result = append(result, "shell")
	return result
}
