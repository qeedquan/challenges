%{

There are a boys and b girls in the class. How many students are in the class in total?

Input
Two positive integers a and b (a, b≤10^18).

Output
Print the number of students in the class.

Examples

Input #1
12 9

Answer #1
21

%}

function total = solve(boys, girls)
	total = boys + girls;
end

solve(12, 9)
