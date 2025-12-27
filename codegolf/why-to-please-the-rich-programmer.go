/*

Have you ever wanted to ask the compiler "Why?" Most of us have been frustrated when the code isn't working as it should. Mathworks has therefore implemented a nice little function, why, that answers the question. To give a few examples from MATLAB:

why
The programmer suggested it.

why
To fool the tall good and smart system manager.

why(2)
You insisted on it.

why(46)
Bill insisted on it.
Your task is to implement the why function in your language. The function should work with and without an input argument (alternatively use input 0 or -1). The function must be named why (or, writing why(n) in STDIN should result in the appropriate string being printed).

If no argument is given, or the argument is zero or negative, the output string should be a random, valid phrase. So, there should be a function why, why(), why(0) or why(-1) that returns a random sentence.

If an input argument, n is given (function argument, not STDIN), the output should be the n'th string (defined below). So, why(1) should always output (print/display) the same result.

The sentences are built up as follows (Type 1, Type 2 and Special). All sentences end with !.

"Person" "ending" !
"Verb" "adjective" "Person" !
A list of special cases
The list of persons:

Stewie
Peter
Homer
The programmer
The system manager
You
The list of endings:

suggested it
insisted on it
did it
The list of verbs are:

To fool
To satisfy
To please
The list of adjectives:

the smart
the bald
the tall
the rich
the stupid
The list of special cases:

How should I know?
Stop asking!
Don't ask!
The way to select a numbered one is:

Type of sentences:

Odd number => Type 1
Even number => Type 2
n % 7 = 0 => Type 3 (% is the modulus operator)
Names: The nth name is defined using modulus (%).

n = 1:   1 % 7  => Stewie
n = 2:   2 % 7  => Peter
...
n = 6:   6 % 7  => You
n = 7:   7 % 7  => How should I know?
n = 11:  11 % 7 => The programmer
n = 14:  14 % 7 => Stop asking!
n = 21:  21 % 7 => Don't ask!
Endings: The nth ending is also defined using the modulus. Assume the endings (1, 2 and 3) are listed like (1 2 2 3). As the numbers are always odd, use ((n+1)/2 % 4)

n = 1:    ((1+1)/2 % 4)  => suggested it
n = 3:    ((3+1)/2 % 4)  => insisted on it
n = 13:   ((13+1)/2 % 4) => did it
Adjectives: The nth adjective is defined using the modulus. As the numbers are always even, use: (n % 10)/2

n = 2:   (2 % 10)/2 => Smart
n = 6:   (6 % 10)/2 => The tall
...
Verbs: The nth verb is also defined using the modulus. Assume the verbs (1, 2 and 3) are listed like (1 2 2 3) As the numbers are always even for verbs, use (n % 8) / 2

n = 2:   (2 % 8)/2 => To fool
n = 4:   (4 % 8)/2 => To satisfy
n = 6:   (6 % 8)/2 => To satisfy
n = 8:   (8 % 8)/2 => To please
Now, the way to create a random one should be fairly simple, simply select a random n.

Some examples:

why
You suggested it!

why
To fool the tall Homer!

why
Don't ask!

why(1)
Stewie suggested it!

why(14)
Stop asking!

why(8)
To please the rich Stewie!

Standard code golf rules apply. A winner will be selected one week from the day the challenge was posted.

*/

package main

import (
	"fmt"
	"math"
	"math/rand"
)

func main() {
	for i := -32; i <= 32; i++ {
		fmt.Println(i, why(i))
	}
	fmt.Println(why())
}

// ported from @user45967 solution
func why(value ...int) string {
	persons := []string{"You", "Stewie", "Peter", "Homer", "programmer", "system manager"}
	endings := []string{"did it", "suggested it", "insisted on it", "insisted on it"}
	verbs := []string{"please", "fool", "satisfy", "satisfy"}
	adjectives := []string{"stupid", "smart", "bald", "tall", "rich"}
	specialcases := []string{"Don't ask!", "How should I know?", "Stop asking!"}

	index := -math.MaxInt/2 + rand.Intn(math.MaxInt)
	if len(value) > 0 {
		index = value[0]
	}

	phrase := ""
	switch {
	case mod(index, 7) == 0:
		phrase = specialcases[mod(index, 3)]

	default:
		person := persons[mod(index, 6)]
		if mod(index, 11) == 0 {
			person = "programmer"
		}

		if mod(index, 2) == 0 {
			if person == "You" {
				person = "you"
			}
			verb := verbs[mod(index, 8)/2]
			adjective := adjectives[mod(index, 10)/2]
			phrase = fmt.Sprintf("To %s the %s %s!", verb, adjective, person)
		} else {
			if person == "programmer" {
				person = "The programmer"
			} else if person == "system manager" {
				person = "The system manager"
			}
			ending := endings[mod((index+1)/2, 4)]
			phrase = fmt.Sprintf("%s %s!", person, ending)
		}
	}
	return phrase
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
