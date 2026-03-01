/*

4-state barcodes
Many postal services (Royal Mail UK, Canada Post, US Mail, etc) use a 4-state barcode to encode information about their mail. Rendered in ASCII, it may look something like this:

|   | |   | | | |   |     |   |
| | | | | | | | | | | | | | | | |
    | |   |   | | |   |     |
A 4-state barcode is a row of bars. Each bar can be extended upwards, downwards, or both, allowing 4 possibilities. This means that each bar essentially represents a base 4 digit:

            |       |
Bar:    |   |   |   |
                |   |

Digit:  0   1   2   3
The problem with this symbology is that it each barcode is a valid, different barcode upside down: drastically changing the meaning if the orientation is incorrect. Therefore, a start and stop sequence are normally implemented so the scanner can calculate which way it is supposed to be read.

For the purpose of this challenge, we will be using the start/stop sequence specified by Australia Post: each barcode begins and ends with a 1 0 sequence.

The Challenge
Your task is to write a program or function which, given a positive integer N, converts it to an ASCII 4-state barcode, where each bar (except for the start/stop sequences) represents a digit in the base-4 representation of N.

Example:
Given the integer 19623, we would first convert it to its base-4 representation, 10302213.

We would then map each digit to the corresponding bar:

1 0 3 0 2 2 1 3

|   |       | |
| | | | | | | |
    |   | |   |
Finally, we would add the start/stop sequences:

Start:              End:
1 0                 1 0

|   |   |       | | |
| | | | | | | | | | | |
        |   | |   |
The resulting barcode should be the program's output.

Rules:
The input will be a positive integer, within the range of your language's standard integer size.
The output:
May be either a list of lines, or a string containing newlines.
May contain leading or trailing newlines/spaces, as long as the shape remains intact.
Should show the barcode with the above format - it must use the pipe character (|) and space character () when drawing bars, and there should be 1 space in between each upright bar.
This is code-golf, so the shortest program (in bytes) wins!
Test Cases
4095:

|   | | | | | | |
| | | | | | | | | |
    | | | | | |
4096:

|   |             |
| | | | | | | | | | |

7313145:

|   |   | |   | |   | |   | |
| | | | | | | | | | | | | | | |
      | | | |     | | | |

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	barcode(19623)
	barcode(4095)
	barcode(4096)
	barcode(7313145)
}

func barcode(n uint64) {
	fmt.Println(n)
	x := "10" + strconv.FormatUint(n, 4) + "10"
	for y := 0; y < 3; y++ {
		for _, r := range x {
			switch {
			case r == '0' && y == 1,
				r == '1' && y < 2,
				r == '2' && y > 0,
				r == '3':
				fmt.Print("| ")
			default:
				fmt.Print("  ")
			}
		}
		fmt.Println()
	}
}
