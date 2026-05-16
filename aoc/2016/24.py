#!/usr/bin/env python3

"""

--- Day 24: Air Duct Spelunking ---
You've finally met your match; the doors that provide access to the roof are locked tight, and all of the controls and related electronics are inaccessible. You simply can't reach them.

The robot that cleans the air ducts, however, can.

It's not a very fast little robot, but you reconfigure it to be able to interface with some of the exposed wires that have been routed through the HVAC system. If you can direct it to each of those locations, you should be able to bypass the security controls.

You extract the duct layout for this area from some blueprints you acquired and create a map with the relevant locations marked (your puzzle input). 0 is your current location, from which the cleaning robot embarks; the other numbers are (in no particular order) the locations the robot needs to visit at least once each. Walls are marked as #, and open passages are marked as .. Numbers behave like open passages.

For example, suppose you have a map like the following:

###########
#0.1.....2#
#.#######.#
#4.......3#
###########
To reach all of the points of interest as quickly as possible, you would have the robot take the following path:

0 to 4 (2 steps)
4 to 1 (4 steps; it can't move diagonally)
1 to 2 (6 steps)
2 to 3 (2 steps)
Since the robot isn't very fast, you need to find it the shortest route. This path is the fewest steps (in the above example, a total of 14) required to start at 0 and then visit every other location at least once.

Given your actual map, and starting from location 0, what is the fewest number of steps required to visit every non-0 number marked on the map at least once?

--- Part Two ---
Of course, if you leave the cleaning robot somewhere weird, someone is bound to notice.

What is the fewest number of steps required to start at 0, visit every non-0 number marked on the map at least once, and then return to 0?

"""

from itertools import permutations
import networkx as nx
import numpy as np

def load(name):
    file = open(name)
    lines = [line.strip() for line in file.readlines()]
    file.close()

    graph = nx.Graph()
    interest = {}
    for y, line in enumerate(lines):
        for x, c in enumerate(line):
            if c == '.' or c.isdigit():
                graph.add_node((x, y))
                if c.isdigit():
                    interest[int(c)] = (x, y)
                if y > 0 and (x, y - 1) in graph:
                    graph.add_edge((x, y), (x, y - 1))
                if x > 0 and (x - 1, y) in graph:
                    graph.add_edge((x, y), (x - 1, y))

    lengths = np.empty((len(interest), len(interest)))
    for i, node in interest.items():
        for j, node in interest.items():
            lengths[i, j] = len(nx.shortest_path(graph, interest[i], interest[j])) - 1

    return interest, lengths

def solve(interest, lengths, origin):
    shortest = float('inf')
    for p in permutations(range(1, len(interest))):
        length = lengths[0, p[0]]
        for i in range(len(p) - 1):
            length += lengths[p[i], p[i + 1]]
        if origin:
            length += lengths[p[-1], 0]
        shortest = min(shortest, length)
    return int(shortest)

def main():
    interest, lengths = load("24.txt")
    print(solve(interest, lengths, False))
    print(solve(interest, lengths, True))

main()

