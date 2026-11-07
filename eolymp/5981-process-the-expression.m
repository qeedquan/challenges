%{

Calculate the derivative of the given function at specified points.

The function is provided as a single-line expression in infix notation, without spaces.
It may include binary operations + - * ^ (exponentiation), parentheses, single-digit positive integers, and the variable x.

Input
The first line of the input contains the functional expression.
The second line lists one or more integers, representing the values of x where the derivative should be evaluated.

The expression's length does not exceed 100 characters.
The expression is guaranteed to be valid, and the results will fit within the standard integer range.
The values of x are also within the standard integer range.

Output
The output should have the same number of lines as there are values of x.
Each line should display the derivative's value of the expression at the corresponding x.

Examples

Input #1
2*7-3^4
375

Answer #1
0

%}

pkg load symbolic;

syms x;

f1 = diff(2*7-3^4);
f2 = diff(x^3 + x^2 + x + 1);

vpa(subs(f1, x, 375))
vpa(subs(f2, x, 3))
