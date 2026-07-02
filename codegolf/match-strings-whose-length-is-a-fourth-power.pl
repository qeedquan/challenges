#!/usr/bin/env perl

=begin comment

Within the scope of this question, let us consider only strings which consist of the character x repeated arbitrary number of times.

For example:

<empty>
x
xx
xxxxxxxxxxxxxxxx
(Well, actually it doesn't have to be x - any character is fine as long as the whole string only has 1 type of character)

Write a regex in any regex flavor of your choice to match all strings whose length is n4 for some non-negative integer n (n >= 0). For example, strings of length 0, 1, 16, 81, etc. are valid; the rest are invalid.

Due to the technical limitation, values of n bigger than 128 is hard to test against. However, your regex should logically work correctly regardless.

Note that you are not allowed to execute arbitrary code in your regex (to Perl users). Any other syntax (look-around, back-reference, etc.) is allowed.

Please also include a short explanation about your approach to the problem.

(Please don't paste auto generated regex syntax explanation, since they are useless)

This is code-golf. For each regex flavor, the regex compatible with that flavor having the shortest length in bytes wins in that category. The shortest of all of the answers wins overall.

Note that this challenge was originally posted as a puzzle, not code-golf. But the actual answers basically treated it as code-golf anyway, just without actually specifying their sizes in bytes. That has now been fixed, to give the challenge objective winning criteria and make it on-topic for CGCC.

=end comment
=cut

use strict;

=begin comment

@primo

This is, in my opinion, one of the most interesting problems on the site. I need to thank deadcode for bumping it back up to the top.

^((^|xx)(^|\3\4\4)(^|\4x{12})(^x|\1))*$
39 bytes, without any conditionals or assertions... sort of. The alternations, as they're being used (^|), are a type of conditional in a way, to select between "first iteration," and "not first iteration."

This regex can be seen to work here: http://regex101.com/r/qA5pK3/1

PCRE interprets the regex correctly, and it has also been tested in Perl up to n = 128, including n4-1, and n4+1.

Definitions

The general technique is the same as in the other solutions already posted: define a self-referencing expression which on each subsequent iteration matches a length equal to the next term of the forward difference function, Df, with an unlimited quantifier (*). A formal definition of the forward difference function:

D_f(n) = f(n+1) - f(n)

Additionally, higher order difference functions may also be defined:

D2_f(n) = D_f(n + 1) - D_f(n)

Or, more generally:

Dk_f(n) = Dk-1_f(n+1) - Dk-1_f(n) = Sum[i=0, k] (-1)^i * binomial(k, i) * f(n+k-i)

The forward difference function has a lot of interesting properties; it is to sequences what the derivative is to continuous functions. For example, Df of an nth order polynomial will always be an n-1th order polynomial, and for any i, if Dfi = Dfi+1, then the function f is exponential, in much the same way that the derivative of ex is equal to itself. The simplest discrete function for which f = Df is 2n.

f(n) = n^2

Before we examine the above solution, let's start with something a bit easier: a regex which matches strings whose lengths are a perfect square. Examining the forward difference function:

Df=[1,3,5,7,9,…]=2n+1

Meaning, the first iteration should match a string of length 1, the second a string of length 3, the third a string of length 5, etc., and in general, each iteration should match a string two longer than the previous. The corresponding regex follows almost directly from this statement:

^(^x|\1xx)*$
It can be seen that the first iteration will match only one x, and each subsequent iteration will match a string two longer than the previous, exactly as specified. This also implies an amazingly short perfect square test in perl:

(1x$_)=~/^(^1|11\1)*$/
This regex can be further generalized to match any n-gonal length:

Triangular numbers:
^(^x|\1x{1})*$

Square numbers:
^(^x|\1x{2})*$

Pentagonal numbers:
^(^x|\1x{3})*$

Hexagonal numbers:
^(^x|\1x{4})*$

etc.

f(n) = n^3

Moving on to n3, once again examining the forward difference function:

Df=[1,7,19,37,61,…]=3n^2+3n+1

It might not be immediately apparent how to implement this, so we examine the second difference function as well:

D2f=[6,12,18,24,30,…]=6n+6

So, the forwards difference function does not increase by a constant, but rather a linear value. It's nice that the initial ('-1th') value of Df2 is zero, which saves an initialization on the second iteration. The resulting regex is the following:

^((^|\2x{6})(^x|\1))*$
The first iteration will match 1, as before, the second will match a string 6 longer (7), the third will match a string 12 longer (19), etc.

f(n) = n^4

The forward difference function for n^4:

Df=[1,15,65,175,369,…]=4n3−6n2+4n−1

The second forward difference function:

D2f=[14,50,110,194,302,…]=12n2−24n+14

The third forward difference function:

D3f=[36,60,84,108,132,…]=24n+36

Now that's ugly. The initial values for Df2 and Df3 are both non-zero, 2 and 12 respectively, which will need to be accounted for. You've probably figured out by now that the regex will follow this pattern:

^((^|\2\3{b})(^|\3x{a})(^x|\1))*$
Because the Df3 must match a length of 12 on the second iteration, a is necessarily 12. But because it increases by 24 each term, the next deeper nesting must use its previous value twice, implying b = 2. The final thing to do is initialize the Df2. Because Df2 influences Df directly, which is ultimately what we want to match, its value can be initialized by inserting the appropriate atom directly into the regex, in this case (^|xx). The final regex then becomes:

^((^|xx)(^|\3\4{2})(^|\4x{12})(^x|\1))*$
Higher Orders

A fifth order polynomial can be matched in with the following regex:
^((^|\2\3{c})(^|\3\4{b})(^|\4x{a})(^x|\1))*$

f(n) = n^5 is a fairly easy excercise, as the initial values for both the second and fourth forward difference functions are zero:

^((^|\2\3)(^|\3\4{4})(^|\4x{30})(^x|\1))*$
For six order polynomials:
^((^|\2\3{d})(^|\3\4{c})(^|\4\5{b})(^|\5x{a})(^x|\1))*$

For seventh order polynomials:
^((^|\2\3{e})(^|\3\4{d})(^|\4\5{c})(^|\5\6{b})(^|\6x{a})(^x|\1))*$

etc.

Note that not all polynomials can be matched in exactly this way, if any of the necessary coefficients are non-integer. For example, n6 requires that a = 60, b = 8, and c = 3/2. This can be worked around, in this instance:

^((^|xx)(^|\3\6\7{2})(^|\4\5)(^|\5\6{2})(^|\6\7{6})(^|\7x{60})(^x|\1))*$
Here I've changed b to 6, and c to 2, which have the same product as the above stated values. It's important that the product doesn't change, as a·b·c·… controls the constant difference function, which for a sixth order polynomial is Df6. There are two initialization atoms present: one to initialize Df to 2, as with n4, and the other to initialize the fifth difference function to 360, while at the same time adding in the missing two from b.

=end comment
=cut

sub ispow4 {
	my $regex = qr/^((^|xx)(^|\3\4\4)(^|\4x{12})(^x|\1))*$/mp;
	my $str = $_[0];
	if ($str =~ /$regex/g) {
		return 1;
	}
	return 0;
}

sub main {
	foreach (0..100000) {
		my $str = "x" x $_;
		if (ispow4($str)) {
			print($_, "\n");
		}
	}
}

main
