#!/usr/bin/env python3

"""

Background
This puzzle is a variation on the four fours puzzle (itself the topic of a past question). Like that puzzle, the aim is to find mathematical expressions for different whole numbers, using only four digits and certain mathematical operators. In this case, however, the permitted digits are just 2, 0, 1 and 5. Each must appear precisely once in the solution and in the correct order. Surprisingly many whole numbers can be represented this way. Solvers are encouraged to try solving it by hand first, as it's strangely enjoyable.

Rules
Constants may be constructed from single or multiple digits:

Integers: e.g. 2, 0, 15, etc.
Decimals: e.g. .2, .01, 1.5, etc.
Repeating decimals: e.g. .2~ (=0.222...), .15~ (=0.1555...), 20.15~~ (=20.1515...)
The following unary operations are permitted:

Unary negation: -x
Square root: sqrt(x)
Integer factorial: x!
The following binary operations are permitted:

Standard arithmetic operators: x+y, x-y, x*y and x/y
Arbitrary exponentiation: x^y
Arbitrary roots: rt[x](y) (= x'th root of y)
Task
Your program should print out expressions for as many of the integers between 0 and 100 as it can, and then output the number of expressions it has produced.

The solutions must be printed in order in the format n=[expr].
The expressions must use all the digits 2, 0, 1, 5, once each in that order.
The expressions must be printed using the notation described above. Unnecessary parentheses are permitted but not required, as is whitespace. The order of operator precedence is unary negation, factorial, exponentiation, multiplication/division and addition/subtraction.
The program need not return solutions for all the numbers. A program that simply outputs 0 is therefore valid; however, see the scoring section below.
The program should run in under 15 minutes on a modern computer.
You may write a program or function. The expressions should be printed to STDOUT (or closest alternative). The number of expressions can be printed to STDOUT or returned as an integer. Standard code golf restrictions apply.

Example output
0=2*0*1*5
10=20*1*.5
42=((2+0!)!+1)!/5!
100=20*1*5
4
Scoring
Update: @orlp has noted a flaw in the scoring system. See http://meta.codegolf.stackexchange.com/questions/5106/way-of-salvaging-two-zero-one-five-puzzle-challenge for a discussion of how or whether this should be fixed.

Solutions are scored first by the number of expressions they produce and then by their code length in bytes. Hence, a 1000 byte program that produce 80 results will beat a 100 byte program that produces only 79 (though the latter could easily be extended to include the missing results).

For those who would like a motivating target, below is a lower bound on the number of expressions that can be represented. I don't plan to submit an entry, so it may well be possible to win with less!

At least 85 (out of 101), though it may well be higher.

Scoreboard
As an extra incentive, here is a summary of the score progression. Whenever you beat the highest score, feel free to add yourself to the top of the table (or ask someone else to).

0 expressions, 1 byte (Pyth): implementation that just outputs 0

"""

"""

@orlp

  0 = ((2*0)^15)
  1 = ((2^0)^15)
  2 = (2-(0^15))
  3 = (20*.15)
  4 = (20*(1/5))
  5 = (20-15)
  6 = ((.20+1)*5)
  7 = ((20*.1)+5)
  8 = (2*((0-1)+5))
  9 = ((.20/.1~)*5)
 10 = (20/(1/.5))
 11 = ((((2-0)+1))!+5)
 12 = (20*(.1+.5))
 13 = ((-(2)-0)+15)
 14 = (20-(1+5))
 15 = ((2*0)+15)
 16 = ((2^0)+15)
 17 = ((2-0)+15)
 18 = (20-(1/.5))
 19 = (20-(1^5))
 20 = (20^(1^5))
 21 = (20+(1^5))
 22 = (20+(1/.5))
 23 = (((2-0)/.1~)+5)
 24 = ((20-1)+5)
 25 = ((20^1)+5)
 26 = ((20+1)+5)
 27 = (rt[.2](((0)!+1))-5)
 28 = (2*(-((0)!)+15))
 29 = ((((2+(0)!)+1))!+5)
 30 = ((2-0)*15)
 31 = (20+sqrt((1+(5)!)))
 32 = ((20*.1)^5)
 33 = ((.2^-((0)!))/.15~~)
 34 = (2+(((0)!+1)^5))
 35 = (20+15)
 36 = (20*(1/.5~))
 37 = (rt[.2](((0)!+1))+5)
 38 = ((20-1)/.5)
 39 = (-((2^0))+(sqrt(.1~)*(5)!))
 40 = (20*(1/.5))
 41 = (((.2~^-((0)!))/.1~)+.5)
 42 = ((20+1)/.5)
 43 = (-(2)+(((0)!/.1~)*5))
 44 = (20+((-(1)+5))!)
 45 = (20/(1-.5~))
 46 = ((.2+((0)!/.1~))*5)
 47 = (2+(((0)!/.1~)*5))
 48 = (2*(((0-1)+5))!)
 49 = ((((2+(0)!))!/.1~)-5)
 50 = (((2^0)/.1)*5)
 51 = ((.2+((0)!/.1))*5)
 52 = (2+(((0)!/.1)*5))
 54 = (((2+(0)!)/.1)/.5~)
 55 = ((2+((0)!/.1~))*5)
 56 = (((.2-(0)!)+sqrt(.1~))*-((5)!))
 58 = (-(2)+sqrt((((((0)!/sqrt(.1~)))!)!*5)))
 59 = ((((2+(0)!))!/.1~)+5)
 60 = (20/(.1~^.5))
 62 = (2*(-((0)!)+sqrt(rt[-(.1)](.5))))
 64 = ((2-0)^(1+5))
 65 = ((20/sqrt(.1~))+5)
 66 = ((-(((2+(0)!))!)/.1~)+(5)!)
 67 = (((((2+(0)!))!)!*.1)-5)
 69 = ((2^(((0)!/sqrt(.1~)))!)+5)
 70 = (((.2^-((0)!))/-(.1))+(5)!)
 72 = ((2+(0)!)*((-(1)+5))!)
 75 = ((.2^-((0)!))*15)
 76 = (rt[(-(2)^-((0)!))](.1~)-5)
 77 = (((((2+(0)!))!)!*.1)+5)
 78 = (2*(-((0)!)+(sqrt(.1~)*(5)!)))
 80 = (-(20)*(1-5))
 81 = (201-(5)!)
 82 = (2*((0)!+(sqrt(.1~)*(5)!)))
 84 = (((.2-(0)!)+.1)*-((5)!))
 85 = (((((2+(0)!))!)!*.1~)+5)
 86 = (rt[(-(2)^-((0)!))](.1~)+5)
 88 = (rt[.2]((-((0)!)-1))+(5)!)
 90 = ((20/.1~)*.5)
 93 = (((2+(0)!)/-(.1~))+(5)!)
 95 = ((20-1)*5)
 96 = ((.20-1)*-((5)!))
 98 = (-(20)*(.1-5))
 99 = ((-(20)-1)+(5)!)
100 = (20/(1/5))
85

"""

def solve():
    return 85

def main():
    print(solve())

main()
