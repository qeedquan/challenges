/*

--- Day 2: Red-Nosed Reports ---
Fortunately, the first location The Historians want to search isn't a long walk from the Chief Historian's office.

While the Red-Nosed Reindeer nuclear fusion/fission plant appears to contain no sign of the Chief Historian, the engineers there run up to you as soon as they see you. Apparently, they still talk about the time Rudolph was saved through molecular synthesis from a single electron.

They're quick to add that - since you're already here - they'd really appreciate your help analyzing some unusual data from the Red-Nosed reactor. You turn to check if The Historians are waiting for you, but they seem to have already divided into groups that are currently searching every corner of the facility. You offer to help with the unusual data.

The unusual data (your puzzle input) consists of many reports, one report per line. Each report is a list of numbers called levels that are separated by spaces. For example:

7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9
This example data contains six reports each containing five levels.

The engineers are trying to figure out which reports are safe. The Red-Nosed reactor safety systems can only tolerate levels that are either gradually increasing or gradually decreasing. So, a report only counts as safe if both of the following are true:

The levels are either all increasing or all decreasing.
Any two adjacent levels differ by at least one and at most three.
In the example above, the reports can be found safe or unsafe by checking those rules:

7 6 4 2 1: Safe because the levels are all decreasing by 1 or 2.
1 2 7 8 9: Unsafe because 2 7 is an increase of 5.
9 7 6 2 1: Unsafe because 6 2 is a decrease of 4.
1 3 2 4 5: Unsafe because 1 3 is increasing but 3 2 is decreasing.
8 6 4 4 1: Unsafe because 4 4 is neither an increase or a decrease.
1 3 6 7 9: Safe because the levels are all increasing by 1, 2, or 3.
So, in this example, 2 reports are safe.

Analyze the unusual data from the engineers. How many reports are safe?

--- Part Two ---
The engineers are surprised by the low number of safe reports until they realize they forgot to tell you about the Problem Dampener.

The Problem Dampener is a reactor-mounted module that lets the reactor safety systems tolerate a single bad level in what would otherwise be a safe report. It's like the bad level never happened!

Now, the same rules apply as before, except if removing a single level from an unsafe report would make it safe, the report instead counts as safe.

More of the above example's reports are now safe:

7 6 4 2 1: Safe without removing any level.
1 2 7 8 9: Unsafe regardless of which level is removed.
9 7 6 2 1: Unsafe regardless of which level is removed.
1 3 2 4 5: Safe by removing the second level, 3.
8 6 4 4 1: Safe by removing the third level, 4.
1 3 6 7 9: Safe without removing any level.
Thanks to the Problem Dampener, 4 reports are actually safe!

Update your analysis by handling situations where the Problem Dampener can remove a single level from unsafe reports. How many reports are now safe?

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"slices"
	"strconv"
	"strings"
)

func main() {
	a, err := getints("2.txt")
	check(err)

	fmt.Println(part1(a))
	fmt.Println(part2(a))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func valid(a []int) bool {
	f := 0
	for i := 1; i < len(a) && f != 3; i++ {
		d := abs(a[i] - a[i-1])
		if d < 1 || d > 3 {
			return false
		}

		if a[i] > a[i-1] {
			f |= 1
		} else if a[i] < a[i-1] {
			f |= 2
		}
	}
	return f == 1 || f == 2
}

func part1(a [][]int) int {
	c := 0
	for i := range a {
		if valid(a[i]) {
			c += 1
		}
	}
	return c
}

func part2(a [][]int) int {
	c := 0
loop:
	for i := range a {
		if valid(a[i]) {
			c += 1
			continue loop
		}

		for j := range len(a[i]) {
			if valid(slices.Concat(a[i][:j], a[i][j+1:])) {
				c += 1
				continue loop
			}
		}
	}
	return c
}

func getints(name string) ([][]int, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	r := [][]int{}
	s := bufio.NewScanner(f)
	for s.Scan() {
		t := strings.Split(s.Text(), " ")
		x := []int{}
		for i := range t {
			v, _ := strconv.Atoi(t[i])
			x = append(x, v)
		}
		r = append(r, x)
	}
	return r, nil
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
