/*

--- Day 10: Balance Bots ---
You come upon a factory in which many robots are zooming around handing small microchips to each other.

Upon closer examination, you notice that each bot only proceeds when it has two microchips, and once it does, it gives each one to a different bot or puts it in a marked "output" bin. Sometimes, bots take microchips from "input" bins, too.

Inspecting one of the microchips, it seems like they each contain a single number; the bots must use some logic to decide what to do with each chip. You access the local control computer and download the bots' instructions (your puzzle input).

Some of the instructions specify that a specific-valued microchip should be given to a specific bot; the rest of the instructions indicate what a given bot should do with its lower-value or higher-value chip.

For example, consider the following instructions:

value 5 goes to bot 2
bot 2 gives low to bot 1 and high to bot 0
value 3 goes to bot 1
bot 1 gives low to output 1 and high to bot 0
bot 0 gives low to output 2 and high to output 0
value 2 goes to bot 2
Initially, bot 1 starts with a value-3 chip, and bot 2 starts with a value-2 chip and a value-5 chip.
Because bot 2 has two microchips, it gives its lower one (2) to bot 1 and its higher one (5) to bot 0.
Then, bot 1 has two microchips; it puts the value-2 chip in output 1 and gives the value-3 chip to bot 0.
Finally, bot 0 has two microchips; it puts the 3 in output 2 and the 5 in output 0.
In the end, output bin 0 contains a value-5 microchip, output bin 1 contains a value-2 microchip, and output bin 2 contains a value-3 microchip. In this configuration, bot number 2 is responsible for comparing value-5 microchips with value-2 microchips.

Based on your instructions, what is the number of the bot that is responsible for comparing value-61 microchips with value-17 microchips?

--- Part Two ---
What do you get if you multiply together the values of one chip in each of outputs 0, 1, and 2?

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"slices"
)

type Bot struct {
	targets [2]*[]int
	chips   []int
}

func main() {
	bots, outs, err := load("10.txt")
	if err != nil {
		log.Fatal(err)
	}

	r1, r2 := solve(bots, outs)
	fmt.Println(r1)
	fmt.Println(r2)
}

func solve(bots, outs map[int]*Bot) (r1, r2 int) {
	defer func() {
		if err := recover(); err != nil {
			r1, r2 = 0, 0
		}
	}()

	for {
		actions := 0
		for id, bot := range bots {
			if len(bot.chips) == 2 {
				low := slices.Min(bot.chips)
				high := slices.Max(bot.chips)
				bot.chips = bot.chips[:0]
				if low == 17 && high == 61 {
					r1 = id
				}

				*bot.targets[0] = append(*bot.targets[0], low)
				*bot.targets[1] = append(*bot.targets[1], high)
				actions += 1
			}
		}
		if actions == 0 {
			break
		}
	}

	r2 = 1
	for i := range 3 {
		r2 *= outs[i].chips[0]
	}
	return
}

func load(name string) (bots, outs map[int]*Bot, err error) {
	file, err := os.Open(name)
	if err != nil {
		return
	}
	defer file.Close()

	bots = make(map[int]*Bot)
	outs = make(map[int]*Bot)
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		var (
			id    int
			nid   [2]int
			sid   [2]string
			value int
		)

		line := scanner.Text()
		_, err := fmt.Sscanf(line, "value %d goes to bot %d", &value, &id)
		if err == nil {
			bot := get(bots, id)
			bot.chips = append(bot.chips, value)
			continue
		}

		_, err = fmt.Sscanf(line, "bot %d gives low to %s %d and high to %s %d", &id, &sid[0], &nid[0], &sid[1], &nid[1])
		if err == nil {
			bot := get(bots, id)
			for i := range sid {
				var bot2 *Bot
				if sid[i] == "output" {
					bot2 = get(outs, nid[i])
				} else {
					bot2 = get(bots, nid[i])
				}
				bot.targets[i] = &bot2.chips
			}
		}
	}

	return
}

func get(pool map[int]*Bot, id int) *Bot {
	if pool[id] == nil {
		pool[id] = new(Bot)
	}
	return pool[id]
}
