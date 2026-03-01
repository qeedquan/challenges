#!/usr/bin/env python3

"""

Consider a binary tree built the following way:

The root node is 1
For a given node n:
If n is odd, its only child is 2n
If n is even, one of its children is 2n.
If (n-1)/3 is an integer and not already part of the tree, its right child is (n-1)/3
Recursively and infinitely define the tree this way, beginning from the root node.
The resulting tree begins like this:

https://i.sstatic.net/KxdQc.png

and continues forever, conjectured to contain all positive integers.
If you choose any integer on this tree and work your way up through its parents, you'll find the Collatz path to 1 for that integer.
This is called a Collatz graph

This is that tree to a depth of 20.
https://upload.wikimedia.org/wikipedia/commons/0/0e/Collatz-tree%2C_depth%3D20.svg

We can read this tree as rows, from left to right, to create a list of lists:

[[1], [2], [4], [8], [16], [32, 5], [64, 10], [128, 21, 20, 3], [256, 42, 40, 6], [512, 85, 84, 80, 13, 12], [1024, 170, 168, 160, 26, 24], [2048, 341, 340, 336, 320, 53, 52, 48], ...

Flattened, this is A088976.

Your program should take a positive integer n and output the first n rows of this tree.
You may output in any format that clearly and consistently shows a separation between each element in the row, and a distinct separation between the rows themselves.
For example, spaces for the elements, and newlines for the rows.

This is a sample program (ungolfed) that takes an integer and outputs each list on a line.
https://tio.run/##VZBBboNADEXXcApvqoxT0pSgbCJxhV6AogoVoyKBZzQMjdrLU3ugUbJ9fvO/x@4nfFkulqWlDj7tMDTh98Pb62Q4g@CJoIQ3y4SXNOm7lfRTREKSzaiqvK6jwFCW8KojT2H2HF@kaSKR6onUWQ9sW4lZh9Uhr6Nvry@Nc8StOcE@KihYM9V@glOMhoZbMBEdIEfhxa3yPuNOOR6hwHRtpoFGbRbzsqb/k2keje6TyZZ4S/M02m8yKmnE9qnHQ2nLdqxnqITVojrfczD7B1NJz24OBhEzmMjJTXbvvMNlyc9/

This is code-golf, so the shortest code in bytes wins.

"""

# https://oeis.org/A088976
def collatz_rows(n, tree=None):
    if n < 0:
        return []

    if tree is None:
        tree = [[1]]
    
    if n == 0:
        return tree

    row = []
    for node in tree[-1]:
        row.append(2 * node)
        if node % 2 == 0 and (node - 1) % 3 == 0:
            row.append((node - 1) // 3)

    for elem in row:
        if elem in sum(tree, []):
            row.remove(elem)

    return collatz_rows(n - 1, tree + [row])

def main():
    for rows in collatz_rows(20):
        print(rows)

main()
