/*

Prince of Songkla University or PSU has 5 campuses in the South of Thailand.
These campuses are Hatyai(H), Pattani(P), Suratthani(S), Phuket(K) and Trang(T).
The distances between these campuses are shown in the table below.

When the President of PSU goes on mission in different campuses, he or she may want to know the total distance of the mission.
The mission always starts from Hatyai campus and when the mission ends the president will always go back directly to Hatyai campus.

Given a list of campuses of a mission, your task is to write a program to calculate the total distance of the mission.

Input
The first line contains an integer n (1≤n≤100) which determines the number of missions.
The following n lines contain a description of each mission.
A mission is described by a string comprising only characters H, P, S, K and T which refer to PSU campuses.
The president visits the campuses in the order indicated in that string.
Since Hatyai campus is always the starting point and also the end point of a mission, we will not mention H at the beginning or the end of the string.
However, H can be an intermediate campus in a mission.
A mission string may contain at most 10 characters.

Output
For each mission (mission_i), print out in a line, "Case i: " followed by the total distance (km), exactly as shown in the sample output.

Examples

Input #1
4
TSK
PHT
PSKT
KT

Answer #1
Case 1: 1127
Case 2: 502
Case 3: 1258
Case 4: 926

*/

package main

func main() {
	assert(solve("TSK") == 1127)
	assert(solve("PHT") == 502)
	assert(solve("PSKT") == 1258)
	assert(solve("KT") == 926)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) int {
	lut := map[[2]byte]int{
		[2]byte{'H', 'P'}: 103,
		[2]byte{'H', 'S'}: 329,
		[2]byte{'H', 'K'}: 466,
		[2]byte{'H', 'T'}: 148,
		[2]byte{'P', 'S'}: 408,
		[2]byte{'P', 'K'}: 577,
		[2]byte{'P', 'T'}: 260,
		[2]byte{'S', 'K'}: 287,
		[2]byte{'S', 'T'}: 226,
		[2]byte{'K', 'T'}: 312,
	}

	r := 0
	s = "H" + s + "H"
	for i := range len(s) - 1 {
		k0 := [2]byte{s[i], s[i+1]}
		k1 := [2]byte{s[i+1], s[i]}
		r += lut[k0] + lut[k1]
	}
	return r
}
