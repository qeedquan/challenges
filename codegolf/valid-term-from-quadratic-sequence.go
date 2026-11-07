/*

You are given four numbers. The first three are a, b, and c respectively, for the sequence:

Tn=a*n^2 + bn + c

You may take input of these four numbers in any way.
The output should be one of two distinct outputs mentioned in your answer, one means that the fourth number is a term in the sequence
(the above equation has at least one solution for n which is an integer when a, b, c and Tn are substituted for the given values), the other means the opposite.

This is code golf, so the shortest answer in bytes wins. Your program should work for any input of a,b,c,Tn where the numbers are negative or positive (or 0), decimal or integer.
To avoid problems but keep some complexity, non-integers will always just end in .5. Standard loop-holes disallowed.

Test cases
a   |b   |c   |T_n |Y/N
------------------------
1   |1   |1   |1   |Y     #n=0
2   |3   |5   |2   |N
0.5 |1   |-2  |-0.5|Y     #n=1
0.5 |1   |-2  |15.5|Y     #n=5
0.5 |1   |-2  |3   |N
-3.5|2   |-6  |-934|Y     #n=-16
0   |1   |4   |7   |Y     #n=3
0   |3   |-1  |7   |N
0   |0   |0   |1   |N
0   |0   |6   |6   |Y     #n=<anything>
4   |8   |5   |2   |N

*/

package main

import "math"

func main() {
	assert(qterm(1, 1, 1, 1) == true)
	assert(qterm(2, 3, 5, 2) == false)
	assert(qterm(0.5, 1, -2, -0.5) == true)
	assert(qterm(0.5, 1, -2, 15.5) == true)
	assert(qterm(0.5, 1, -2, 3) == false)
	assert(qterm(0, 1, 4, 7) == true)
	assert(qterm(0, 3, -1, 7) == false)
	assert(qterm(0, 0, 0, 1) == false)
	assert(qterm(0, 0, 6, 6) == true)
	assert(qterm(4, 8, 5, 2) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Arnauld

How?
For the sake of clarity, we define d = Tn - c.
(The same variable t is re-used to store this result in the JS code.)

Case a != 0 The equation really is quadratic:

Tn = a*n^2 + b*n + c
a*n^2 + b*n - d = 0

With a′=2a, the discriminant is:

Δ = b^2 + 2a′d

and the roots are:

n0 = (-b - sqrt(Δ)) / (2*a')
n1 = (-b + sqrt(Δ)) / (2*a')

The equation admits an integer root if sqrt(Δ) is an integer and either:
-b - sqrt(Δ) ≡ 0 (mod a')
-b + sqrt(Δ) ≡ 0 (mod a')

Case a=0, b≠0
The equation is linear:

Tn = bn + c
bn = d
n  = d/b

It admits an integer root if d ≡ 0 (mod b).

Case a=0,b=0
The equation is not depending on n anymore:

Tn = c
d = 0

*/

func qterm(a, b, c, T float64) bool {
	d := T - c
	if a == 0 && b == 0 {
		return d == 0
	}

	if a == 0 {
		return math.Mod(d, b) == 0
	}

	α := 2 * a
	Δ := b*b + 2*α*d
	δ := math.Floor(math.Sqrt(Δ))
	if δ*δ != Δ {
		return false
	}
	return math.Mod(-b-δ, α) == 0 || math.Mod(-b+δ, α) == 0
}
