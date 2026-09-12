/*

Given: A string x, followed by the alphabet Σ from which x was constructed, followed by a hidden path π, followed by the states States and emission matrix Emission of an HMM (Σ, States, Transition, Emission).

Return: The conditional probability Pr(x|π) that string x will be emitted by the HMM given the hidden path π.

Sample Dataset
xxyzyxzzxzxyxyyzxxzzxxyyxxyxyzzxxyzyzxzxxyxyyzxxzx
--------
x   y   z
--------
BBBAAABABABBBBBBAAAAAABAAAABABABBBBBABAABABABABBBB
--------
A   B
--------
    x   y   z
A   0.612   0.314   0.074
B   0.346   0.317   0.336

Sample Output
1.93157070893e-28

*/

package main

import "fmt"

func main() {
	fmt.Println(prob(
		"xxyzyxzzxzxyxyyzxxzzxxyyxxyxyzzxxyzyzxzxxyxyyzxxzx",
		"BBBAAABABABBBBBBAAAAAABAAAABABABBBBBABAABABABABBBB",
		[][]float64{
			{0.612, 0.314, 0.074},
			{0.346, 0.317, 0.336},
		},
	))

	fmt.Println(prob(
		"zyyyxzxzyyzxyxxyyzyzzxyxyxxxxzxzxzxxzyzzzzyyxzxxxy",
		"BAABBAABAABAAABAABBABBAAABBBABBAAAABAAAABBAAABABAA",
		[][]float64{
			{0.093, 0.581, 0.325},
			{0.77, 0.21, 0.02},
		},
	))
}

func prob(s, h string, E [][]float64) float64 {
	L := map[byte]int{
		'A': 0,
		'B': 1,
		'x': 0,
		'y': 1,
		'z': 2,
	}

	p := 1.0
	for i := 0; i < len(s); i++ {
		t0 := L[h[i]]
		t1 := L[s[i]]
		p *= E[t0][t1]
	}
	return p
}
