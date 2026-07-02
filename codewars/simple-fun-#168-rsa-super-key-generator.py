#!/usr/bin/env python3

"""

Task
We need to create a RSA Super Key Generator(SKG).

For simplicity, SKG(x) = true means that x is an RSA-SKG; otherwise, SKG(x) = false.

SKG(x) = true if and only if:

It's composed of exactly n digits;
There are numbers t and f, such as:
three is the number of 3s;
five is the number of 5s;
three is a multiple of 5;
five is a multiple of 3;
n = three + five.
Given number n, your task is to find the largest x, such as SKG(x) = true. If there is no such number, return "-1".

Example
For n = 3, the result should be "555". Because:

five = 3  --- number of fives is 3, which is a multiple of 3;
three = 0 --- number of threes is 0, which is a multiple of 5;
"555" is the largest number that meets these conditions.
Input/Output
[input] integer n
A positive integer.

[output] a string
The largest RSA-SKG number with n digits if it exists, "-1"otherwise.

"""

def superkey(n):
    r = -1
    for i in range(0, n + 1, 5):
        j = n - i
        if j%3 == 0:
            r = max(r, int('5'*j + '3'*i))
    return str(r)

def main():
    assert(superkey(1) == "-1");
    assert(superkey(2) == "-1");
    assert(superkey(3) == "555");
    assert(superkey(4) == "-1");
    assert(superkey(5) == "33333");
    assert(superkey(6) == "555555");
    assert(superkey(7) == "-1");
    assert(superkey(8) == "55533333");
    assert(superkey(15) == "555555555555555");

main()
