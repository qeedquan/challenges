package main

import (
	"fmt"
	"math"
)

type Matrix [4][4]float64

type Vector struct {
	x, y, z float64
}

type Plane struct {
	a, b, c, d float64
}

func main() {
	solve([]Vector{{1, 2, 3}}, []Plane{{0, 0, 1, -2}, {3, 4, 1, -2}}, []string{
		"TRANSLATE 2 3 4",
		"ROTATE 1 0 0 90",
		"SCALE 3 2 1",
	})

	solve([]Vector{{1, 2, 3}}, []Plane{{0, 0, 1, -2}, {3, 4, 1, -2}}, []string{
		"TRANSLATE 2 3 4",
		"ROTATE 1 0 0 90",
		"SCALE 3 2 1",
		"ROTATE 1 4 2 90",
		"TRANSLATE 2 6 4",
	})
}

func solve(points []Vector, planes []Plane, commands []string) {
	var (
		op             string
		a1, a2, a3, a4 float64
		matrix         = matrix_eye()
	)
	for _, command := range commands {
		_, err := fmt.Sscanf(command, "%s %f %f %f %f", &op, &a1, &a2, &a3, &a4)
		if err != nil {
			_, err = fmt.Sscanf(command, "%s %f %f %f", &op, &a1, &a2, &a3)
		}

		if err != nil {
			continue
		}

		transformation := matrix_eye()
		switch op {
		case "TRANSLATE":
			transformation = matrix_translation(Vector{a1, a2, a3})
		case "ROTATE":
			transformation = matrix_rotation(deg2rad(a4), Vector{a1, a2, a3})
		case "SCALE":
			transformation = matrix_scale(Vector{a1, a2, a3})
		}
		matrix = matrix_multiply(transformation, matrix)
	}

	for _, point := range points {
		point = vector_transform(matrix, point)
		fmt.Println(point)
	}
	for _, plane := range planes {
		plane = plane_transform(matrix, plane)
		fmt.Println(plane)
	}
	fmt.Println()
}

func (v Vector) String() string {
	return fmt.Sprintf("[%.2f, %.2f, %.2f]", v.x, v.y, v.z)
}

func vector_transform(m Matrix, p Vector) Vector {
	return Vector{
		m[0][0]*p.x + m[0][1]*p.y + m[0][2]*p.z + m[0][3],
		m[1][0]*p.x + m[1][1]*p.y + m[1][2]*p.z + m[1][3],
		m[2][0]*p.x + m[2][1]*p.y + m[2][2]*p.z + m[2][3],
	}
}

func vector_length(v Vector) float64 {
	return math.Sqrt(v.x*v.x + v.y*v.y + v.z*v.z)
}

func vector_normalize(v Vector) Vector {
	l := vector_length(v)
	return Vector{v.x / l, v.y / l, v.z / l}
}

func vector_cross(a, b, c Vector) Vector {
	b.x -= a.x
	b.y -= a.y
	b.z -= a.z
	c.x -= a.x
	c.y -= a.y
	c.z -= a.z
	return Vector{
		b.y*c.z - b.z*c.y,
		b.z*c.x - b.x*c.z,
		b.x*c.y - b.y*c.x,
	}
}

func (p Plane) String() string {
	return fmt.Sprintf("[%.2f, %.2f, %.2f, %.2f]", p.a, p.b, p.c, p.d)
}

func plane_transform(m Matrix, p Plane) Plane {
	var a, b, c Vector
	w := max(math.Abs(p.a), math.Abs(p.b), math.Abs(p.c))
	switch {
	case math.Abs(p.a) == w:
		a = Vector{-p.d / p.a, 0, 0}
		b = Vector{(-p.d - p.b) / p.a, 1, 0}
		c = Vector{(-p.d - p.c) / p.a, 0, 1}
	case math.Abs(p.b) == w:
		a = Vector{1, (-p.d - p.a) / p.b, 0}
		b = Vector{0, -p.d / p.b, 0}
		c = Vector{0, (-p.d - p.c) / p.b, 1}
	default:
		a = Vector{1, 0, (-p.d - p.a) / p.c}
		b = Vector{0, 1, (-p.d - p.b) / p.c}
		c = Vector{0, 0, -p.d / p.c}
	}

	a = vector_transform(m, a)
	b = vector_transform(m, b)
	c = vector_transform(m, c)

	v := vector_cross(a, b, c)
	v = vector_normalize(v)

	return plane_negate(Plane{
		v.x,
		v.y,
		v.z,
		-(v.x*a.x + v.y*a.y + v.z*a.z),
	})
}

func plane_negate(p Plane) Plane {
	return Plane{-p.a, -p.b, -p.c, -p.d}
}

func matrix_multiply(a, b Matrix) Matrix {
	c := Matrix{}
	for i := range a {
		for j := range a[i] {
			for k := range a[j] {
				c[i][j] += a[i][k] * b[k][j]
			}
		}
	}
	return c
}

func matrix_eye() Matrix {
	return Matrix{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1},
	}
}

func matrix_scale(scale Vector) Matrix {
	return Matrix{
		{scale.x, 0, 0, 0},
		{0, scale.y, 0, 0},
		{0, 0, scale.z, 0},
		{0, 0, 0, 1},
	}
}

func matrix_translation(offset Vector) Matrix {
	return Matrix{
		{1, 0, 0, offset.x},
		{0, 1, 0, offset.y},
		{0, 0, 1, offset.z},
		{0, 0, 0, 1},
	}
}

func matrix_rotation(rad float64, axis Vector) Matrix {
	c := math.Cos(rad)
	s := math.Sin(rad)
	w := vector_normalize(axis)
	m := Matrix{}
	m[0][0] = c + w.x*w.x*(1-c)
	m[0][1] = w.x*w.y*(1-c) - w.z*s
	m[0][2] = w.y*s + w.x*w.z*(1-c)
	m[1][0] = w.z*s + w.x*w.y*(1-c)
	m[1][1] = c + w.y*w.y*(1-c)
	m[1][2] = -w.x*s + w.y*w.z*(1-c)
	m[2][0] = -w.y*s + w.x*w.z*(1-c)
	m[2][1] = w.x*s + w.y*w.z*(1-c)
	m[2][2] = c + w.z*w.z*(1-c)
	m[3][3] = 1
	return m
}

func deg2rad(x float64) float64 {
	return x * math.Pi / 180
}
