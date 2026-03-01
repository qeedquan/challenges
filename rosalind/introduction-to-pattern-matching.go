/*

If At First You Don't Succeed...

We introduced the problem of finding a motif in a genetic string in “Finding a Motif in DNA”.
More commonly, we will have a collection of motifs that we may wish to find in a larger string, for example when searching a genome for a collection of known genes.

This application sets up the algorithmic problem of pattern matching, in which we are searching a large string (called a text) for instances of a collection of smaller strings, called patterns.
For the moment, we will focus on requiring that all matches should be exact.

The most obvious method for finding exact patterns in a text is to simply apply a simple "sliding window" algorithm for each pattern.
However, this method is time-consuming if we have a large number of patterns to consider (which will often be the case when dealing with a database of genes).
It would be better if instead of traversing the genome for every pattern, we could somehow only traverse it once. To this end, we will need a data structure that can efficiently organize a collection of patterns.

Problem

Given a collection of strings, their trie (often pronounced "try" to avoid ambiguity with the general term tree) is a rooted tree formed as follows.
For every unique first symbol in the strings, an edge is formed connecting the root to a new vertex. This symbol is then used to label the edge.

We may then iterate the process by moving down one level as follows. Say that an edge connecting the root to a node v is labeled with 'A';
then we delete the first symbol from every string in the collection beginning with 'A' and then treat v as our root.
We apply this process to all nodes that are adjacent to the root, and then we move down another level and continue. See Figure 1 for an example of a trie.

As a result of this method of construction, the symbols along the edges of any path in the trie from the root to a leaf will spell out a unique string from the collection,
as long as no string is a prefix of another in the collection (this would cause the first string to be encoded as a path terminating at an internal node).

Given: A list of at most 100 DNA strings of length at most 100 bp, none of which is a prefix of another.

Return: The adjacency list corresponding to the trie T for these patterns, in the following format.
If T has n nodes, first label the root with 1 and then label the remaining nodes with the integers 2 through n in any order you like.
Each edge of the adjacency list of T will be encoded by a triple containing the integer representing the edge's parent node, followed by the integer representing the edge's child node, and finally the symbol labeling the edge.

Sample Dataset

Sample Dataset
ATAGA
ATC
GAT
Sample Output
1 2 A
2 3 T
3 4 A
4 5 G
5 6 A
3 7 C
1 8 G
8 9 A
9 10 T

*/

package main

import "fmt"

func main() {
	test([]string{"ATAGA", "ATC", "GAT"})
}

func test(sequences []string) {
	_, edge := build(sequences)
	for key, value := range edge {
		fmt.Printf("%d %d %c\n", key[0]+1, key[1]+1, value)
	}
}

func build(sequences []string) (map[int][]int, map[[2]int]int) {
	trie := make(map[int][]int)
	edge := make(map[[2]int]int)
	index := 1
	for _, sequence := range sequences {
		node := 0
	loop:
		for _, symbol := range sequence {
			link := int(symbol)
			for _, neighbor := range trie[node] {
				key := [2]int{node, neighbor}
				if edge[key] == link {
					node = neighbor
					continue loop
				}
			}
			key := [2]int{node, index}
			trie[node] = append(trie[node], index)
			edge[key] = link
			node = index
			index += 1
		}
	}
	return trie, edge
}
