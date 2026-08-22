/*

The prefix of a string S is any string of the form S[1..k], k≤size(S) (size(S) is the length of a string).
Prefix can be either empty or match the string itself.
If prefix is not empty and does not match with the string S, it is called the proper prefix of string S.
Print the number of prefixes and all proper prefixes of substring S[i..j] in the increasing order of their lengths.

Input
First line contains S, its length is no more than 100.
Second line contains two indexes i and j (1≤i≤size(S), 1≤j≤size(S)).

Output
Print in the first line the number of prefixes of substring S[i..j].
In the next lines print all proper prefixes of a given substring. The output format is given in a sample.

Examples

Input #1
abracadabra
2 5

Answer #1
5
b
br
bra

*/

package main

import "fmt"

func main() {
	solve("abracadabra", 2, 5)
}

func solve(s string, a, b int) {
	if a < 0 || b < 0 || a > b || b > len(s) {
		return
	}
	fmt.Println(b - a + 2)
	for i := a; i < b; i++ {
		fmt.Println(s[a-1 : i])
	}
}
