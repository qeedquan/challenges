/*

Once upon a time, in Ancient India, there was Raja - ruler of a certain region - infamous for his wealth, his cruelty - and his beautiful daughter. And it come to pass that this lovely princess fell in love with poor young guy from the village. They loved each other happily but were soon discovered. And Raja set the following trial - the fellow is placed in the room of a small labyrinth, overlooked by spectators - the room has two doors - and after some turns each of the passageways comes to one of two halls - either with a beautiful girl (not the princess herself though) - or with a fierce tiger. If the boy choses the way which leads him to the girl - he is freed and married to that girl. Otherwise, if he eventually finds the tiger - well, he has no chances, being even unarmed. So the boy is placed in the start room, he casts a glance around, sees spectators... and notices the princes, who, being able to visually trace passageways from above, makes a motion of her beautiful eyes, hinting to choose one of the doors. The encouraged youth quickly opens the door, follows the passageway and... what, do you think, he finds at the end?

This was just a variation of some short story (by Frank R. Stockton) - which we turn into the puzzle. Raja is keen about psychology and converted the maze into single line of rooms (say, N rooms) chained so that every room has left door and right door - to the neighboring rooms. The leftmost and rightmost rooms open to halls with a tiger and a girl. Here is an example with 5 rooms:

+---------+---+---+---+---+---+-------+
|         |   |   |   |   |   |   /   |
| (^.,.^) | 1 | 2 | 3 | 4 | 5 | O<8<= |
|         |   |   |   |   |   |   \   |
+---------+---+---+---+---+---+-------+
The poor fellow is put into one of the rooms (numbered) and doesn't know at which end what expects him. Thus he is to open every next door shivering, trembling, cold-sweating - but often he simply founds just a next room. Raja is much pleased to watch such emotions thus the chain of rooms may be pretty long.

Our hero being not very brave but some sort of mathematician decided not to provide Raja with such a pleasure and instead perform a kind of random walk. For this he uses stones found in every room - there are some brown and some yellow. He gathers them in the heap in the center of the room and closing his eyes pick one - if it is yeLLow, he moves to the Left, if bRown - to the Right. Stones remains in the rooms where they initially belonged, and the stone which was picked is carefully returned to the heap. Thus if some room is revisited eventually, exactly same chances are to leave it in this or that direction, as before.

Problem Statement
We are spectators and we know that tiger is on the left side and girl is on the right (just as in schematic above) we also know how many stones of which color are in each of the rooms. We know the number of the room where the young fellow is placed initially.

And we wonder, what is probability that he finds a girl rather than tiger (eventually - as his stochastic travel could be very-very long).

Input data contain the number of rooms N and starting room index P (1-based) in the first line.
Then N lines follow, each containing two values - for yellow (first) and brown (second) stones in each room.

Answer should give the probability, precise to 1e-7 or better.

Example

input:
5 2
5 4
3 6
7 7
6 3
4 5

answer
0.39130435

*/

package main

import "fmt"

func main() {
	fmt.Println(solve(2, [][2]int{
		{5, 4},
		{3, 6},
		{7, 7},
		{6, 3},
		{4, 5},
	}))
}

/*

This problem can be mathematically modeled as a one-dimensional random walk with absorbing boundaries,
often called the Gambler's Ruin problem with variable probabilities.


Mathematical Formulation

Let N be the total number of rooms, indexed from 1 to N.
1. Moving left from room 1 leads to the Tiger (an absorbing state at index 0).
2. Moving right from room N leads to the Girl (an absorbing state at index N+1).

For each room i (where 1 <= i <= N) let Yi be the number of yellow stones (move left) and Bi be the number of brown stones (move right)
The transition probabilities from room i are:

PL(i) = Yi/(Yi + Bi)
PR(i) = Bi/(Yi + Bi)

Let Pi be the probability that the mathematician eventually reaches the girl starting from room i.
The boundary conditions are:

P[0] = 0 (reaches the tiger)
P[N+1] = 1 (reaches the girl)

For any intermediate room i, the recurrence relation is:
P[i] = PL[i]*P[i-1] + PR[i]*P[i+1]

Solution:
Rewrite the above equation as:
P[i+1] - P[i] = Y[i]/B[i]*(P[i]-P[i-1])

Let D[i] = P[i+1] - P[i], then
D[i] = Y[i]/B[i]*D[i-1]

This gives a way to calculate D[i] as a dynamic programming problem.
After computing D[i], sum the probability up for the numerators/denominators to get the final probability

*/

func solve(P int, R [][2]int) float64 {
	N := len(R)
	D := make([]float64, N+1)
	D[0] = 1
	for i := 1; i <= N; i++ {
		Y := float64(R[i-1][0])
		B := float64(R[i-1][1])
		D[i] = D[i-1] * Y / B
	}

	n := 0.0
	d := 0.0
	for i := 0; i <= P-1; i++ {
		n += D[i]
	}
	for i := 0; i <= N; i++ {
		d += D[i]
	}
	return n / d
}
