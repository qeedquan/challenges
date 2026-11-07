/*

--- Day 5: Cafeteria ---
As the forklifts break through the wall, the Elves are delighted to discover that there was a cafeteria on the other side after all.

You can hear a commotion coming from the kitchen. "At this rate, we won't have any time left to put the wreaths up in the dining hall!" Resolute in your quest, you investigate.

"If only we hadn't switched to the new inventory management system right before Christmas!" another Elf exclaims. You ask what's going on.

The Elves in the kitchen explain the situation: because of their complicated new inventory management system, they can't figure out which of their ingredients are fresh and which are spoiled. When you ask how it works, they give you a copy of their database (your puzzle input).

The database operates on ingredient IDs. It consists of a list of fresh ingredient ID ranges, a blank line, and a list of available ingredient IDs. For example:

3-5
10-14
16-20
12-18

1
5
8
11
17
32
The fresh ID ranges are inclusive: the range 3-5 means that ingredient IDs 3, 4, and 5 are all fresh. The ranges can also overlap; an ingredient ID is fresh if it is in any range.

The Elves are trying to determine which of the available ingredient IDs are fresh. In this example, this is done as follows:

Ingredient ID 1 is spoiled because it does not fall into any range.
Ingredient ID 5 is fresh because it falls into range 3-5.
Ingredient ID 8 is spoiled.
Ingredient ID 11 is fresh because it falls into range 10-14.
Ingredient ID 17 is fresh because it falls into range 16-20 as well as range 12-18.
Ingredient ID 32 is spoiled.
So, in this example, 3 of the available ingredient IDs are fresh.

Process the database file from the new inventory management system. How many of the available ingredient IDs are fresh?

--- Part Two ---
The Elves start bringing their spoiled inventory to the trash chute at the back of the kitchen.

So that they can stop bugging you when they get new inventory, the Elves would like to know all of the IDs that the fresh ingredient ID ranges consider to be fresh. An ingredient ID is still considered fresh if it is in any range.

Now, the second section of the database (the available ingredient IDs) is irrelevant. Here are the fresh ingredient ID ranges from the above example:

3-5
10-14
16-20
12-18
The ingredient IDs that these ranges consider to be fresh are 3, 4, 5, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, and 20. So, in this example, the fresh ingredient ID ranges consider a total of 14 ingredient IDs to be fresh.

Process the database file again. How many ingredient IDs are considered to be fresh according to the fresh ingredient ID ranges?

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"sort"
)

func main() {
	p, r, err := load("5.txt")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(part1(p, r))
	fmt.Println(part2(r))
}

func part1(p []int64, r [][2]int64) int64 {
	c := int64(0)
	for _, i := range p {
		for _, r := range r {
			if r[0] <= i && i <= r[1] {
				c += 1
				break
			}
		}
	}
	return c
}

func part2(r [][2]int64) int64 {
	sort.Slice(r, func(i, j int) bool {
		if r[i][0] == r[j][0] {
			return r[i][1] < r[j][1]
		}
		return r[i][0] < r[j][0]
	})

	m := [][2]int64{}
	for _, r := range r {
		i := len(m)
		if i == 0 || m[i-1][1] < r[0]-1 {
			m = append(m, r)
		} else {
			m[i-1][1] = max(m[i-1][1], r[1])
		}
	}

	c := int64(0)
	for _, p := range m {
		c += p[1] - p[0] + 1
	}
	return c
}

func load(name string) ([]int64, [][2]int64, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, nil, err
	}
	defer f.Close()

	r := [][2]int64{}
	p := []int64{}
	s := bufio.NewScanner(f)
	for s.Scan() {
		var x, y int64
		t := s.Text()
		n, _ := fmt.Sscanf(t, "%d-%d", &x, &y)
		if n != 2 {
			n, _ = fmt.Sscanf(t, "%d", &x)
		}

		if n == 1 {
			p = append(p, x)
		} else if n == 2 {
			r = append(r, [2]int64{x, y})
		}
	}
	return p, r, nil
}
