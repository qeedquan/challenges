/*

Given positive integers w and h output w columns and h rows of text as described below.

The first row begins with 11 0s, the second row with 10 1s, third with nine 2s and so on down the the tenth row with two 9s.
On each of these first ten rows, following the initial run of consecutive digits,
the next lowest digit appears two times before the second next lowest digit appears two times, with this pattern repeating forever.
If a run of 0s occurs, the digits after it are always 9s.

Rows below the tenth row are the same as the row immediately above it but shifted to the right by one.
The new digit that appears is the same as the previous leftmost digit if it was not next to another instance of itself.
Otherwise it is the next highest digit (cycling from 9 back to 0).

The first 11×10 elements are as follows:

00000000000
11111111110
22222222211
33333333221
44444443322
55555544332
66666554433
77776655443
88877665544
99887766554
Here is an image with colored text to make the pattern more clear.
https://i.sstatic.net/sYcT1m.png

If you need to produce fewer columns/rows then you should simply crop the above text.

If you need to produce more columns/rows than this, existing staircases should be extended. If more columns/rows adds new staircases of consecutive digits, digits should be cyclicly chosen from the integers. Thus for input (15,13)
 the output should be

000000000009988
111111111100998
222222222110099
333333332211009
444444433221100
555555443322110
666665544332211
777766554433221
888776655443322
998877665544332
099887766554433
009988776655443
100998877665544
Here is an image of this text with color:
https://i.sstatic.net/BqDCUm.png

Rules
Output can be given by any convenient method.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
You can return a list of lines if you prefer.
You can return a 2D array of digits or list of lists of digits if you prefer.
Standard loopholes disallowed.
Shortest code wins.

Test cases
Input is taken as (w,h) for the test cases.

1,1
0

3,2
000
111

20,1
00000000000998877665

11,10
00000000000
11111111110
22222222211
33333333221
44444443322
55555544332
66666554433
77776655443
88877665544
99887766554

15,13
000000000009988
111111111100998
222222222110099
333333332211009
444444433221100
555555443322110
666665544332211
777766554433221
888776655443322
998877665544332
099887766554433
009988776655443
100998877665544

*/

package main

import "fmt"

func main() {
	sd(1, 1)
	sd(3, 2)
	sd(20, 1)
	sd(11, 10)
	sd(15, 13)
}

func sd(w, h int) {
	fmt.Printf("%d %d\n", w, h)
	for y := range h {
		for x := range w {
			k0 := bool2(x > 10-y)
			k1 := 10*x + 9 - (x+y-11)/2
			fmt.Printf("%c", '0'+(y+k0*k1)%10)
		}
		fmt.Println()
	}
	fmt.Println()
}

func bool2(x bool) int {
	if x {
		return 1
	}
	return 0
}
