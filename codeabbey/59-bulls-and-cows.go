/*

This is an old game for two players, often played with paper and pen. Modern version is also known as Mastermind.

First player, let it be Alice - chooses a secret 4-digit code (like 1492), with all digits different.

The second player, let it be Barbara - makes several attempts to guess this code. She can offer any combinations of 4 digits (without repetitions) - and for each attempt the Alice should answer with a hint.

The hint consists of two values:

first tells how many digits are guessed correctly and are in correct positions;
second tells how many digits are guessed correctly but are in wrong positions.
For example, if the secret value is 1492 and Barbara's guess is 2013 - Alice should answer with 0-2.
And if the guess is 1865, then the hint would be 1-0.

This game could also be played with 4-letter words, but in this case it may require the knowledge of the language.
Further information could be found in the dedicated wikipedia article.

Problem statement
Your goal is to write a program which calculates the values which should be told as a hint to the given guess.

Input data will contain the secret value and the number of guesses in the first line.
Second line will contain the specified amount of guesses.
Answer should contain hints for these guesses, they should be given in format X-Y and separated with spaces.

Example:

input data:
1492 5
2013 1865 1234 4321 7491

answer:
0-2 1-0 1-2 0-3 2-1

*/

package main

import "fmt"

func main() {
	secret := uint(1492)
	assert(solve(secret, 2013) == "0-2")
	assert(solve(secret, 1865) == "1-0")
	assert(solve(secret, 1234) == "1-2")
	assert(solve(secret, 4321) == "0-3")
	assert(solve(secret, 7491) == "2-1")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(secret, value uint) string {
	lookup1 := indexize(secret)
	lookup2 := indexize(value)
	correct1 := 0
	correct2 := 0
	for number, positions := range lookup2 {
		for position := range positions {
			if lookup1[number][position] {
				correct1 += 1
			} else if len(lookup1[number]) > 0 {
				correct2 += 1
			}
		}
	}
	return fmt.Sprintf("%d-%d", correct1, correct2)
}

func indexize(value uint) map[uint]map[uint]bool {
	lookup := make(map[uint]map[uint]bool)
	for index := range uint(10) {
		lookup[index] = make(map[uint]bool)
	}

	position := uint(0)
	for {
		lookup[value%10][position] = true
		if value /= 10; value == 0 {
			break
		}
		position += 1
	}
	return lookup
}
