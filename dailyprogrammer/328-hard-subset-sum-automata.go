/*

Description
Earlier this year we did the subset sum problem wherein given a sequence of integers, can you find any subset that sums to 0. Today, inspired by this post let's play subset sum automata. It marries the subset sum problem with Conway's Game of Life.

You begin with a board full of random integers in each cell. Cells will increment or decrement based on a simple application of the subset sum problem: if any subset of the 8 neighboring cells can sum to the target value, you increment the cell's sum by some value; if not, you decrement the cell by that value. Automata are defined with three integers x/y/z, where x is the target value, y is the reward value, and z is the penalty value.

Your challenge today is to implement the subset automata:

Create a 2 dimensional board starting with random numbers

Color the board based on the value of the cell (I suggest some sort of rainbow effect if you can)

Parse the definition as described above

Increment or decrement the cell according to the rules described above

Redraw the board at each iteration

You'll probably want to explore various definitions and see what sorts of interesting patterns emerge.

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"math/rand"
	"os"
)

var flags struct {
	size    int
	scale   int
	target  int
	reward  int
	penalty int
	steps   int
}

func main() {
	parseflags()
	sim(flags.size, flags.scale, flags.target, flags.reward, flags.penalty, flags.steps)
}

func parseflags() {
	flag.IntVar(&flags.size, "size", 80, "specify grid size")
	flag.IntVar(&flags.scale, "scale", 10, "specify scale")
	flag.IntVar(&flags.target, "target", 8, "specify target")
	flag.IntVar(&flags.reward, "reward", 1, "specify reward value")
	flag.IntVar(&flags.penalty, "penalty", -1, "specify penalty value")
	flag.IntVar(&flags.steps, "steps", 1024, "number of steps to run")
	flag.Parse()
}

// ported from @skeeto solution
// ffmpeg -framerate 5 -i gol_%04d.ppm -c:v libx264 -r 30 gol.mp4
func sim(size, scale, target, reward, penalty, steps int) {
	var grid [2][][]int
	for i := range grid {
		grid[i] = alloc(size)
	}
	for y := range size {
		for x := range size {
			grid[0][y][x] = rand.Intn(17) - 8
		}
	}

	for step := range steps {
		name := fmt.Sprintf("gol_%04d.ppm", step)
		fd, err := os.Create(name)
		if err != nil {
			log.Println(err)
			continue
		}

		log.Println("writing to:", name)
		stream := bufio.NewWriter(fd)
		update(grid, step, target, reward, penalty)
		paint(stream, grid, step, size, scale)
		stream.Flush()
	}
}

func update(grid [2][][]int, step, target, reward, penalty int) {
	s := step & 1
	d := s ^ 1
	for y := range grid[s] {
		for x := range grid[s][y] {
			success := false
			for b := range 0x100 {
				sum := 0
				for i := range 8 {
					if ((b >> i) & 1) != 0 {
						nx := (x + DX(i) + len(grid[s][y])) % len(grid[s][y])
						ny := (y + DY(i) + len(grid[s])) % len(grid[s])
						sum += grid[s][ny][nx]
					}
				}
				if sum == target {
					success = true
					break
				}
			}

			if success {
				grid[d][y][x] += reward
			} else {
				grid[d][y][x] += penalty
			}
		}
	}
}

func paint(stream *bufio.Writer, grid [2][][]int, step, size, scale int) {
	d := (step & 1) ^ 1
	fmt.Fprintf(stream, "P6\n%d %d\n255\n", size*scale, size*scale)
	for py := range size * scale {
		for px := range size * scale {
			x := px / scale
			y := py / scale
			pixel(stream, grid[d][y][x]+180)
		}
	}
}

func pixel(w *bufio.Writer, v int) {
	h := mod(v, 360) / 60
	f := mod(v, 360) % 60
	t := byte(255 * f / 60)
	q := byte(255 - t)
	switch h {
	case 0:
		w.WriteByte(0xff)
		w.WriteByte(t)
		w.WriteByte(0)

	case 1:
		w.WriteByte(q)
		w.WriteByte(0xff)
		w.WriteByte(0)

	case 2:
		w.WriteByte(0)
		w.WriteByte(0xff)
		w.WriteByte(t)

	case 3:
		w.WriteByte(0)
		w.WriteByte(q)
		w.WriteByte(0xff)

	case 4:
		w.WriteByte(t)
		w.WriteByte(0)
		w.WriteByte(0xff)

	case 5:
		w.WriteByte(0xff)
		w.WriteByte(0)
		w.WriteByte(q)
	}
}

func alloc(n int) [][]int {
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, n)
	}
	return p
}

func mod(a, b int) int {
	return (a%b + b) % b
}

func DX(i int) int {
	return (((0x0489a621 >> (4*(i) + 0)) & 3) - 1)
}

func DY(i int) int {
	return (((0x0489a621 >> (4*(i) + 2)) & 3) - 1)
}
