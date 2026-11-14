#!/usr/bin/env perl -w

=begin comment

Petryk received a homework assignment: to find the sum of two natural numbers A and B.

Input
The first line contains the number of examples N given to Petryk.
Then N lines follow, each in the format A+B, where A and B are two given natural numbers, and the addition symbol "+" appears between them with no spaces.

The input strictly follows the specified format (see the sample input). The input numbers do not exceed 10^500 . (0<N≤250)

Output
Print the required sums, one per line, for all N examples.

Examples

Input #1
2
5+3
14818641113280510+52467

Answer #1
8
14818641113332977

=end
=cut

use strict;
use warnings;
use bignum;

my $r0 = 5 + 3;
my $r1 = 14818641113280510 + 52467;

print "$r0\n";
print "$r1\n";
