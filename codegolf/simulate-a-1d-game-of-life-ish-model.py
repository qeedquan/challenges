#!/usr/bin/env python3

"""

This question just trended over on code-review and I figured you might like it adapted as a codegolf challenge:

You are given a non-empty list of x houses represented as booleans. Each day, the houses compete with adjacent ones. 1 represents an "active" house and 0 represents an "inactive" house. If the neighbors on both sides of a given house are either both active or both inactive, then that house becomes inactive on the next day. Otherwise it becomes active.

def get_state_as_pos(thelist, pos):
    if thelist[pos-1] == thelist[pos+1]:
        return 0
    else:
        return 1
For example, if we had a group of neighbors [0, 1, 0] then the house at [1] would become 0 since both the house to its left and right are both inactive. The cells at both ends check the opposite side as well, so the neighbors at index 0 are at index length-1 and indexn1 and vice versa. Even after updating the cell, you have to consider its prior state when updating the others so that the state information of each cell is updated simultaneously.

The function takes the array of states and a number of steps and should output the state of the houses after the given number of steps.

    input: states = [1, 0, 0, 0, 0, 1, 0, 0], steps = 1
   output should be [0, 1, 0, 0, 1, 0, 1, 1]

    input: states = [1, 1, 1, 0, 1, 1, 1, 1], steps = 2
intermediate state= [0, 0, 1, 0, 1, 0, 0, 0]
   output should be [0, 1, 0, 0, 0, 1, 0, 0]


    input: states = [1], steps=1
    output: states= [0]
Take the list and steps however you like and output the resulting list via default I/O. Standard loopholes are forbidden. This is codegolf, shortest answer in bytes wins!

"""

def evolve(state0, iterations):
    state = state0
    nextstate = [0] * len(state)
    for _ in range(iterations):
        for i in range(len(state)):
            nextstate[i] = state[i - 1] ^ state[(i + 1) % len(state)]
        state, nextstate = nextstate, state
    return state

def main():
    assert(evolve([1, 0, 0, 0, 0, 1, 0, 0], 1) == [0, 1, 0, 0, 1, 0, 1, 1])
    assert(evolve([1, 1, 1, 0, 1, 1, 1, 1], 2) == [0, 1, 0, 0, 0, 1, 0, 0])
    assert(evolve([1], 1) == [0])

main()
