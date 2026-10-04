#!/usr/bin/perl -w

=begin comment

Two complex numbers are given. Find their product or quotient.

Input
Each line contains an example of multiplication or division of complex numbers. The complex number is given in the format a+bi or a−bi, where a is integer, b is non-negative integer. The real and imaginary part of each complex number is no more than 10^9 by absolute value.

Output
For each input example, print in a separate line the answer. The real and imaginary part of the complex number should be presented with two decimal places.

Examples

Input #1
2+3i * 7-4i
12-4i / 5-4i
-1-1i * -1-1i
5-2i / -7+12i

Answer #1
26.00+13.00i
1.85+0.68i
0.00+2.00i
-0.31-0.24i

=end
=cut

use strict;
use warnings;
use Math::Complex;

my $z1 = (2+3*i) * (7-4*i);
my $z2 = (12-4*i) / (5-4*i);
my $z3 = (-1-1*i) * (-1-1*i);
my $z4 = (5-2*i) / (-7+12*i);
print $z1 . "\n";
print $z2 . "\n";
print $z3 . "\n";
print $z4 . "\n";
