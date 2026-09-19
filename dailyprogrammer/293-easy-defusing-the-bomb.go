/*

Description
To disarm the bomb you have to cut some wires. These wires are either white, black, purple, red, green or orange.

The rules for disarming are simple:

If you cut a white cable you can't cut white or black cable.
If you cut a red cable you have to cut a green one
If you cut a black cable it is not allowed to cut a white, green or orange one
If you cut a orange cable you should cut a red or black one
If you cut a green one you have to cut a orange or white one
If you cut a purple cable you can't cut a purple, green, orange or white cable
If you have anything wrong in the wrong order, the bomb will explode.

There can be multiple wires with the same colour and these instructions are for one wire at a time. Once you cut a wire you can forget about the previous ones.

Formal Inputs & Outputs
Input description
You will recieve a sequence of wires that where cut in that order and you have to determine if the person was succesfull in disarming the bomb or that it blew up.

Input 1
white
red
green
white
Input 2
white
orange
green
white
Output description
Wheter or not the bomb exploded

Output 1
"Bomb defused"
Output 2
"Boom"
Notes/Hints
A state machine will help this make easy

Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

*/

package main

func main() {
	assert(disarm([]string{
		"white",
		"red",
		"green",
		"white",
	}) == "Bomb defused")

	assert(disarm([]string{
		"white",
		"orange",
		"green",
		"white",
	}) == "Boom")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@skeeto

The state machine is packed into a 64-bit integer, which is used as an array of six 6-bit integers.
Each 6-bit integer has a bit set for each edge.
An input that doesn't match an edge is a failure.
That is, I've encoded the challenge description into a single integer.

  ogrpkw
o 001010
g 100001
r 010000
p 001010
b 001110
w 111100

Which flattens to: 001010100001010000001010001110111100
Which is: 0x2a140a3bc

*/

func disarm(colors []string) string {
	const rules = 0x2a140a3bc

	ids := map[string]int{
		"white":  0,
		"black":  1,
		"purple": 2,
		"red":    3,
		"green":  4,
		"orange": 5,
	}

	next := uint64(0x3f)
	for _, color := range colors {
		id, found := ids[color]
		if !found {
			return "Invalid"
		}
		if next&(1<<id) == 0 {
			return "Boom"
		}
		next = (rules >> (6 * id)) & 0x3f
	}
	return "Bomb defused"
}
