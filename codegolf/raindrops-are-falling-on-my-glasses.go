/*

I live in the UK, where it rains. A lot. I also have the unfortunate necessity to need to wear glasses to see, which means that when it rains (as it is now), I can barely see out of them. This challenge is so that you can all experience the same!

Task
Output ASCII art glasses with a drop of water added each second.

Input
None

Output
A pair of glasses with drops of water on them.

Glasses
 ________________________
|          /__\          |
|         /    \         |
|        /      \        |
\_______/        \_______/
Raindrops
A raindrop is denoted by a .. A raindrop is randomly placed on the glasses' lenses. So when a raindrop is placed, the glasses might look like this

 ________________________
|          /__\          |
|    .    /    \         |
|        /      \        |
\_______/        \_______/
If it is placed on a blank space (), an . is placed on the image. If it is placed on a square which already has a raindrop, the drop graduates.

The steps on drops are

no drops placed:
1 drop placed: .
2 drops placed: o
3 drops placed: O
4+ drops placed: @

Rules
The image should look as though it stays in place. This means that you can either clear the screen or print enough newlines to "clear" the screen. You cannot return a list of steps. Sorry about this, but you should be able to work around that.
When outputting newlines to "clear" the screen, you must have at least 3 newlines between the glasses.
The code runs until the glasses are full of fully graduated drops i.e. until the output looks like this:
     ________________________
    |@@@@@@@@@@/__\@@@@@@@@@@|
    |@@@@@@@@@/    \@@@@@@@@@|
    |@@@@@@@@/      \@@@@@@@@|
    \_______/        \_______/

Shortest code in bytes wins.

*/

package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"time"
)

func main() {
	rainman()
}

func rainman() {
	pool, spots := newpool()
	for {
		output(pool)
		if full(pool) {
			break
		}
		update(pool, spots)
		time.Sleep(100 * time.Millisecond)
	}
}

func newpool() ([][]byte, [][2]int) {
	pool := [][]byte{
		[]byte(`     ________________________`),
		[]byte(`    |@@@@@@@@@@/__\@@@@@@@@@@|`),
		[]byte(`    |@@@@@@@@@/    \@@@@@@@@@|`),
		[]byte(`    |@@@@@@@@/      \@@@@@@@@|`),
		[]byte(`    \_______/        \_______/`),
	}
	spots := [][2]int{}

	for y := range pool {
		for x := range pool[y] {
			if pool[y][x] == '@' {
				pool[y][x] = 0
				spots = append(spots, [2]int{x, y})
			}
		}
	}

	return pool, spots
}

func full(pool [][]byte) bool {
	for y := range pool {
		for _, c := range pool[y] {
			if c < 4 {
				return false
			}
		}
	}
	return true
}

func update(pool [][]byte, spots [][2]int) {
	for {
		i := rand.Intn(len(spots))
		p := spots[i]
		x, y := p[0], p[1]
		if pool[y][x] < 4 {
			pool[y][x]++
			break
		}
	}
}

func output(pool [][]byte) {
	sym := []byte{' ', '.', 'o', 'O', '@'}
	fmt.Fprintf(stdout, "\033c")
	for y := range pool {
		for _, c := range pool[y] {
			if int(c) < len(sym) {
				c = sym[c]
			}
			fmt.Fprintf(stdout, "%c", c)
		}
		fmt.Fprintln(stdout)
	}
	stdout.Flush()
}

var stdout = bufio.NewWriter(os.Stdout)
