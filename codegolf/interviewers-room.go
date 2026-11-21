/*

You are James and four of your friends (Bjarne, Eich, Rossum, Ada) are called for an interview. There are n interviewers, and they can each serve one person at a time, alphabetically. Each round of interview takes 20 min.

Let's take n = 2,

So, the first round started with Ada and Bjarne, takes 20 min (they're handled simultaneously). Then, interviewers call persons for next round, who are Eich and James, they took another 20 min.

Hence, finally you're out after 40 min.

Challenge
Given an array as input like ["yourName", [an, Array, Of, Friends], numberOfInterviewers], your task is to output the time it'll take for you to complete the interview, in minutes.

Feel free to take three arguments as input, instead of the array.

Sample I/O:
(In = Out format)

[ "James", ["Bjarne", "Eich"   , "Rossum", "Ada"  ], 2  ]   =   40
[ "Stark", ["Steve" , "Tchalla", "Banner", "Scott"], 3  ]   =   20
[ "spam" , ["bar"   , "eggs"   , "foo"   , "lorem"], 1  ]   =   100
[ "Oggy" , ["Jack"  , "DeeDee" , "Marky" , "Bob"  ], 10 ]   =   20
This is a code-golf, so fewest bytes will win!

*/

package main

func main() {
	assert(wait("James", []string{"Bjarne", "Eich", "Rossum", "Ada"}, 2) == 40)
	assert(wait("Stark", []string{"Steve", "Tchalla", "Banner", "Scott"}, 3) == 20)
	assert(wait("spam", []string{"bar", "eggs", "foo", "lorem"}, 1) == 100)
	assert(wait("Oggy", []string{"Jack", "DeeDee", "Marky", "Bob"}, 10) == 20)
	assert(wait("John", []string{}, 0) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func wait(name string, friends []string, interviewers int) int {
	if interviewers < 1 {
		return 0
	}
	position := rank(friends, name)
	return 20 * max(position/interviewers, 1)
}

func rank(array []string, value string) int {
	result := 1
	for _, other := range array {
		if value > other {
			result += 1
		}
	}
	return result
}
