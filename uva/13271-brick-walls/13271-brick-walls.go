package main

func main() {
	assert(dist(1, 7, 2, 7) == 1)
	assert(dist(5, 4, 3, 2) == 4)
	assert(dist(2, 3, 3, 6) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func dist(sx, sy, ex, ey int64) int64 {
	if sx == ex {
		return abs(sy - ey)
	}
	if sx > ex {
		return dist(ex, ey, sx, sy)
	}
	if sy > ey {
		return dist(sx, sy, ex, sy+(sy-ey))
	}
	if ex-sx <= ey-sy {
		return (ex - sx) + (ey - sy)
	}
	sx += ey - sy

	r := (ey - sy) * 2
	if sx%2 != ex%2 {
		if (sx+ey)%2 != 0 {
			r += 3
		} else {
			r += 1
		}
		sx += 1
	}
	r += (ex - sx) * 2
	return r
}

func abs(x int64) int64 {
	if x < 0 {
		x = -x
	}
	return x
}
