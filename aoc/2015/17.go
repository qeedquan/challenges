/*

--- Day 17: No Such Thing as Too Much ---
The elves bought too much eggnog again - 150 liters this time. To fit it all into your refrigerator, you'll need to move it into smaller containers. You take an inventory of the capacities of the available containers.

For example, suppose you have containers of size 20, 15, 10, 5, and 5 liters. If you need to store 25 liters, there are four ways to do it:

15 and 10
20 and 5 (the first 5)
20 and 5 (the second 5)
15, 5, and 5
Filling all containers entirely, how many different combinations of containers can exactly fit all 150 liters of eggnog?

--- Part Two ---
While playing with all the containers in the kitchen, another load of eggnog arrives! The shipping and receiving department is requesting as many containers as you can spare.

Find the minimum number of containers that can exactly fit all 150 liters of eggnog. How many different ways can you fill that number of containers and still hold exactly 150 litres?

In the example above, the minimum number of containers was two. There were three ways to use that many containers, and so the answer there would be 3.

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"strconv"
)

func main() {
	x, err := load("17.txt")
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(part1(x, 150))
	fmt.Println(part2(x, 150))
}

func part1(x []int64, t int64) int64 {
	w := make([]int64, t+1)
	w[0] = 1
	for i := range len(x) {
		for j := t; j >= x[i]; j-- {
			w[j] += w[j-x[i]]
		}
	}
	return w[t]
}

func part2(x []int64, t int64) int64 {
	w := make([]int64, t+1)
	m := make([]int64, t+1)

	w[0] = 1
	for i := 1; i < len(m); i++ {
		m[i] = math.MaxInt32
	}

	for i := range len(x) {
		for j := t; j >= x[i]; j-- {
			a := m[j-x[i]] + 1
			b := m[j]
			if a < b {
				w[j] = w[j-x[i]]
				m[j] = a
			} else if a == b {
				w[j] += w[j-x[i]]
			}
		}
	}
	return w[t]
}

func load(name string) ([]int64, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	r := []int64{}
	s := bufio.NewScanner(f)
	for s.Scan() {
		v, _ := strconv.ParseInt(s.Text(), 0, 32)
		r = append(r, v)
	}
	return r, nil
}
