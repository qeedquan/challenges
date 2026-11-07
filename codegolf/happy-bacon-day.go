/*

Today is Bacon Day which is probably why the name of the hat for participating today is "Mmmm Bacon". What better way to celebrate bacon day with fun filled 2d matrices made out of bacon! A 1 by 1 bacon strip is represented by this:

-----
)===)
(===(
)===)
-----
You goal here is given two coordinates in a tuple, (x, y), where x and y are nonzero positive integers, you are to create the bacon and return in some format (list, array, string).

Input and Output:

Input: (2, 1)

Output:
----------
)===))===)
(===((===(
)===))===)
----------

Input: (1, 2)

Output:

-----
)===)
(===(
)===)
-----
)===)
(===(
)===)
-----

Input: (2, 2)

----------
)===))===)
(===((===(
)===))===)
----------
)===))===)
(===((===(
)===))===)
----------
Rules:

As you can see with the second test case, if multiple pieces of bacon are stacked together, only one ----- separates with each piece of bacon above and/or below it. That means stacking bacon like this is invalid:

-----
)===)
(===(
)===)
-----
-----
)===)
(===(
)===)
-----
Standard loopholes are forbidden

The code must work for the above test cases and the following: (4, 4), (1, 6), (5, 1), (2, 3), (3, 2)

Provide an interpreter where the above test cases can be tested

Winning Criteria:

Shortest code wins! Happy Bacon Day to everyone!



*/

package main

import "fmt"

func main() {
	bacon(2, 1)
	bacon(1, 2)
	bacon(2, 2)
	bacon(4, 4)
	bacon(1, 6)
	bacon(5, 1)
	bacon(2, 3)
	bacon(3, 2)
}

func bacon(w, h int) {
	fmt.Printf("(%dx%d)\n", w, h)
	if w < 1 || h < 1 {
		return
	}

	w = 5*w + 1
	for i := range 4*w*h + w {
		c := '\n'
		if i%w < w-1 {
			c = '-'
			if i/w%4 != 0 {
				c = '='
				if i%w%5%4 == 0 {
					c = '(' + rune(i/w%2)
				}
			}
		}
		fmt.Printf("%c", c)
	}
	fmt.Println()
}
