#!/usr/bin/env python3

"""

My GPS describes lanes like this:

“Right lane”
“Second lane from the left”
“Middle lane”
“Third lane from the right”
Given a number of lanes and the index (from left) of a lane, compute the lane description. For our purposes a lane description is the nearest roadside (“L” for left, “R” for right) and the number of lanes from that side. The middle lane is just “M”.

Examples
Lane	Description
Leftmost	L0
Second from left	L1
Rightmost	R0
Third from right	R2
Middle	M
Input
The input will be a positive number of lanes and a non-negative lane index. You may use 0- or 1-indexed lanes, just specify in your answer. The input will always be valid, i.e. you won’t be asked to compute the description of the 5th lane when there are only 4 lanes. There may be an odd or even number of lanes.

Output
For lanes nearest the left or right side (i.e. not the middle lane) the output must be a symbol indicating the nearest side (e.g. “L” or “R”) and the number of lanes from that side, counting from either 0 or 1. For the middle lane the output must be a third symbol (e.g. “M”) and, optionally, 0, 1, or your language’s “null” value.

The symbols you choose for side or middle may be anything as long as they’re consistent. Just specify in your answer. An error is not valid output.

Rules
This is code-golf. Shortest answer in bytes wins.

Default I/O rules and standard rules apply. Standard loopholes are forbidden.

Test cases
Using 0-indexed input and output:

Input (# of lanes, lane index)	Output (side, lanes from side)
4, 2	“R”, 1
3, 0	“L”, 0
5, 2	“M”, 0
6, 5	“R”, 0
9, 4	“M”, 0
16, 6	“L”, 6

"""

# Ported from @spears0fgungnir solution
def lane(n, k):
    j = n // 2
    s = "L"*j + "M"*(n % 2) + "R"*j
    t = str(min(k, n - k - 1) % (j + -(n+1)%2))
    return s[k] + t

def main():
    assert(lane(4, 2) == "R1")
    assert(lane(3, 0) == "L0")
    assert(lane(5, 2) == "M0")
    assert(lane(6, 5) == "R0")
    assert(lane(9, 4) == "M0")
    assert(lane(16, 6) == "L6")

main()
