#!/usr/bin/env python3

"""

The Monty Hall Problem is a probability brain teaser that has a rather unintuitive solution.

The gist of it, taken from Wikipedia:

Suppose you're on a game show, and you're given the choice of three doors: Behind one door is a car; behind the others, goats. You pick a door, say No. 1 [but the door is not opened], and the host, who knows what's behind the doors, opens another door, say No. 3, which has a goat. He then says to you, "Do you want to pick door No. 2?" Is it to your advantage to switch your choice? (clarification: the host will always reveal a goat)

Your task is to write a function that will compare the strategies of switching and not switching over many random position iterations. Your program should output the proportion of successful choices by each strategy. Assume that if both unpicked doors contain goats the host will open one of those doors at random with equal probability.

If you want to, you can for simplicity's sake assume that the player picks the first door every time. The only aspect of this scenario that needs to vary is what is behind each door.

Thanks to SleepyTurtle for posting this idea at r/dailyprogrammer_ideas! Do you have a problem you think would be good for us! Head on over there and post it!

"""

import random

def simulate(trials):
    stay = 0
    switch = 0
    pick = 0
    for _ in range(trials):
        prize = random.randint(0, 2)
        if pick == prize:
            stay += 1
        else:
            switch += 1
    print("Trials:", trials, "Stay:", stay, "Switch:", switch)

def main():
    simulate(1000000)

main()
