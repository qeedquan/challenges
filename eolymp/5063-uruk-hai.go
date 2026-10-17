/*

Saruman stands atop Orthanc, surveying the vast expanse around him.
At the base of the tower, countless legions of Uruk-Hai are ready to march.
To boost the morale of his army, the wise Saruman decides to conduct a roll call.
Amidst the enthusiastic roar of the crowd, the wizard calls out a number—the name of an orc (Saruman assigned numbers instead of names to his subordinates so that no two names would coincide and each orc would feel their individuality).
The named orc then shouts "Yes, lord!".
However, even Saruman could not foresee in his palantír that after celebrating their recent victory, half of the Uruk-Hai are sleeping deeply in the dungeons beneath Isengard and, therefore, cannot respond to their master.
As the chronicler of Middle-earth's history, you are to simulate the process, showing what response the wizard receives each time.

Input
The first line contains the numbers N—the number of Uruk-Hai, and K—the number of Saruman's calls, 1≤N≤100000, 1≤K≤10000.

The second line contains N numbers—the names of the Uruk-Hai.

The third line contains K numbers—the names called by Saruman.

All number-names are not less than 0 and do not exceed 2×10^9.

For your convenience, the numbers in the second line are already sorted in ascending order.

Output
Print the responses to each of the wizard's calls—each on a new line. If the named orc is present, print Yes, lord!, otherwise print Silence.

Examples

Input #1
10 10
1 61 126 217 2876 6127 39162 98126 712687 1000000000
100 6127 1 61 200 -10000 1 217 10000 1000000000

Answer #1
Silence
Yes, master!
Yes, master!
Yes, master!
Silence
Silence
Yes, master!
Yes, master!
Silence
Yes, master!

*/

package main

import "fmt"

func main() {
	solve(
		[]int{1, 61, 126, 217, 2876, 6127, 39162, 98126, 712687, 1000000000},
		[]int{100, 6127, 1, 61, 200, -10000, 1, 217, 10000, 1000000000},
	)
}

func solve(N, K []int) {
	m := make(map[int]bool)
	for _, v := range N {
		m[v] = true
	}
	for _, v := range K {
		if m[v] {
			fmt.Println("Yes, master!")
		} else {
			fmt.Println("Silence")
		}
	}
}
