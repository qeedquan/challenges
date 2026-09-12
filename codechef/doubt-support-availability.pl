#!/usr/bin/perl

=begin comment

Problem
On the CodeChef Practice page, problems with difficulty ≤1600
≤1600 now have Doubt Support — you can go to the problem page and get your queries answered by an experienced CodeChef Doubt Solver through the "Doubt Support" tab.

Given the difficulty of a problem, output whether this problem has Doubt Support or not.

Input Format
The input consists of a single integer, D, which is the difficulty of the problem.

Output Format
Output Yes if the problem has Doubt Support, or No if it doesn't.

Each letter of the output may be printed in either lowercase or uppercase. For example, the strings yes, YeS, and YES will all be treated as equivalent.

Constraints
1≤D≤5000

Sample 1:
Input
800
Output
Yes
Explanation:
800≤1600. Hence, this problem has Doubt Support.

Sample 2:
Input
1600
Output
Yes
Explanation:
1600≤1600. Hence, this problem has Doubt Support.

Sample 3:
Input
1601
Output
No
Explanation:
1601≰1600. Hence, this problem does not have Doubt Support.

Sample 4:
Input
5000
Output
No
Explanation:
5000≰1600. Hence, this problem does not have Doubt Support.

=end comment
=cut

use strict;
use warnings;

sub assert($) {
    die "Assertion failed\n" unless $_[0];
}

sub doubt_support {
	return ($_[0] <= 1600) ? "Yes" : "No";
}

assert(doubt_support(800) eq "Yes");
assert(doubt_support(1600) eq "Yes");
assert(doubt_support(1601) eq "No");
assert(doubt_support(5000) eq "No");
