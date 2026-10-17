/*

The suffix of a string S is any substring of the form S[k..size(S)], where 1≤k≤size(S) and size(S) is the length of the string.
A suffix may be empty or coincide with the string itself.
If a suffix is non-empty and not equal to S, it is called a proper suffix of the string S.

Print the number of suffixes, and then list all proper suffixes of the substring S[i..j] in increasing order of their lengths.

Input
The first line contains the string S, with length not exceeding 100.The second line contains two indices i and j (1≤i≤size(S), 1≤j≤size(S)).

Output
Print, on the first line, the number of suffixes of the substring S[i..j].
On the following lines, print all proper suffixes of the given substring.The output format follows the sample.

Examples

Input #1
abracadabra
2 5

Answer #1
5
rac
ac
c

Input #4
aaaaaaaaaaaaaaaaa
5 9

Answer #4
6
aaaa
aaa
aa
a

*/

package main

import "fmt"

func main() {
	solve("abracadabra", 2, 5)
	solve("aaaaaaaaaaaaaaaaa", 5, 9)
}

func solve(s string, a, b int) {
	if a < 0 || b < 0 || a > b || b > len(s) {
		return
	}
	fmt.Println(b - a + 2)
	for i := a; i < b; i++ {
		fmt.Println(s[i:b])
	}
}
