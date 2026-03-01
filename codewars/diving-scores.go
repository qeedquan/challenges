/*

Description

For this Kata you will need to create a function which works out the score of a dive in an Olympic diving competition and displays it in the correct format. The function will take 2 arguments:

    An array of numbers representing the judges' scores, called scores
    A number representing the degree of difficulty of the dive, called tariff

The 2 lowest and 2 highest scores by the judges are discarded and the 3 remaining scores are added together. The result of this is then multiplied by the difficulty ( tariff ) to get the score for the dive.

https://www.britannica.com/story/how-is-diving-scored

The answer should be a string, and should always have exactly 2 digits after the decimal point, as this is how diving scores are displayed.
Note

The scores will only contain numbers between 0 and 10 and the tariff will always be greater than 0.
Example

scoreOfDive( [ 7, 7.5, 8, 7.5, 6, 7, 7 ], 3 )  =>  '64.50'

*/

package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	test([]float64{7, 7.5, 8, 7.5, 6, 7, 7}, 3, 64.5)
	test([]float64{5, 6.5, 5.5, 5, 6, 4.5, 6}, 3.2, 52.8)
	test([]float64{7, 7, 7, 7.5, 6.5, 7, 7}, 2.6, 54.6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(scores []float64, tariff, expected float64) {
	result := divescore(scores, tariff)
	fmt.Println(result)
	assert(math.Abs(result-expected) < 1e-2)
}

func divescore(scores []float64, tariff float64) float64 {
	sort.Slice(scores, func(i, j int) bool {
		return scores[i] < scores[j]
	})

	sum := 0.0
	for i := 2; i < len(scores)-2; i++ {
		sum += scores[i] * tariff
	}
	return sum
}
