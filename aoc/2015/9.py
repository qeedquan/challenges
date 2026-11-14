#!/usr/bin/env python3

"""

--- Day 9: All in a Single Night ---
Every year, Santa manages to deliver all of his presents in a single night.

This year, however, he has some new locations to visit; his elves have provided him the distances between every pair of locations. He can start and end at any two (different) locations he wants, but he must visit each location exactly once. What is the shortest distance he can travel to achieve this?

For example, given the following distances:

London to Dublin = 464
London to Belfast = 518
Dublin to Belfast = 141
The possible routes are therefore:

Dublin -> London -> Belfast = 982
London -> Dublin -> Belfast = 605
London -> Belfast -> Dublin = 659
Dublin -> Belfast -> London = 659
Belfast -> Dublin -> London = 605
Belfast -> London -> Dublin = 982
The shortest of these is London -> Dublin -> Belfast = 605, and so the answer is 605 in this example.

What is the distance of the shortest route?

--- Part Two ---
The next year, just to show off, Santa decides to take the route with the longest distance instead.

He can still start and end at any two (different) locations he wants, and he still must visit each location exactly once.

For example, given the distances above, the longest route would be 982 via (for example) Dublin -> London -> Belfast.

What is the distance of the longest route?

"""

from itertools import permutations

def read_routes(name):
    distances = {}
    file = open(name)
    for line in file.readlines():
        line = line.strip()
        fields = line.split()
        if len(fields) != 5:
            continue

        key0 = (fields[0], fields[2])
        key1 = (fields[2], fields[0])

        distances[key0] = int(fields[4])
        distances[key1] = int(fields[4])
    places = list(set(data[0] for data in distances.keys()))

    file.close()
    return distances, places

def solve(distances, places):
    shortest = float('inf')
    longest = -float('inf')
    for p in permutations(places):
        length = 0
        for i in range(len(p) - 1):
            length += distances[p[i], p[i + 1]]
        
        shortest = min(shortest, length)
        longest = max(longest, length)

    print(shortest)
    print(longest)

def main():
    distances, places = read_routes("9.txt")
    solve(distances, places)

main()

