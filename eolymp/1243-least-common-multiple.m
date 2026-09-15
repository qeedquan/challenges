%{

The least common multiple (LCM) of a set of positive integers is the smallest positive integer that is divisible by all the numbers in the set.
For example, the LCM of 5, 7, and 15 is 105.

You are required to find the LCM for each given set of numbers.

Input
The first line contains the number of tests.

Each test case is a single line containing m n[1] n[2] n[3]… n[m], where m (1≤m≤100) is the number of integers in the set,
and n[1],…,n[m] are the integers themselves. All integers are positive and within the range of a 32-bit integer.

Output
For each test case, print the corresponding LCM value on a separate line. All output values will fit within the range of a 32-bit integer.

Examples

Input #1
2
3 5 7 15
6 4 10296 936 1287 792 1

Answer #1
105
10296

%}

function r = solve(a)
	r = 1;
	for x = a
		r = lcm(r, x);
	end
end

solve([3 5 7 15])
solve([6 4 10296 936 1287 792 1])
