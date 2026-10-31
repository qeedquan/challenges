/*

According to me, a tornado looks like this:

########
#######
 ######
  #####
   ####
   ###
    ##
     #
This tornado starts out with width n, and on each next line, a character is removed from either the left or the right, depending on the input.

Input
The input will be a list of some sort of any two unique values (a string of two unique characters works too), and an optional positive integer to indicate the starting width. If the optional integer is not taken, then the starting width is 1 greater than the length of the list. Let the starting width be n.

How to make a tornado
In my example, I choose my list to contain 1s and 0s, though you may choose any two distinct constant values, or a string of any two distinct constant characters.

The first row will consist of n non-whitespace characters (you may choose any consistent character; I choose # for my example).

Then, for each number in the list, if the number is 0, remove the left character and create a new row; if it's a 1, remove the right character and create a new row.

Thus, the above tornado is the output for 8, [1, 0, 0, 0, 1, 0, 0].

Output
The output can be a list of strings, a list of lists of characters, or a multiline string. Trailing whitespace on each line is allowed, and a trailing newline at the end is allowed.

Test Cases
These testcases include the starting width and use lists of 1, 0.

5, [1,0,0,1]

#####
####
 ###
  ##
  #

10, [1,0,0,1,0,1,0,0,1]

##########
#########
 ########
  #######
  ######
   #####
   ####
    ###
     ##
     #

7, [1,1,1,1,1,1]

#######
######
#####
####
###
##
#

Rules
Standard loopholes apply
Shortest code in bytes wins! code-golf
Background doesn't have to be a space (I forgot to specify this earlier).
Your language only has to support numbers (widths) that it can handle, but if your interpreter were rewritten with a larger number size, it has to theoretically work.
Reference Implementation

array = [int(element) for element in input().split()]
row = ['#'] * (len(array) + 1)
for element in array:
	print(''.join(row))
	if element:
		for index in range(len(row) - 1, -1, -1):
			if row[index] == '#': row[index] = ' '; break
	else:
		for index in range(len(row)):
			if row[index] == '#': row[index] = ' '; break

*/

package main

import "fmt"

func main() {
	tornado([]int{1, 0, 0, 1})
	tornado([]int{1, 0, 0, 1, 0, 1, 0, 0, 1})
	tornado([]int{1, 1, 1, 1, 1, 1})
}

func tornado(a []int) {
	r := make([]byte, len(a)+1)
	for i := range r {
		r[i] = '#'
	}

	for _, v := range a {
		fmt.Println(string(r))

		x, y, z := 0, len(r), 1
		if v != 0 {
			x, y, z = len(r)-1, -1, -1
		}

		for i := x; i != y; i += z {
			if r[i] == '#' {
				r[i] = ' '
				break
			}
		}
	}
	fmt.Println(string(r))
	fmt.Println()
}
