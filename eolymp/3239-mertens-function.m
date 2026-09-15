%{

The Mobius function μ(n) – a multiplicative function, so named after the famous nineteenth-century mathematician August Mobius, also well-known for his strip.
The function is defined by the following recurrence relation:

mu(1)          = 1
Sum[d|n] mu(d) = 0, n > 1

The Mobius function is related to the Mertens function by the relation:

M(n) = Sum[k=1, n] mu(k)

Find the value of Mertens function for a given number n.

Input
The first line contains the number of tests t (1≤t≤10^5). Each test consists of a single number n (1≤n≤10^7).

Output
For each test case output a single number – the value of the Mertens function.

Examples
Input #1
4
2
1
4
7
Answer #1
0
1
-1
-2

%}

% https://blogs.mathworks.com/cleve/2024/10/22/mobius-mertens-and-redheffer/
function mu = mobius(n)
	mu = -eye(1,n);
	for k = 2:n
		f = factor(k);
		d = diff([1 f]);
        if any(d == 0)
            mu(k) = 0;
        else
            mu(k) = (-1)^length(f);
        end
    end
end

% https://oeis.org/A002321
function M = mertens(n)
	mu = mobius(n);
	S = cumsum([1 mu(2:n)]);
	M = S(end, end);
end

mertens(2)
mertens(1)
mertens(4)
mertens(7)
