%{

With equations that have more than one unknown, simultaneous equations can be used in solving for them. This challenge will only deal with linear equations with two unknowns, to make things as elementary as possible.

The program should take two lines of input from stdin, each containing a linear equation with two unknowns (x and y). Output should be in the form x=<x-value>, y=<y-value>, where the angled bracketed text should be replaced by the appropriate value. Non-integer values can be outputted in either decimal point form rounded to at least 3 decimal places or until the fraction terminates (eg. 1/2 would be 0.5 not 0.500), or simplest (improper, not mixed) fraction form (as all results will be rational). If the equations are unsolvable (ie are parallel but not equivalent), output Unsolvable. If the equations are equivalent and would therefore have an infinite number of solutions, output Degenerate.

The use of external modules is not allowed. Also, any library functions that solve equations (this applies especially to Mathematica) are not allowed.

Each equation in the input will be in general form, with no whitespace. If a coefficent or the constant term is 0, the whole term will not appear, and if a coefficient is ±1, only the pronumeral will appear.

Test cases:

Input:                 Input:                 Input:                 Input:
7x+4y-8=0              4x+3y+32=0             x-y=0                  2x+5y-1=0
x-8y+1=0               x-4=0                  x-y+5=0                2x+5y-1=0
Output:                Output:                Output:                Output:
x=1, y=1/4 (or 0.25)   x=4, y=-16             Unsolvable             Degenerate

This is once again code-golf, so shortest code wins.

%}

M = [[7 4]; [1 -8]]
b = [8; -1]
x = M^-1*b

M = [[4 3]; [1 0]]
b = [-32; 4]
x = M^-1*b

M = [[1 -1]; [1 -1]]
b = [0; -5]
x = M^-1*b

M = [[2 5]; [2 5]]
b = [1; 1]
x = M^-1*b
