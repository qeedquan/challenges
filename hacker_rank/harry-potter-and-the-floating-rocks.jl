#!/usr/bin/env julia

#=

Famous wizard Sumar moonji kumaru is stuck in a huge room and has to save Hermione Granger from a monster.
Kumaru is at location P1 given by integral coordinates (x1,y1) and Hermione is at location P2 given by integral coordinates (x2,y2).
Sadly P1 and P2 are the only points at which floating rocks are present. Rest of the room is without floor and underneath is hot lava.

Kumaru has to go from P1 to P2 but there are no floating rocks to walk on. Kumaru knows a spell that can make the rocks appear but only on the integral coordinates on the straight line joining P1 and P2.

How many rocks can appear at locations (x,y) on the line segment between P1 and P2 (excluding P1 and P2) which satisfy the condition that both x and y are integers?

Input Format
The first line contains a single integer T, the number of test cases. T lines follow.
Each of the following T lines contains one test case each. Each test case contains 4 integers x1, y1, x2 and y2 separated by a single space.

Output Format
A single line containing the number of rocks.

Constraints
1 <= T <= 10^5
-10^9 <= x1, y1, x2, y2 <= 10^9

Sample input

3
0 2 4 0
2 2 5 5
1 9 8 16

Sample Output

1
2
6

=#

# https://www.quora.com/Given-two-points-A-and-B-on-the-X-Y-plane-what-is-the-number-of-the-points-on-the-segment-AB-which-have-both-x-and-y-co-ordinate-as-integer
function points(x1, y1, x2, y2)
	return gcd(abs(x1 - x2), abs(y1 - y2)) - 1
end

@assert(points(0, 2, 4, 0) == 1)
@assert(points(2, 2, 5, 5) == 2)
@assert(points(1, 9, 8, 16) == 6)
