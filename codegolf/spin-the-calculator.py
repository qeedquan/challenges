#!/usr/bin/env python3

"""

Introduction:
Let's take a look at a standard Calculator in Windows:

https://i.sstatic.net/DLmi6.png

For this challenge, we'll only look at the following buttons, and ignore everything else:

7 8 9 /
4 5 6 *
1 2 3 -
0 0 . +
Challenge:
Input:
You will receive two inputs:

One is something to indicate the rotation in increments of 90 degrees
The other is a list of coordinates representing the buttons pressed on the rotated calculator.
Based on the first input, we rotate the layout mentioned above clockwise in increments of 90 degrees. So if the input is 0 degrees, it remains as is; but if the input is 270 degrees, it will be rotated three times clockwise (or once counterclockwise). Here are the four possible lay-outs:

Default / 0 degrees:
7 8 9 /
4 5 6 *
1 2 3 -
0 0 . +

90 degrees clockwise:
0 1 4 7
0 2 5 8
. 3 6 9
+ - * /

180 degrees:
+ . 0 0
- 3 2 1
* 6 5 4
/ 9 8 7

270 degrees clockwise / 90 degrees counterclockwise:
/ * - +
9 6 3 .
8 5 2 0
7 4 1 0
The second input is a list of coordinates in any reasonable format †. For example (0-index 2D integer-array):

[[1,2],[2,3],[0,3],[1,0],[1,1]]
Output:
We output both the sum, as well as the result (and an equal sign =).

Example:
So if the input is 270 degrees and [[1,2],[2,3],[0,3],[1,0],[1,1]], the output will become:

517*6=3102

Challenge rules:
† The inputs can be in any reasonable format. The first input can be 0-3, 1-4, A-D, 0,90,180,270, etc. The second input can be a 0-indexed 2D array, 1-indexed 2D array, a String, list of Point-objects, etc. Your call. It's even possible to swap the x and y coordinates compared to the example inputs given. Please state which input formats you've used in your answer!
You are allowed to add spaces (i.e. 517 * 6 = 3102) if you want to.
You are allowed to add trailing zeros after the comma, to a max of three (i.e. 3102.0/3102.00/3102.000 instead of 3102 or 0.430 instead of 0.43).
You are not allowed to add parenthesis in the output, so (((0.6+4)-0)/2)/4=0.575 is not a valid output.
You are allowed to use other operand-symbols for your language. So × or · instead of *; or ÷ instead of /; etc.
Since a calculator automatically calculates when inputting an operand, you should ignore operator precedence! So 10+5*3 will result in 45 ((10+5)*3=45), not 25 (10+(5*3)=25)
(i.e. 10 → + → 5 → * (it now displays 15 in the display) → 3 → = (it now displays the answer 45)). Keep this in mind when using eval and similar functions on the resulting sum.
There won't be any test cases for division by 0.
There won't be any test cases with more than three decimal digits as result, so no need for rounding the result.
There won't be any test cases where multiple operands follow each other, or where two dots follow each other.
There won't be any test cases for negative numbers. The minus-sign (-) will only be used as operand, not as negative.
There won't be any test cases for .## without a leading number before the comma (i.e. 2+.7 will not be a valid test case, but 2+0.7 could be).

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.

Test cases:
Input:   270 degrees & [[1,2],[2,3],[0,3],[1,0],[1,1]]
Output:  517*6=3102

Input:   90 degrees & [[3,1],[0,0],[0,1],[3,3],[2,0],[0,3],[0,0],[0,2],[3,0],[2,1]]
Output:  800/4+0.75=200.75

Input:   0 degrees & [[0,0],[1,0],[2,0],[3,0],[1,2],[2,1],[2,2]]
Output:  789/263=3

Input:   180 degrees & [[3,0],[1,0],[1,2],[0,0],[3,2],[0,1],[2,0],[0,3],[2,1],[0,3],[3,2]]
Output:  0.6+4-0/2/4=0.575

"""

from tokenize import *
from io import *

def spineval(d, a):
    if d == 0:
        C = [['7', '8', '9', '/'], ['4', '5', '6', '*'], ['1', '2', '3', '-'], ['0', '0', '.', '+']]
    elif d == 90:
        C = [['0', '1', '4', '7'], ['0', '2', '5', '8'], ['.', '3', '6', '9'], ['+', '-', '*', '/']]
    elif d == 180:
        C = [['+', '.', '0', '0'], ['-', '3', '2', '1'], ['*', '6', '5', '4'], ['/', '9', '8', '7']]
    elif d == 270:
        C = [['/', '*', '-', '+'], ['9', '6', '3', '.'], ['8', '5', '2', '0'], ['7', '4', '1', '0']]
    else:
        return None

    s = ""
    for j, i in a:
        s += C[i][j]

    b = BytesIO(s.encode('utf-8'))
    p = []
    for t, v, _, _, _ in tokenize(b.readline):
        if t == OP or t == NUMBER:
            p.append(str(v))

        if len(p) == 3:
            p = [str(eval(''.join(p)))]
    
    if len(p) == 0:
        return 0

    return float(p[0])

def main():
    assert(spineval(270, [[1, 2], [2, 3], [0, 3], [1, 0], [1, 1]]) == 3102)
    assert(spineval(90, [[3, 1], [0, 0], [0, 1], [3, 3], [2, 0], [0, 3], [0, 0], [0, 2], [3, 0], [2, 1]]) == 200.75)
    assert(spineval(0, [[0, 0], [1, 0], [2, 0], [3, 0], [1, 2], [2, 1], [2, 2]]) == 3)
    assert(spineval(180, [[3, 0], [1,0], [1, 2], [0, 0], [3, 2], [0, 1], [2, 0], [0, 3], [2, 1], [0, 3], [3, 2]]) == 0.575)

main()
