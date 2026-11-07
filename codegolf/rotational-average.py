#!/usr/bin/env python3

"""

Given an input integer n >= 10, output the average of all deduplicated rotations of the integer.

For example, for input 123, the rotations are 123 (no rotation), 231 (one rotation) and 312 (two rotations). The average of those is (123 + 231 + 312) / 3 or 222.

As another example, take 4928. The rotations are 4928, 9284, 2849, and 8492. Taking the average of those four numbers equals 6388.25.

For another example, for input 445445, the deduplicated rotations are 445445, 454454, and 544544, so the output is 481481.

For input 777, there is only one deduplicated rotation, so the output is 777.

Rules
If applicable, you can assume that the input/output will fit in your language's native Integer type.
The input and output can be given by any convenient method.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

"""

# ported from @Dennis solution
def rotational_average(n):
    x = list(map(int, str(n)))
    return (10**len(x)//9 * sum(x)) / len(x)

def main():
    print(rotational_average(123))
    print(rotational_average(4928))
    print(rotational_average(445445))
    print(rotational_average(777))

main()

