#!/usr/bin/env python3

"""

Introduction
Note that I learned it from a Numberphile Video, where Neil Sloane explains it better. I recommend you to watch his Video. But for a quick Introduction:
The Levine Sequence is made from the Levine's Triangle, which is made as follows:
First you have 0 ones, and 1 twos.
Then you read the list backwards (right to left) and you have the same number of ones, as the 0
th element of the list.
Then you have the same number of twos, as the 1th element of the list. That goes on and on, till the list ends. These are the first few rows:

ln[0]: 2
ln[1]: 11
ln[2]: 12
ln[3]: 112
ln[4]: 1123
ln[5]: 1112234
ln[6]: 11112223344567
Really, I don't think I've explained it good, so check out Neil's Video to learn more about it.

So, now, the Levine's Sequence. The nth Term of the sequence (starting at 0), is just the sum of the nth row of the Levine's Triangle. These are the first few terms: 2, 2, 3, 4, 7, 14.
Then it just blows up.

Disclaimer: In the Numberphile video, also when you follow the steps I told, the 0th term is 2. But in OEIS the first term is 1. So I will accept both sequences.

Rules
The output must be printed to the program's output.
The output must be in base 10 (outputting them in any other base is not allowed).
Your program must can take input, the nth term.
Outputting the integers with trailing / leading spaces is allowed.
This is code-golf, so the shortest (original) code in each language wins!
I'm a bit free about this, so you can output just the nth term, up to the nth term, or even the whole sequence!

"""

# https://oeis.org/A011784
def gen(n):
    r = []
    x = [2]
    while len(r) < n:
        i = len(x)
        r.append(i)
        for j in range(i):
            x += x.pop(i - 1) * [i]
            i -= 1
    return r

def main():
    tab = [1, 2, 2, 3, 4, 7, 14, 42, 213, 2837]

    assert(gen(len(tab)) == tab)

main()
