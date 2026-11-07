#!/usr/bin/env python3

"""

For those who are not familiarized with the Pea Pattern, it is a simple mathematical pattern.

There are multiple variations of this pattern, but we will focus in one:

Ascending Pea Pattern

It looks like this:

1
11
21
1112
3112
211213
...
It seems really hard to get the following line, but it is really easy. The way to get the next line is by counting the number of times a digit have repeated on the previous line (start counting with the lowest, to largest):

one
one one
two ones
one one, one two
three ones, one two
two ones, one two, one three
...
Requirements/Rules:

We will start at 1
It will be a snippet
There must be a way to specify the number of lines generates (e.g 5 will give the first 5 lines)
The code should be as short as possible
It must start counting from lowest to largest (the Ascending variation)

"""

# https://oeis.org/A005151
def peas(n):
    s = "1"
    for _ in range(n):
        t = ""
        for k in sorted(set(s)):
            t += str(s.count(k)) + k
        s = t
    return int(s)

def main():
    tab = [1, 11, 21, 1112, 3112, 211213, 312213, 212223, 114213, 31121314, 41122314, 31221324, 21322314, 21322314, 21322314, 21322314, 21322314, 21322314, 21322314, 21322314, 21322314, 21322314, 21322314, 21322314, 21322314, 21322314]

    for i in range(len(tab)):
        assert(peas(i) == tab[i])

main()
