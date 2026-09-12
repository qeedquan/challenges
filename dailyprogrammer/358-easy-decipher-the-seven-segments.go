/*

Description
Today's challenge will be to create a program to decipher a seven segment display, commonly seen on many older electronic devices.

Input Description
For this challenge, you will receive 3 lines of input, with each line being 27 characters long (representing 9 total numbers), with the digits spread across the 3 lines. Your job is to return the represented digits. You don't need to account for odd spacing or missing segments.

Output Description
Your program should print the numbers contained in the display.

Challenge Inputs
    _  _     _  _  _  _  _
  | _| _||_||_ |_   ||_||_|
  ||_  _|  | _||_|  ||_| _|

    _  _  _  _  _  _  _  _
|_| _| _||_|| ||_ |_| _||_
  | _| _||_||_| _||_||_  _|

 _  _  _  _  _  _  _  _  _
|_  _||_ |_| _|  ||_ | ||_|
 _||_ |_||_| _|  ||_||_||_|

 _  _        _  _  _  _  _
|_||_ |_|  || ||_ |_ |_| _|
 _| _|  |  ||_| _| _| _||_
Challenge Outputs
123456789
433805825
526837608
954105592
Ideas!
If you have an idea for a challenge please share it on r/dailyprogrammer_ideas and there's a good chance we'll use it.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	decipher(INPUT1)
	decipher(INPUT2)
	decipher(INPUT3)
	decipher(INPUT4)
}

var numbers = map[string]int{
	" _ | ||_|": 0,
	"     |  |": 1,
	" _  _||_ ": 2,
	" _  _| _|": 3,
	"   |_|  |": 4,
	" _ |_  _|": 5,
	" _ |_ |_|": 6,
	" _   |  |": 7,
	" _ |_||_|": 8,
	" _ |_| _|": 9,
}

func decipher(input string) {
	lines := strings.Split(input, "\n")
	lines = trim(lines)
	if len(lines) != 3 {
		return
	}

	for i := 0; i+2 < len(lines[0]); i += 3 {
		num := lines[0][i : i+3]
		num += lines[1][i : i+3]
		num += lines[2][i : i+3]
		fmt.Print(numbers[num])
	}
	fmt.Println()
}

func trim(lines []string) []string {
	result := []string{}
	for _, line := range lines {
		if strings.TrimSpace(line) != "" {
			result = append(result, line)
		}
	}
	return result
}

const INPUT1 = `
    _  _     _  _  _  _  _ 
  | _| _||_||_ |_   ||_||_|
  ||_  _|  | _||_|  ||_| _|
`

const INPUT2 = `
    _  _  _  _  _  _  _  _ 
|_| _| _||_|| ||_ |_| _||_ 
  | _| _||_||_| _||_||_  _|
`

const INPUT3 = `
 _  _  _  _  _  _  _  _  _ 
|_  _||_ |_| _|  ||_ | ||_|
 _||_ |_||_| _|  ||_||_||_|
`

const INPUT4 = `
 _  _        _  _  _  _  _ 
|_||_ |_|  || ||_ |_ |_| _|
 _| _|  |  ||_| _| _| _||_ 
 `
