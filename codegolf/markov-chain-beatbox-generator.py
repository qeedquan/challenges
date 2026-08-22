#!/usr/bin/env python3

"""

Just an idea I had the other day: Making beats following a Markov Chain of predefined sounds.

I remember someone did a beatbox with Google Translate and the German language (follow the link and press listen).

So, the challenge is to build a text input to Google Translate from a given chain. Or you can use musical notes and play it yourself :).

https://i.sstatic.net/gZM9P.png

You can make a program reading a line with the number of beats, another with their names and a matrix representation of the probabilities (you can choose the representation).

You may also make a function with those three arguments.

E.g.

[input]

20
pv zk bschk kkkk
[[.1, .4, .5, 0.],
 [.3, .2, .3, .2],
 [0., .3, .2, .5],
 [.1, .8, .1, 0.]]
[output] something like:

pv zk bschk zk pv bschk zk pv zk bschk kkkk pv bschk zk bschk bschk bschk zk kkkk bschk
The starting probability is the same for each beat.

That's not a code-golf challenge because I would like to see some nice solutions (be creative).

Extra points if you invent new beats and/or choose a table of probabilities that gives nice beats most of the time.

If you want, you can use real beats (In many languages it's easy to open .wav files, like the wave module in Python) and generate music! Here are some free sample beats.
https://samples.kb6.de/downloads.php

I may post a reference implementation if needed.

"""

from random import random

# ported from @JBernardo solution
def find(num, pdf):
    cdf = (sum(pdf[:i+1]) for i in range(len(pdf)))
    for i, j in enumerate(cdf):
        if num < j:
            return i

def build(t, beats, table):
    node = int(random()*len(table))
    nodes = [node]
    for i in range(t-1):
        node = find(random(), table[node])
        nodes.append(node)
    return ' '.join(beats[i] for i in nodes)

table = [[.1, .4, .5, 0.],
         [.3, .2, .3, .2],
         [0., .3, .2, .5],
         [.1, .8, .1, 0.]]

print(build(20, 'pv zk bschk kkkk'.split(), table))
