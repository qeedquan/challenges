#!/usr/bin/env perl

=begin comment

Definition
From the description on OEIS A006345:

To find a(n), consider either a 1 or a 2. For each, find the longest repeated suffix, that is, for each of a(n)=1,2, find the longest sequence s with the property that the sequence a(1),...,a(n) ends with ss. Use the digit that results in the shorter such suffix. a(1) = 1.

Worked-out Example
a(1)=1.

If a(2)=1, we will have the sequence 1 1 where the longest doubled substring from the end is 1. If a(2)=2 instead, then it would be the empty substring. Therefore a(2)=2.

When n=6, we choose between 1 2 1 1 2 1 and 1 2 1 1 2 2. In the first choice, 1 2 1 is doubled consecutively from the end. In the second choice, it is 2 instead. Therefore, a(6)=2.

When n=9, we choose between 1 2 1 1 2 2 1 2 1 and 1 2 1 1 2 2 1 2 2. In the first choice, the longest doubled consecutive substring is 2 1, while in the second choice 1 2 2 is doubled consecutively at the end. Therefore a(9)=1.

Task
Given n, return a(n).

Specs
n will be positive.
You can use 0-indexed instead of 1-indexed. In that case, please state so in your answer. Also, in that case, n can be 0 also.
Testcases
The testcases are 1-indexed. However, you can use 0-indexed.

n  a(n)
1  1
2  2
3  1
4  1
5  2
6  2
7  1
8  2
9  1
10 1
11 2
12 1
13 2
14 2
15 1
16 1
17 2
18 1
19 1
20 1

References
WolframMathWorld
Obligatory OEIS A006345

=end comment
=cut

sub assert($) {
    die "Assertion failed\n" unless $_[0];
}

# https://oeis.org/A006345
sub gen {
    my $limit = $_[0];
    my $string = "";
    my @list = ();

    digit('1', 0);

    for (2 .. $limit) {
        my ($repeat, $digit) = ($string =~ m{ ^ (.*) ([12]) \1 }x) or die;
        digit($digit eq '1' ? '2' : '1', length($repeat) + 1);
    }

    sub digit {
        my ($digit, $repeat) = @_;
        $string = $digit . $string;
        push @list, $digit;
    }

    return @list;
}

sub main {
    my @table = (1, 2, 1, 1, 2, 2, 1, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 1, 1, 2, 2, 1, 2, 1, 1, 2, 2, 1, 1, 1, 2, 1, 1, 2, 2, 1, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 1, 1, 2, 2, 1, 2, 1, 1, 2, 2, 1, 2, 2, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, 2, 1, 2, 2, 1, 1, 2, 1, 2, 2, 1, 2, 1, 1, 2, 2, 1, 2, 2, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, 2, 1, 2);
    my @values = gen($#table + 1);

    for my $i (0 .. $#table) {
        assert($table[$i] == $values[$i]);
    }
}

main();
