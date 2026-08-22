/*

Magpies are my favourite birds

Baby ones even more so...
https://upload.wikimedia.org/wikipedia/commons/thumb/0/0b/Magpie_samcem05.jpg/220px-Magpie_samcem05.jpg

It is a little known fact^ that the black & white colours of baby magpies differ by at least one place and at most two places from the colours of the mother magpie.

So now you can work out if any two magpies may be related.

...and Quardle oodle ardle wardle doodle the magpies said

Kata Task
Given the colours of two magpies, determine if one is a possible child or grand-child of the other.

Notes
Each pair of birds being compared will have same number of colour areas
B = Black
W = White

Example
Given these three magpies
Magpie 1  BWBWBW
Magpie 2  BWBWBB
Magpie 3  WWWWBB

You can see:

Magpie 2 may be a child of Magpie 1 because there is only one difference
Magpie 3 may be child of Magpie 2 because there are two differences
So Magpie 3 may be a grand-child of Magpie 1
On the other hand, Magpie 3 cannot be a child of Magpie 1 because there are three differences
DM :-)

^ This fact is little known because I just made it up

*/

package main

func main() {
	assert(child("BWBWBW", "BWBWBB") == true)
	assert(child("BWBWBB", "WWWWBB") == true)
	assert(child("BWBWBW", "WWWWBB") == false)
	assert(child("BWBWBW", "BWBWBW") == false)

	assert(grandchild("BWBWBW", "BWBWBB") == true)
	assert(grandchild("", "") == true)
	assert(grandchild("B", "W") == false)
	assert(grandchild("BWBWBW", "WBWBWB") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func child(b1, b2 string) bool {
	d := diff(b1, b2)
	return d > 0 && d < 3
}

func grandchild(b1, b2 string) bool {
	d := diff(b1, b2)
	return (len(b1) > 1 && d < 5) || d == 0
}

func diff(b1, b2 string) int {
	n1 := len(b1)
	n2 := len(b2)
	d := 0
	for i := range min(n1, n2) {
		if b1[i] != b2[i] {
			d++
		}
	}
	return d + max(n1, n2) - min(n1, n2)
}
