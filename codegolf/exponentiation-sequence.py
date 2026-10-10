#!/usr/bin/env python3

"""

The oldest Polish salt mine, located in Bochnia*, was started in year 1248, which we can consider a magical number.
We can see that it's equal to 4 digits from the sequence of exponentiations: 2^0, 2^1, 2^2, 2^3.

As the date is actually 4 digits from the sequence, we could make it longer.
We could repeat the process until we reach infinity.
The sequence would look like this, if we limit it to number 2048

124816326412825651210242048
To make it look a bit better, we can separate the numbers:

1|2|4|8|16|32|64|128|256|512|1024|2048
Let's try a custom, longer sequence than the date. Let's say, we want it to have 5 digits - there are more than one possibility:

24816
81632
64128
Or 3 digit ones:

124
248
816
We could also add the 3 digit numbers to this, but let's say, that a sequence must have at least two numbers.

* There is no information about this on the English Wikipedia. If you enter the Polish version - then there is. If you visit the mine, the workers will also tell you, that it started in 1248.

The challenge
Create a exponentiation sequence like in examples above with 2 as the base.

Given a number from range 2-27, output all possible parts of the sequence (The 2048 one or larger if you want) with amount of digits equal to the input. You cannot cut a number, so output like 481 is invalid, because 16 is cut in half.

Rules:

Standard loopholes are forbidden.
You can assume the input is a number inside the range.
Your program can accept inputs larger than the range (28+), but that won't increase/decrease score.
Spaces in output are ignored. You can output like 124 or like 4 8 16.
Different possibilities should be separated by any character from the list: ,./| or a line feed.
You can output as an array.
Every possibility should include at least 2 different numbers.
You must output a part of the sequence, you cannot mix numbers that aren't next to each other, like: 14.
Hardcoded output isn't allowed, however, you can hardcode a string/number/array containing the full sequence.
Input 27 should return the full 2048 sequence.
As already mentioned before, do not cut numbers. Ex. 16 must stay 16 - you can't use 481 - you must use 4816.
EDIT: I might have said something wrong there; 2048 is the last number which your program should support, you can add support for larger int's.

Test cases

Input: 2
12, 24, 48

Input: 3
124, 248, 816

Input: 4
1248, 4816, 1632, 3264

Input: 5
24816, 81632, 64128

Input: 27
124816326412825651210242048

And later numbers...

If I made a mistake in any of the test cases, tell me or edit the question.

This is code-golf, so the shortest code in bytes wins!

"""

def f(n):
    p = []
    for i in range(13):
        for j in range(i, 11):
            s = ""
            for k in range(i, j + 2):
                s += str(2**k)
            p.append(s)

    r = []
    for x in p:
        if len(x) == n:
            r.append(int(x))

    return r

def main():
    assert(f(2) == [12, 24, 48])
    assert(f(3) == [124, 248, 816])
    assert(f(4) == [1248, 4816, 1632, 3264])
    assert(f(5) == [24816, 81632, 64128])
    assert(f(27) == [124816326412825651210242048])

main()
