#!/usr/bin/env python3

"""

This problem uses the same money-changing device from Monday's Easy challenge.

Bytelandian Currency is made of coins with integers on them. There is a coin for each non-negative integer (including 0). You have access to a peculiar money changing machine. If you insert a N-valued coin, it pays back 3 coins of the value N/2,N/3 and N/4, rounded down. For example, if you insert a 19-valued coin, you get three coins worth 9, 6, and 4. If you insert a 2-valued coin, you get three coins worth 1, 0, and 0.

This machine can potentially be used to make a profit. For instance, a 20-valued coin can be changed into three coins worth 10, 6, and 5, and 10+6+5 = 21. Through a series of exchanges, you're able to turn a 1000-valued coin into a set of coins with a total value of 1370.

Starting with a single N-valued coin, what's the maximum value you could get using this machine? Be able to handle very large N.

Author: Thomas1122

Formal Inputs & Outputs
Input Description
The value N of the coin you start with

Output Description
The maximum total value of coins you can potentially exchange that coin for.

Sample Inputs & Outputs
Sample Input
1000

Sample Output
1370

Challenge Input
10000000000 (aka 1010 aka 10 billion)

Challenge Input Solution
???

Note
Hint: use recursion!

Please direct questions about this challenge to u/Cosmologicon

Bonus:

Given a value N, what single-valued coin less than or equal to N will yield the greatest profit (ie, total value of all coins you finish with, minus the value of the starting coin)? What value of coin <= 10,000,000,000 yields the greatest profit?

"""

from functools import lru_cache
import sys

@lru_cache(maxsize=None)
def solve(n):
    if n < 1:
        return 0
    return max(n, solve(n//2) + solve(n//3) + solve(n//4))

def main():
    sys.setrecursionlimit(1000000)

    assert(solve(1000) == 1370)
    assert(solve(10000000000) == 51544065905)
    assert(solve(10**1000) == 107428639370816894282905754471321831518581303185425911940693187681195007321945988349882143120902910400886527923620957274764951380456741382084706587048538786154771612940823867761038833086956122124681283950342202102907719931543369912800740053443551539289722666291720359846410140779179924104094766456788576904771417042802444892483345375529093935583084253865006408160389805593176530643710579419012595042578031772447113635678144051094440330549055091411989660718033246620933839392551824546424923488957675932121571155907787854455748165845176223146906449047431508730495745633313271764866571423579399796775704176595215852644453976623823367419021424402783381524810655198501269693938129700094066493794659564823372029540527720068315371071207607522278012105675340595722082148948234123939638207721957567717407731813328775369184448827317789554077827350035143824296462233041623198614297228892656550316185255221724146893318035161668707135088732309129845480263028807967273443643378810339582419287587907021278692142889371486606957198689248383852081657427214676080014962347334671570118688132967723155789)

main()

