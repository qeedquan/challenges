/*

Challenge
Write a program that outputs the lyrics to 99 Bottles of Beer, but instead of "beer", output "fizz" if the number of bottles on the wall is a multiple of 3, "buzz" if it is a multiple of 5, and "fizzbuzz" if it is a multiple of 3 and a multiple of 5. If the number of bottles on the wall is not a multiple of 3 or 5, just output "beer" as usual.

Lyrics
99 bottles of fizz on the wall, 99 bottles of fizz.
Take one down and pass it around, 98 bottles of beer on the wall.

98 bottles of beer on the wall, 98 bottles of beer.
Take one down and pass it around, 97 bottles of beer on the wall.

97 bottles of beer on the wall, 97 bottles of beer.
Take one down and pass it around, 96 bottles of fizz on the wall.

96 bottles of fizz on the wall, 96 bottles of fizz.
Take one down and pass it around, 95 bottles of buzz on the wall.

95 bottles of buzz on the wall, 95 bottles of buzz.
Take one down and pass it around, 94 bottles of beer on the wall.

....

3 bottles of fizz on the wall, 3 bottles of fizz.
Take one down and pass it around, 2 bottles of beer on the wall.

2 bottles of beer on the wall, 2 bottles of beer.
Take one down and pass it around, 1 bottle of beer on the wall.

1 bottle of beer on the wall, 1 bottle of beer.
Go to the store and buy some more, 99 bottles of fizz on the wall.


This is code-golf, so the shortest submission in each language wins.

*/

package main

import "fmt"

func main() {
	output()
}

func output() {
	for i := 99; i > 1; i-- {
		b0 := at(i)
		b1 := at(i - 1)
		s := "s"
		if i == 2 {
			s = ""
		}
		fmt.Printf("%d bottles of %s on the wall, %d bottles of %s.\n", i, b0, i, b0)
		fmt.Printf("Take one down and pass it around, %d bottle%s of %s on the wall.\n\n", i-1, s, b1)
	}
	fmt.Println("1 bottle of beer on the wall, 1 bottle of beer.")
	fmt.Println("Go to the store and buy some more, 99 bottles of fizz on the wall.")
}

func at(n int) string {
	switch {
	case n%15 == 0:
		return "fizzbuzz"
	case n%5 == 0:
		return "buzz"
	case n%3 == 0:
		return "fizz"
	}
	return "beer"
}
