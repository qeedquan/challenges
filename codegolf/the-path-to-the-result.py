#!/usr/bin/env python3

"""

Input:

A grid of varying size only containing numbers in the range 00-99, the following four characters: ^; >; v; <, and spaces to fill (and new-lines of course).

Output:

The result of the sum (integer) when you follow the path.

How does this work?

You start at the arrow with the highest number, and follow the path the arrows point to.
For each of the four arrows we'll do a different arithmetic calculation:

> = Addition (+);
< = Subtraction (−);
^ = Multiplication (* or × or ·);
v = Real / Calculator Division (/ or ÷);
(NOTE: The symbols between parenthesis are just added as clarification. If your programming language uses a completely different symbol for the arithmetic operation than the examples, then that is of course completely acceptable.)

Challenge rules:

You can choose the input (to some extent). A string-array would be most logical I think, but a symbol/newline-separated single string is also fine. (Full functions as input that are simply executed in the actual code snippet aren't allowed!)
Trailing spaces for the input are optional.
Numbers 0-9 will have a leading 0 so all numbers plus arrow are of an equal three-character length.
The number & arrow will always have the following format: DDA (D being a digit; A being one of the four arrows).
You use the current value with the previous arithmetic operation (the example below explains this better).
The final arithmetic operation can be ignored because of the rule above.
It is possible to have DDA's in the input-grid that aren't being used in the path to the resulting sum.
There won't be any test-cases for arrows that form a loop.
There won't be any test-cases for dividing by 0.
There won't be any test-cases where dividing creates a decimal sum-result. You only have to worry about integers.
EDIT: Since there weren't any answer yet, I decided to change the grids slightly to perhaps make it easier. I know this is usually not recommended to do with challenges, but since no answers were given yet, I think this will make it slightly easier, giving more (/any) answers: The spaces between de DDA's are random. There could even be no spaces in between at all. All DDA's and spaces are grouped per three. Also, it is possible to have no spaces between DDA's at all.
Example:

Input:

94>      66v
   05v   08<
         43>
   03>   00^
Path it follows:

Path it follows   |   Current sum value
________________________________________
94>               |   94  (highest value)
66v               |   160 (+)
08<               |   20  (/)
05v               |   15  (-)
03>               |   5   (/)
00^               |   5   (+)
43>               |   215 (*)
                          '>' after 43 is ignored because it's the last number
Output: 215

General Rules:

This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.
Test cases:

94>      66v           ->     215
   05v   08<
         43>
   03>   00^


77>   80v55^02<        ->     -19
      20>   14^


22>11>15>80>14v        ->     -16
18^17>      10v
00^   90v43^02v
07^11<15<22v01<


99>98>97>96>95>94v     ->     102
93>92>   91v   03<

"""

# ported from @Daniel solution
def solve(grid):
    pos = [-1, 0]
    dir = ">"
    out = 0
    op = "+"

    max = 0
    for y in range(len(grid)):
        for x in range(len(grid[0])):
            if grid[y][x] in "><^v":
                val = int(grid[y][x - 2] + grid[y][x - 1])
                if val > max:
                    max = val
                    pos = [x - 2, y]

    while True:
        if dir == ">":
            pos[0] += 1
        if dir == "<":
            pos[0] -= 1
        if dir == "^":
            pos[1] -= 1
        if dir == "v":
            pos[1] += 1
        
        try:
            cur = grid[pos[1]][pos[0]]
            if cur in "><^v":
                dir = cur
                val = int(grid[pos[1]][pos[0] - 2] + grid[pos[1]][pos[0] - 1])
                if pos[0] < 0 or pos[1] < 0:
                    break

                out = eval(str(out) + op + str(val))
                if cur == ">":
                    op = "+"
                if cur == "<":
                    op = "-"
                if cur == "^":
                    op = "*"
                if cur == "v":
                    op = "//"

        except:
            break
    
    return out

def main():
    assert(solve(["94>      66v", "   05v   08<", "         43>", "   03>   00^"]) == 215)
    assert(solve(["77>   80v55^02<", "      20>   14^"]) == -19)
    assert(solve(["22>11>15>80>14v", "18^17>      10v", "00^   90v43^02v", "07^11<15<22v01<"]) == -16)
    assert(solve(["99>98>97>96>95>94v", "93>92>   91v   03<"]) == 102)

main()
