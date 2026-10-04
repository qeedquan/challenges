#!/usr/bin/env python3

"""

Description

Bill has found the perfect way to make money playing the slot machines. After months of careful research, he has finally figured out the mechanics behind how the machines operate. Now he is ready to make profit of his findings.

But first an introduction to the game. A slot machine consists of a number of wheels, usually three or four, each with a number of symbols printed on it – cherries, oranges, bells, etc. – and will show one of its symbols at a given time. To play, you insert a coin, push a button and the wheels start spinning. After spinning for a while, each wheel stops – at random it seems – at one of its symbols. If all wheels stop at the same symbol, or some nice combination of symbols, the player wins. One combination that is especially desirable is having the jackpot symbol on all wheels. This combination is simply called ’jackpot’ and will make you rich for life.

What Bill has discovered is that each wheel will stop at the jackpot symbol with a certain periodicity, which differs a lot between wheels. He has also figured out (after some sneeking around at the slot-machine factory) that all newly manufactured slot-machines are delivered showing the jackpot combination, and that they all have a counter at the back, telling how many times the machine has been played. This counter is always set to zero at delivery.

Now, all Bill needs to do is to calculate the number of times a machine has to be played between two occurrences of the jackpot combination. We will call this number the jackpot periodicity. This is of course the same as the number of times the machine has to be played after leaving the factory, before it gives its first jackpot. Thus, with a glance at the counter on the back of a machine, Bill can figure out if it is about to give a jackpot.

As Bill knows that you are a skillful computer programmer, he turns to you with the problem of calculating the jackpot periodicity. For each machine, he will give you the number of wheels, and the periodicity with which the jackpot symbol shows up on each wheel.

Input

One line with the number of machines n ≤ 20. For each machine, one line with the number of wheels w ≤ 5, and one line with w numbers, p1, ..., pw the periodicity of each wheel pk ≤ 1000.

Output

One line per machine: The jackpot periodicity of the machine, if it is less than or equal to a billion (109), otherwise output the text ’More than a billion.’.

Sample Input

1
3
10 6 15

Sample Output

30

Source

Svenskt Mästerskap i Programmering/Norgesmesterskapet 2003

"""

from math import *

def periodicity(p):
    n = len(p)
    if n == 0:
        return 0

    v = p[0]
    for i in range(1, n):
        v = (v * p[i]) // gcd(v, p[i])
        if v > 1000000000:
            return "More than a billion."
    return v

def main():
    assert(periodicity([10, 6, 15]) == 30)

main()
