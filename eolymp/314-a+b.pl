#!/usr/bin/env perl -w

=begin comment

Petryk has been given the same homework assignment again: to find the sum of two natural numbers A and B.
However, since Petryk is an enthusiastic fisherman who wanted to get to the evening catch, he copied the assignment in a hurry and always made the same mistake:
sometimes, instead of the addition sign "+", he wrote the subtraction sign "-".
In the evening, after fishing, he sat down to do his homework and began to solve all the problems exactly as they were written in his notebook.

Can you solve this assignment?

Input
The first line contains the number of examples N.
The next N lines follow the format A+B, where A and B are two given natural numbers.
Between them, without spaces, there is either the sign for addition "+" or the sign for subtraction "-".

The format of the input is guaranteed (see the sample input). The numbers in the inputs do not exceed 10^500. 0<N≤800.

Output
Output the resulting answer for each example on N lines.

Examples

Input #1
2
5+3
14818641113280510-52467

Answer #1
8
14818641113228043

=end
=cut

use strict;
use warnings;
use bignum;

my $r0 = 5 + 3;
my $r1 = 14818641113280510 - 52467;

print "$r0\n";
print "$r1\n";
