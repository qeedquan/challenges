#!/usr/bin/env python3

"""

Write the shortest code that traverses a tree, breadth-first.

Input
any way you like

Output
a list of "names" of the nodes in correct order.

"""

# ported from @gnibbler solution
def bfs(tree):
    iterator = iter(tree)
    for value in iterator:
        yield value
        tree += next(iterator)
        tree += next(iterator)

def main():
    tree = [4, [2, [1, [], []], [3, [], []]], [9, [6, [5, [], []], [7, [], [8, [], []]]], [10, [], []]]]
    assert(list(bfs(tree)) == [4, 2, 9, 1, 3, 6, 10, 5, 7, 8])

main()
