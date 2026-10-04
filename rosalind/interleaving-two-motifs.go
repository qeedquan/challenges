/*

Two Motifs, One Gene

Recall that in “Finding a Shared Spliced Motif”, we found the longest motif that could have been shared by two genetic strings, allowing for the motif to be split onto multiple exons in the process. As a result, we needed to find a longest common subsequence of the two strings (which extended the problem of finding a longest common substring from “Finding a Shared Motif”).

In this problem, we consider an inverse problem of sorts in which we are given two different motifs and we wish to interleave them together in such a way as to produce a shortest possible genetic string in which both motifs occur as subsequences.

Problem
A string s is a supersequence of another string t if s contains t as a subsequence.

A common supersequence of strings s and t is a string that serves as a supersequence of both s and t.
For example, "GACCTAGGAACTC" serves as a common supersequence of "ACGTC" and "ATAT". A shortest common supersequence of s and t is a supersequence for which there does not exist a shorter common supersequence.
Continuing our example, "ACGTACT" is a shortest common supersequence of "ACGTC" and "ATAT".

Given: Two DNA strings s and t.

Return: A shortest common supersequence of s and t. If multiple solutions exist, you may output any one.

Sample Dataset
ATCTGAT
TGCATA
Sample Output
ATGCATGAT

*/

package main

func main() {
	assert(scs("ATCTGAT", "TGCATA") == "ATGCATGAT")
	assert(scs("ATCTGGATCACGGGACCGCCGCTGGAAGGCGTTAGCGGCCCCGCACTTCCTAAAGTCGGAACGTGAAGTTAATCCAGGAGGCAACTTTACTTAG", "CCTTTTGTGGAGTTAATCGAGCTGGTCTATGATACTGTCTATCGTACAGAGATATATGGCCAATGACGAACGACTTTTAGAATCATTCCA") == "ATCCTTTTGGATCACGGGACCGCCGCTTGGAATGGCGTTAGCTGGTCTATCCCGCATACTGTCCTAAAGTCGTGACACGATGATAGTTAATGGCCAATGGACGGCAACGACTTTTAGAATCATTCCAG")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func scs(s, t string) string {
	m := len(s)
	n := len(t)
	p := make([][]int, m+1)
	for i := range p {
		p[i] = make([]int, n+1)
	}

	for i := range m + 1 {
		for j := range n + 1 {
			switch {
			case i == 0 || j == 0:
				p[i][j] = 0
			case s[i-1] == t[j-1]:
				p[i][j] = p[i-1][j-1] + 1
			default:
				p[i][j] = max(p[i-1][j], p[i][j-1])
			}
		}
	}

	r := ""
	for i, j := m, n; i > 0 || j > 0; {
		switch {
		case p[i][j] == p[i-1][j]:
			i -= 1
			r = string(s[i]) + r
		case p[i][j] == p[i][j-1]:
			j -= 1
			r = string(t[j]) + r
		default:
			r = string(s[i-1]) + r
			i -= 1
			j -= 1
		}
	}
	return r
}
