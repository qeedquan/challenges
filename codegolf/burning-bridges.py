#!/usr/bin/env python3

"""

Note: When I refer to a bridge, I mean it in the non-mathematical sense

Introduction
You are on a network of islands which are connected by wooden bridges and you want to see if you can burn every bridge in the island network. However, you can only burn a bridge once you've walked over it.

Once a bridge has been burned, it has gone and you cannot go back over it. None of the islands are connected.

Since you are going on a stroll, you cannot swim.

Challenge
Given a list of the bridges and which islands they connect, output a truthy value if you can burn every bridge and falsey value if you cannot.

Input
The input will be a list of numbers. A bridge is defined as:

X,Y
Where are X and Y are integers. Each bridge has an integer number which X and Y refer to.

For example,

2,6
Means that there is a bridge between the islands 2 and 6.

The input will be a list of these bridges:

2,6 8,1 8,2 6,1
You may take this a flat array, if you wish.

Rules
The numbers for the islands will always be positive integers, n, where 0 < n < 10. The island numbers will not always be contiguous.

When you walk over a bridge, you must burn it.

You will be given a maximum of eight islands. There is no limit on the number of bridges.

Island networks will always connect together. There will always be exactly one connected component.

This is an undirected network. For example, you can go either way across the bridge 1,2.

Examples
Input > Output
1,2 1,3 1,3 1,4 1,4 2,3 2,4 > Falsey
1,5 1,6 2,3 2,6 3,5 5,6 > Truthy
1,2 1,3 1,4 2,3 2,4 3,4 > Falsey
1,2 > Truthy

Winning
Shortest code in bytes wins.

"""

"""

Ported from @vroomfondel solution

A graph has a Eulerian trail iff the number of vertices with odd degree is 0 or 2.
This assumes all of the islands are connected.
You can't have an odd number of vertices with odd degree

"""
def solve(graph):
    degree = 0
    for vertex in set(graph):
        if graph.count(vertex) % 2:
            degree += 1
    return degree < 3

def main():
    assert(solve([1, 2, 1, 3, 1, 3, 1, 4, 1, 4, 2, 3, 2, 4]) == False)
    assert(solve([1, 5, 1, 6, 2, 3, 2, 6, 3, 5, 5, 6]) == True)
    assert(solve([1, 2, 1, 3, 1, 4, 2, 3, 2, 4, 3, 4]) == False)
    assert(solve([1, 2]) == True)

main()
