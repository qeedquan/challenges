#!/usr/bin/env python3

"""

Introduction
In a private chat, a friend of mine apparently recently stumbled across a security system which has the following two restrictions on its valid pins:

Each digit must be unique (that is "1" may only appear once)
The order of the digits doesn't matter ("1234"="4321")
So to illustrate how bad this padlock system is, let's actually enumerate all valid PINs!

Input
Your input will consist of a single, positive integer, which denotes the length of the PIN.

Output
Your output consists of a list of non-negative integers or strings*, which enumerate all valid PINs of the given length.

*More precisely something that a human can use to try all combinations if you would print it for them. This means set of sets of digits and arrays of arrays of digits are fine.

Who wins?
This is code-golf so the shortest answer in bytes wins! Standard rules and loopholes apply.

Corner Cases
The output behaviour is undefined if an integer greater than 10 is input.
The ordering of the digits within each output entry is undefined, as entries with a zero actually contain said zero, that is you may not strip "0123" to "123" but "1230", "1203" and "1023" are all valid as is "0123".
Test Cases
1
[0,1,2,3,4,5,6,7,8,9]

2
[10,20,30,40,50,60,70,80,90,21,31,41,51,61,71,81,91,32,42,52,62,72,82,92,43,53,63,73,83,93,54,64,74,84,94,65,75,85,95,76,86,96,87,97,98]

3
[210,310,410,510,610,710,810,910,320,420,520,620,720,820,920,430,530,630,730,830,930,540,640,740,840,940,650,750,850,950,760,860,960,870,970,980,321,421,521,621,721,821,921,431,531,631,731,831,931,541,641,741,841,941,651,751,851,951,761,861,961,871,971,981,432,532,632,732,832,932,542,642,742,842,942,652,752,852,952,762,862,962,872,972,982,543,643,743,843,943,653,753,853,953,763,863,963,873,973,983,654,754,854,954,764,864,964,874,974,984,765,865,965,875,975,985,876,976,986,987]

4
[3210,4210,5210,6210,7210,8210,9210,4310,5310,6310,7310,8310,9310,5410,6410,7410,8410,9410,6510,7510,8510,9510,7610,8610,9610,8710,9710,9810,4320,5320,6320,7320,8320,9320,5420,6420,7420,8420,9420,6520,7520,8520,9520,7620,8620,9620,8720,9720,9820,5430,6430,7430,8430,9430,6530,7530,8530,9530,7630,8630,9630,8730,9730,9830,6540,7540,8540,9540,7640,8640,9640,8740,9740,9840,7650,8650,9650,8750,9750,9850,8760,9760,9860,9870,4321,5321,6321,7321,8321,9321,5421,6421,7421,8421,9421,6521,7521,8521,9521,7621,8621,9621,8721,9721,9821,5431,6431,7431,8431,9431,6531,7531,8531,9531,7631,8631,9631,8731,9731,9831,6541,7541,8541,9541,7641,8641,9641,8741,9741,9841,7651,8651,9651,8751,9751,9851,8761,9761,9861,9871,5432,6432,7432,8432,9432,6532,7532,8532,9532,7632,8632,9632,8732,9732,9832,6542,7542,8542,9542,7642,8642,9642,8742,9742,9842,7652,8652,9652,8752,9752,9852,8762,9762,9862,9872,6543,7543,8543,9543,7643,8643,9643,8743,9743,9843,7653,8653,9653,8753,9753,9853,8763,9763,9863,9873,7654,8654,9654,8754,9754,9854,8764,9764,9864,9874,8765,9765,9865,9875,9876]

"""

from itertools import *

def pins(n):
    r = []
    for c in combinations(range(10), n):
        s = ""
        for p in c:
            s += str(p)
        r.append(s)
    return r

def main():
    print(pins(1))
    print(pins(2))
    print(pins(3))
    print(pins(4))

main()
