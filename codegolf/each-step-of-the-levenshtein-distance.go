/*

In this challenge you will write a program that takes two newline-separated strings, s1 (the first line) and s2 (the second line), as input (STDIN or closest). You can assume that the length of s1 will always be smaller than 30 and bigger than the length of s2. The program should then output each step in the levenshtein distance from s1 to s2.

To clarify what each step in the levenshtein distance means, the program will print n strings, where n is the levenshtein distance between s1 and s2, and the levenshtein distance between two adjacent strings will always be one. The order doesn't matter. The output should be newline-separated and not include s1, only the in-betweens and s2. The program should also run in under one minute on a modern computer.

Examples:

Input:

Programming
Codegolf
Output:

rogramming
Cogramming
Coramming
Coamming
Codmming
Codeming
Codeging
Codegong
Codegolg
Codegolf
Input:

Questions
Answers
Output:

uestions
Aestions
Anstions
Ansions
Answons
Answens
Answers
Input:

Offline
Online
Output:

Ofline
Online
Input:

Saturday
Sunday
Output:

Sturday
Surday
Sunday
Here is a link to a python script that prints out the distance and the steps.
https://ideone.com/w5zhpz

def lev(s1, s2):
    if len(s1) < len(s2):
        return lev(s2, s1)

    # len(s1) >= len(s2)
    if len(s2) == 0:
        return len(s1)

    previous_row = range(len(s2) + 1)
    for i, c1 in enumerate(s1):
        current_row = [i + 1]
        for j, c2 in enumerate(s2):
            insertions = previous_row[j + 1] + 1 # j+1 instead of j since previous_row and current_row are one character longer
            deletions = current_row[j] + 1       # than s2
            substitutions = previous_row[j] + (c1 != c2)
            current_row.append(min(insertions, deletions, substitutions))
        previous_row = current_row

    return previous_row[-1]

s1=raw_input()
s2=raw_input()

def printAllLevSteps(s1, s2):
    if len(s1) < len(s2):
        s1, s2 = s2, s1
    chars = set(s2)
    while s1 != s2:
        oldS1 = s1
        for i in range(len(s1)*2):
            temp = list(s1)
            if i % 2 == 0:
                del(temp[i/2]) #Remove char #i from temp
            temp = "".join(temp)
            if lev(temp, s2) < lev(s1, s2):
                s1 = temp
                break
            if s1 != oldS1: # For some reason before the loop wouldn't stop
                break       # so I added this and now it's fine. Don't ask.
            for char in chars:
                temp = list(s1)      # Make it into a list
                temp[i/2] = char       # Make char #i to variable char
                temp = "".join(temp) # Convert it to a string
                if lev(temp, s2) < lev(s1, s2):
                    s1 = temp
                    break
        print s1

print "Distance:",lev(s1, s2)
print "Steps:"
printAllLevSteps(s1, s2)

Additional rules:

No use of the internet
Standard loopholes apply
This is code-golf so keep you code short; shortest code wins!

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	solve("Programming", "Codegolf")
	solve("Questions", "Answers")
	solve("Offline", "Online")
	solve("Saturday", "Sunday")
	solve("CATURDAI", "sunday")
}

func solve(s1, s2 string) {
	fmt.Println("Distance:", lev(s1, s2))
	steps(s1, s2)
	fmt.Println()
}

func steps(s1, s2 string) {
	fmt.Println("Steps:")

	if len(s1) < len(s2) {
		s1, s2 = s2, s1
	}
	cs := set(s2)
	for s1 != s2 {
		t1 := s1
		for i := range len(s1) * 2 {
			tp := s1
			if i%2 == 0 {
				tp = tp[:i/2] + tp[i/2+1:]
			}

			if lev(tp, s2) < lev(s1, s2) {
				s1 = tp
				break
			}
			if s1 != t1 {
				break
			}

			for _, c := range cs {
				tp := s1[:i/2] + string(c) + s1[i/2+1:]
				if lev(tp, s2) < lev(s1, s2) {
					s1 = tp
					break
				}
			}
		}
		fmt.Println(s1)
	}
}

func set(s string) []rune {
	p := []rune{}
	m := make(map[rune]bool)
	for _, r := range s {
		if !m[r] {
			p = append(p, r)
			m[r] = true
		}
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i] < p[j]
	})
	return p
}

func lev(s1, s2 string) int {
	a := []rune(s1)
	b := []rune(s2)

	m := len(a)
	n := len(b)

	d := make([][]int, m+1)
	p := make([]int, (m+1)*(n+1))
	for i := range d {
		d[i] = p[i*(n+1) : (i+1)*(n+1)]
	}

	for i := 1; i <= m; i++ {
		d[i][0] = i
	}
	for j := 1; j <= n; j++ {
		d[0][j] = j
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if a[i-1] == b[j-1] {
				d[i][j] = d[i-1][j-1]
			} else {
				d[i][j] = min(d[i][j-1]+1, d[i-1][j]+1, d[i-1][j-1]+1)
			}
		}
	}
	return d[m][n]
}
