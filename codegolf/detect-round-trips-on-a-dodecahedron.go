/*

An ant starts on an edge of a dodecahedron, facing parallel to it. At each step, it walks forward to the next vertex and turns either left or right to continue onto one of the other two edges that meet there. A sequence of left/right choices that returns the ant to its initial state (edge and direction) is called a round trip.

Write a function (or program) that takes a string of Ls and Rs and returns (or outputs) one of two values, indicating whether the input represents a round trip.

Examples:

LLLLL -> yes
LRLRLRLRLR -> yes
RRLRRLRRL -> yes
(empty sequence) -> yes
R -> no
LLLLLL -> no (starts with a round trip but leaves initial state)
RLLLLR -> no (returns to initial edge but opposite direction)

*/

package main

func main() {
	assert(cycle("LLLLL") == true)
	assert(cycle("LRLRLRLRLR") == true)
	assert(cycle("RRLRRLRRL") == true)
	assert(cycle("") == true)
	assert(cycle("R") == false)
	assert(cycle("LLLLLL") == false)
	assert(cycle("RLLLLR") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@xnor

lambda s:all(n==reduce(lambda n,c:-~[n,n%3+n%4][c>'L']%5,s,n)for n in range(5))

This uses the group-theoretic approach from Ilmari Karonen's GolfScript answer to my 2014 challenge, in particular to the bonus question.

Instead of the ant crawling around the dodecahedron, we imagine it stays in place while the dodecahedron turns under its feet. We must determine whether the sequence of rotations returns the dodecahedron to the initial position.

There are 60 rotation of the dodecahedron -- 12 faces times 5 positions per face. These rotations can be expressed as permutations of 5 elements. Specifically, they permute 5 colored tetrahedra shown below that partition the 20 vertices of the dodecahedron.

https://i.sstatic.net/zCRYMm.jpg

We could take each rotation and write down which color tetrahedron moves onto which color's position to obtain a permutation of the five colors. Specifically, these are the even permutations, which are half of the 5!=120 permutations of five elements, or 60, forming the alternating group A5
 on five elements. The other 60 odd permutations would involve reflecting the dodecahedron and well as rotating it, so they do not figure in this problem.

We want to choose two even permutations that represent the rotations from the ant turning left and right. As noted by Ilmari Karonen, the two permutations must have order 5, corresponding to five left or five right turns brining the ant back to the same place. Moreover, their product must have order 5 as well, and neither can be a power of the other.

There are many choices for the two permutations. If we think of them as permuting the values 0 to 4, the pair our code uses is 12340 and 13042. The first one simply adds one modulo 5. From here, there's 5 choices for the other one: 13042, 14302, 24310, 32041, 32410. The code uses 13042 because it happens to have a short expression in Python 1+(n%3+n%4)%5, or just n%3+n%4 if we "share" the +1 and %5 for the other case`. I found this via some brute-forcing.

S=s=`321.`
for c in input():s=(s+s[ord(c)%9:3]+s)[3:8]
print s==S

This uses a different mapping pair: 34012, 34120. These are nice to implement as operations on lists, moving the last two elements to the front in both cases, and for the latter cycling the last 3. To start, we just need any sequence of 5 distinct elements, so we use `321.` which equals '321.0'.

*/

func cycle(s string) bool {
	r := "321.0"
	for _, c := range s {
		i := min(3, c%9)
		r = (r + r[i:3] + r)[3:8]
	}
	return r == "321.0"
}
