#!/usr/bin/env perl -w

=begin comment

Create a Function that takes one parameter and returns its square root rounded to 5 decimal places. You are not allowed to use the Math.sqrt() or the Math.pow() methods.

Trailing zeros should be left out. For example

squareRoot(39) // => 6.245;

rather than

squareRoot(39) // => 6.24500;

=end comment
=cut

use strict;

my @i = (1..100);
for (@i) {
	printf("%.0f: %.3f\n", $_, sqrt($_));
}

