#=

The Gray code sequence is a binary encoding of the integers where successive integers differ by a single bit flip.

The first couple of terms are as follows:

1     1
2    11
3    10
4   110
5   111
6   101
7   100
8  1100
etc...
Your program will take a positive integer as input and output its Gray code as a binary string.
This is code-golf, so the shortest answer in bytes wins!

=#

function gray(n)
	return string(n⊻(n>>1),base=2)
end

for i in 1:8
	println(i, " ", gray(i))
end
