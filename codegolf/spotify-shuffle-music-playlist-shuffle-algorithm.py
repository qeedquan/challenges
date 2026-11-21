#!/usr/bin/env python3

"""

Background
Perfect shuffle algorithms like Fisher-Yates shuffle don't produce great results when it comes to music playlist shuffling, because it often produces clusters of songs from the same album. In an attempt to solve this problem, Spotify introduced an interesting shuffle algorithm in 2014. At the end of the article, they claimed (emphasis mine):

All in all the algorithm is very simple and it can be implemented in just a couple of lines. It’s also very fast and produces decent results.

Let's see if this is indeed the case.

Task
Implement the modified Spotify shuffle. The algorithm described in the article has some gaps in its specification, so I present a refined one here.

The algorithm
Let's assume we have a list of items grouped into categories, e.g.:

[['A', 'AA', 'AAA'], ['B'], ['C', 'CC'], ['D'], ['E', 'EE', 'EEE', 'EEEE']]
Shuffle items within each category.
You may use any shuffle algorithm that can produce every possible permutation with nonzero probability.
[['AAA', 'A', 'AA'], ['B'], ['C', 'CC'], ['D'], ['EEE', 'EEEE', 'EE', 'E']]
Assign each item a "positional value". Items in one category should be uniformly spaced, but with some randomness. To achieve this, do the following operations on each category having n items:
Initialize the positional value vector v of length n with the values v[k] = k/n for 0 <= k < n (i.e. 0-indexed), so that the items have default spacing of 1/n.
Generate an initial random offset io within the range of 0 <= io <= 1/n, and add it to every v[k].
Generate n individual random offsets o[k] within the range of -1/10n <= o[k] <= 1/10n, and apply v[k] += o[k] for each k. So the positional value of k-th item (0-indexed) within an n-item category will be v[k] = k/n + io + o[k].
The random offsets io and o[k] should ideally be picked from a uniform random variable, but can be approximated by picking from a discrete distribution with at least 5 distinct equally-spaced outcomes, including both lower and upper bounds. (e.g. you can choose to randomly pick io from [0, 1/4n, 2/4n, 3/4n, 1/n].)
Don't do extra processing even if v[k] < 0 or v[k] > 1.
[['AAA' -> 0.1, 'A' -> 0.41, 'AA' -> 0.79],
 ['B' -> 0.2],
 ['C' -> 0.49, 'CC' -> 1.01],
 ['D' -> 0.03],
 ['EEE' -> 0.12, 'EEEE' -> 0.37, 'EE' -> 0.6, 'E' -> 0.88]]
Sort all items by the positional values.
['D', 'AAA', 'EEE', 'B', 'EEEE', 'A', 'C', 'EE', 'AA', 'E', 'CC']
The shuffled result roughly looks like this (from the article):

    https://spotifylabscom.files.wordpress.com/2014/02/algorithm.png?w=533&h=458
(source: wordpress.com)

Here is Python-like pseudocode of the above algorithm:

x = nested array of items
uniform(a,b) = uniformly generate a random value between a and b
items = []
v = []
for i in range(len(x)):  # for each category
    shuffle(x[i])  # shuffle items within category in place
    items += x[i]
    n = len(x[i])  # size of the current category
    io = uniform(0, 1/n)  # initial offset
    o = [uniform(-0.1/n, 0.1/n) for k in range(n)]  # individual offsets
    v += [k/n + io + o[k] for k in range(n)]  # resulting positional values
sort items by v
print items

Input and output
The input is a list of groups of items (i.e. a nested list) as shown in the example above. An item is a string made of only uppercase letters (or only lowercase if you want). You can assume that all items are distinct, within and across categories.

The output is a shuffled list including all items in the input, which is produced by the algorithm described above.

The randomness requirements are covered in the algorithm description.

Scoring and winning criterion
Standard code-golf rules apply. Shortest code in bytes wins.

"""

from random import *

# ported from @lyxal solution
def spotify(x):
    I, v = [], []
    for i in range(len(x)):
        shuffle(x[i])
        I += x[i]
        n = len(x[i])
        t = 0.1 / n
        v += [k/n + uniform(0, 1 / n) + uniform(-t, t) for k in range(n)]
    return [s[1] for s in sorted(zip(v, I))]

print(spotify([['A', 'AA', 'AAA'], ['B'], ['C', 'CC'], ['D'], ['E', 'EE', 'EEE', 'EEEE']]))
