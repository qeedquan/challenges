#!/usr/bin/env python3

"""

One of the built-in functions of Python is divmod, which takes two arguments a and b and returns a tuple containing the quotient of a/b first and then the remainder a.

For example:

>>> print divmod(177,10)
(17, 7)
Here, the integer division is 177/10 => 17 and the modulo operator is 177%10 => 7.

Task
Read in two integers,  and , and print three lines.
The first line is the integer division  (While using Python2 remember to import division from __future__).
The second line is the result of the modulo operator: a%b.
The third line prints the divmod of a and b.

Input Format
The first line contains the first integer, , and the second line contains the second integer, .

Output Format
Print the result as described above.

Sample Input

177
10
Sample Output

17
7
(17, 7)

"""

def quotients(a, b):
    print(a // b)
    print(a % b)
    print(divmod(a, b))

def main():
    quotients(177, 10)

main()
