/*

The Xerox Alto, originally released in 1973, was the first computer to feature the now-familiar angled mouse pointer. The Alto's bitmapped pointer looked like this (redrawn from Fig. 2 here):

https://i.sstatic.net/sEyuYm.png

Your task in this code-golf challenge is to write a program/function that generates an ASCII art representation of the mouse pointer pictured above. Rules:

Input is a positive integer n, which is a scaling factor for the output.
Represent each black pixel as an n×n block of any single printable character. (The test cases use @, which vaguely resembles a mouse viewed from above.)
Similarly, represent each empty pixel to the bottom/left of the pointer as an n×n block of a second printable character. (Spaces are used in the test cases.)
Optionally, your output may also include the empty pixels to the top/right of the pointer, represented by the same character chosen under Rule 3.
Any sensible output format (e.g. multi-line string, array of strings, matrix of characters) is acceptable.
A single trailing newline at the end of the output is permitted.

Test cases
n=1

@
@@
@@@
@@@@
@@@@@
@@@@@@
@@@@@@@
@@@@
@@ @@
@  @@
    @@
    @@
     @@
     @@
      @@
      @@
n=2

@@
@@
@@@@
@@@@
@@@@@@
@@@@@@
@@@@@@@@
@@@@@@@@
@@@@@@@@@@
@@@@@@@@@@
@@@@@@@@@@@@
@@@@@@@@@@@@
@@@@@@@@@@@@@@
@@@@@@@@@@@@@@
@@@@@@@@
@@@@@@@@
@@@@  @@@@
@@@@  @@@@
@@    @@@@
@@    @@@@
        @@@@
        @@@@
        @@@@
        @@@@
          @@@@
          @@@@
          @@@@
          @@@@
            @@@@
            @@@@
            @@@@
            @@@@
n=3

@@@
@@@
@@@
@@@@@@
@@@@@@
@@@@@@
@@@@@@@@@
@@@@@@@@@
@@@@@@@@@
@@@@@@@@@@@@
@@@@@@@@@@@@
@@@@@@@@@@@@
@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@
@@@@@@@@@@@@
@@@@@@@@@@@@
@@@@@@   @@@@@@
@@@@@@   @@@@@@
@@@@@@   @@@@@@
@@@      @@@@@@
@@@      @@@@@@
@@@      @@@@@@
            @@@@@@
            @@@@@@
            @@@@@@
            @@@@@@
            @@@@@@
            @@@@@@
               @@@@@@
               @@@@@@
               @@@@@@
               @@@@@@
               @@@@@@
               @@@@@@
                  @@@@@@
                  @@@@@@
                  @@@@@@
                  @@@@@@
                  @@@@@@
                  @@@@@@

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 3; i++ {
		cursor(i)
	}
}

func cursor(n int) {
	mask := []int{
		0x03, 0x03, 0x06, 0x06, 0x0c, 0x0c, 0x98, 0xd8,
		0xf0, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80,
		0x00,
	}
	for i := 16*n - 1; i >= 0; i-- {
		for j := 8*n - 1; j >= 0; j-- {
			if (mask[i/n]>>(j/n))&1 != 0 {
				fmt.Printf("@")
			} else {
				fmt.Printf(" ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}
