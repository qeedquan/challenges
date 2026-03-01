%{

Description

Given a n × n matrix A and a positive integer k, find the sum S = A + A^2 + A^3 + … + A^k.

Input

The input contains exactly one test case. The first line of input contains three positive integers n (n ≤ 30), k (k ≤ 10^9) and m (m < 10^4). Then follow n lines each containing n nonnegative integers below 32,768, giving A’s elements in row-major order.

Output

Output the elements of S modulo m in the same way as A is given.

Sample Input

2 2 4
0 1
1 1
Sample Output

1 2
2 3
Source

POJ Monthly--2007.06.03, Huang, Jinsong

%}

function R = mps(A, k, m)
	R = zeros(size(A));
	for i = 1:k
		R += A^i;
	end
	R = mod(R, m);
end

mps([0 1; 1 1], 2, 4)
