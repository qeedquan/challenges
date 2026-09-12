%{

Hilbert numbers are defined as positive integers of the form 4n + 1 for n >= 0. The first few Hilbert numbers are:

1, 5, 9, 13, 17, 21, 25, 29, 33, 37, 41, 45, 49, 53, 57, 61, 65, 69, 73, 77, 81, 85, 89, 93, 97
The Hilbert number sequence is given by OEIS sequence A016813.

A related number sequence, the Hilbert primes, are defined as the Hilbert numbers H > 1 that are not divisible by any Hilbert number k such that 1 < k < H. The first few Hilbert primes are:

5, 9, 13, 17, 21, 29, 33, 37, 41, 49, 53, 57, 61, 69, 73, 77, 89, 93, 97, 101, 109, 113, 121, 129, 133, 137, 141, 149, 157, 161, 173, 177, 181, 193, 197
Naturally, OEIS has this sequence too.

Given a integer n such that 0 <= n <= 2^16 as input, output the nth Hilbert prime.

This is code-golf, so standard rules apply, and the shortest code in bytes wins.

%}

% https://oeis.org/A057948
% ported from @Luis Mendo solution
function r = H(n)
	if n < 1
		r = 0;
		return;
	end

	x = 5;
	r = x;
	while nnz(x) < n
		r = r + 4;
		x = [x r(1:+all(mod(r, x)))];
	end
end

for i = 0:20
	H(i)
end
