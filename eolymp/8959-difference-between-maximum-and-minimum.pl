#!/usr/bin/perl -w

=begin comment

Given n integers. Print the difference between the maximum and minimum number.

Input
The first line contains number n (1≤n≤100). The second line contains n integers, each one is no more than 100 by absolute value.

Output
Print the difference between the maximum and minimum number.

Examples

Input #1
7
0 -7 -13 14 -2 13 13

Answer #1
27

=end comment
=cut

use List::Util qw(max);
use List::Util qw(min);

my @array = (0, -7, -13, 14, -2, 13, 13);
print max(@array) - min(@array) . "\n";

