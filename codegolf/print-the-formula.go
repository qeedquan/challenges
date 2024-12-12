/*

Introduction
In chemistry there is a type of extension, .xyz extension,(https://en.wikipedia.org/wiki/XYZ_file_format), that prints in each line a chemical element, and the coordinates in the plane of the element. This is very useful for chemists to understand chemical compounds and to visualize the compounds in 3D. I thought it would be fun to, given a .xyz file, print the chemical formula.

Challenge
Given an .xyz file, print the chemical formula of the compound in any programming language in the smallest possible number of bytes. Note:

Originally, the input was to be given as a file. As I have been pointed out, this constraints the challenge. Therefore you may assume the input is a list/array of strings, each representing a line of the .xyz file.
There are no restrictions in the ordering of the elements.
Each element should be printed with an underscore "_" delimiting the element and the number of times it appears
The first two lines of any .xyz file is the number of elements, and a comment line (keep that in mind).
Example Input and Output
Suppose you have a file p.xyz which contains the following (where the first line is the number of elements, and the second a comment), input:

5
A mystery chemical formula...
Ba      0.000   0.000  0.000
Hf      0.5     0.5    0.5
O       0.5     0.5    0.000
O       0.5     0.000  0.5
O       0.000   0.5    0.5
Output:
Ba_1Hf_1O_3

Testing
A quick test is with the example mentioned. A more thorough test is the following: since the test file is thousands of lines, I'll share the .xyz file:
https://gist.github.com/nachonavarro/1e95cb8bbbc644af3c44

*/

package main

import (
	"bufio"
	"fmt"
	"sort"
	"strings"
)

func main() {
	assert(formula(BAHFO3) == "Ba_1Hf_1O_3")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func formula(text string) string {
	text = strings.TrimSpace(text)
	reader := strings.NewReader(text)
	scan := bufio.NewScanner(reader)

	var (
		state      int
		nelements  int
		element    string
		substances = make(map[string]int)
	)
	for scan.Scan() {
		line := scan.Text()
		switch state {
		case 0:
			fmt.Sscanf(line, "%d", &nelements)
			state = 1
		case 1:
			state = 2
		case 2:
			fmt.Sscanf(line, "%s", &element)
			substances[element] += 1
		}
	}

	result := []string{}
	for element, count := range substances {
		result = append(result, fmt.Sprintf("%s_%d", element, count))
	}
	sort.Strings(result)
	return strings.Join(result, "")
}

const BAHFO3 = `
5
A mystery chemical formula...
Ba      0.000   0.000  0.000
Hf      0.5     0.5    0.5
O       0.5     0.5    0.000
O       0.5     0.000  0.5
O       0.000   0.5    0.5
`
