#!/usr/bin/env python3

"""

In one of our projects at work, we recently discovered a particularly large method for generating a 6 character string from a 15 character alphabet. A few of us claimed "I bet we can get that in one line" which started a little internal game of code golf.

Your task is to beat us, which I have no doubt won't take long!

The original algorithm used the alphabet 0-9A-E, but we've experimented with other alphabets. There are therefore three subtasks.

Generate a 6 character string randomly selecting from an arbitrary hardcoded 15 character alphabet like ABC123!@TPOI098. (This is just an example, and should be customizable without affecting the byte count.)
Generate a 6 character string randomly selecting from a 15 character alphabet 0123456789ABCDE.
Generate a 6 character string randomly selecting from a 15 character alphabet of your choice (printable characters only please).
Each character should have equal chance of selection and repetition should be possible.

The best we have been able to manage for each of the subtasks is:

"ABC123!@TPOI098" - 24 bytes
"0123456789ABCDE" - 21 bytes
Custom alphabet - 13 bytes
Your score is the sum of the bytes in each subtask's solution. i.e. our score is currently 58.

We've attempted using among others, CJam and Ruby. The original was in C#. Use any language you like, but we'll be interested to see solutions in these languages particularly

"""

from random import *

def generate(table, length):
    result = ""
    for _ in range(length):
        result += choice(table)
    return result

def main():
    print(generate("ABC123!@TPOI098", 6))
    print(generate("0123456789ABCDE", 6))
    print(generate("!@#$%^&*()_+,", 6))

main()
