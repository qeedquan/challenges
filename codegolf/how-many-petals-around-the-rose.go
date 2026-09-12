/*

How many petals around the rose
How many petals around the rose is a dice game you can play with your friends. Similar to "can I join the music box", there is a person that knows how the game works and the others have to discover the rule.

In this game, someone rolls some dice (usually two or more) and then people have to call "how many petals are around the rose".

Algorithm
If you want to play it by yourself, you can play it over at TIO. Just hide the header (which is where the rule is implemented) and try passing different arguments (from 1 to 6) in the function.

spoiler, what follows is the rule you are invited to find by yourself!


enter image description here

Input
Your input will be a non-empty list (or equivalent) of integers in the range [1, 6].

Output
The number of petals around the rose.

Test cases
Reference implementation in Python, that also generated the test cases.

1, 1 -> 0
1, 2 -> 0
1, 3 -> 2
1, 4 -> 0
1, 5 -> 4
1, 6 -> 0
2, 1 -> 0
2, 2 -> 0
2, 3 -> 2
2, 4 -> 0
2, 5 -> 4
2, 6 -> 0
3, 1 -> 2
3, 2 -> 2
3, 3 -> 4
3, 4 -> 2
3, 5 -> 6
3, 6 -> 2
4, 1 -> 0
4, 2 -> 0
4, 3 -> 2
4, 4 -> 0
4, 5 -> 4
4, 6 -> 0
5, 1 -> 4
5, 2 -> 4
5, 3 -> 6
5, 4 -> 4
5, 5 -> 8
5, 6 -> 4
6, 1 -> 0
6, 2 -> 0
6, 3 -> 2
6, 4 -> 0
6, 5 -> 4
6, 6 -> 0
3, 1, 5 -> 6
4, 5, 2 -> 4
4, 3, 5 -> 6
1, 4, 4 -> 0
5, 5, 2 -> 8
4, 1, 1 -> 0
3, 4, 1 -> 2
4, 3, 5 -> 6
4, 4, 5 -> 4
4, 2, 1 -> 0
3, 5, 5, 2 -> 10
6, 1, 4, 6, 3 -> 2
3, 2, 2, 1, 2, 3 -> 4
3, 6, 1, 2, 5, 2, 5 -> 10

This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it... And happy golfing!

def petals(*roses):
  petals = 0
  for rose in roses:
    if rose == 3:
      petals += 2
    elif rose == 5:
      petals += 4
  return petals

*/

package main

func main() {
	assert(petals(1, 1) == 0)
	assert(petals(1, 2) == 0)
	assert(petals(1, 3) == 2)
	assert(petals(1, 4) == 0)
	assert(petals(1, 5) == 4)
	assert(petals(1, 6) == 0)
	assert(petals(2, 1) == 0)
	assert(petals(2, 2) == 0)
	assert(petals(2, 3) == 2)
	assert(petals(2, 4) == 0)
	assert(petals(2, 5) == 4)
	assert(petals(2, 6) == 0)
	assert(petals(3, 1) == 2)
	assert(petals(3, 2) == 2)
	assert(petals(3, 3) == 4)
	assert(petals(3, 4) == 2)
	assert(petals(3, 5) == 6)
	assert(petals(3, 6) == 2)
	assert(petals(4, 1) == 0)
	assert(petals(4, 2) == 0)
	assert(petals(4, 3) == 2)
	assert(petals(4, 4) == 0)
	assert(petals(4, 5) == 4)
	assert(petals(4, 6) == 0)
	assert(petals(5, 1) == 4)
	assert(petals(5, 2) == 4)
	assert(petals(5, 3) == 6)
	assert(petals(5, 4) == 4)
	assert(petals(5, 5) == 8)
	assert(petals(5, 6) == 4)
	assert(petals(6, 1) == 0)
	assert(petals(6, 2) == 0)
	assert(petals(6, 3) == 2)
	assert(petals(6, 4) == 0)
	assert(petals(6, 5) == 4)
	assert(petals(6, 6) == 0)
	assert(petals(3, 1, 5) == 6)
	assert(petals(4, 5, 2) == 4)
	assert(petals(4, 3, 5) == 6)
	assert(petals(1, 4, 4) == 0)
	assert(petals(5, 5, 2) == 8)
	assert(petals(4, 1, 1) == 0)
	assert(petals(3, 4, 1) == 2)
	assert(petals(4, 3, 5) == 6)
	assert(petals(4, 4, 5) == 4)
	assert(petals(4, 2, 1) == 0)
	assert(petals(3, 5, 5, 2) == 10)
	assert(petals(6, 1, 4, 6, 3) == 2)
	assert(petals(3, 2, 2, 1, 2, 3) == 4)
	assert(petals(3, 6, 1, 2, 5, 2, 5) == 10)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func petals(roses ...int) int {
	total := 0
	for _, rose := range roses {
		switch rose {
		case 3:
			total += 2
		case 5:
			total += 4
		}
	}
	return total
}
