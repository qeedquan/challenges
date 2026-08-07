/*

--- Day 16: Permutation Promenade ---
You come upon a very unusual sight; a group of programs here appear to be dancing.

There are sixteen programs in total, named a through p. They start by standing in a line: a stands in position 0, b stands in position 1, and so on until p, which stands in position 15.

The programs' dance consists of a sequence of dance moves:

Spin, written sX, makes X programs move from the end to the front, but maintain their order otherwise. (For example, s3 on abcde produces cdeab).
Exchange, written xA/B, makes the programs at positions A and B swap places.
Partner, written pA/B, makes the programs named A and B swap places.
For example, with only five programs standing in a line (abcde), they could do the following dance:

s1, a spin of size 1: eabcd.
x3/4, swapping the last two programs: eabdc.
pe/b, swapping programs e and b: baedc.
After finishing their dance, the programs end up in order baedc.

You watch the dance for a while and record their dance moves (your puzzle input). In what order are the programs standing after their dance?

--- Part Two ---
Now that you're starting to get a feel for the dance moves, you turn your attention to the dance as a whole.

Keeping the positions they ended up in from their previous dance, the programs perform it again and again: including the first dance, a total of one billion (1000000000) times.

In the example above, their second dance would begin with the order baedc, and use the same dance moves:

s1, a spin of size 1: cbaed.
x3/4, swapping the last two programs: cbade.
pe/b, swapping programs e and b: ceadb.
In what order are the programs standing after their billion dances?

*/

package main

import (
	"bytes"
	"fmt"
	"log"
	"math"
	"os"
	"strings"
)

type Op struct {
	code int
	arg  [2]int
}

func main() {
	const state = "abcdefghijklmnop"
	ops, err := load("16.txt")
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("%s\n", part1(ops, []byte(state)))
	fmt.Printf("%s\n", part2(ops, []byte(state)))
}

func part1(ops []Op, state []byte) []byte {
	return execute(ops, state)
}

func part2(ops []Op, state []byte) []byte {
	state0 := append([]byte{}, state...)
	length := 1
	for ; length < math.MaxInt; length++ {
		execute(ops, state)
		if bytes.Compare(state, state0) == 0 {
			break
		}
	}

	for range 1000000000 % length {
		execute(ops, state)
	}
	return state
}

func execute(ops []Op, state []byte) []byte {
	for _, op := range ops {
		switch op.code {
		case 'p':
			partner(state, byte(op.arg[0]), byte(op.arg[1]))
		case 's':
			spin(state, op.arg[0])
		case 'x':
			exchange(state, op.arg[0], op.arg[1])
		}
	}
	return state
}

func exchange(state []byte, index0, index1 int) {
	state[index0], state[index1] = state[index1], state[index0]
}

func spin(state []byte, amount int) {
	pivot := len(state) - amount
	newstate := append([]byte{}, state[pivot:]...)
	newstate = append(newstate, state[:pivot]...)
	copy(state, newstate)
}

func partner(state []byte, symbol0, symbol1 byte) {
	i := bytes.IndexByte(state, symbol0)
	j := bytes.IndexByte(state, symbol1)
	if i >= 0 && j >= 0 {
		state[i], state[j] = state[j], state[i]
	}
}

func load(name string) ([]Op, error) {
	data, err := os.ReadFile(name)
	if err != nil {
		return nil, err
	}

	ops := []Op{}
	for _, line := range strings.Split(string(data), ",") {
		if len(line) == 0 {
			continue
		}

		op := Op{}
		switch line[0] {
		case 'p':
			fmt.Sscanf(line, "%c%c/%c", &op.code, &op.arg[0], &op.arg[1])
		case 's':
			fmt.Sscanf(line, "%c%d", &op.code, &op.arg[0])
		case 'x':
			fmt.Sscanf(line, "%c%d/%d", &op.code, &op.arg[0], &op.arg[1])
		}
		ops = append(ops, op)
	}
	return ops, nil
}
