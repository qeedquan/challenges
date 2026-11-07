/*

Description

In a big and rich on natural resources country, the government started a campaign to control deforestation. In fact the government is not too interested in how many trees get fallen, but rather how effectively the wood is utilized. So a law was passed which requires every logging company to pay amount of money in proportion to amount of wood that it wastes during operation.

A felling quota on some territory was allotted to a company in this country. Company lorries may only transport logs of exactly L meters long. So when a tree gets sawed into logs, the remainder is wasted.

Trees in this country grow exactly 1 meter per year, so the company may decrease the amount of tax to be paid by simply waiting for some years. Your task is to determine the number of years needed to achieve smallest possible tax. If there is more than one answer, find minimal (earliest) one.

Input

Input file contains number of trees N, length of log L, followed by integers i1 i2 ... iN — heights of each tree.

Constraints
1 ≤ N ≤ 30000, 1 ≤ L, ik ≤ 30000

Output

Output file must contain single integer — number of years to wait.

Sample Input

Sample Input 1
3 1
10 15 11

Sample Input 2
3 2
5 3 6

Sample Output

Sample Output 1
0

Sample Output 2
1

Hint

Bold texts appearing in the sample sections are informative and do not form part of the actual data.

Source

Northeastern Europe 2006, Far-Eastern Subregion

*/

package main

func main() {
	assert(years([]int{10, 15, 11}, 1) == 0)
	assert(years([]int{5, 3, 6}, 2) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func years(a []int, l int) int {
	if l == 0 {
		return 0
	}

	r := 0
	for i := range a {
		a[i] %= l
		if a[i] != 0 {
			r = max(r, l-a[i])
		}
	}
	return r
}
