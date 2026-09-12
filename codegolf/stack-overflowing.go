/*

(Inspired by this question)
https://codegolf.stackexchange.com/questions/80961/stack-exchanging

Objective
Your task is to write a program or function to print an ASCII version of the Stack Overflow logo to STDOUT

 \|/
(-)
(-)
(-)
(-)
Your program should take two inputs, referred to here as H and N. The height of the stack "container" (the parentheses) is determined by H. The number of items in the stack is determined by N. If N>H, the stack will "overflow".

Input/Output
H will determine the height of the containers

For example:

H=1:

( )
H=2:

( )
( )
H=3:

( )
( )
( )
H will always be at least 1

N will determine how many items are in the stack. The following examples are all H = 2:

N=0

( )
( )
N=1

( )
(-)
N=2

(-)
(-)
N=3

 \
(-)
(-)
N=4

 \|
(-)
(-)
N=5

 \|/
(-)
(-)
N=6

 \|/
(-)-
(-)
N=7

 \|/
(-)-
(-)-
N will never be more than 2H+3 (In other words, the stack will never go through the ground).

Rules
No Standard Loopholes.
Your program must not produce any errors.
All test cases must pass.
You can input H and N any way you want.
I seriously doubt that your language has a built-in for this.
Each line may optionally have an extra space at the end. A blank line above a stack where N <= H is optional, as is a trailing newline.
This is code-golf, so shortest code in bytes wins!
Test Cases
In addition to all of the H=2 test cases from the Input/Output section, all of the following test cases must pass:

H=1, N=1

(-)
H=1, N=5

 \|/
(-)-
H=4, N=7

 \|/
(-)
(-)
(-)
(-)
H=5, N=0

( )
( )
( )
( )
( )

*/

package main

import "fmt"

func main() {
	for h := range 4 {
		logo(h, 0)
	}
	for n := range 8 {
		logo(2, n)
	}
	logo(1, 1)
	logo(1, 5)
	logo(4, 7)
	logo(5, 0)
}

func logo(h, n int) {
	fmt.Printf("h=%d n=%d\n", h, n)

	s := " \\|/( ) (-) (-)-"
	t := max(min(n-h, 3), 0)
	n -= t
	fmt.Println(s[:t+1])
	for ; h > 0; h-- {
		switch {
		case n > h:
			t = 2
		case h > n:
			t = 0
		default:
			t = 1
		}
		n -= t
		i := 4 + 4*t
		fmt.Println(s[i : i+4])
	}
	fmt.Println()
}
