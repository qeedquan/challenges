#!/usr/bin/env python3

"""

Define f(a,b) := a if b=1; a^f(a,b-1) if b>1 (Tetration, where ^ means power) for positive integers a and b, given four positive integers a,b,c,d, compare f(a,b) and f(c,d).

Your program should output three constant values to mean "greater", "less" and "equal".

Samples:

a b c d f(a,b) output f(c,d)
3 2 2 3 27     >      16
4 2 2 4 256    <      65536
4 1 2 2 4      =      4
Lowest time complexity to max{a,b,c,d} win, with tie-breaker code length(the shorter the better) and then answer time(the earlier the better).

Complexity assumption
Your code should handle a,b,c,d up to 100, and your algorithm should handle all legal input
You can assume integer calculations (that your language directly support) in O((a+b+c+d)^k) cost O(1) time if can be done in O(1) for 2k bit numbers if k bit computing can be done in O(1)
For example, both plus(+) and multiply(*) can be done in O(1) for 2k bit numbers if k bit computing for both can be done in O(1), so both satisy the requirement. It's fine if multiply can't be done without plus, or even if both can't be done without each other.
Float calculations in O(log(a+b+c+d)) bit precision in ±2^O((a+b+c+d)^k), takes O(1), with same requirements like integer calculations.

"""

def tetration(a, b):
    if b < 0:
        return 0
    if b == 0:
        return 1
    if b == 1:
        return a
    return a**tetration(a, b - 1)

def cmp(a, b, c, d):
    x = tetration(a, b)
    y = tetration(c, d)
    if x < y:
        return '<'
    if x == y:
        return '='
    return '>'

def main():
    assert(cmp(3, 2, 2, 3) == '>')
    assert(cmp(4, 2, 2, 4) == '<')
    assert(cmp(4, 1, 2, 2) == '=')

main()
