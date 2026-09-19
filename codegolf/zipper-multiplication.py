#!/usr/bin/env python3

"""

Introduction
Let's define a new arithmetical operation, which I call zipper multiplication. To zipper multiply two nonnegative integers, you add leading zeros to make the lengths match, multiply the corresponding base-10 digits of the numbers, add leading zeros to the results to get 2-digit numbers, concatenate them, and finally drop leading zeros.

Here's an example with A = 1276 and B = 933024:

1. Add leading zeros
 A = 001276
 B = 933024

2. Multiply digit-wise
 A = 0  0  1  2  7  6
 B = 9  9  3  0  2  4
 ->  0  0  3  0 14 24

3. Pad to 2 digits
 -> 00 00 03 00 14 24

4. Concatenate
 -> 000003001424

5. Drop leading zeros
 -> 3001424
The operation is extended to all integers with the usual sign rules: positive times negative is negative, negative times negative is positive and so on.

The task
Your inputs are two integers, and your output is their zipper multiplication. You should be able to handle arbitrarily large inputs. Input and/or output can be in string format (and indeed must be, if your language doesn't support arbitrarily large integers). Note that -0 is not a valid input or output.

Rules and scoring
You can write a full program or a function, and the lowest byte count wins.

Test cases
0 0 -> 0
302 40 -> 0
302 -40 -> 0
-4352 448 -> -122016
0 6623 -> 0
0 -6623 -> 0
20643 -56721 -> -1000420803
63196 21220 -> 1203021800
1276 933024 -> 3001424
-1276 933024 -> -3001424
-1276 -933024 -> 3001424
5007204555 350073039 -> 12001545
-612137119 -8088606033 -> 816060042000327
3389903661 -6619166963 -> -18180881090018543603
-23082746128560880381 1116941217 -> -8050600723200060807
-668336881543038127783364011867 896431401738330915057436190556 -> -485448120906320001351224000900090235004021121824000900403042
402878826066336701417493206805490000415 312487283677673237790517973105761463808 -> 120004325656161618004242182118140007280900200921180018080025285400000000320040

"""

def sign(x):
    if x < 0:
        return -1
    return 1

def intjoin(a):
    if len(a) == 0:
        return 0

    s = ""
    for v in a:
        t = str(v)
        if len(t) == 1:
            t = '0' + t
        s += t
    return int(s)

def zipmul(x, y):
    s0 = sign(x)
    s1 = sign(y)
    n0 = abs(x)
    n1 = abs(y)

    v = []
    while n0 > 0 and n1 > 0:
        v.append((n0 % 10) * (n1 % 10))
        n0 //= 10
        n1 //= 10

    return intjoin(v[::-1]) * s0 * s1

def main():
    assert(zipmul(0, 0) == 0)
    assert(zipmul(302, 40) == 0)
    assert(zipmul(302, -40) == 0)
    assert(zipmul(-4352, 448) == -122016)
    assert(zipmul(0, 6623) == 0)
    assert(zipmul(0, -6623) == 0)
    assert(zipmul(20643, -56721) == -1000420803)
    assert(zipmul(63196, 21220) == 1203021800)
    assert(zipmul(1276, 933024) == 3001424)
    assert(zipmul(-1276, 933024) == -3001424)
    assert(zipmul(-1276, -933024) == 3001424)
    assert(zipmul(5007204555, 350073039) == 12001545)
    assert(zipmul(-612137119, -8088606033) == 816060042000327)
    assert(zipmul(3389903661, -6619166963) == -18180881090018543603)
    assert(zipmul(-23082746128560880381, 1116941217) == -8050600723200060807)
    assert(zipmul(-668336881543038127783364011867, 896431401738330915057436190556) == -485448120906320001351224000900090235004021121824000900403042)
    assert(zipmul(402878826066336701417493206805490000415, 312487283677673237790517973105761463808) == 120004325656161618004242182118140007280900200921180018080025285400000000320040)

main()
