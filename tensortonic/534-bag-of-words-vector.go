/*

Create a bag-of-words count vector for a token sequence and an ordered vocabulary. Output position i stores the number of times vocab[i] occurs in tokens. Ignore tokens outside the vocabulary and return a one-dimensional integer NumPy array.

Examples
Input: tokens = ["i", "love", "ml", "love"], vocab = ["i", "love", "hate", "ml"]

Output: [1, 2, 0, 1]

Explanation: The output follows vocabulary order, and "love" occurs twice.

Input: tokens = ["hello", "world"], vocab = ["hello", "ml"]

Output: [1, 0]

Input: tokens = [], vocab = ["hello", "world"]

Output: [0, 0]

Hint 1
Build {word: index for index, word in enumerate(vocab)}.

Hint 2
Increment the mapped position only when a token exists in the index dictionary.

Requirements
Map each vocabulary token to its output index
Count repeated in-vocabulary tokens
Ignore tokens that are absent from the vocabulary
Return an integer NumPy array of length len(vocab)
Constraints
Vocabulary entries are unique strings
Tokens and vocabulary may be empty
Use NumPy only for the output array

*/

package main

import (
	"fmt"
	"slices"
)

func main() {
	test(
		[]string{"i", "love", "ml", "love"},
		[]string{"i", "love", "hate", "ml"},
		[]int{1, 2, 0, 1},
	)

	test(
		[]string{"hello", "world"},
		[]string{"hello", "ml"},
		[]int{1, 0},
	)

	test(
		[]string{},
		[]string{"hello", "world"},
		[]int{0, 0},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(tokens, vocab []string, expected []int) {
	result := bagofwords(tokens, vocab)
	fmt.Println(result)
	assert(slices.Equal(result, expected))
}

func bagofwords(tokens, vocab []string) []int {
	count := make(map[string]int)
	for _, token := range tokens {
		count[token] += 1
	}

	result := make([]int, len(vocab))
	for index, vocab := range vocab {
		result[index] = count[vocab]
	}
	return result
}
