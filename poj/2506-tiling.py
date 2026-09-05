#!/usr/bin/env python3

"""

Description

In how many ways can you tile a 2xn rectangle by 2x1 or 2x2 tiles?
Here is a sample tiling of a 2x17 rectangle.

http://poj.org/images/2506_1.jpg

Input

Input is a sequence of lines, each line containing an integer number 0 <= n <= 250.

Output

For each line of input, output one integer number in a separate line giving the number of possible tilings of a 2xn rectangle.

Sample Input

2
8
12
100
200

Sample Output

3
171
2731
845100400152152934331135470251
1071292029505993517027974728227441735014801995855195223534251

Source

The UofA Local 2000.10.14

"""

# https://oeis.org/A001045
def jacobsthal(n):
    if n < 1:
        return 0

    a, b = 1, 1
    for i in range(n):
        a, b = b, b + 2*a
    return a

def main():
    assert(jacobsthal(2) == 3)
    assert(jacobsthal(8) == 171)
    assert(jacobsthal(12) == 2731)
    assert(jacobsthal(100) == 845100400152152934331135470251)
    assert(jacobsthal(200) == 1071292029505993517027974728227441735014801995855195223534251)

main()
