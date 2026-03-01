/*

https://i.stack.imgur.com/J8ryq.jpg

Credit: Marco Verch CC BY 2.0

A two-cube calendar, as shown in the picture, uses two cubes with digits painted on the faces to display the date. For dates in the range 1-9, a leading zero is used ("01", "02", ..., "09").

Now, if you do the math, you might come to the conclusion that these calendars should be impossible. After all, the numbers "0","1" and "2" must appear on both cubes (proof left to the reader). This means that there are only six faces remaining for the other seven numbers.

Two-cube calendars use a trick where the face with a "6" can be rotated upside down to look like a "9". For example, one cube may have faces "012345" and the other one "012678" where the "6" can also be a nine. For the purposes of this challenge these kind of font-dependent tricks are banned.

With these restrictions we can only display the numbers from 0 to 21 for a total of 22 numbers. We can display some other numbers too, but we are only interested in the longest possible sequence of numbers displayable (no gaps), starting from 0.

If, instead of using base 10, we would have used base 6, we could display 0-55[6] for a total of 36 numbers. (55[6]=35[10])

If, instead of using cubes, we would have used octahedrons (8 faces), we could display 0-65 (using base 10).

And finally, with three cubes we can get 0-76 for a total of 77 numbers (using base 10).

The maximal amount of numbers we can get in the initial range is called the cube calendar number. It depends on the number of faces, on the number of dice ("cubes") and on the base of the numbers.

Task
Given a base b, the number of faces f and the number of dice d, return the cube calendar number for those parameters.

b, f and d are natural numbers guaranteed to satisfy:

b≥2

b≥f≥1

d≥1

Test cases
d f b result
1 1 2 1
1 1 3 1
1 1 4 1
1 2 2 2
1 2 3 2
1 2 4 2
1 3 3 3
1 3 4 3
1 4 4 4
2 1 2 1
2 1 3 1
2 1 4 1
2 2 2 4
2 2 3 4
2 2 4 3
2 3 3 9
2 3 4 10
2 4 4 16
3 1 2 1
3 1 3 1
3 1 4 1
3 2 2 8
3 2 3 8
3 2 4 5
3 3 3 27
3 3 4 21
3 4 4 64
4 1 2 1
4 1 3 1
4 1 4 1
4 2 2 16
4 2 3 13
4 2 4 10
4 3 3 81
4 3 4 63
4 4 4 256
2 6 10 22
2 6 6 36
2 8 10 66
3 6 10 77

*/

package main

func main() {
	assert(cubecalendar(1, 1, 2) == 1)
	assert(cubecalendar(1, 1, 3) == 1)
	assert(cubecalendar(1, 1, 4) == 1)
	assert(cubecalendar(1, 2, 2) == 2)
	assert(cubecalendar(1, 2, 3) == 2)
	assert(cubecalendar(1, 2, 4) == 2)
	assert(cubecalendar(1, 3, 3) == 3)
	assert(cubecalendar(1, 3, 4) == 3)
	assert(cubecalendar(1, 4, 4) == 4)
	assert(cubecalendar(2, 1, 2) == 1)
	assert(cubecalendar(2, 1, 3) == 1)
	assert(cubecalendar(2, 1, 4) == 1)
	assert(cubecalendar(2, 2, 2) == 4)
	assert(cubecalendar(2, 2, 3) == 4)
	assert(cubecalendar(2, 2, 4) == 3)
	assert(cubecalendar(2, 3, 3) == 9)
	assert(cubecalendar(2, 3, 4) == 10)
	assert(cubecalendar(2, 4, 4) == 16)
	assert(cubecalendar(3, 1, 2) == 1)
	assert(cubecalendar(3, 1, 3) == 1)
	assert(cubecalendar(3, 1, 4) == 1)
	assert(cubecalendar(3, 2, 2) == 8)
	assert(cubecalendar(3, 2, 3) == 8)
	assert(cubecalendar(3, 2, 4) == 5)
	assert(cubecalendar(3, 3, 3) == 27)
	assert(cubecalendar(3, 3, 4) == 21)
	assert(cubecalendar(3, 4, 4) == 64)
	assert(cubecalendar(4, 1, 2) == 1)
	assert(cubecalendar(4, 1, 3) == 1)
	assert(cubecalendar(4, 1, 4) == 1)
	assert(cubecalendar(4, 2, 2) == 16)
	assert(cubecalendar(4, 2, 3) == 13)
	assert(cubecalendar(4, 2, 4) == 10)
	assert(cubecalendar(4, 3, 3) == 81)
	assert(cubecalendar(4, 3, 4) == 63)
	assert(cubecalendar(4, 4, 4) == 256)
	assert(cubecalendar(2, 6, 10) == 22)
	assert(cubecalendar(2, 6, 6) == 36)
	assert(cubecalendar(2, 8, 10) == 66)
	assert(cubecalendar(3, 6, 10) == 77)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@loopy walt

How?
Given D,F,B a best set of dice has a zero on every die because 0 (with leading zeros) must be representable. The remaining D(F-1) faces should evenly split between the B-1 non-zero digits. Indeed, if we write

(1)M:=⌊D(F−1)/(B−1)⌋

then to get up to at least 10M(B) we need 11..11(B),22..22(B),33..33(B) etc. (M digits each).

How much farther can we go? If the division in (1) splits cleanly (no remainder) then we top out at 11..110(B) (M+1 digits).
This also shows that if the split was not clean then the first excess face should be a 1.
If that is the only excess face it will carry us up to 22..221(B).
The next excess face if it exists should therefore be a 2. Etc.
Since we start at 0, the corresponding cube calendar numbers are 11..11(B)=(10M+1(B)−1)/(B−1),22..22(B),...

It remains to special case B=F and that's it.

*/

func cubecalendar(d, f, b int) int {
	if b < 2 || f < 1 || d < 1 {
		return 0
	}

	x := d*(f-1)%(b-1) + 1
	y := ipow(b, (d*(f-1)/(b-1) + 1))
	z := b - truth(b > f)*truth(b > 2)
	return x * (y / z)
}

func ipow(x, p int) int {
	r := 1
	for i := 0; i < p; i++ {
		r *= x
	}
	return r
}

func truth(b bool) int {
	if b {
		return 1
	}
	return 0
}
