#!/usr/bin/env python3

r"""

Keeping with a festive theme, print a carol singing angel with the shortest possible code. The angel is raising money for the homeless, so must be able to sing all three of the below songs available at request. To illustrate she can sing them, the title of the song must be placed within the speech bubble. This song title will be input by the user. Examples include:

Mother Mary
Jingle Bells
Silent Night
Input:

Title: 1 of the 3 songs.

Output:

                  ____________
(\   ___   /)    /            \
( \ (‘o‘) / )   /              \
(           )  <
 (  ‘> <’  )    \              /
    /    \       \____________/
   /      \
  ‘ – “ - ‘
Please paste the result of your singing angel along with the song: "Silent Night".

Speech Bubble Rules:

The speech bubble must always have a frame of 12 underscore lines long.

The title of the song must always start on the second line.

The title of the song must always start 3 underscore spaces inside the bubble.

                  123456789...
(\   ___   /)    /            \
( \ (‘o‘) / )   /    Song      \
(           )  <     Title
 (  ‘> <’  )    \              /
    /    \       \____________/
   /      \
  ‘ – “ - ‘
Examples below:

                  ____________
(\   ___   /)    /            \
( \ (‘o‘) / )   /    Mother    \
(           )  <     Mary
 (  ‘> <’  )    \              /
    /    \       \____________/
   /      \
  ‘ – “ - ‘

                  ____________
(\   ___   /)    /            \
( \ (‘o‘) / )   /    Jingle    \
(           )  <     Bells
 (  ‘> <’  )    \              /
    /    \       \____________/
   /      \
  ‘ – “ - ‘

                  ____________
(\   ___   /)    /            \
( \ (‘o‘) / )   /    Silent    \
(           )  <     Night
 (  ‘> <’  )    \              /
    /    \       \____________/
   /      \
  ‘ – “ - ‘

"""

# ported from @James Hollis solution
def angel(s):
    a, b = s.split()
    u = '_' * 12
    out = "99" + u + "\n"
    out += "(\\3___3/)4/66\\\n"
    out += "( \\ (‘o‘) / )3/4" + a + "4\\\n"
    out += "(92)2<5" + b + "\n"
    out += " (2‘> <’2)4\\95/\n"
    out += "4/4\\7\\" + u + "/\n"
    out += "3/6\\\n"
    out += "2‘ – “ - ‘"
    [print(' '*int(x) if x.isdigit() else x, end='') for x in out]
    print()

def main():
    angel("Mother Mary")
    angel("Jingle Bells")
    angel("Silent Night")

main()
