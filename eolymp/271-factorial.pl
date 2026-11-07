#!/usr/bin/env perl -w

=begin comment

Calculate the factorial of the integer n.

Input
The input contains one integer n (0≤n≤3000).

Output
Output the factorial of n.

Examples
Input #1
3

Answer #1
6

=end comment
=cut

use strict;
use warnings;
use Math::BigInt;

sub solve {
	my ($n) = @_;
	return Math::BigInt->new($n)->bfac();
}

for (1..100) {
	print solve($_) . "\n";
}
