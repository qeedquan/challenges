#!/usr/bin/env python3

"""

Remember the good old days when opening a simple document or web page was painfully slow as it hogged all the meager resources your computer had? And today, doing the same is even slower, despite your processor being hundreds of times faster and having access to thousands of times more memory?

To simulate the effect of bloat in current document viewers and similar applications, write a program which has visible performance problems when run on more powerful machines.

To have a common task for everyone, make it a prime number generator.

The program has to print consecutive prime numbers, starting from 2, each in a new line, and nothing else. It should to this forever (or until running out of memory). Like this:
2
3
5
7
11
13
17
There should be a delay between printing each line, enough to be perceivable by a human.

This delay should be longer as the machine the program is running on gets faster. The faster the machine, the slower the program.

I won't specify exact benchmarks as it might become subjective, but there should be a human-perceivable difference in the speed on two different machines if there is significant difference between the performance of the two machines.

The speed of the program doesn't have to be monotonically decreasing across all existing machines ever created. This would be hard to specify, and even harder to verify. I trust the common sense of the contestants about what can be considered a significantly different performance between to machines, and it is enough to satisfy that.

I also won't specify exact upper or lower time limits, but it should be under reasonable limits, so no days or years between printing two lines please.

I won't require it to run on everything from the Eniac to modern day, but it should be general enough, for example, it's not allowed to say it only works on two specific CPU types, and specifically detects the name of one specific CPU on which it will run slower or faster.

The code shouldn't rely on compiler or interpreter version. It should work if the same version of the compiler/interpreter is installed on both a slower and faster machine, or even if the binary / bytecode is compiled on one machine and then run on two different machines.

Please explain the principles of how your program is operating. As it will be difficult to reproduce the results, the validity of the answer might depend on the the feasibility of the method.

Although I would have liked it to become an underhanded contest, sadly this site is no longer "Programming Puzzles & Code Golf" but just simply "Code Golf", so the shortest code wins.

"""

from sympy import nextprime

def main():
    n = 2
    while True:
        print(n)
        n = nextprime(n)

main()
