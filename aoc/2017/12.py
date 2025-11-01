#!/usr/bin/env python3

"""

--- Day 12: Digital Plumber ---
Walking along the memory banks of the stream, you find a small village that is experiencing a little confusion: some programs can't communicate with each other.

Programs in this village communicate using a fixed system of pipes. Messages are passed between programs using these pipes, but most programs aren't connected to each other directly. Instead, programs pass messages between each other until the message reaches the intended recipient.

For some reason, though, some of these messages aren't ever reaching their intended recipient, and the programs suspect that some pipes are missing. They would like you to investigate.

You walk through the village and record the ID of each program and the IDs with which it can communicate directly (your puzzle input). Each program has one or more programs with which it can communicate, and these pipes are bidirectional; if 8 says it can communicate with 11, then 11 will say it can communicate with 8.

You need to figure out how many programs are in the group that contains program ID 0.

For example, suppose you go door-to-door like a travelling salesman and record the following list:

0 <-> 2
1 <-> 1
2 <-> 0, 3, 4
3 <-> 2, 4
4 <-> 2, 3, 6
5 <-> 6
6 <-> 4, 5
In this example, the following programs are in the group that contains program ID 0:

Program 0 by definition.
Program 2, directly connected to program 0.
Program 3 via program 2.
Program 4 via program 2.
Program 5 via programs 6, then 4, then 2.
Program 6 via programs 4, then 2.
Therefore, a total of 6 programs are in this group; all but program 1, which has a pipe that connects it to itself.

How many programs are in the group that contains program ID 0?

--- Part Two ---
There are more programs than just the ones in the group containing program ID 0. The rest of them have no way of reaching that group, and still might have no way of reaching each other.

A group is a collection of programs that can all communicate via pipes either directly or indirectly. The programs you identified just a moment ago are all part of the same group. Now, they would like you to determine the total number of groups.

In the example above, there were 2 groups: one consisting of programs 0,2,3,4,5,6, and the other consisting solely of program 1.

How many groups are there in total?

"""

import re

def load(name):
    file = open(name)
    data = []
    for line in file:
        tokens = re.findall(r'\d+', line)
        tokens = [int(x) for x in tokens]
        data.append(tokens)
    return data

def find_group_with(data, x):
    group = set([x])
    last_group_size = -1
    while len(group) != last_group_size:
        last_group_size = len(group)
        for row in data:
            if group & set(row):
                group |= set(row)
    return group

def part1(data):
    return len(find_group_with(data, 0))

def part2(data):
    ungrouped_nodes = set()
    for row in data:
        ungrouped_nodes |= set(row)

    group_count = 0
    while ungrouped_nodes:
        ungrouped_nodes -= find_group_with(data, ungrouped_nodes.pop())
        group_count += 1
    return group_count

def main():
    data = load("12.txt")
    print(part1(data))
    print(part2(data))

main()
