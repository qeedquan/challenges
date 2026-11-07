%{

Print the number 2^n using bit operations only.

Input
One number n (0≤n≤30).

Output
Print the number 2^n using bit operations only.

Examples

Input #1
0

Answer #1
1

Input #2
1

Answer #2
2

%}

for i=0:32
	bitshift(1, i)
end
