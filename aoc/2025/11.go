/*

--- Day 11: Reactor ---
You hear some loud beeping coming from a hatch in the floor of the factory, so you decide to check it out. Inside, you find several large electrical conduits and a ladder.

Climbing down the ladder, you discover the source of the beeping: a large, toroidal reactor which powers the factory above. Some Elves here are hurriedly running between the reactor and a nearby server rack, apparently trying to fix something.

One of the Elves notices you and rushes over. "It's a good thing you're here! We just installed a new server rack, but we aren't having any luck getting the reactor to communicate with it!" You glance around the room and see a tangle of cables and devices running from the server rack to the reactor. She rushes off, returning a moment later with a list of the devices and their outputs (your puzzle input).

For example:

aaa: you hhh
you: bbb ccc
bbb: ddd eee
ccc: ddd eee fff
ddd: ggg
eee: out
fff: out
ggg: out
hhh: ccc fff iii
iii: out
Each line gives the name of a device followed by a list of the devices to which its outputs are attached. So, bbb: ddd eee means that device bbb has two outputs, one leading to device ddd and the other leading to device eee.

The Elves are pretty sure that the issue isn't due to any specific device, but rather that the issue is triggered by data following some specific path through the devices. Data only ever flows from a device through its outputs; it can't flow backwards.

After dividing up the work, the Elves would like you to focus on the devices starting with the one next to you (an Elf hastily attaches a label which just says you) and ending with the main output to the reactor (which is the device with the label out).

To help the Elves figure out which path is causing the issue, they need you to find every path from you to out.

In this example, these are all of the paths from you to out:

Data could take the connection from you to bbb, then from bbb to ddd, then from ddd to ggg, then from ggg to out.
Data could take the connection to bbb, then to eee, then to out.
Data could go to ccc, then ddd, then ggg, then out.
Data could go to ccc, then eee, then out.
Data could go to ccc, then fff, then out.
In total, there are 5 different paths leading from you to out.

How many different paths lead from you to out?

--- Part Two ---
Thanks in part to your analysis, the Elves have figured out a little bit about the issue. They now know that the problematic data path passes through both dac (a digital-to-analog converter) and fft (a device which performs a fast Fourier transform).

They're still not sure which specific path is the problem, and so they now need you to find every path from svr (the server rack) to out. However, the paths you find must all also visit both dac and fft (in any order).

For example:

svr: aaa bbb
aaa: fft
fft: ccc
bbb: tty
tty: ccc
ccc: ddd eee
ddd: hub
hub: fff
eee: dac
dac: fff
fff: ggg hhh
ggg: out
hhh: out
This new list of devices contains many paths from svr to out:

svr,aaa,fft,ccc,ddd,hub,fff,ggg,out
svr,aaa,fft,ccc,ddd,hub,fff,hhh,out
svr,aaa,fft,ccc,eee,dac,fff,ggg,out
svr,aaa,fft,ccc,eee,dac,fff,hhh,out
svr,bbb,tty,ccc,ddd,hub,fff,ggg,out
svr,bbb,tty,ccc,ddd,hub,fff,hhh,out
svr,bbb,tty,ccc,eee,dac,fff,ggg,out
svr,bbb,tty,ccc,eee,dac,fff,hhh,out
However, only 2 paths from svr to out visit both dac and fft.

Find all of the paths that lead from svr to out. How many of those paths visit both dac and fft?

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

type Key struct {
	node string
	dac  bool
	fft  bool
}

func main() {
	maps, err := load("11.txt")
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(solve(maps, "you", true, true))
	fmt.Println(solve(maps, "svr", false, false))
}

func solve(maps map[string][]string, node string, dac, fft bool) int64 {
	return find(maps, node, dac, fft, make(map[Key]int64))
}

func find(maps map[string][]string, node string, dac, fft bool, seen map[Key]int64) int64 {
	key := Key{node, dac, fft}
	if result, found := seen[key]; found {
		return result
	}

	dac = dac || node == "dac"
	fft = fft || node == "fft"
	if node == "out" {
		return truth(dac && fft)
	}

	result := int64(0)
	for _, to := range maps[node] {
		result += find(maps, to, dac, fft, seen)
	}

	key = Key{node, dac, fft}
	seen[key] = result
	return result
}

func load(name string) (map[string][]string, error) {
	file, err := os.Open(name)
	if err != nil {
		return nil, nil
	}
	defer file.Close()

	maps := make(map[string][]string)
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		line = strings.TrimSpace(line)

		fields := strings.Split(line, " ")
		if len(fields) < 2 {
			continue
		}

		fields[0] = strings.TrimSuffix(fields[0], ":")
		maps[fields[0]] = fields[1:]
	}
	return maps, nil
}

func truth(x bool) int64 {
	if x {
		return 1
	}
	return 0
}
