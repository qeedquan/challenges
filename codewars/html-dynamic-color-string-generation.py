#!/usr/bin/env python3

"""

Generate a valid randomly generated hexadecimal color string. Assume all of them always have 6 digits.

Valid Output
#ffffff
#FfFfFf
#25a403
#000001

Non-Valid Output
#fff
#aaa
#zzzzz
cafebabe
#a567567676576756A7

"""

from random import randint

def random_color():
    return "#%06x" % randint(0, 0xffffff)

def main():
    for i in range(20):
        print(random_color())

main()
