#!/usr/bin/env python3

"""

Your task is to form an expression equaling 11111111111 (11 ones) using only the following characters: 1+(). Keep in mind that the result is in base 10, and not some other base like binary. Of course, these expressions should follow the order of operations.
Furthermore, the only operations which should be performed are addition, multiplication, and exponentation.

Some examples of valid expressions include

1+1+1=3
(1+1)(1+1)=4
(1+1)1+1+1=8
1+(1+1(1+1)1+11+1)=6

Some examples of invalid expressions include

11+11|concatenation of ones
1+((1)|unbalanced parentheses
(11+1)|disallowed operation

Scoring
After forming an expression which equals 11111111111, your score will be calculated by the sum of the no. of 1, the no. of +, and the no. of pairs of parentheses. For example, (1+1)(1+1)1+(1) has a score of 12, because it has 61s, 3 pluses, and 3 pairs of parentheses.

The submission with the lowest score wins!

"""

# @Anders Kaseorg optimal for up to 8 digits, found via brute force
def solve():
    return 1 + (1 + 1) * (1 + 1 + 1 + (1 + 1)**((1 + 1)**(1 + 1 + 1))*(1 + ((1 + 1)*(1 + 1 + 1))**(1 + 1 + 1))) * (1 + (1 + (1 + 1 + 1)**(1 + 1))**(1 + (1 + 1)**(1 + 1)))

def main():
    assert(solve() == 11111111111)

main()
