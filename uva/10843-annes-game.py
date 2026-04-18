#!/usr/bin/env python3

"""

Lily: “Chantarelle was part of my exotic phase.”
Buffy: “It’s nice. It’s a mushroom.”
Lily: “It is? That’s really embarrassing.”
Buffy: “Well, it’s an exotic mushroom, if that’s any comfort.”
Joss Whedon, "Anne".
A little girl whose name is Anne Spetring likes to play the following game. She draws a circle on
paper. Then she draws another one and connects it to the first cicrle by a line. Then she draws another
and connects it to one of the first two circles by a line. She continues this way until she has n circles
drawn and each one connected to one of the previously drawn circles. Her circles never intersect and
lines never cross. Finally, she numbers the circles from 1 to n in some random order.
How many different pictures can she draw that contain exactly n circles? Two pictures are different
if one of them has a line connecting circle number i to circle number j, and the other picture does not.

Input
The first line of input gives the number of cases, N. N test cases follow. Each one is a line containing
n (0 < n ≤ 100).

Output
For each test case, output one line containing ‘Case #x:’ followed by X, where X is the remainder
after dividing the answer by 2000000011.

Sample Input
3
1
2
3

Sample Output
Case #1: 1
Case #2: 1
Case #3: 3

"""

def solve(n):
    if n < 0:
        return 0 
    if n <= 2:
        return 1
    return n**(n-2) % 2000000011

def main():
    assert(solve(1) == 1)
    assert(solve(2) == 1)
    assert(solve(3) == 3)

main()

