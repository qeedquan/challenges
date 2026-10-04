/*

Room Number Locator
I have come across an interesting problem solving technique at my job when given the wrong room number from a colleague for a meeting. Every now and then, while on the way to a meeting, a member on my team will send me the wrong room number, typically because they are in a rush at their desk and fat finger the wrong key.

Interestingly, upon arrival at the wrong room, I typically can guess which room they really meant by imagining a Numeric Keypad:

https://upload.wikimedia.org/wikipedia/commons/thumb/9/99/Numpad.svg/220px-Numpad.svg.png

and by guessing an adjacent number they meant to press.

Challenge
Your challenge is to write a function that takes a building office number (000-999) and outputs the possible typo solutions, assuming your colleague only mistypes one digit.

The following table shows which numbers are adjacent to each other on a Numeric Keypad:

0 -> 1,2
1 -> 0,2,4
2 -> 0,1,3,5
3 -> 2,6
4 -> 1,5,7
5 -> 2,4,6,8
6 -> 3,5,9
7 -> 4,8
8 -> 5,7,9
9 -> 6,8

Input
A 3 digit number: 000-999. Assume input of exactly 3 digits. If the number is less than 100 or less than 10, you will be given the leading zeros. (i.e. 004 & 028).

Output
A list of possible rooms. This can be in any form you want, as long as there is a delimiter between room numbers. (i.e. space, comma, new line, etc..) If the number is less than 100 or less than 10, you can or cannot have the leading zeros as output, that is up to you. (i.e. 004 can be 004 04 4, and 028 can be 028 28)

Test Cases(leading zeros are optional):

008 -> 108, 208, 018, 028, 005, 007, 009
123 -> 023, 223, 423, 103, 113, 133, 153, 122, 126
585 -> 285, 485, 685, 885, 555, 575, 595, 582, 584, 586, 588
777 -> 477, 877, 747, 787, 774, 778
963 -> 663, 863, 933, 953, 993, 962, 966
555 -> 255, 455, 655, 855, 525, 545, 565, 585, 552, 554, 556, 558

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(8, []int{108, 208, 18, 28, 5, 7, 9})
	test(123, []int{23, 223, 423, 103, 113, 133, 153, 122, 126})
	test(585, []int{285, 485, 685, 885, 555, 575, 595, 582, 584, 586, 588})
	test(777, []int{477, 877, 747, 787, 774, 778})
	test(963, []int{663, 863, 933, 953, 993, 962, 966})
	test(555, []int{255, 455, 655, 855, 525, 545, 565, 585, 552, 554, 556, 558})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r []int) {
	p := rooms(n)
	fmt.Println(p)
	sort.Ints(r)
	assert(reflect.DeepEqual(p, r))
}

// Based on @gastropner solution
func rooms(n int) []int {
	tab := []int{12, 240, 1350, 26, 157, 2468, 359, 48, 579, 68}
	r := []int{}
	for d, i := 10, 100; i > 0; i /= d {
		for p := tab[n/i%d]; p > 0; p /= d {
			r = append(r, n/(i*d)*(i*d)+(p%d*i)+(n%i))
		}
	}
	sort.Ints(r)
	return r
}
