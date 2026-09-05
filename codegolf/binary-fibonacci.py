#!/usr/bin/env python3

"""

Challenge
You need to generate a program or function that takes in a positive integer N, calculates the first N terms of the Fibonacci sequence in binary, concatenates it into a single binary number, converts that number back to decimal, and then outputs the decimal as an integer.

For example

1 -> [0] -> 0 to decimal outputs 0
3 -> [0, 1, 1] -> 011 to decimal outputs 3
4 -> [0, 1, 1, 10] -> 01110 to decimal outputs 14
You do not need to output the ->, just the number (e.g. if the user types 4, just output 14). The arrows are just to help explain what the program must do.

Test cases
1 -> 0
2 -> 1
3 -> 3
4 -> 14
5 -> 59
6 -> 477
7 -> 7640
8 -> 122253
9 -> 3912117
10 -> 250375522
11 -> 16024033463
12 -> 2051076283353
13 -> 525075528538512
14 -> 134419335305859305
15 -> 68822699676599964537
16 -> 70474444468838363686498
17 -> 72165831136090484414974939
18 -> 147795622166713312081868676669
19 -> 605370868394857726287334099638808
20 -> 4959198153890674493745840944241119317
The program must be able to output up to the limit of the language in use. No lookup tables or common workarounds allowed.

This is code-golf, so the answer with the shortest number of bytes wins!

"""

def binfib(n):
    s, a, b = "", 0, 1
    for i in range(n):
        s, a, b = s + bin(a)[2:], b, a + b
    
    if s == "":
        s = "0"

    return int(s, base=2)

def main():
    tab = [0, 1, 3, 14, 59, 477, 7640, 122253, 3912117, 250375522, 16024033463, 2051076283353, 525075528538512, 134419335305859305, 68822699676599964537, 70474444468838363686498, 72165831136090484414974939, 147795622166713312081868676669, 605370868394857726287334099638808, 4959198153890674493745840944241119317]

    for i in range(len(tab)):
        assert(binfib(i + 1) == tab[i])

main()
