/*

An Octothorpe, (also called number sign, hash or hashtag, or pound sign) is the following ASCII character:

#
Isn't that a fun shape? Lets make bigger versions of it! So here is your challenge:

Given a positive integer N, output an ASCII hashtag of size N.

For example, an ASCII hashtag of size 1 looks like this:

 # #
#####
 # #
#####
 # #
Trailing whitespace on each line is allowed, but not required.

The input will always be a valid positive integer, so you don't have to handle non-numbers, negative, or 0. Your output can be in any reasonable format, so outputting to STDOUT, returning a list of strings, or string with newlines, a 2D matrix of characters, writing to a file, etc. are all fine.

Test cases
2:
  ##  ##
  ##  ##
##########
##########
  ##  ##
  ##  ##
##########
##########
  ##  ##
  ##  ##

3:
   ###   ###
   ###   ###
   ###   ###
###############
###############
###############
   ###   ###
   ###   ###
   ###   ###
###############
###############
###############
   ###   ###
   ###   ###
   ###   ###

4:
    ####    ####
    ####    ####
    ####    ####
    ####    ####
####################
####################
####################
####################
    ####    ####
    ####    ####
    ####    ####
    ####    ####
####################
####################
####################
####################
    ####    ####
    ####    ####
    ####    ####
    ####    ####

5:
     #####     #####
     #####     #####
     #####     #####
     #####     #####
     #####     #####
#########################
#########################
#########################
#########################
#########################
     #####     #####
     #####     #####
     #####     #####
     #####     #####
     #####     #####
#########################
#########################
#########################
#########################
#########################
     #####     #####
     #####     #####
     #####     #####
     #####     #####
     #####     #####

Since this is a code-golf, try to write the shortest possible solution you can, and above all else, have fun!

*/

package main

import "fmt"

func main() {
	for i := 0; i <= 5; i++ {
		octothorpe(i)
	}
}

func octothorpe(n int) {
	fmt.Printf("n=%d\n\n", n)
	s := 5 * n
	for x := 0; x < s; x++ {
		for y := 0; y < s; y++ {
			c := ' '
			if (x/n)&1+(y/n)&1 > 0 {
				c = '#'
			}
			fmt.Printf("%c", c)
		}
		fmt.Println()
	}
	fmt.Println()
}
