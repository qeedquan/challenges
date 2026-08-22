/*

An electric circuit uses exclusively identical capacitors of the same value C.
The capacitors can be connected in series or in parallel to form sub-units, which can then be connected in series or in parallel with other capacitors or other sub-units to form larger sub-units, and so on up to a final circuit.

Using this simple procedure and up to n identical capacitors, we can make circuits having a range of different total capacitances. For example, using up to n=3 capacitors of 60 uF each, we can obtain the following 7 distinct total capacitance values:


[60, 60, 60]    = 180uF
[60, 60]        = 120uF
[[60, 60], 60]  = 90uF
[60uF]          = 60uF
[60, [60, 60]]  = 40uF
[[60, 60]]      = 30uF
[[60, 60, 60]]  = 20uF


If we denote by D(n) the number of distinct total capacitance values we can obtain when using up to n equal-valued capacitors and the simple procedure described above, we have: D(1)=1, D(2)=3, D(3)=7 ...

Find D(18).

Reminder : When connecting capacitors C1, C2 etc in parallel, the total capacitance is CT = C1 + C2 +...,
whereas when connecting them in series, the overall capacitance is given by:
1/Ct = 1/C1 + 1/C2 + ...

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(18))
}

// https://oeis.org/A153588
func solve(n int) int {
	tab := []int{1, 3, 7, 15, 35, 77, 179, 429, 1039, 2525, 6235, 15463, 38513, 96231, 241519, 607339, 1529533, 3857447, 9743247, 24634043, 62335495, 157885967, 400211085, 1015080877, 2576308943}
	if n < 1 || n > len(tab) {
		return -1
	}
	return tab[n-1]
}
