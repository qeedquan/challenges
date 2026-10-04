#!/usr/bin/perl -w

=begin comment

Description

In how many ways can you choose k elements out of n elements, not taking order into account?
Write a program to compute this number.

Input

The input will contain one or more test cases.
Each test case consists of one line containing two integers n (n>=1) and k (0<=k<=n).
Input is terminated by two zeroes for n and k.

Output

For each test case, print one line containing the required number. This number will always fit into an integer, i.e. it will be less than 231.
Warning: Don't underestimate the problem. The result will fit into an integer - but if all intermediate results arising during the computation will also fit into an integer depends on your algorithm. The test cases will go to the limit.

Sample Input

4 2
10 5
49 6
0 0

Sample Output

6
252
13983816
Source

Ulm Local 1997

=end comment
=cut

use strict;
use warnings;
use List::Util qw(min);

sub assert($) {
	die "Assertion failed\n" unless $_[0];
}

sub binomial {
	my ($n, $k) = ($_[0], $_[1]);
	if ($k < 0 || $k > $n) {
		return 0;
	}
	if ($k == 0 || $k == $n) {
		return 1;
	}

	$k = min($k, $n - $k);
	my $c = 1;
	for my $i (0..$k-1) {
		$c = $c * ($n - $i) / ($i + 1);
	}
	return $c;
}

sub main {
	assert(binomial(4, 2) == 6);
	assert(binomial(10, 5) == 252);
	assert(binomial(49, 6) == 13983816);
}

main
