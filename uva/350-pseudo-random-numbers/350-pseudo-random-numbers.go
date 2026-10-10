package main

func main() {
	assert(period(7, 5, 12, 4) == 6)
	assert(period(5173, 3849, 3279, 1511) == 546)
	assert(period(9111, 5309, 6000, 1234) == 500)
	assert(period(1079, 2136, 9999, 1237) == 220)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func period(z, i, m, l uint) uint {
	p := LCG{z, i, m, l}
	q := p
	for {
		p.Next()

		q.Next()
		q.Next()

		if p.l == q.l {
			break
		}
	}

	v := p.l
	n := uint(0)
	for {
		p.Next()
		if n++; v == p.l {
			break
		}
	}
	return n
}

type LCG struct {
	z, i, m, l uint
}

func (c *LCG) Next() uint {
	c.l = (c.z*c.l + c.i) % c.m
	return c.l
}
