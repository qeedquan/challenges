/*

The challenge
In the least number of source code characters, in a language of your choosing, devise a function which raises base a to power b, modulo m, using purely integer arithmetic, where a, b, and m are all unsigned 64-bit values or larger. You may use signed arithmetic if your language does not have unsigned arithemetic.

This is the standard number-theory operation a^b (mod m), and not a^(b mod m). Conceptually, and perhaps literally, depending on your implementation, all of your intermediate results should conform to the modulus m. That is to say, you won't actually be raising a to the b power and then computing the remainder after dividing by m — that would require as much as two trillion gigabytes of RAM to store a number that big. Instead, you'll be raising a to the b power while staying within the constraints of modulus m, or straying from it only a bit (no pun intended).

This is actually a lot easier than it sounds!—Raising numbers to astronomically large powers can actually be a surprisingly fast operation. If you do it right, you can compute the result in a handful of microseconds, or perhaps few milliseconds if you're using a slow language. However, you are free to use any algorithm you like, even if it uses an increment-counter in a hard loop running for quadrillions of years. The only requirement with regard to execution time is that your program provably halt in a finite amount of time, providing the correct answer.

Input assumptions
You can assume that a ≥ 0, b ≥ 0, m > 0, and a < m, but you should not assume that b < m. That is, you should assume that both b and m can be any value as large as your integer type supports (this will be 2⁶³–1 for signed 64-bit integers and 2⁶⁴–1 for unsigned 64-bit integers).

If you are given a = b = 0, you can return whatever value you like, since 0^0 is undefined. Similarly, if you are given m = 0, you can return whatever you like, since 0 is not a valid modulus.

Test values
Your program should work correctly for all inputs, but here are a few samples to help you with validation:

              Base             Exponent               Modulus                Result
                 2                    8                   255                     1
                 2                    8                   256                     0
                 2                    8                   257                   256
                 3                    7                 10000                  2187
                 2                 2046                  2047                     1
               123                  456                   789                   699
                 3                 1000  18446744073709551615  12311760789144243126
             86400             22157322        48519018006822        40149207423504
           8675309         100018327824   8621993634251008000   3858055581225668161
325284989554104320  1508436685178379520   8582294829391072256   6354230931838838784
Counting source characters

Spaces and tabs each count as 1 character. Newlines do not count, unless the newline character adds syntactic whitespace in order to permit parsing. For example, the newline at the end of the first line here counts as 1 character because it is required to permit proper parsing:

#define foo 7
int f(){...}
But the newline character at the end of the first line here does not count:

int f(){...}
int g(){...}
because parsing would still be possible if the two lines were adjoined:

int f(){...}int g(){...}
This allows you to present your source code with line-breaks at natural locations without penalty, so that you don't have to try to cram everything onto a single line. Finally, if you're using C/C++ and you put a \ at the end of a line, then the newline also does not count because you're using the \ only for readability of presentation.

Restrictions & Allowances:

Arithmetic: You may use only integer addition, subtraction, logical operations, and conditionals. Comparisons count as a form of subtraction. Multiplication and division are not allowed. (However, the specific case of left- and right-shifting may be written using *2, *=2, /2, /=2 if these are syntactically shorter than the bit-shifting operators in your language, e.g., <<1, <<=1, >>1, >>=1, etc.) Use of a built-in exponentiation operator (e.g., **) is not allowed.
Floating-point arithmetic is not allowed. However, you may use floating-point variables provided you only use them to hold integers. (Floating-point operations aren't really going to help you on this challenge anyway, so don't be discouraged by this restriction.)
Your function is not required to have a name (it can be an anonymous or lamba function if your language supports that), but it does have to be a bona fide function that you can call an arbitrary number of times.
No global variables. (Exception: If there is no way in your language to provide a solution without global variables, then you may use global variables. But only if there is no other way.)
You may ignore any and all compiler, interpreter, or runtime warnings, so long as your program computes correct results.
If you are using a language which requires importation of type declarations in order to guarantee a 64-bit integer size (e.g, <stdint.h> in C), you may assume that this is already included. Note that uint64_t is considerably fewer characters than unsigned long long.
Cheating:

You may optionally provide a cheat solution, but only if you are also providing a legal solution and your cheat solution computes correct results as well (please post the cheat version below the legal version and do not count the cheat version as your score).
If you do provide a cheat version that uses a built-in exponentiation operator or function call (e.g., ** in AWK or pow() in C), beware of rounding and truncation issues. Just because you're providing a cheat version doesn't mean you're allowed to produce incorrect results. :-) For example, writing uint64_t modpow(uint64_t a,uint64_t b,uint64_t m){return pow(a,b)%m;} in C hasn't even the remotest chance of being correct for anything but the smallest values, so don't do that. (Actually, it might even be a challenge to use built-in non-modular exponentiation. I'd be interested to see if anyone actually manages to pull that off. But even though I'm posing that as a sub-challenge, it's still considered a cheat for the purposes of the larger challenge.)
If you need help getting started:

Here are a couple resources with simple algorithms for computing modular exponentiation:

Modular exponentiation [Wikipedia.org]
Fastest modular exponentiation [CodeGolf.StackExchange.com]
Lastly:

I will be posting a solution in C99 that I worked out earlier today as a byproduct of writing a Miller–Rabin primality test for another purpose. My answer should not be treated as an eligible entry to the challenge.

I am really looking forward to seeing what you come up with in Golfscript, Befunge, Haskell, Clojure, and more!

*/

#include <cassert>
#include <cstdint>

using binfn = uint64_t (&)(uint64_t, uint64_t, uint64_t);

template <uint64_t N, binfn f>
uint64_t modbin(uint64_t a, uint64_t b, uint64_t m)
{
	auto c = N;
	for (; b; b >>= 1)
	{
		if (b & 1)
			c = f(c, a, m);
		a = f(a, a, m);
	}
	return c;
}

uint64_t modadd(uint64_t a, uint64_t b, uint64_t m)
{
	auto c = a + b;
	if (c >= m || c < b)
		c -= m;
	return c;
}

uint64_t modmul(uint64_t a, uint64_t b, uint64_t m)
{
	return modbin<0, modadd>(a, b, m);
}

uint64_t modexp(uint64_t a, uint64_t b, uint64_t m)
{
	return modbin<1, modmul>(a, b, m);
}

int main()
{
	assert(modexp(2, 8, 255) == 1);
	assert(modexp(2, 8, 256) == 0);
	assert(modexp(2, 8, 257) == 256);
	assert(modexp(3, 7, 10000) == 2187);
	assert(modexp(2, 2046, 2047) == 1);
	assert(modexp(123, 456, 789) == 699);
	assert(modexp(3, 1000, 18446744073709551615ULL) == 12311760789144243126ULL);
	assert(modexp(86400, 22157322, 48519018006822) == 40149207423504);
	assert(modexp(8675309, 100018327824, 8621993634251008000) == 3858055581225668161);
	assert(modexp(325284989554104320, 1508436685178379520, 8582294829391072256) == 6354230931838838784);

	return 0;
}
