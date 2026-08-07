/*

Objective
Given two closed surfaces (a.k.a. closed 2-manifolds), decide whether they're homeomorphic.

Introduction
In lay terms, a closed surface is a finite-sized shape that resembles a flat plane everywhere (say, when magnified very much). Familiar examples of a closed surface include a sphere and a torus, while obscurer examples include a Klein bottle and a real projective plane.

Two shapes are homeomorphic when one can be transformed to the other without cutting or pasting, but with only continuous stretching or shrinking. The act of identifying two shapes to be homeomorphic is called a homeomorphism.

When given two closed surfaces, there is a method of creating a new closed surface, namely the connected sum. In lay terms, the connected sum is performed by puncturing each closed surface and then gluing the resulting two circular holes to each other.

Classification and I/O format
Up to homeomorphism, there are (countably) infinitely many closed surfaces, but they admit an easy classification.

In fact, using the notion of connected sum, only two surfaces are needed to generate all closed surfaces, namely the torus (represented by the ASCII letter T) and the real projective plane (represented by the ASCII letter P). As such, every closed surface shall be inputted as a string consisting of the letter T and the letter P, representing the connected sum of the surfaces involved. In particular, the sphere is the empty string "", and the Klein bottle is "PP".

The notion of connected sum is associative and commutative; and it admits the identity element, namely the sphere "".

One final caveat is that "TP" equals to "PPP"; this surface is called Dyck's surface.

Every input not fitting into this format is invalid.

Examples
"Input 1", "Input 2", Output

"", "", True
"", "P", False
"", "T", False
"P", "T", False
"PP", "T", False
"PT", "PPP", True
"PT", "TP", True
"PPT", "PPP", False
"PTP", "PPPP", True
"TT", "TT", True
"TT", "PPPP", False
"PTPPTTP", "TTTPPPP", True
"PTPTPPP", "PPPPPTPP", True
Worked example
For look at the last example above:

"PTPTPPP", "PPPPPTPP"
Since the notion of connected sum is associative and commutative, they can be "sorted" into:

"TTPPPPP", "TPPPPPPP"
And then since "TP" == "PPP", the TP inside the "TTPPPPP" can be replaced to PPP, resulting in "TPPPPPPP". Thus their equality is proven.

*/

package main

import "strings"

func main() {
	assert(eq("", "") == true)
	assert(eq("", "P") == false)
	assert(eq("", "T") == false)
	assert(eq("P", "T") == false)
	assert(eq("PP", "T") == false)
	assert(eq("PT", "PPP") == true)
	assert(eq("PT", "TP") == true)
	assert(eq("PPT", "PPP") == false)
	assert(eq("PTP", "PPPP") == true)
	assert(eq("TT", "TT") == true)
	assert(eq("TT", "PPPP") == false)
	assert(eq("PTPPTTP", "TTTPPPP") == true)
	assert(eq("PTPTPPP", "PPPPPTPP") == true)
	assert(eq("TP", "PPP") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@xnor

Replaces every T in each string with PP before checking for equality.
But, to tell apart strings of only T with no "catalyst" P, the number of replacements is capped at len(s)-1, which leaves one T unconverted in such strings.

*/

func eq(s, t string) bool {
	return re(s) == re(t)
}

func re(s string) string {
	if len(s) > 1 {
		s = strings.Replace(s, "T", "PP", len(s)-1)
	}
	return s
}
