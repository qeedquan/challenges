#!/usr/bin/env perl -w

=begin comment

Given nonnegative integers m and n. Find their product.

Input
The first line contains the number m, the second n (0≤m,n≤10^2500).

Output
Print the product of two numbers.

Examples

Input #1
9876543210
1023456789

Answer #1
10108215200126352690

=end
=cut

use strict;
use warnings;
use bignum;

my $r0 = 9876543210 * 1023456789;

print "$r0\n";
