%{

Problem The Fibonacci numbers 0,1,1,2,3,5,8,13,21,34,… are generated by the following simple rule
Fn = F[n-1] + F[n-2] n > 1
     1,              n = 1
     0,              n = 0

Given: A positive integer n≤25.

Return: The value of Fn.

Source: Algorithms by Dasgupta, Papadimitriou, Vazirani. McGraw-Hill. 2006.

Sample Dataset
6
Sample Output
8

%}

function r = fib(n)
	p = (1+sqrt(5))/2;
	r = floor(p^n/sqrt(5) + 1/2);
end

for i = 0:32
	fib(i)
end

