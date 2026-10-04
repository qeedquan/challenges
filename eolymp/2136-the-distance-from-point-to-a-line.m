%{

Find the distance from a given point to a given straight line.

Input
Six integers are given: the coordinates of the point and the coordinates of two points that define the line.
The absolute value of each input number does not exceed 10000.

Output
Output a single number — the distance from the point to the line, with precision up to 10^-6.

Examples
Input #1
1 1 0 0 2 0

Answer #1
1.000000

%}

function l = solve(a, b, x1, y1, x2, y2)
	l = ((x2-x1)*b + (y1-y2)*a + y2*x1 - y1*x2) / sqrt((x2-x1)^2 + (y1-y2)^2);
	l = abs(l);
end

solve(1, 1, 0, 0, 2, 0)
