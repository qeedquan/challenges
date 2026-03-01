/*

You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni].
For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a').
Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

Example 1:

Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
Output: "ace"
Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
Example 2:

Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
Output: "catz"
Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".


Constraints:

1 <= s.length, shifts.length <= 5 * 10^4
shifts[i].length == 3
0 <= starti <= endi < s.length
0 <= directioni <= 1
s consists of lowercase English letters.

Hint 1
Instead of shifting every character in each shift, could you keep track of which characters are shifted and by how much across all shifts?

Hint 2
Try marking the start and ends of each shift, then perform a prefix sum of the shifts.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	test(
		"abc", [][3]int{{0, 1, 0}, {1, 2, 1}, {0, 2, 1}},
		"ace",
	)

	test(
		"dztz", [][3]int{{0, 0, 0}, {1, 1, 1}},
		"catz",
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(input string, shifts [][3]int, expected string) {
	output := shiftletters(input, shifts)
	fmt.Println(output)
	assert(output == expected)
}

func shiftletters(input string, shifts [][3]int) string {
	events := make([]int, len(input)+1)
	for _, shift := range shifts {
		step := 1
		if shift[2] == 0 {
			step = -1
		}
		events[shift[0]] += step
		events[shift[1]+1] -= step
	}

	output := new(bytes.Buffer)
	current := 0
	for i := range input {
		current += events[i]
		symbol := 'a' + ((int(input[i])-'a'+current)%26+26)%26
		output.WriteByte(byte(symbol))
	}
	return output.String()
}
