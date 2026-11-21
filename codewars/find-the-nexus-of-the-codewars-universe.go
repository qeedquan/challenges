/*

Not to brag, but I recently became the nexus of the Codewars universe! My honor and my rank were the same number. I cried a little.

Complete the method that takes a hash/object/directory/association list of users, and find the nexus: the user whose rank is the closest or equal to his honor. Return the rank of this user. For each user, the key is the rank and the value is the honor.

If nobody has an exact rank/honor match, return the rank of the user who comes closest. If there are several users who come closest, return the one with the lowest rank (numeric value). The hash will not necessarily contain consecutive rank numbers; return the best match from the ranks provided.

Example
         rank    honor
users = {  1  =>  93,
          10  =>  55,
          15  =>  30,
          20  =>  19,    <--- nexus
          23  =>  11,
          30  =>   2 }

*/

package main

import "math"

type User struct {
	rank  int
	honor int
}

func main() {
	assert(nexus([]User{{1, 3}, {3, 3}, {5, 1}}) == 3)
	assert(nexus([]User{{1, 10}, {2, 6}, {3, 4}, {5, 1}}) == 3)
	assert(nexus([]User{{1, 93}, {10, 55}, {15, 30}, {20, 19}, {23, 11}, {30, 2}}) == 20)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func nexus(users []User) int {
	minimum := math.MaxInt
	rank := 0
	for _, user := range users {
		distance := abs(user.rank - user.honor)
		if distance < minimum {
			minimum = distance
			rank = user.rank
		}
	}
	return rank
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
