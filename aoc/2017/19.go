/*

--- Day 19: A Series of Tubes ---
Somehow, a network packet got lost and ended up here. It's trying to follow a routing diagram (your puzzle input), but it's confused about where to go.

Its starting point is just off the top of the diagram. Lines (drawn with |, -, and +) show the path it needs to take, starting by going down onto the only line connected to the top of the diagram. It needs to follow this path until it reaches the end (located somewhere within the diagram) and stop there.

Sometimes, the lines cross over each other; in these cases, it needs to continue going the same direction, and only turn left or right when there's no other option. In addition, someone has left letters on the line; these also don't change its direction, but it can use them to keep track of where it's been. For example:

     |
     |  +--+
     A  |  C
 F---|----E|--+
     |  |  |  D
     +B-+  +--+

Given this diagram, the packet needs to take the following path:

Starting at the only line touching the top of the diagram, it must go down, pass through A, and continue onward to the first +.
Travel right, up, and right, passing through B in the process.
Continue down (collecting C), right, and up (collecting D).
Finally, go all the way left through E and stopping at F.
Following the path to the end, the letters it sees on its path are ABCDEF.

The little packet looks up at you, hoping you can help it find the way. What letters will it see (in the order it would see them) if it follows the path? (The routing diagram is very wide; make sure you view it without line wrapping.)

--- Part Two ---
The packet is curious how many steps it needs to go.

For example, using the same routing diagram from the example above...

     |
     |  +--+
     A  |  C
 F---|--|-E---+
     |  |  |  D
     +B-+  +--+

...the packet would go:

6 steps down (including the first line at the top of the diagram).
3 steps right.
4 steps up.
3 steps right.
4 steps down.
3 steps right.
2 steps up.
13 steps left (including the F it stops on).
This would result in a total of 38 steps.

How many steps does the packet need to go?

*/

package main

import (
	"bytes"
	"fmt"
	"log"
	"os"
)

func main() {
	pipes, err := load("19.txt")
	if err != nil {
		log.Fatal(err)
	}

	route, steps := solve(pipes)
	fmt.Printf("%s\n", route)
	fmt.Println(steps)
}

func solve(pipes [][]byte) (route []byte, steps int) {
	if len(pipes) == 0 || len(pipes[0]) == 0 {
		return
	}

	x := bytes.IndexByte(pipes[0], '|')
	y := 0
	letter := byte('|')
	direction := 'd'
	for letter != ' ' {
		steps += 1
		switch letter {
		case '|', '-':

		case '+':
			switch direction {
			case 'd', 'u':
				direction = 'r'
				if pipes[y][x-1] != ' ' {
					direction = 'l'
				}

			default:
				direction = 'd'
				if pipes[y-1][x] != ' ' {
					direction = 'u'
				}
			}

		default:
			route = append(route, letter)
		}

		switch direction {
		case 'd':
			y += 1
		case 'u':
			y -= 1
		case 'r':
			x += 1
		case 'l':
			x -= 1
		}
		letter = pipes[y][x]
	}
	return
}

func load(name string) ([][]byte, error) {
	data, err := os.ReadFile(name)
	if err != nil {
		return nil, err
	}

	pipes := bytes.Split(data, []byte{'\n'})
	size := len(pipes)
	if size > 0 && len(pipes[size-1]) == 0 {
		pipes = pipes[:size-1]
	}
	return pipes, nil
}
