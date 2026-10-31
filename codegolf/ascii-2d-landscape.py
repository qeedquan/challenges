#!/usr/bin/env python3

r"""

You are given an input string, called path, consisting of u, d and s characters (i.e. uusduudsdduu):

u go up
d go down
s stay
All paths start with an upward movement u.

Your task is to generate the 2D landscape resulting from the given path and print it.

Example:

uusduudsdduu
     /\_
 /‾\/   \  /
/        \/
The input character s should never trigger a vertical movement:

STAY after UP
 "...us..." -> .../‾...
STAY after DOWN
 "...ds..." -> ...\_...
STAY after STAY
 "...uss..." -> .../‾‾...
 "...dss..." -> ...\__...
This is a code-golf challenge, the shortest implementation in bytes wins.

"""

def landscape(s):
    x1 = y1 = 0
    x2 = y2 = 0
    x = y = 0
    m = {}
    for i in range(len(s)):
        p = (x, y)
        if s[i] == 'u':
            m[p] = '/'
        elif s[i] == 'd':
            m[p] = '\\'
        elif s[i] == 's':
            m[p] = '‾'
        else:
            continue

        t = s[i:i+2]
        if t in ("uu", "su"):
            y += 1
        elif t in ("dd", "ds"):
            y -= 1

        x1 = min(x1, x)
        y1 = min(y1, y)
        x2 = max(x2, x)
        y2 = max(y2, y)
        x += 1

    print(s)
    for y in range(y2, y1-1, -1):
        for x in range(x1, x2+1):
            p = (x, y)
            if p in m:
                print(m[p], end='')
            else:
                print(' ', end='')
        print()
    print()

def main():
    landscape("uusduudsdduu")
    landscape("sudsssdu")

main()
