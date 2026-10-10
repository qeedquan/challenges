#!/usr/bin/env python3

"""

Lets say your job is to paint poles, and a client asks you to paint a pole with 4 red sections and 3 yellow sections. You can do that pretty easily as follows:

r y r y r y r
With just yellow and red stripes. Now lets say your client asks you to paint a pole with 2 red sections, 2 yellow sections, and 1 green section. There are a couple of ways you could paint your pole

g y r y r
y g r y r
y r g y r
y r y g r
y r y r g
g r y r y
r g y r y
r y g r y
r y r g y
r y r y g
y r g r y
r y g y r
More precisely thats 12 ways to paint the pole. This blows up the more colors and sections that are involved

Now if your client says they want 3 red sections and 1 yellow section there is no way to paint a pole like that. Because no matter how you attempt to arrange the sections two red sections will touch, and when two red sections touch they become a single red section.

And that is pretty much our one rule for painting poles

Adjacent sections may not be of the same color

Task
Given a list of colors and sections required, output the number of possible ways to paint a pole as requested. You may represent colors in any reasonable way (integers, characters, strings), but you will never be given more than 255 different colors at a time. If you wish you can even choose to not have the colors assigned names and just take a list of section counts if that is easier.

Test Cases
These are rather hard to calculate by hand, especially as they get larger. If anyone has a suggested test case I'll add it.

[4,3]    -> 1
[2,2,1]  -> 12
[3,1]    -> 0
[8,3,2]  -> 0
[2,2,1,1]-> 84

"""

from itertools import *
import sys

def cmp(a, b):
    if a > b:
        return 1
    if a < b:
        return -1
    return 0

def mkstr(a):
    r = ""
    i = ord('a')
    for x in a:
        r += chr(i)*x
        i += 1
    return r

"""

https://math.stackexchange.com/questions/1060583/permute-aaaaabbbbbccccc-so-that-no-two-identical-letters-are-adjacent
https://oeis.org/A110706

"""

def colorpole(a):
    s = mkstr(a)
    r = []
    for p in permutations(s):
        if all(map(cmp, p, p[1:])):
            r.append(p)
    return len(set(r))

def main():
    assert(colorpole([4, 3]) == 1)
    assert(colorpole([2, 2, 1]) == 12)
    assert(colorpole([3, 1]) == 0)
    assert(colorpole([2, 2, 1, 1]) == 84)
    if len(sys.argv) >= 2:
        assert(colorpole([8, 3, 2]) == 0)

main()
