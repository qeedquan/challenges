#!/usr/bin/env python3

"""

Task

You have a row of numbered boxes, with some filled with items and some empty. Your job is to output the number of boxes from the first to the last box, inclusive, minus the number of boxes of the largest gap between two filled boxes.

Rules

Your program should handle up to 1000 boxes. Score = size of program in bytes. -50 if you don't use a built-in sorting functionality. -150 if you program in assembly :D All cases will have at least one gap.

Input is a list of n-th boxes that are filled. Standard loop-holes aren't allowed.

Sample Input

9, 5, 4, 2
Functions with a list as input are fine.

Sample Output

5

This is the number of boxes between the 2nd and 9th box, inclusive, subtracted by the number of boxes of the gap between the 5th and 9th box (8 - 3 = 5)

"""

# Ported from @FryAmTheEggman solution
def maxgap(x):
    M = max(x) - min(x) + 1
    X = ['1'] * M
    for i in x:
        X[i - min(x)] = '0'
    return M - len(max("".join(X).split('0')))

def main():
    assert(maxgap([9, 5, 4, 2]) == 5)

main()
