/*

Given an array with 3 subarrays, each containing hexadecimal color codes loosely defining red, green and blue colors based on their predominant byte value, return a string description of which of the three colors each array contains.

Input is an array which contains 3 subarrays. These subarrays contain strings representing colors in RGB format, each string will contain one predominant color channel that is more saturated than the other two. Among all the strings in an subarray only 2 color channels will come up as predominant - the one that appears more often is "major" and the one that appears less often is "minor". Your task is to determine the major and minor colors inside each subarray and return them in the following format: {Major1}+{Minor1},{Major2}+{Minor2},{Major3}+{Minor3}.

Example:

input = [
  ["FFA07A", "FA8072", "8DC4DE"],
  ["7FFF00", "ADFF2F", "FF0000", "00FF7F", "00FF7F"],
  ["ADD8E6", "6B8E23", "9ACD32", "32CD32", "00FF00"]
]

result = "Red+Blue,Green+Red,Green+Blue"
Explanation:

first subarray's predominant colors: Red, Red, Blue (Red is major, Blue is minor)
second subarray's predominant colors: Green, Green, Red, Green, Green (Green is major, Red is minor)
third subarray's predominant colors: Blue, Green, Green, Green, Green (Green is major, Blue is minor)

*/

package main

import (
	"bytes"
	"fmt"
	"math"
	"sort"
	"strings"
)

func main() {
	fmt.Println(colors([][]string{
		{"FFA07A", "FA8072", "8DC4DE"},
		{"7FFF00", "ADFF2F", "FF0000", "00FF7F", "00FF7F"},
		{"ADD8E6", "6B8E23", "9ACD32", "32CD32", "00FF00"},
	}))
}

func colors(inputs [][]string) string {
	channels := []string{"Red", "Green", "Blue"}
	output := new(bytes.Buffer)
	for _, input := range inputs {
		counts := [3][2]int{
			{0, 0},
			{1, 0},
			{2, 0},
		}

		for _, code := range input {
			var values [3]int
			fmt.Sscanf(code, "%02x%02x%02x", &values[0], &values[1], &values[2])

			index := argmax(values[:])
			counts[index][1] += 1
		}

		sort.Slice(counts[:], func(i, j int) bool {
			return counts[i][1] > counts[j][1]
		})

		fmt.Fprintf(output, "%s+%s,", channels[counts[0][0]], channels[counts[1][0]])
	}

	result := output.String()
	result = strings.TrimSuffix(result, ",")
	return result
}

func argmax(values []int) int {
	result := 0
	maximum := math.MinInt
	for index, value := range values {
		if maximum < value {
			result = index
			maximum = value
		}
	}
	return result
}
