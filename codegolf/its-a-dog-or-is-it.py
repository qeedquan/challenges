#!/usr/bin/env python3

r"""

The city defines a dog as any living entity with four legs and a tail. So raccoons, bears, mountain lions, mice, these are all just different sizes of dog.

Given an ASCII-art image of an animal, determine if that animal is a dog.

Rules
An animal is a dog if it has four legs and a tail.

The foot of a leg starts with one of \ (backslash), | (pipe), or / (slash), has one or more _ in between, and another \, |, or /. Each foot will hit the last line of the string. The feet may not share a common border.

\ \  |   /   /    |  |     /  |   |  / /     <-- These are all just
|_|  |___|  |_____|  |_____|  |___|  |_|         different sizes of leg.
A tail is a line coming out of the left side of the figure and touching the leftmost part of the multiline string. The tail is made up of either - or = characters. The tail must be at least one character long, and can optionally end with a o or *.

o---  *--  *==  --  ==  -  =  o===  *-      <-- These are all just
                                                different sizes of tail.
You can take input as a multiline string, or array of lines. Output a truthy or falsy value to determine if the figure is a dog, or any two distinct values.

Truthy test cases:

      ______/\__/\
    _/    (  U U  )
*--/____. ,\_ w _/
    \  /| |\ |\ \
    /_/ \_/|_| \_\
    _________/\
o==/         ''>
   |_||_||_||_|
        /\__/\
       (  o O)
       /   m/
      |    |      don't ask
o-----|    \__
      |   ___ \_______
      //\ \  \___ ___ \
     /_/ \_\    /_|  \_|
Falsy test cases:

        __________          _
 ______/ ________ \________/o)<
(_______/        \__________/
     ____/)(\
    /   \o >o
   (     \_./
o--\ \_.  /
    \____/
    ||  ||
    \/  \/
   /\/\/\/\/\
o-/       o.o
   /_/_/_/_/

"""

import re

ANIMAL_1 = r"""
      ______/\__/\
    _/    (  U U  )
*--/____. ,\_ w _/
    \  /| |\ |\ \
    /_/ \_/|_| \_\
"""

ANIMAL_2 = r"""
    _________/\
o==/         ''>
   |_||_||_||_|
"""

ANIMAL_3 = r"""
        /\__/\
       (  o O)
       /   m/ 
      |    |
o-----|    \__
      |   ___ \_______
      //\ \  \___ ___ \
     /_/ \_\    /_|  \_|
"""

ANIMAL_4 = r"""
        __________          _
 ______/ ________ \________/o)<
(_______/        \__________/
"""

ANIMAL_5 = r"""
     ____/)(\
    /   \o >o
   (     \_./
o--\ \_.  / 
    \____/
    ||  ||
    \/  \/
"""

ANIMAL_6 = r"""
   /\/\/\/\/\
o-/       o.o
   /_/_/_/_/
"""

# Ported from @97.100.97.109 solution
def isdog(lines):
    has_marker = any(
        re.match(r"[*o]?[-=]+", line)
        for line in lines
    )
    part_count = len(re.split(r"[\\/|]_+[\\/|]", lines[-1]))
    return has_marker and part_count == 5

def test(input, expected):
    lines = input.split("\n")
    lines = lines[1:len(lines) - 1]
    assert(isdog(lines) == expected)

def main():
    test(ANIMAL_1, True)
    test(ANIMAL_2, True)
    test(ANIMAL_3, True)

    test(ANIMAL_4, False)
    test(ANIMAL_5, False)
    test(ANIMAL_6, False)

main()
