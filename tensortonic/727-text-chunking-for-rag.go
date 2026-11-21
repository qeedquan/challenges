/*

Text chunking splits a sequence of tokens into fixed-size chunks with optional overlap between consecutive chunks. This is a fundamental preprocessing step in NLP pipelines, especially in retrieval-augmented generation (RAG) systems where documents must be split into manageable segments for embedding and retrieval.

Given a list of tokens, a chunk size, and an overlap count, split the tokens into chunks.

Algorithm
1. Compute the step size between chunk start positions:
step = chunk_size - overlap

2. Starting from position 0, extract a chunk of chunk_size tokens, then advance by step.
Stop once a chunk reaches the end of the token list.

Return the chunks as a list of token lists.


Examples
Input: tokens = ["a", "b", "c", "d", "e", "f"], chunk_size = 3, overlap = 0

Output: [["a", "b", "c"], ["d", "e", "f"]]

Explanation: A step of three produces two non-overlapping chunks.

Input: tokens = ["a", "b", "c", "d", "e", "f", "g"], chunk_size = 3, overlap = 1

Output: [["a", "b", "c"], ["c", "d", "e"], ["e", "f", "g"]]

Hint 1
Compute the distance between chunk starts as chunk_size minus overlap.

Hint 2
Slice from each start position and stop after the first chunk that reaches the end.

Requirements
Split the token list into chunks of the specified size with the given overlap between consecutive chunks
The step between chunk start positions is chunk_size - overlap
The last chunk may be shorter than chunk_size if there are remaining tokens
Return a list of lists of tokens
Constraints
tokens has at least 1 element
chunk_size >= 1
0 <= overlap < chunk_size
Return a list of lists
Time limit: 300 ms

*/

package main

import "fmt"

func main() {
	fmt.Println(text_chunking(
		[]string{"a", "b", "c", "d", "e", "f"},
		3, 0,
	))

	fmt.Println(text_chunking(
		[]string{"a", "b", "c", "d", "e", "f", "g"},
		3, 1,
	))
}

func text_chunking(tokens []string, chunksize, overlap int) [][]string {
	step := chunksize - overlap
	result := [][]string{}
	for index := 0; index+chunksize <= len(tokens); index += step {
		result = append(result, tokens[index:index+chunksize])
	}
	return result
}
