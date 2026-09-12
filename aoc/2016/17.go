/*

--- Day 17: Two Steps Forward ---
You're trying to access a secure vault protected by a 4x4 grid of small rooms connected by doors. You start in the top-left room (marked S), and you can access the vault (marked V) once you reach the bottom-right room:

#########
#S| | | #
#-#-#-#-#
# | | | #
#-#-#-#-#
# | | | #
#-#-#-#-#
# | | |
####### V
Fixed walls are marked with #, and doors are marked with - or |.

The doors in your current room are either open or closed (and locked) based on the hexadecimal MD5 hash of a passcode (your puzzle input) followed by a sequence of uppercase characters representing the path you have taken so far (U for up, D for down, L for left, and R for right).

Only the first four characters of the hash are used; they represent, respectively, the doors up, down, left, and right from your current position. Any b, c, d, e, or f means that the corresponding door is open; any other character (any number or a) means that the corresponding door is closed and locked.

To access the vault, all you need to do is reach the bottom-right room; reaching this room opens the vault and all doors in the maze.

For example, suppose the passcode is hijkl. Initially, you have taken no steps, and so your path is empty: you simply find the MD5 hash of hijkl alone. The first four characters of this hash are ced9, which indicate that up is open (c), down is open (e), left is open (d), and right is closed and locked (9). Because you start in the top-left corner, there are no "up" or "left" doors to be open, so your only choice is down.

Next, having gone only one step (down, or D), you find the hash of hijklD. This produces f2bc, which indicates that you can go back up, left (but that's a wall), or right. Going right means hashing hijklDR to get 5745 - all doors closed and locked. However, going up instead is worthwhile: even though it returns you to the room you started in, your path would then be DU, opening a different set of doors.

After going DU (and then hashing hijklDU to get 528e), only the right door is open; after going DUR, all doors lock. (Fortunately, your actual passcode is not hijkl).

Passcodes actually used by Easter Bunny Vault Security do allow access to the vault if you know the right path. For example:

If your passcode were ihgpwlah, the shortest path would be DDRRRD.
With kglvqrro, the shortest path would be DDUDRLRRUDRD.
With ulqzkmiv, the shortest would be DRURDRUDDLLDLUURRDULRLDUUDDDRR.
Given your vault's passcode, what is the shortest path (the actual path, not just the length) to reach the vault?

--- Part Two ---
You're curious how robust this security solution really is, and so you decide to find longer and longer paths which still provide access to the vault. You remember that paths always end the first time they reach the bottom-right room (that is, they can never pass through it, only end in it).

For example:

If your passcode were ihgpwlah, the longest path would take 370 steps.
With kglvqrro, the longest path would be 492 steps long.
With ulqzkmiv, the longest path would be 830 steps long.
What is the length of the longest path that reaches the vault?

*/

package main

import (
	"container/heap"
	"crypto/md5"
	"fmt"
	"image"
)

type Vertex struct {
	position image.Point
	path     string
}

type Queue []Vertex

var dirnames = []string{
	"U", "D", "L", "R",
}

var directions = [4]image.Point{
	{0, -1},
	{0, 1},
	{-1, 0},
	{1, 0},
}

func main() {
	input := "veumntbg"
	fmt.Println(part1(input))
	fmt.Println(part2(input))
}

func part1(input string) string {
	return dijkstra(input)
}

func part2(input string) int {
	return longest_path(input, Vertex{})
}

func dijkstra(input string) string {
	queue := &Queue{}
	heap.Init(queue)
	heap.Push(queue, Vertex{})
	for queue.Len() > 0 {
		vertex := heap.Pop(queue).(Vertex)
		if vertex.position == image.Pt(3, 3) {
			return vertex.path
		}

		hash := md5s(input + vertex.path)
		for i := range directions {
			if !(hash[i] >= 'b' && hash[i] <= 'f') {
				continue
			}

			next := vertex.position.Add(directions[i])
			if oob(next) {
				continue
			}

			heap.Push(queue, Vertex{next, vertex.path + dirnames[i]})
		}
	}
	return ""
}

func longest_path(input string, vertex Vertex) int {
	if vertex.position == image.Pt(3, 3) {
		return len(vertex.path)
	}

	longest := 0
	hash := md5s(input + vertex.path)
	for i := range directions {
		if !(hash[i] >= 'b' && hash[i] <= 'f') {
			continue
		}

		next := vertex.position.Add(directions[i])
		if oob(next) {
			continue
		}

		length := longest_path(input, Vertex{next, vertex.path + dirnames[i]})
		longest = max(longest, length)
	}
	return longest
}

func md5s(input string) string {
	return fmt.Sprintf("%02x", md5.Sum([]byte(input)))
}

func oob(p image.Point) bool {
	return p.X < 0 || p.Y < 0 || p.X >= 4 || p.Y >= 4
}

func (h Queue) Len() int           { return len(h) }
func (h Queue) Less(i, j int) bool { return len(h[i].path) < len(h[j].path) }
func (h Queue) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *Queue) Push(x any) {
	*h = append(*h, x.(Vertex))
}

func (h *Queue) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
