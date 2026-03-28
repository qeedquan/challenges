#!/usr/bin/env perl -w

=begin comment

Complete the method that takes a boolean value and return a "Yes" string for true, or a "No" string for false.

=end comment
=cut

use strict;

sub bool2word {
	my ($bool) = @_;
	return ($bool) ? "yes" : "no";
}

print bool2word(1) . "\n";
print bool2word(0) . "\n";

print bool2word("x") . "\n";
print bool2word("") . "\n";

