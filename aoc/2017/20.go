/*

--- Day 20: Particle Swarm ---
Suddenly, the GPU contacts you, asking for help. Someone has asked it to simulate too many particles, and it won't be able to finish them all in time to render the next frame at this rate.

It transmits to you a buffer (your puzzle input) listing each particle in order (starting with particle 0, then particle 1, particle 2, and so on). For each particle, it provides the X, Y, and Z coordinates for the particle's position (p), velocity (v), and acceleration (a), each in the format <X,Y,Z>.

Each tick, all particles are updated simultaneously. A particle's properties are updated in the following order:

Increase the X velocity by the X acceleration.
Increase the Y velocity by the Y acceleration.
Increase the Z velocity by the Z acceleration.
Increase the X position by the X velocity.
Increase the Y position by the Y velocity.
Increase the Z position by the Z velocity.
Because of seemingly tenuous rationale involving z-buffering, the GPU would like to know which particle will stay closest to position <0,0,0> in the long term. Measure this using the Manhattan distance, which in this situation is simply the sum of the absolute values of a particle's X, Y, and Z position.

For example, suppose you are only given two particles, both of which stay entirely on the X-axis (for simplicity). Drawing the current states of particles 0 and 1 (in that order) with an adjacent a number line and diagram of current X positions (marked in parentheses), the following would take place:

p=< 3,0,0>, v=< 2,0,0>, a=<-1,0,0>    -4 -3 -2 -1  0  1  2  3  4
p=< 4,0,0>, v=< 0,0,0>, a=<-2,0,0>                         (0)(1)

p=< 4,0,0>, v=< 1,0,0>, a=<-1,0,0>    -4 -3 -2 -1  0  1  2  3  4
p=< 2,0,0>, v=<-2,0,0>, a=<-2,0,0>                      (1)   (0)

p=< 4,0,0>, v=< 0,0,0>, a=<-1,0,0>    -4 -3 -2 -1  0  1  2  3  4
p=<-2,0,0>, v=<-4,0,0>, a=<-2,0,0>          (1)               (0)

p=< 3,0,0>, v=<-1,0,0>, a=<-1,0,0>    -4 -3 -2 -1  0  1  2  3  4
p=<-8,0,0>, v=<-6,0,0>, a=<-2,0,0>                         (0)
At this point, particle 1 will never be closer to <0,0,0> than particle 0, and so, in the long run, particle 0 will stay closest.

Which particle will stay closest to position <0,0,0> in the long term?

--- Part Two ---
To simplify the problem further, the GPU would like to remove any particles that collide. Particles collide if their positions ever exactly match. Because particles are updated simultaneously, more than two particles can collide at the same time and place. Once particles collide, they are removed and cannot collide with anything else after that tick.

For example:

p=<-6,0,0>, v=< 3,0,0>, a=< 0,0,0>
p=<-4,0,0>, v=< 2,0,0>, a=< 0,0,0>    -6 -5 -4 -3 -2 -1  0  1  2  3
p=<-2,0,0>, v=< 1,0,0>, a=< 0,0,0>    (0)   (1)   (2)            (3)
p=< 3,0,0>, v=<-1,0,0>, a=< 0,0,0>

p=<-3,0,0>, v=< 3,0,0>, a=< 0,0,0>
p=<-2,0,0>, v=< 2,0,0>, a=< 0,0,0>    -6 -5 -4 -3 -2 -1  0  1  2  3
p=<-1,0,0>, v=< 1,0,0>, a=< 0,0,0>             (0)(1)(2)      (3)
p=< 2,0,0>, v=<-1,0,0>, a=< 0,0,0>

p=< 0,0,0>, v=< 3,0,0>, a=< 0,0,0>
p=< 0,0,0>, v=< 2,0,0>, a=< 0,0,0>    -6 -5 -4 -3 -2 -1  0  1  2  3
p=< 0,0,0>, v=< 1,0,0>, a=< 0,0,0>                       X (3)
p=< 1,0,0>, v=<-1,0,0>, a=< 0,0,0>

------destroyed by collision------
------destroyed by collision------    -6 -5 -4 -3 -2 -1  0  1  2  3
------destroyed by collision------                      (3)
p=< 0,0,0>, v=<-1,0,0>, a=< 0,0,0>
In this example, particles 0, 1, and 2 are simultaneously destroyed at the time and place marked X. On the next tick, particle 3 passes through unharmed.

How many particles are left after all collisions are resolved?

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
)

type Vec3 struct {
	x, y, z int
}

type Particle struct {
	position     Vec3
	velocity     Vec3
	acceleration Vec3
}

func main() {
	particles, err := load("20.txt")
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(part1(particles))
	fmt.Println(part2(particles))
}

func part1(particles []Particle) int {
	result := 0
	best := math.MaxInt
	for index, particle := range particles {
		distance := manhattan(particle.acceleration)
		if distance < best {
			best = distance
			result = index
		}
	}
	return result
}

func part2(particles []Particle) int {
	collided := make([]bool, len(particles))
	for range 40 {
		for i := range particles {
			update(&particles[i])
		}

		collisions := []int{}
		for i := 0; i < len(particles); i++ {
			if collided[i] {
				continue
			}

			for j := i + 1; j < len(particles); j++ {
				if collided[j] {
					continue
				}

				if particles[i].position == particles[j].position {
					collisions = append(collisions, i, j)
				}
			}
		}

		for _, i := range collisions {
			collided[i] = true
		}
	}

	result := 0
	for i := range collided {
		if !collided[i] {
			result += 1
		}
	}
	return result
}

func load(name string) (particles []Particle, err error) {
	file, err := os.Open(name)
	if err != nil {
		return
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		var (
			px, py, pz int
			vx, vy, vz int
			ax, ay, az int
		)
		line := scanner.Text()
		fmt.Sscanf(line, "p=<%d,%d,%d>, v=<%d,%d,%d>, a=<%d,%d,%d>",
			&px, &py, &pz, &vx, &vy, &vz, &ax, &ay, &az)

		particles = append(particles, Particle{
			Vec3{px, py, pz},
			Vec3{vx, vy, vz},
			Vec3{ax, ay, az},
		})

	}
	return
}

func update(p *Particle) {
	p.velocity = add(p.velocity, p.acceleration)
	p.position = add(p.position, p.velocity)
}

func add(a, b Vec3) Vec3 {
	return Vec3{
		a.x + b.x,
		a.y + b.y,
		a.z + b.z,
	}
}

func manhattan(v Vec3) int {
	return abs(v.x) + abs(v.y) + abs(v.z)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
