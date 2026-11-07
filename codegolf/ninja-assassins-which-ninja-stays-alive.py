#!/usr/bin/env python3

"""

Ninja Assassins - which ninja stays alive
some basic information

given an int N as the number of ninjas, return the number of the winning ninja.
At the end only 1 ninja survives,the question is which one? what was his number?.
Each ninja kills the ninja who stands after him. Afterwards, he passes the sword to the first alive ninja who stood after the killed one.
Explenation - How the Game Works
The ninjas are numbered from 1 to N and stand in a circle according to the numbers. The circle goes clockwise: ninja 2 is left to ninja 1, ninja 3 is left to ninja 2, ninja 4 is left to ninja 3.... ninja 1 is left to ninja N.
Ninja 1 gets a sword and the game begins:
Each ninja (starting from ninja 1) kills the closest and alive ninja he has to the left (clockwise) . Afterwards, he passes the sword to the 2nd closest and alive ninja he has to the left.The 2nd ninja does the same (kills and passes) (as an example: N=3(we have 3 ninjas), ninja 1 kills ninja 2 and gives the sword to ninja 3. Ninja 3 has ninja 1 as his closest and alive ninja to the left(clockwise - its a circle) so he kills ninja 1, stays the last ninja alive and wins (so the output\return is 3, as the number of the ninja)).
A more detailed example below

Example - Word-detailed scenario
N = 7 (we got 7 ninjas) :

1 2 3 4 5 6 7 (L=alive, D=dead)
L D L L L L L The first ninja gets the sword and kills the 2nd ninja.
              The first ninja passes the sword to the 3rd ninja.
L D L D L L L The 3rd ninja gets the sword and kills the 4th ninja.
              The 3rd Ninja passes the sword to the 5th ninja.
L D L D L D L The 5th ninja gets the sword and kills the 6th ninja.
              The 5th Ninja passes the sword to the 7th ninja.
D D L D L D L The 7th ninja gets the sword and kills the first(1st) ninja.
              The 7th ninja passes the sword to the 3rd ninja.
D D L D D D L The 3rd ninja gets the sword and kills the 5th ninja.
              The 3rd ninja passes the sword to the 7th ninja.
D D D D D D L The 7th ninja gets the sword and kills the 3rd ninja,
              stays as the last one alive and wins (the final result /
              the output is 7).
More scenarios without words
N=3 : 1 2 3 - 1 3 - 3 wins
N=4 : 1 2 3 4 - 1 3 - 1 wins
N=5 : 1 2 3 4 5 - 1 3 5 - 3 5 - 3 wins
N=6 : 1 2 3 4 5 6 - 1 3 5 - 1 5 - 5 wins
N=7 : 1 2 3 4 5 6 7 - 1 3 5 7 - 3 7 - 7 wins

Scoring is based on the least number of bytes used, as this is a code-golf question.

"""

"""

https://oeis.org/A006257

@xnor

Takes the binary expansion of n and moves the initial 1 to the end.

"""
def alive(n):
    if n < 1:
        return 0
    return int(bin(n)[3:] + '1', 2)

def main():
    tab = [0, 1, 1, 3, 1, 3, 5, 7, 1, 3, 5, 7, 9, 11, 13, 15, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29]

    assert(alive(3) == 3)
    assert(alive(4) == 1)
    assert(alive(5) == 3)
    assert(alive(6) == 5)
    assert(alive(7) == 7)

    for i in range(len(tab)):
        assert(alive(i) == tab[i])

main()
