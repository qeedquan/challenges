#!/usr/bin/env python3

"""

Madison is a little girl who is fond of toys.
Her friend Mason works in a toy manufacturing factory.
Mason has a 2D board A of size HxW with H rows and W columns.
The board is divided into cells of size 1x1 with each cell indicated by its coordinate (i, j).
The cell (i, j) has an integer Aij written on it.
To create the toy Mason Aij stacks number of cubes of size 1x1x1 on the cell (i, j).

Input Format
The first line contains two space-separated integers H and W the height and the width of the board respectively.

The next H lines contains W space separated integers. The jth integer in ith line denotes Aij.

Constraints
1 <= H, W <= 100
1 <= A[i, j] <= 100

Output Format
Print the required answer, i.e the price of the toy, in one line.

Sample Input 0

1 1
1
Sample Output 0

6
Explanation 0

https://s3.amazonaws.com/hr-assets/0/1505569910-2f8fc5da13-3d.png

Sample Input 1

3 3
1 3 4
2 2 3
1 2 4
Sample Output 1

60
Explanation 1
https://s3.amazonaws.com/hr-assets/0/1509009918-091bdd4cba-1502631298-5cd3275ce9-img2.png

The object is rotated so the front row matches column 1 of the input, heights 1, 2, and 1.

The front face is 1 + 2 + 1 = 4 units in area.
The top is 3 units.
The sides are 4 units.
None of the rear faces are exposed.
The underside is 3 units.
The front row contributes 4 + 3 + 4 + 3 = 14 units to the surface area.

"""

def surface_area(A):
    r = 0
    for i in range(len(A)):
        for j in range(len(A[i])):
            r += 4 * A[i][j] + 2
            if i + 1 < len(A):
                r -= 2 * min(A[i][j], A[i + 1][j])
            if j + 1 < len(A[i]):
                r -= 2 * min(A[i][j], A[i][j + 1])
    return r

def main():
    assert(surface_area([[1]]) == 6)
    assert(surface_area([[1, 3, 4], [2, 2, 3], [1, 2, 4]]) == 60)

main()
