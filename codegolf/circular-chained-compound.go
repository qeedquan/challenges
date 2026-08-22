/*

Task
Given a positive integer n, output the joined compound of circles

The circles are of square of size n+2 but removing the corner edges and the middle, before finally overlapping n times of itself

E.g.

2
->

####
####
####
####
->

 ##
#  #
#  #
 ##
->

 ## ##
#  #  #
#  #  #
 ## ##

Testcases
1
->
 #
# #
 #

2
->
 ## ##
#  #  #
#  #  #
 ## ##


3
->
 ### ### ###
#   #   #   #
#   #   #   #
#   #   #   #
 ### ### ###


4
->
 #### #### #### ####
#    #    #    #    #
#    #    #    #    #
#    #    #    #    #
#    #    #    #    #
 #### #### #### ####
Trailing spaces are allowed

You have to use the character #

You have to join the strings by newlines (no lists)

This is code-golf, so shortest code wins!

*/

package main

import "fmt"

func main() {
	for i := 0; i <= 10; i++ {
		circularchain(i)
	}
}

func circularchain(n int) {
	fmt.Printf("n=%d\n", n)
	n += 1
	for y := 0; y <= n; y++ {
		for x := 0; x <= n*(n-1); x++ {
			if not(x%n)^truth(y^n != 0 && y != 0) != 0 {
				fmt.Print(" ")
			} else {
				fmt.Print("#")
			}
		}
		fmt.Println("")
	}
	fmt.Println("")
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}

func not(x int) int {
	if x == 0 {
		return 1
	}
	return 0
}
