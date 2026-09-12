/*

https://en.wikipedia.org/wiki/Boolean_algebra

*/

package main

func main() {
	arithmetic()
	associativity()
	commutativity()
	distributivity()
	demorgan()
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

x, y = [0, 1] arithmetic is done mod 2

x AND y = x * y                       = min(x, y)
x OR  y = x + y - x*y = x + y*(1 - x) = max(x, y)
x XOR y = x + y = (x OR y) and NOT (x AND y)
NOT x   = 1 - x

x IMPLY y = (NOT A) OR B

*/

func arithmetic() {
	imply := []int{1, 1, 0, 1}
	for x := range 2 {
		for y := range 2 {
			assert((x*y)%2 == x&y)
			assert(min(x, y) == x&y)

			assert((x+y-x*y)%2 == x|y)
			assert((x+y*(1-x))%2 == x|y)
			assert(max(x, y) == x|y)

			assert((x+y)%2 == x^y)
			assert(((x | y) & ^(x & y)) == x^y)

			assert((^x|y)&1 == imply[2*x+y])
		}

		assert((1-x)%2 == ^x&1)
	}
}

/*

x OR (y OR z) = (x OR y) OR z
x AND (y AND z) = (x AND y) AND z

*/

func associativity() {
	N := 100
	for x := -N; x <= N; x++ {
		for y := -N; y <= N; y++ {
			for z := -N; z <= N; z++ {
				assert(x|(y|z) == (x|y)|z)
				assert(x&(y&z) == (x&y)&z)
			}
		}
	}
}

/*

x OR y = y OR x
x AND y = y AND x

*/

func commutativity() {
	N := 100
	for x := -N; x <= N; x++ {
		for y := -N; y <= N; y++ {
			assert(x|y == y|x)
			assert(x&y == y&x)
		}
	}
}

/*

x AND (y OR z) = (x AND y) OR (x AND z)

*/

func distributivity() {
	N := 100
	for x := -N; x <= N; x++ {
		for y := -N; y <= N; y++ {
			for z := -N; z <= N; z++ {
				assert(x&(y|z) == (x&y)|(x&z))
			}
		}
	}
}

/*

NOT (X OR Y)  = (NOT X) AND (NOT Y)
NOT (X AND Y) = (NOT X) OR (NOT Y)

*/

func demorgan() {
	N := 100
	for x := -N; x <= N; x++ {
		for y := -N; y <= N; y++ {
			assert(^(x | y) == ^x&^y)
			assert(^(x & y) == ^x|^y)
		}
	}
}
