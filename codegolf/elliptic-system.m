%{

Introduction
Given five points in the plane, your task is to compute the area of the ellipse passing through these points.

You can assume that exactly one non-degenerate ellipse can be constructed with the given input values.

Rules
Input is 10 integers in any convenient form, corresponding to the x and y coordinates of the points. For example, you could take input as a list of 10 integers [x1, y1, x2, y2, ..., x5, y5], or as [[x1, y1], [x2, y2], ..., [x5, y5]], etc.. You may also handle decimal numbers, but only integers are required.

Output is a representation of the area of the ellipse. This may be some symbolic expression, or a decimal value with at least 8 digits of precision.

This is code-golf, so the shortest answer in bytes wins.

Example Input and Output
Input:

[-2, 3, 2, 5, 5, 3, 4, 0, 1, -3]

Output:

62.15326783788685

A depiction of the ellipse passing through these points:

https://i.stack.imgur.com/xJOpP.png

More examples:

f(60, -92, -31, -10, 78, -19, -27, -35, 91, -37) = 9882.59540465108
f(-9, -4, 7, 7, 10, 1, -7, -10, 0, 7) = 269.5966648188643
f(-3, 2, 0, -5, 4, 0, -4, 1, -1, 2) = 98.54937293879908

%}

%{

@flawr

https://math.stackexchange.com/questions/1385426/area-of-the-ellipse-ax22bxycy22dx2eyf-0

Given an implicit equation of an ellipse
A*x^2 + 2*B*x*y + C*y^2 + 2*D*x + 2*E*y + F = 0 where A*C - B^2 > 0

The area is
S = -pi*G / (A*C - B^2)^1.5

G = Determinant of the following matrix:
|A B D|
|B C E|
|D E F|

To figure out the coefficients A, B, C, D, E, F given a list of points, we want to solve the following equation:
Mx = 0 (ie, find the nullspace of M)

%}

function A = elliptic_area(x, y)
	p = null([x.^2, 2*x.*y, y.^2, 2*x, 2*y, 0*x + 1]);
	A = pi*det(p([1, 2, 4; 2, 3, 5; 4 5 6])) / abs(p(1)*p(3) - p(2)^2)^1.5;
end

elliptic_area([-2, 2, 5, 4, 1]', [3,5, 3, 0, -3]')
elliptic_area([60, -31, 78, -27, 91]', [-92, -10, -19, -35, -37]')
elliptic_area([-9, 7, 10, -7, 0]', [-4, 7, 1, -10, 7]')
elliptic_area([-3, 0, 4, -4, -1]', [2, -5, 0, 1, 2]')

