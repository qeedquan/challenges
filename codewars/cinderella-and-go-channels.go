/*

Introduction
The good ones go into the pot the bad ones go into your crop

This sounds like the story of Cinderella and if she used Go, this exercise might help her to get the job done.

Learning Goals
This kata should teach you about how to read from channels and how to use multiple return values.

Task
You're given a channel, filled with strings ... many strings. Those strings are either good or bad. Your task is to read all of those strings out of the channel until it's empty. And while doing it, keep track of the amounts of good and bad grains ... ehm strings.

Write a function func PickGrains(<-chan string) (int, int), which takes a channel of strings and returns two integers: the first one with the amount of good occurrences, the second one with the amount of bad occurrences.

Example
// channel contains 3 times "good" and 4 times "bad"
grains := make(chan string, 7)
grains<-"good"
grains<-"bad"
grains<-"bad"
grains<-"good"
grains<-"bad"
grains<-"bad"
grains<-"good"
close(grains)

// your implementation of the PickGranes function
good, bad := PickGrains(grains)
// good must be 3
// bad must be 4

*/

package main

import "fmt"

func main() {
	grains := make(chan string, 7)
	grains <- "good"
	grains <- "bad"
	grains <- "bad"
	grains <- "good"
	grains <- "bad"
	grains <- "bad"
	grains <- "good"
	close(grains)

	fmt.Println(pickgrains(grains))
}

func pickgrains(grains <-chan string) (int, int) {
	var good, bad int
	for grain := range grains {
		switch grain {
		case "good":
			good++
		case "bad":
			bad++
		}
	}
	return good, bad
}
