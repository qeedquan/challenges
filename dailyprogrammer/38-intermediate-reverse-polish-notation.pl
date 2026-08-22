#!/usr/bin/perl -wl

=begin comment

Reverse Polish Notation(RPN) is a mathematical notation where every operator follows all of its operands. For instance, to add three and four, one would write "3 4 +" rather than "3 + 4". If there are multiple operations, the operator is given immediately after its second operand; so the expression written "3 − 4 + 5" would be written "3 4 − 5 +" first subtract 4 from 3, then add 5 to that.

Transform the algebraic expression with brackets into RPN form.

You can assume that for the test cases below only single letters will be used, brackets [ ] will not be used and each expression has only one RPN form (no expressions like abc)

Test Input:

(a+(b*c))

((a+b)*(z+x))

((a+t)*((b+(a+c)) ^ (c+d)))

Test Output:

abc*+

ab+zx+*

at+bac++cd+ ^ *

=end comment
=cut

use strict;
use warnings;

# ported from @luxgladius solution
sub rpn {
	for my $op ('+','-','*','/','^') {
		my $d = 0;
		for (my $i = 0; $i < @_; $i++) {
			if ($_[$i] eq '(') {
				$d++;
			} elsif ($_[$i] eq ')') {
				$d--;
			}
			next unless $d == 0 && $_[$i] eq $op;
			return (rpn(@_[0 .. $i-1]), rpn(@_[$i+1 .. $#_]), $op);
		}
	}
	if ($_[0] eq '(' && $_[-1] eq ')') {
		return rpn(@_[1 .. $#_-1]);
	}
	return @_;
}

sub solve {
	my $expr = $_[0];
	$expr =~ s/\s+//g;
	return join('', rpn(split //, $expr));
}

print solve("(a+(b*c))");
print solve("((a+b)*(z+x))");
print solve("((a+t)*((b+(a+c)) ^ (c+d)))");
