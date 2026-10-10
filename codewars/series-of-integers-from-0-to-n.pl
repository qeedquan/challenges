#!/usr/bin/perl -w

=begin comment

Write a function generateIntegers/generate_integers that accepts a single argument n/$n and generates an array containing the integers from 0 to n/$n inclusive.

For example, generateIntegers(3)/generate_integers(3) should return [0, 1, 2, 3].

n/$n can be any integer greater than or equal to 0.

=end
=cut

use strict;

sub generate_integers {
	return (0..$_[0]);
}

print generate_integers(3), "\n";
print generate_integers(10), "\n";

