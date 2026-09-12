%{

In base-10, all perfect squares end in 0, 1, 4, 5, 6, or 9.

In base-16, all perfect squares end in 0, 1, 4, or 9.

Nilknarf describes why this is and how to work this out very well in this answer, but I'll also give a brief description here:

When squaring a base-10 number, N, the "ones" digit is not affected by what's in the "tens" digit, or the "hundreds" digit, and so on. Only the "ones" digit in N affects the "ones" digit in N^2, so an easy (but maybe not golfiest) way to find all possible last digits for N^2 is to find n^2 mod 10 for all 0≤n<10. Each result is a possible last digit. For base-m, you could find n^2 mod m for all 0≤n<m.

Write a program which, when given the input N, outputs all possible last digits for a perfect square in base-N (without duplicates). You may assume N is greater than 0, and that N is small enough that N^2 won't overflow (If you can test all the way up to N^2, I'll give you a finite amount of brownie points, but know that the exchange rate of brownie points to real points is infinity to one).

Tests:

 Input -> Output
 1     -> 0
 2     -> 0,1
 10    -> 0,1,5,6,4,9
 16    -> 0,1,4,9
 31    -> 0,1,2,4,5,7,8,9,10,14,16,18,19,20,25,28
 120   -> 0,1,4,9,16,24,25,36,40,49,60,64,76,81,84,96,100,105
this is code-golf, so standard rules apply!

(If you find this too easy, or you want a more in-depth question on the topic, consider this question: Minimal cover of bases for quadratic residue testing of squareness).

%}

function r = square_end(n)
	r = unique(mod((1:n).^2, n));
end

square_end(1)
square_end(2)
square_end(10)
square_end(16)
square_end(32)
square_end(120)
