#!/usr/bin/perl -w

=begin comment

Since childhood, little Garik was curious about one question: in how many ways can n rooks be placed on a chessboard of size n×n so that they do not attack each other? He spent a long time solving this puzzle for each case; and when he finally solved it, he gave up chess.

How quickly can you solve this problem?

Input
The size of the chessboard n (n≤1000).

Output
Print the answer found by Garik.

Examples
Input #1
2

Answer #1
2

=end
=cut

use Math::BigInt;

sub factorial($) {
	my $n = $_[0];
	my $r = Math::BigInt->new($n)->bfac();
	return $r;
}

print factorial(2) . "\n";
print factorial(1000) . "\n";

