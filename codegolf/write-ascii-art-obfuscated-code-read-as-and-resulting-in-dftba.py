#!/usr/bin/env python3

"""

The challenge is to write the most elaborate code, embedded in ASCII art that reads and prints "DFTBA". For example, the following reads DFTBA:

oooooooooo.   oooooooooooo ooooooooooooo oooooooooo.        .o.
`888'   `Y8b  `888'     `8 8'   888   `8 `888'   `Y8b      .888.
 888      888  888              888       888     888     .8"888.
 888      888  888oooo8         888       888oooo888'    .8' `888.
 888      888  888    "         888       888    `88b   .88ooo8888.
 888     d88'  888              888       888    .88P  .8'     `888.
o888bood8P'   o888o            o888o     o888bood8P'  o88o     o8888o
And the following, in bash prints DFTBA

echo "DFTBA"
The challenge is to write one that does both.

Winning conditions
Valid answers, (all conditions at my discretion)

Can be clearly read as DFTBA
Print DFTBA when executed
Must be functional with no Internet connection
have letters of equal height
must not have more than 80 columns
must not have more than 10 rows
Points (highest sum wins)

Rows * Columns / 32
Readability: 25 for legible, 50 for very clear
1 point for each different non-whitespace character used
Restrictions
These may be used for something, so all responses are assumed to be released into the public domain. If you can't, or choose not to release your answer into the public domain: post a comment/response to the original question saying "The answer authored and/or shared by me, may not be considered to be in the public domain".

Non-public domain answers are welcome too! Just make sure to specify :-)

What is DFTBA?
It sometimes stands for "Don't Forget To Be Awesome", but not always... Long story... This related song might help explain (or confuse).

"""

ART = """
oooooooooo.   oooooooooooo ooooooooooooo oooooooooo.        .o.
`888'   `Y8b  `888'     `8 8'   888   `8 `888'   `Y8b      .888.
 888      888  888              888       888     888     .8"888.
 888      888  888oooo8         888       888oooo888'    .8' `888.
 888      888  888    "         888       888    `88b   .88ooo8888.
 888     d88'  888              888       888    .88P  .8'     `888.
o888bood8P'   o888o            o888o     o888bood8P'  o88o     o8888o
"""

print(ART)
