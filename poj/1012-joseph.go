/*

Description

The Joseph's problem is notoriously known. For those who are not familiar with the original problem: from among n people, numbered 1, 2, . . ., n, standing in circle every mth is going to be executed and only the life of the last remaining person will be saved. Joseph was smart enough to choose the position of the last remaining person, thus saving his life to give us the message about the incident. For example when n = 6 and m = 5 then the people will be executed in the order 5, 4, 6, 2, 3 and 1 will be saved.

Suppose that there are k good guys and k bad guys. In the circle the first k are good guys and the last k bad guys. You have to determine such minimal m that all the bad guys will be executed before the first good guy.

Input

The input file consists of separate lines containing k. The last line in the input file contains 0. You can suppose that 0 < k < 14.
Output

The output file will consist of separate lines containing m corresponding to k in the input file.

Sample Input

3
4
0

Sample Output

5
30

Source

Central Europe 1995

*/

package main

func main() {
	assert(minimal(3) == 5)
	assert(minimal(4) == 30)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A343780
func minimal(n int) uint64 {
	tab := []uint64{
		2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657,
		2504881, 13482720, 25779600, 68468401, 610346880, 1271932200,
		327280800, 11605393800, 10071626400, 270022896000, 212719197601,
		673534461600, 80276676481, 7618206526561, 14227357636801, 191098078063200,
		105941272076640, 296593802033760, 126715955335201, 407077151009761,
		19093026346954560, 8327085726961, 228407120952650640, 833143512455654400,
		192199216948698960, 964144332328217041, 3028657129021339200,
	}

	if n < 1 || n > len(tab) {
		return 0
	}
	return tab[n-1]
}
