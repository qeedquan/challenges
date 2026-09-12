#!/usr/bin/env python3

"""

The "standard" polyhedral game dice have 4, 6, 8, 10, 12 and 20 sides.
(Yes, I know that there are two 10-sided dice which together make a d100, but we're ignoring that right now.)

If I want to generate a random number between 1 and n where n is not one of those sides, I have a couple of options.

One option is to pick a die with more sides than my maximum and just re-roll if the result is larger than I want.
For example, if I want a number between 1 and 7, I can roll the 8-sided die:
if it's between 1 and 7, that's great; if it's 8, I can just re-roll until it is between 1 and 7.

Re-rolling is a bit of a pain though, but if your number n is a factor of one of the die's side counts, you can just double-count some of the faces.
Specifically, if your number is n, you can choose an (n×m)-sided die, roll it, and then take the result modulo m.
For example, if you want to generate a number between 1 and 3, then you can roll a six-sided die:
if the result is between 1 and 3, you are done; if it's greater than 3, just subtract 3 to get the result.

We can even use both at once!
For example, if I want to generate a number from 1 to 9, I can use a 20-sided die to generate a number from 1 to 18 with Method 1.
18 is a multiple of 9, so I can use Method 2 to get a number from 1 to 9.

So there are multiple ways to roll certain numbers. How do we decide which is best? Well, I have a couple of criteria I use:

First, I count the number of dead faces where we would have to re-roll. The method with fewer dead faces is better.
If the dead faces are equal, then the method using the die with fewer faces is better.

Task
Your task is to take a set of integers representing the polyhedral dice,
and an integer representing the size of a range to generate a random int on (range from 1 to n).

You should output which polyhedral die in the input set has the best method as described above.

You may take the set in any reasonable format, including a strictly ascending or descending list.
The size of the range will always be at most equal to the maximum of the set and at least 1.

This is code-golf, so the goal is to minimize the size of your source code as measured in bytes.

Test cases
set = {4,6,8,10,12,20}
1 -> 4
2 -> 4
3 -> 6
4 -> 4
5 -> 10
6 -> 6
7 -> 8
8 -> 8
9 -> 10
10 -> 10
11 -> 12
12 -> 12
13 -> 20
14 -> 20
19 -> 20
20 -> 20
set = {12,16}
5 -> 16
set = {3,5}
2 -> 3

"""

def solve(s, d):
    return min((z < d, z % d, z) for z in sorted(s))[2]

def main():
    s = [4, 6, 8, 10, 12, 20]
    r = [4, 4, 6, 4, 10, 6, 8, 8, 10, 10, 12, 12, 20, 20, 20, 20]
    for i in range(len(r)):
        assert(solve(s, i + 1) == r[i])

    assert(solve([12, 16], 5) == 16)
    assert(solve([3, 5], 2) == 3)

main()
