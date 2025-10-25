#!/usr/bin/env python3

"""

Input
Your input is a list of single-digit numbers in any reasonable format, including a string of digits. The input will not be empty.

Output
Your output shall be the input list, but with each maximal run of nonzero digits being reversed.

Example
Consider the input

95883007414830
<--->  <---->
where the nonzero runs have been marked with arrows. Reversing each of these runs, we obtain the output

38859003841470
Rules and scoring
You can write a full program or a function. The lowest byte count wins, and standard loopholes are disallowed.

This challenge is related, but much more complex, since it includes additional string processing.

Test cases
4 -> 4
00 -> 00
123 -> 321
0010 -> 0010
12000345 -> 21000543
18161604 -> 61618104
95883007414830 -> 38859003841470
010230456078912 -> 010320654021987
357509902003550 -> 575309902005530
2492882377675046 -> 5767732882942064
03026302053000357099 -> 03036202035000753099

"""

def rps(s):
    r = ""
    for t in s.split('0'):
        r += t[::-1] + "0"
    if len(r) > 0:
        r = r[:-1]
    return r

def main():
    assert(rps("4") == "4")
    assert(rps("00") == "00")
    assert(rps("123") == "321")
    assert(rps("0010") == "0010")
    assert(rps("12000345") == "21000543")
    assert(rps("18161604") == "61618104")
    assert(rps("95883007414830") == "38859003841470")
    assert(rps("010230456078912") == "010320654021987")
    assert(rps("357509902003550") == "575309902005530")
    assert(rps("2492882377675046") == "5767732882942064")
    assert(rps("03026302053000357099") == "03036202035000753099")

main()
