/*

The Olympiad starts at h1 hours, m1 minutes, s1 seconds and ends on the same calendar day at h2 hours, m2 minutes, s2 seconds.
Find the duration of the Olympiad in the format hour minute second.

Input
The first line contains the starting time, and the second line contains the ending time, both in the format hour minute second.

Constraints: 0≤h1≤h2≤23, 0≤m1,m2,s1,s2≤59.

Output
Print the duration of the Olympiad in the format hour minute second.

Examples

Input #1
9 30 0
12 45 30

Answer #1
3 15 30

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(9, 30, 0, 12, 45, 30))
}

func solve(h1, m1, s1, h2, m2, s2 int) (int, int, int) {
	t := -(h1*3600 + m1*60 + s1)
	t += h2*3600 + m2*60 + s2
	return t / 3600, (t % 3600) / 60, t % 60
}
