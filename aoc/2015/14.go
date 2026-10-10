/*

--- Day 14: Reindeer Olympics ---
This year is the Reindeer Olympics! Reindeer can fly at high speeds, but must rest occasionally to recover their energy. Santa would like to know which of his reindeer is fastest, and so he has them race.

Reindeer can only either be flying (always at their top speed) or resting (not moving at all), and always spend whole seconds in either state.

For example, suppose you have the following Reindeer:

Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.
Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds.
After one second, Comet has gone 14 km, while Dancer has gone 16 km. After ten seconds, Comet has gone 140 km, while Dancer has gone 160 km. On the eleventh second, Comet begins resting (staying at 140 km), and Dancer continues on for a total distance of 176 km. On the 12th second, both reindeer are resting. They continue to rest until the 138th second, when Comet flies for another ten seconds. On the 174th second, Dancer flies for another 11 seconds.

In this example, after the 1000th second, both reindeer are resting, and Comet is in the lead at 1120 km (poor Dancer has only gotten 1056 km by that point). So, in this situation, Comet would win (if the race ended at 1000 seconds).

Given the descriptions of each reindeer (in your puzzle input), after exactly 2503 seconds, what distance has the winning reindeer traveled?

--- Part Two ---
Seeing how reindeer move in bursts, Santa decides he's not pleased with the old scoring system.

Instead, at the end of each second, he awards one point to the reindeer currently in the lead. (If there are multiple reindeer tied for the lead, they each get one point.) He keeps the traditional 2503 second time limit, of course, as doing otherwise would be entirely ridiculous.

Given the example reindeer from above, after the first second, Dancer is in the lead and gets one point. He stays in the lead until several seconds into Comet's second burst: after the 140th second, Comet pulls into the lead and gets his first point. Of course, since Dancer had been in the lead for the 139 seconds before that, he has accumulated 139 points by the 140th second.

After the 1000th second, Dancer has accumulated 689 points, while poor Comet, our old champion, only has 312. So, with the new scoring system, Dancer would win (if the race ended at 1000 seconds).

Again given the descriptions of each reindeer (in your puzzle input), after exactly 2503 seconds, how many points does the winning reindeer have?

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"strconv"
	"strings"
)

type Reindeer struct {
	name  string
	speed int
	fly   int
	rest  int
}

func main() {
	reindeers, err := load("14.txt")
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(part1(reindeers))
	fmt.Println(part2(reindeers))
}

func part1(reindeers []Reindeer) int {
	best := math.MinInt
	for _, reindeer := range reindeers {
		best = max(best, distance(reindeer, 2503))
	}
	return best
}

func part2(reindeers []Reindeer) int {
	points := make(map[string]int)
	result := math.MinInt
	for time := 1; time <= 2503; time++ {
		best := math.MinInt
		winners := []string{}
		for _, reindeer := range reindeers {
			length := distance(reindeer, time)
			if length >= best {
				if length == best {
					winners = append(winners, reindeer.name)
				} else {
					winners = []string{reindeer.name}
				}
				best = max(best, length)
			}
		}

		for _, winner := range winners {
			points[winner] += 1
			result = max(result, points[winner])
		}
	}
	return result
}

func distance(reindeer Reindeer, time int) int {
	cycle_time := reindeer.fly + reindeer.rest
	complete := time / cycle_time
	partial := min(time%cycle_time, reindeer.fly)
	return reindeer.speed * (reindeer.fly*complete + partial)
}

func load(name string) ([]Reindeer, error) {
	file, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	reindeers := []Reindeer{}
	for scanner.Scan() {
		fields := strings.Split(scanner.Text(), " ")
		if len(fields) != 15 {
			continue
		}

		reindeer := Reindeer{}
		reindeer.name = fields[0]
		reindeer.speed, _ = strconv.Atoi(fields[3])
		reindeer.fly, _ = strconv.Atoi(fields[6])
		reindeer.rest, _ = strconv.Atoi(fields[13])
		reindeers = append(reindeers, reindeer)
	}
	return reindeers, nil
}
