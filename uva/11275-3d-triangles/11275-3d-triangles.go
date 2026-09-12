package main

type Vec3 struct {
	x, y, z float64
}

type Triangle [3]Vec3

func main() {
	A1 := Triangle{
		{0.366955, 0.566515, 0.398724},
		{0.573168, 0.175512, 0.873745},
		{0.705588, 0.374035, 0.072390},
	}

	A2 := Triangle{
		{0.039521, 0.379528, 0.617084},
		{0.759484, 0.836268, 0.097446},
		{0.594165, 0.484085, 0.191534},
	}

	A3 := Triangle{
		{0, 0, 0},
		{2, 3, 0},
		{4, 0, 0},
	}

	B1 := Triangle{
		{0.292306, 0.515061, 0.371929},
		{0.623737, 0.169012, 0.514115},
		{0.839076, 0.717612, 0.255867},
	}

	B2 := Triangle{
		{0.283731, 0.896054, 0.182867},
		{0.443800, 0.472579, 0.899808},
		{0.473342, 0.573901, 0.769219},
	}

	B3 := Triangle{
		{0, 2, 0},
		{4, 2, 0},
		{2, -1, 0},
	}

	assert(trixtri(A1, B1) == true)
	assert(trixtri(A2, B2) == false)
	assert(trixtri(A3, B3) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func trixtri(A, B Triangle) bool {
	na := normal(A[0], A[1], A[2])
	nb := normal(B[0], B[1], B[2])
	for i := range 3 {
		j := (i + 1) % 3
		if trixseg(A, na, B[i], B[j]) || trixseg(B, nb, A[i], A[j]) {
			return true
		}
	}
	return false
}

func trixseg(A Triangle, n, p, q Vec3) bool {
	if cmp(dot(n, sub(q, p))) == 0 {
		return false
	}

	t := dot(n, sub(A[0], p)) / dot(n, sub(q, p))
	if !(0 <= t && t <= 1) {
		return false
	}

	r := add(p, scale(sub(q, p), t))
	return trixpt(A, r)
}

func trixpt(A Triangle, p Vec3) bool {
	s0 := cmp(dot(normal(A[0], A[2], p), normal(A[0], p, A[1])))
	s1 := cmp(dot(normal(A[1], A[0], p), normal(A[1], p, A[2])))
	s2 := cmp(dot(normal(A[2], A[1], p), normal(A[2], p, A[0])))
	return s0 == s1 && s1 == s2
}

func cmp(v float64) int {
	const eps = 1e-8
	if v < eps {
		return 0
	}
	if v > 0 {
		return 1
	}
	return -1
}

func add(a, b Vec3) Vec3 {
	return Vec3{a.x + b.x, a.y + b.y, a.z + b.z}
}

func sub(a, b Vec3) Vec3 {
	return Vec3{a.x - b.x, a.y - b.y, a.z - b.z}
}

func scale(a Vec3, s float64) Vec3 {
	return Vec3{a.x * s, a.y * s, a.z * s}
}

func dot(a, b Vec3) float64 {
	return a.x*b.x + a.y*b.y + a.z*b.z
}

func cross(a, b Vec3) Vec3 {
	return Vec3{
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x,
	}
}

func normal(p0, p1, p2 Vec3) Vec3 {
	return cross(sub(p1, p0), sub(p2, p0))
}
