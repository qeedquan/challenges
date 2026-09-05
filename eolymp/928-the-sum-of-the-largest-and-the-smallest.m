%{

The array of integers is given. Find the sum of the smallest and the largest elements of the array.

Input
The first line contains the number of elements n (n≤100) in the array.
The second line contains n integers, each of which does not exceed 100 in absolute value.

Output
Print the sum of the smallest and the largest elements of the array.

Examples
Input #1
4
1 2 3 4

Answer #1
5

%}

function r = solve(a)
	r = min(a) + max(a);
end

solve([1 2 3 4])

