/*

Description

A Benedict monk No.16 writes down the decimal representations of all natural numbers between and including m and n, m ≤ n. How many 0's will he write down?

Input

Input consists of a sequence of lines. Each line contains two unsigned 32-bit integers m and n, m ≤ n. The last line of input has the value of m negative and this line should not be processed.

Output

For each line of input print one line of output with one integer number giving the number of 0's written down by the monk.

Sample Input

10 11
100 200
0 500
1234567890 2345678901
0 4294967295
-1 -1

Sample Output

1
22
92
987654304
3825876150

Source

Waterloo Local Contest, 2006.5.27

*/

package main

func main() {
	assert(zeros(10, 11) == 1)
	assert(zeros(100, 200) == 22)
	assert(zeros(0, 500) == 92)
	assert(zeros(1234567890, 2345678901) == 987654304)
	assert(zeros(0, 4294967295) == 3825876150)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func zeros(m, n uint64) uint64 {
	r := count(n)
	if m != 0 {
		r -= count(m - 1)
	}
	return r
}

func count(n uint64) uint64 {
	p := []uint64{0, 1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19}
	r := uint64(1)
	v := n
	for i := 1; v/10 != 0; i, v = i+1, v/10 {
		l := n / p[i+1]
		if v%10 != 0 {
			r += l * p[i]
		} else {
			r += (l-1)*p[i] + n%p[i] + 1
		}
	}
	return r
}
