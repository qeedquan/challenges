#!/usr/bin/env python3

"""

Write a function (or a whole program) that outputs (or prints) an ASCII art of the initial position of Mölkky pins.

Output :
    __    __    __
 __(07)__(09)__(08)__
(05)__(11)__(12)__(06)
|  (03)__(10)__(04)  |
|  |  (01)  (02)  |  |
|__|  |  |  |  |  |__|
   |__|  |__|  |__|
      |__|  |__|
Rules :
This is code-golf, so the shortest solution in bytes wins!
Trailing spaces are allowed on each line
Additional leading spaces (meaning, without counting the already mandatory leading spaces) are allowed only if there are the same number of additional leading spaces in each of the 8 mandatory lines
Additional newlines are allowed at the beginning and at the end. These additional lines can contain any number of spaces
Thanks to Arnauld for the ASCII art and his advices concerning the challenge!

Despite the risk of just having to hardcode and/or compress the output, i hope the challenge will be interesting enough!

I intend to post my own answer in Javascript, but since i forced myself to do it without hardcoding, it has become quite long :')

"""

ART = """
    __    __    __
 __(07)__(09)__(08)__
(05)__(11)__(12)__(06)
|  (03)__(10)__(04)  |
|  |  (01)  (02)  |  |
|__|  |  |  |  |  |__|
   |__|  |__|  |__|
      |__|  |__|

"""

print(ART)

