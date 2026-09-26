/*

Let us start numbering positions in the string from 1.
The substring S[i…j] is defined as the sequence of characters from position i to position j (inclusive) of the string S.
Given indices i and j, output the length of the substring and the substring itself, preserving the original order of characters.

Input
The first line contains a string S, whose length does not exceed 100.
The second line contains two integers i and j (1≤i≤j≤size(S)), where size(S) denotes the length of string S.

Output
In the first line, output the length of the substring S[i…j]. In the second line, print the substring itself.

Examples

Input #1
abracadabra
2 5

Answer #1
4
brac

*/

package main

import "fmt"

func main() {
	fmt.Println(solve("abracadabra", 2, 5))
}

func solve(s string, a, b int) (int, string) {
	return b - a + 1, s[a-1 : b-a+2]
}
