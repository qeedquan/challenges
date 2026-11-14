/*

--- Day 20: Firewall Rules ---
You'd like to set up a small hidden computer here so you can use it to get back into the network later. However, the corporate firewall only allows communication with certain external IP addresses.

You've retrieved the list of blocked IPs from the firewall, but the list seems to be messy and poorly maintained, and it's not clear which IPs are allowed. Also, rather than being written in dot-decimal notation, they are written as plain 32-bit integers, which can have any value from 0 through 4294967295, inclusive.

For example, suppose only the values 0 through 9 were valid, and that you retrieved the following blacklist:

5-8
0-2
4-7
The blacklist specifies ranges of IPs (inclusive of both the start and end value) that are not allowed. Then, the only IPs that this firewall allows are 3 and 9, since those are the only numbers not in any range.

Given the list of blocked IPs you retrieved from the firewall (your puzzle input), what is the lowest-valued IP that is not blocked?

--- Part Two ---
How many IPs are allowed by the blacklist?

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
	p, err := load("20.txt")
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(part1(p))
	fmt.Println(part2(p))
}

func part1(p [][2]int) int {
	i := 0
	for _, r := range p {
		if i < r[0] {
			return i
		}
		i = max(i, r[1]+1)
	}
	return -1
}

func part2(p [][2]int) int {
	i := 0
	v := 0
	for _, r := range p {
		if i < r[0] {
			v += r[0] - i
		}
		i = max(i, r[1]+1)
	}
	return v
}

func load(name string) ([][2]int, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	s := bufio.NewScanner(f)
	r := [][2]int{}
	for s.Scan() {
		var r0, r1 int
		_, err := fmt.Sscanf(s.Text(), "%d-%d", &r0, &r1)
		if err != nil {
			break
		}
		r = append(r, [2]int{r0, r1})
	}

	sort.Slice(r, func(i, j int) bool {
		return r[i][0] < r[j][0]
	})
	return r, nil
}
