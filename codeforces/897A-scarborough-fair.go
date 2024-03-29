/*

Are you going to Scarborough Fair?
Parsley, sage, rosemary and thyme.
Remember me to one who lives there.
He once was the true love of mine.

Willem is taking the girl to the highest building in island No.28, however, neither of them knows how to get there.

Willem asks his friend, Grick for directions, Grick helped them, and gave them a task.

Although the girl wants to help, Willem insists on doing it by himself.

Grick gave Willem a string of length n.

Willem needs to do m operations, each operation has four parameters l, r, c1, c2, which means that all symbols c1 in range [l, r] (from l-th to r-th, including l and r) are changed into c2. String is 1-indexed.

Grick wants to know the final string after all the m operations.

Input
The first line contains two integers n and m (1 ≤ n, m ≤ 100).

The second line contains a string s of length n, consisting of lowercase English letters.

Each of the next m lines contains four parameters l, r, c1, c2 (1 ≤ l ≤ r ≤ n, c1, c2 are lowercase English letters), separated by space.

Output
Output string s after performing m operations described above.

Examples

input
3 1
ioi
1 1 i n
output
noi

input
5 3
wxhak
3 3 h x
1 5 x a
1 3 w g
output
gaaak

Note
For the second example:

After the first operation, the string is wxxak.

After the second operation, the string is waaak.

After the third operation, the string is gaaak.

*/

package main

func main() {
	assert(apply("ioi", [][4]int{
		{1, 1, 'i', 'n'},
	}) == "noi")

	assert(apply("wxhak", [][4]int{
		{3, 3, 'h', 'x'},
		{1, 5, 'x', 'a'},
		{1, 3, 'w', 'g'},
	}) == "gaaak")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func apply(s string, p [][4]int) string {
	b := []byte(s)
	for _, p := range p {
		l, r, c0, c1 := p[0]-1, p[1]-1, byte(p[2]), byte(p[3])
		for i := l; i <= r; i++ {
			if b[i] == c0 {
				b[i] = c1
			}
		}
	}
	return string(b)
}
