%{

Gamma function is defined as

https://i.stack.imgur.com/ES8hs.png

It is a well-known fact that for positive integers it coincides with a properly shifted factorial function: Γ(n) = (n - 1)!. However, a less famous fact is

Γ(1/2) = π^(1/2)

Actually, the Gamma function can be evaluated for all half-integer arguments, and the result is a rational number multiplied by π1/2. The formulas, as mentioned in Wikipedia, are:

Gamma function for half-integer arguments (for n > 0)
https://i.stack.imgur.com/DrL55.png

In this challenge, you should write code (program or function) that receives an integer n and returns the rational representation of Γ(1/2 + n) / π^(1/2), as a rational-number object, a pair of integers or a visual plain-text representation like 15/8.

The numerator and denominator don't need to be relatively prime. The code should support values of n at least in the range -10 ... 10 (I chose 10 because 20! < 264 and 19!! < 2^32).

Test cases (taken from Wikipedia):

Input | Output (visual) | Output (pair of numbers)
0     | 1               | 1, 1
1     | 1/2             | 1, 2
-1    | -2              | -2, 1
-2    | 4/3             | 4, 3
-3    | -8/15           | -8, 15

%}

function r = ghi(n)
	r = rats(gamma(n + .5) / pi^.5);
end

ghi(0)
ghi(1)
ghi(-1)
ghi(-2)
ghi(-3)
