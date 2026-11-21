#!/usr/bin/env python3

"""

Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

Example 1:


Input: path = "NES"
Output: false
Explanation: Notice that the path doesn't cross any point more than once.
Example 2:


Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.


Constraints:

1 <= path.length <= 10^4
path[i] is either 'N', 'S', 'E', or 'W'.

Hint:
Simulate the process while keeping track of visited points.
Use a set to store previously visited points.

"""

def pathcross(s):
    m = {(0, 0): True}
    x, y = 0, 0
    for c in s:
        if c == 'N':
            y += 1
        elif c == 'S':
            y -= 1
        elif c == 'E':
            x += 1
        elif c == 'W':
            x -= 1
        
        k = (x, y)
        if k in m:
            return True
        m[k] = True
    
    return False

def main():
    assert(pathcross("NES") == False)
    assert(pathcross("NESWW") == True)

main()
