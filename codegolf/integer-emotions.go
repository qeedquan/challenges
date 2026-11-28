/*

Write a program or function that "reacts" to a given integer n (input via function parameter/args/stdin)

The program doesn't care about negative numbers, likes even, dislikes odd numbers and fears the number 13.

It should output the following:

if n<0:

 --------------------------
 |                        |
 |                        |
(|      _          _      |)
 |                        |
 |                        |
 |                        |
 |                        |
 |       oooooooooo       |
 |                        |
 |                        |
 |                        |
 --------------------------
if n%2 == 0 and n>-1:

 --------------------------
 |                        |
 |                        |
(|      ^          ^      |)
 |                        |
 |                        |
 |                        |
 |     o            o     |
 |       oooooooooo       |
 |                        |
 |                        |
 |                        |
 --------------------------
if n%2 == 1 and n>-1 and n!=13:

 --------------------------
 |                        |
 |                        |
(|      >          <      |)
 |                        |
 |                        |
 |                        |
 |                        |
 |       oooooooooo       |
 |     o            o     |
 |                        |
 |                        |
 --------------------------
if n==13:

 --------------------------
 |                        |
 |                        |
(|     (O)        (O)     |)
 |                        |
 |                        |
 |       oooooooooo       |
 |       o        o       |
 |       oooooooooo       |
 |                        |
 |                        |
 |                        |
 --------------------------

The shortest solution in bytes wins.

*/

package main

import "fmt"

func main() {
	emo(-1)
	emo(0)
	emo(1)
	emo(13)
}

func emo(n int) {
	switch {
	case n < 0:
		fmt.Println(EMO1)
	case n%2 == 0:
		fmt.Println(EMO2)
	case n%2 == 1 && n != 13:
		fmt.Println(EMO3)
	case n == 13:
		fmt.Println(EMO4)
	}
}

const EMO1 = `
 --------------------------
 |                        |
 |                        |
(|      _          _      |)
 |                        |
 |                        |
 |                        |
 |                        |
 |       oooooooooo       |
 |                        |
 |                        |
 |                        |
 --------------------------
`

const EMO2 = `
 --------------------------
 |                        |
 |                        |
(|      ^          ^      |)
 |                        |
 |                        |
 |                        |
 |     o            o     |
 |       oooooooooo       |
 |                        |
 |                        |
 |                        |
 --------------------------
 `

const EMO3 = `
 --------------------------
 |                        |
 |                        |
(|      >          <      |)
 |                        |
 |                        |
 |                        |
 |                        |
 |       oooooooooo       |
 |     o            o     |
 |                        |
 |                        |
 --------------------------
 `

const EMO4 = `
 --------------------------
 |                        |
 |                        |
(|     (O)        (O)     |)
 |                        |
 |                        |
 |       oooooooooo       |
 |       o        o       |
 |       oooooooooo       |
 |                        |
 |                        |
 |                        |
 --------------------------
 `
