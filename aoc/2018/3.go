/*

--- Day 3: No Matter How You Slice It ---
The Elves managed to locate the chimney-squeeze prototype fabric for Santa's suit (thanks to someone who helpfully wrote its box IDs on the wall of the warehouse in the middle of the night). Unfortunately, anomalies are still affecting them - nobody can even agree on how to cut the fabric.

The whole piece of fabric they're working on is a very large square - at least 1000 inches on each side.

Each Elf has made a claim about which area of fabric would be ideal for Santa's suit. All claims have an ID and consist of a single rectangle with edges parallel to the edges of the fabric. Each claim's rectangle is defined as follows:

The number of inches between the left edge of the fabric and the left edge of the rectangle.
The number of inches between the top edge of the fabric and the top edge of the rectangle.
The width of the rectangle in inches.
The height of the rectangle in inches.
A claim like #123 @ 3,2: 5x4 means that claim ID 123 specifies a rectangle 3 inches from the left edge, 2 inches from the top edge, 5 inches wide, and 4 inches tall. Visually, it claims the square inches of fabric represented by # (and ignores the square inches of fabric represented by .) in the diagram below:

...........
...........
...#####...
...#####...
...#####...
...#####...
...........
...........
...........
The problem is that many of the claims overlap, causing two or more claims to cover part of the same areas. For example, consider the following claims:

#1 @ 1,3: 4x4
#2 @ 3,1: 4x4
#3 @ 5,5: 2x2
Visually, these claim the following areas:

........
...2222.
...2222.
.11XX22.
.11XX22.
.111133.
.111133.
........
The four square inches marked with X are claimed by both 1 and 2. (Claim 3, while adjacent to the others, does not overlap either of them.)

If the Elves all proceed with their own plans, none of them will have enough fabric. How many square inches of fabric are within two or more claims?

--- Part Two ---
Amidst the chaos, you notice that exactly one claim doesn't overlap by even a single square inch of fabric with any other claim. If you can somehow draw attention to it, maybe the Elves will be able to make Santa's suit after all!

For example, in the claims above, only claim 3 is intact after all claims are made.

What is the ID of the only claim that doesn't overlap?

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"math/big"
	"os"
)

func main() {
	c, err := readcells("3.txt")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(calc1(c))
	fmt.Println(calc2(c))
}

type Cell struct {
	ids *big.Int
	hit int
}

func readcells(name string) (map[[2]int]*Cell, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	c := make(map[[2]int]*Cell)
	b := bufio.NewScanner(f)
	for b.Scan() {
		var id uint
		var x, y, w, h int
		n, _ := fmt.Sscanf(b.Text(), "#%d @ %d,%d: %dx%d", &id, &x, &y, &w, &h)
		if n != 5 {
			continue
		}
		mark(c, id, x, y, w, h)
	}
	return c, nil
}

func mark(c map[[2]int]*Cell, id uint, x, y, w, h int) {
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			p := [2]int{x + j, y + i}
			e := c[p]
			if e == nil {
				e = &Cell{ids: new(big.Int)}
				c[p] = e
			}

			b := big.NewInt(1)
			b.Lsh(b, id)
			e.ids.Or(e.ids, b)
			e.hit++
		}
	}
}

func calc1(c map[[2]int]*Cell) int {
	r := 0
	for _, e := range c {
		if e.hit > 1 {
			r++
		}
	}
	return r
}

func calc2(c map[[2]int]*Cell) int {
	u := new(big.Int)
	v := new(big.Int)
	for _, e := range c {
		if e.hit == 1 {
			u.Or(u, e.ids)
		} else {
			v.Or(v, e.ids)
		}
	}
	v.Not(v)
	u.And(u, v)

	return int(u.TrailingZeroBits())
}
