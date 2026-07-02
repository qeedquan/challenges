#!/usr/bin/env python3

"""

You're in ancient Greece and giving Philoctetes a hand in preparing a training exercise for Hercules! You've filled a pit with two different ferocious mythical creatures for Hercules to battle!

Orthus

Hydra

The formidable "Orthus" is a 2 headed dog with 1 tail. The mighty "Hydra" has 5 heads and 1 tail.

Before Hercules goes in, he asks you "How many of each beast am I up against!?".

You know the total number of heads and the total number of tails, that's the dangerous parts, right? But you didn't consider how many of each beast.

Task
Given the number of heads and the number of tails, work out the number of each mythical beast!

The data is given as two parameters. Your answer should be returned as an array:

 VALID ->      [24 , 15]           INVALID ->  "No solutions"
            [Orthus, Hydra]
If there aren't any cases for the given amount of heads and tails - return "No solutions" or null (C#).

"""

def beasts(heads, tails):
    value = (heads - tails*2) // 3
    if tails - value >= 0 and value >= 0:
        return [tails - value, value]
    return "No solutions"

def main():
    assert(beasts(123, 39) == [24, 15])
    assert(beasts(371, 88) == [23, 65])
    assert(beasts(24, 12) == [12, 0])
    assert(beasts(113, 37) == [24, 13])
    assert(beasts(635, 181) == [90, 91])

    assert(beasts(25, 555) == "No solutions")
    assert(beasts(12, 25) == "No solutions")
    assert(beasts(54, 956) == "No solutions")

main()
