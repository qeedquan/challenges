/*

You might already be familiar with the game: Basketball FRVR in facebook. There are two types of score you can make:

A virgin-shot:(we call it so in our country :D) When the ball enters the basket without touching the rim or
A stale shot: When the ball enters the basket, but after touching the rim.
The game is over once you miss a shot. Stale shot always scores 2 points.The first in a run of consecutive virgin-shots scores 3 points, the second scores 6 points, and subsequent ones score 9 points each.

For example,

Hits             Total score

S-V-V-V          2+3+6+9 = 20
S-V-V-V-V        2+3+6+9+9 = 29 (see how added score for consecutive virgin-
                                 shots
                                 saturates at the 5th hit)
S-V-S-V-V-S-V    2+3+2+3+6+2+3= 21
Using simple mathematics, it can easily be proven that any score greater than 1 n>1 can be scored in the game

The Challenge
For any given number 1<n<100, output all the possible ways to score n.

Rules:
You can either write a complete program or function(s), snippets however are not acceptable.
Hard-coding the output or loading from memory/other programs/website is strictly prohibited, you must compute the output in real-time.
The output must be a well-separated collection of string of Ss and Vs. For eg: ['SVS','SSV','VSS'] or {'SVS','SSV','VSS'}.
It is encouraged to, but the collection need not be sorted or contain only unique elements. Brownie points if you output sorted and unique collection of strings.
Winning condition:
This is code-golf so the shortest code in bytes wins.
Input/Output (Test-cases)
2: {'S'}
3: {'V'}
4: {'SS'}
12: {'SSSSSS', 'VSSVS', 'VSVSS', 'VSSSV', 'SSVSV', 'SVSVS', 'SVSSV'}
16: {'SSSVSVS', 'SSSVSSV', 'VSSSSSV', 'SSVSSVS', 'SVVSV', 'VSSSSVS', 'SVSVV', 'SVSSSSV', 'VVSSV', 'VSVVS', 'SVSVSSS', 'SVSSSVS', 'VSSVSSS', 'SSVSSSV', 'SSSSSSSS', 'VVSVS', 'VSSSVSS', 'SVSSVSS', 'VSVSSSS', 'SSSSVSV', 'SSVSVSS', 'VSSVV'}
Thanks to Peter Taylor for improving this question

*/

package main

import (
	"fmt"
	"slices"
	"sort"
)

func main() {
	test(2, []string{"S"})
	test(3, []string{"V"})
	test(4, []string{"SS"})
	test(12, []string{"SSSSSS", "VSSVS", "VSVSS", "VSSSV", "SSVSV", "SVSVS", "SVSSV"})
	test(16, []string{"SSSVSVS", "SSSVSSV", "VSSSSSV", "SSVSSVS", "SVVSV", "VSSSSVS", "SVSVV", "SVSSSSV", "VVSSV", "VSVVS", "SVSVSSS", "SVSSSVS", "VSSVSSS", "SSVSSSV", "SSSSSSSS", "VVSVS", "VSSSVSS", "SVSSVSS", "VSVSSSS", "SSSSVSV", "SSVSVSS", "VSSVV"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(target int, expected []string) {
	sort.Strings(expected)
	result := solve(target)
	fmt.Println(result)
	assert(slices.Equal(result, expected))
}

func solve(target int) []string {
	result := []string{}
	find(target, 0, "", &result)
	sort.Strings(result)
	return result
}

func find(target, value int, moves string, result *[]string) {
	if value > target {
		return
	}
	if value == target {
		if moves != "" {
			*result = append(*result, moves)
		}
		return
	}

	find(target, value+2, moves+"S", result)
	find(target, value+virginscore(moves), moves+"V", result)
}

func virginscore(moves string) int {
	score := 3
	for i := len(moves) - 1; i >= 0; i-- {
		if moves[i] != 'V' {
			break
		}
		if score += 3; score >= 9 {
			break
		}
	}
	return score
}
