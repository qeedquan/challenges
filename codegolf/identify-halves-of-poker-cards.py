#!/usr/bin/env python3

"""

A casino uses the following deck of cards. (* is one of the card suits D, S, C or H.)

 _________    _________    _________    _________    _________
|         |  |         |  |         |  |         |  |         |
|         |  |         |  |    *    |  |  *   *  |  |  *   *  |
|         |  |    *    |  |         |  |         |  |         |
|    *    |  |         |  |    *    |  |         |  |    *    |
|         |  |    *    |  |         |  |         |  |         |
|         |  |         |  |    *    |  |  *   *  |  |  *   *  |
|_________|  |_________|  |_________|  |_________|  |_________|

 _________    _________    _________    _________    _________
|         |  |         |  |         |  |         |  |         |
|  *   *  |  |  *   *  |  |  *   *  |  |  *   *  |  |  *   *  |
|         |  |         |  |  *   *  |  |  *   *  |  |  *   *  |
|  *   *  |  |  * * *  |  |         |  |    *    |  |  *   *  |
|         |  |         |  |  *   *  |  |  *   *  |  |  *   *  |
|  *   *  |  |  *   *  |  |  *   *  |  |  *   *  |  |  *   *  |
|_________|  |_________|  |_________|  |_________|  |_________|

 _________    _________    _________
|         |  |         |  |         |
|  *   *  |  |  *   *  |  |  * * *  |
|  *   *  |  |  * * *  |  |  *   *  |
|  * * *  |  |  *   *  |  |  * * *  |
|  *   *  |  |  * * *  |  |  *   *  |
|  *   *  |  |  *   *  |  |  * * *  |
|_________|  |_________|  |_________|
After each night, old decks are discarded, and cut in half to avoid reuse. As a result, the casino has a big room full of cut card halves.

Unfortunately the economy is bad, and the casino is in financial trouble. The most reasonable thing to save money seems to be recycling, so the casino owners decide to tape old cards back together. So they hire a team to build a machine which will do this.

You are part of the team, and your job is to help identifying the card.

Write a program or function which will take an ASCII art image of a card half in the form of a string, and will return a string of what card it is.

Input is an 11x5 string, plus line break characters (CR, LF or CRLF, you only need to support one). You may assume trailing whitespace at the end of each input line, if necessary. The input won't contain any invalid characters (any other than _|-HSCD and space and line break).

A card half will look like this:

 _________
|         |
|  H   H  |
|  H H H  |
---H---H---
which should be identified as the Queen of Hearts:

H12
The casino is on a limited budget, so this is code golf: the shortest program wins.

"""

def identify(s):
    r = ""
    s = (s*2)[:-9]
    for c in "CDHS":
        if c in s:
            r += c + str(s.count(c))
    return r

def main():
    assert(identify("_________\n|         |\n|  H   H  |\n|  H H H  |\n---H---H---") == "H12")

main()

