/*

Lost is a 2-D programming language where the start position and direction of the ip are entirely random.

Today we will be writing a Lost program which uses this randomness to simulate a coin flip.

A coin flip can have 3 outcomes:

It lands on "heads"
It lands on "tails"
It lands perfectly balanced on the side
To simulate these outcomes your program should output:

"Heads!"
"Tails!"
"Side?!"
Heads and tails are equally likely while landing on the side is extremely unlikely, so your program should output "Heads!" about as often as it outputs "Tails!", specifically of all the possible start states the number of heads and tails should differ by at most 1. The side is extremely unlikely so of all the possible start conditions exactly 1 should output "Side?!" when run.

No other output should occur, and your program should deterministically halt.

Answers must be in Lost. To simulate all the outputs you should run your program with the -Q flag.

You may assume no input is passed to the program.

This is code-golf, so the goal is to minimize the size of your program as measured in bytes.

Description of Lost
[Lost appears in the EsoLang Wiki at https://esolangs.org/wiki/Lost]

Lost operates on a grid where each instruction is a character of the source. Lost's instruction pointer (ip) moves through the grid in one of the four cardinal directions. When it goes off one side of the grid it wraps around to the other as if the program were written on a torus.

Lost's memory is stored in a main stack and a scope. Both are stacks padded with zeros at the bottom. At the end of execution the contents of the main stack are printed and the scope discarded. Lost also stores a single value called the "safety", which begins on.

Programs can only terminate when the safety is off.

Doors
[ Reflects the ip if it is moving east; becomes ] if the ip is moving horizontally

] Reflects the ip if it is moving west; becomes [ if the ip is moving horizontally

Jumps
! Skips the next operation

? Pops off the top of the stack and jumps if not zero

Stack manipulation
: Duplicates the top of the stack

$ Swaps the top two items of the stack

( Pops from the stack and pushes to the scope

) Pops from the scope and pushes to the stack

Literals
0-9 pushes n to the top of the stack

" Starts and ends a string literal. During a string literal commands are not run and instead their character values are pushed to the stack.

Operations
+ Adds the top two numbers

* Multiplies the top two numbers

- Multiplies the top by -1

Flow
\ Swaps the x and y directions

/ Swaps the x and y directions and multiplies them by -1

| Multiplies the horizontal direction by -1

> Tells the ip to move east

< Tells the ip to move west

v Tells the ip to move south

^ Tells the ip to move north

Control
% Turns the safety off

# Turns the safety on

@ Ends execution if the safety is off (starts on)

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	sim(1000)
}

func sim(n int) {
	p, o, h, t, s := rand.Perm(n), rand.Intn(2), 0, 0, 0
	for i := range p {
		switch {
		case p[i] == 0:
			fmt.Println("Side?!")
			s++
		case p[i]&1 == o&1:
			fmt.Println("Heads!")
			h++
		default:
			fmt.Println("Tails!")
			t++
		}
	}
	fmt.Printf("Heads: %d Tails: %d Sides: %d\n", h, t, s)
}
