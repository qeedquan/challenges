/*

Gena is preparing for a school tourist trip. In his class, he is responsible for the tents.
At home, he found 3 tents: the first tent weighs a1 kilograms and accommodates b1 people, the second tent weighs a2 kilograms and accommodates b2 people,
and the third tent weighs a3 kilograms and accommodates b3 people.

There are k pupils in Gena's class.
Determine whether he can select a subset of these tents so that all k pupils can fit, and the total weight of the selected tents does not exceed w kilograms.

Input
The first line contains two integers k and w (1≤k≤15, 1≤w≤30).

The second line contains six integers: a1, b1, a2, b2, a3, b3 (1≤a1,a2,a3≤10, 1≤b1,b2,b3≤15).

Output
Print YES if it is possible to select the tents as described, or NO otherwise.

Examples

Input #1
10 10
5 5 6 6 4 5

Answer #1
YES

Input #18
12 3
2 11 5 13 2 8

Answer #18
NO

*/

package main

func main() {
	assert(solve(10, 10, 5, 5, 6, 6, 4, 5) == "YES")
	assert(solve(12, 3, 2, 11, 5, 13, 2, 8) == "NO")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(k, w, a1, b1, a2, b2, a3, b3 int) string {
	if (b1 >= k && a1 <= w) || (b2 >= k && a2 <= w) || (b3 >= k && a3 <= w) {
		return "YES"
	}
	if (b1+b2 >= k && a1+a2 <= w) || (b1+b3 >= k && a1+a3 <= w) || (b3+b2 >= k && a3+a2 <= w) {
		return "YES"
	}
	if b1+b2+b3 >= k && a1+a2+a3 <= w {
		return "YES"
	}
	return "NO"
}
