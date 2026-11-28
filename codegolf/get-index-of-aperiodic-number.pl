#!/usr/bin/perl -w

=begin comment

https://codegolf.stackexchange.com/questions/278622/a121016-numbers-whose-binary-expansion-is-properly-periodic-or-a328594-number
related

Update: 2026-03-29
sequence applies.

Task
sequence problem with following sequence:

Given an unsigned integer,

if it is in A328594 output its index; or
if it is in A121016 do step 1 for what is repeated.
The index to output is in either 0-indexed or 1-indexed, and must be consistent.

I/O format
See /tags/sequence/info.

A121016: Numbers whose binary expansion is properly periodic.
For example, 204=(1100 1100)_2 and 292=(100 100 100)_2 belong to the sequence, but 30=(11110)_2 cannot be split into repeating periods.

A328594: Numbers whose binary expansion is aperiodic.
It's complement of A121016; every nonnegative integer not belonged to A121016 is A328594, for example 30 is in but 204, 292 are not.

Example output
Since 204 and 292 are, in binary, periodic numbers of binary 1100 and 100 (aka decimal 12 and 4) respectively, the function should return their occurrences in A328594: 9 and 3, if 0-indexed. Since 30 is in A328594, the function should output 26, if 0-indexed.

Test cases for first 200 unsigned integers
This is 0-indexed version.

0, 1, 2, 1, 3, 4, 5, 1, 6, 7,
2, 8, 9, 10, 11, 1, 12, 13, 14, 15,
16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
26, 1, 27, 28, 29, 30, 3, 31, 32, 33,
34, 35, 2, 36, 37, 4, 38, 39, 40, 41,
42, 43, 44, 45, 5, 46, 47, 48, 49, 50,
51, 52, 53, 1, 54, 55, 56, 57, 58, 59,
60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
110, 111, 112, 113, 114, 115, 116, 1, 117, 118,
119, 120, 121, 122, 123, 124, 6, 125, 126, 127,
128, 129, 130, 131, 132, 133, 134, 135, 136, 137,
138, 139, 140, 7, 141, 142, 143, 144, 145, 146,
147, 148, 149, 150, 151, 152, 153, 154, 155, 156,
2, 157, 158, 159, 160, 161, 162, 163, 164, 165,
166, 167, 168, 169, 170, 171, 172, 8, 173, 174,
175, 176, 177, 178, 179, 180, 181, 182, 183, 184,
Non-competing Perl 5 answer, 457 bytes
use v5.28;

my $n_aperiodics = 0;
my %s_aperiodic_bins_idx;

for (my $i = 0; ; $i++) {
  my $output = $n_aperiodics;
  my $s = bin($i);
  if ($s =~ m/^([01]+?)\1+$/) {
    $output = $s_aperiodic_bins_idx{$1};
  } else {
    $s_aperiodic_bins_idx{$s} = $n_aperiodics;
    $n_aperiodics++;
  }
  print $output, ", ";
  print $/ unless ($i+1) % 10;
}

sub bin {
  my ($n) = @_;
  my $ret = $n & 1;
  while ($n >>= 1) {
    $ret = ($n & 1) . $ret;
  }
  $ret;
}

=end comment
=cut

my $n_aperiodics = 0;
my %s_aperiodic_bins_idx;

for (my $i = 0; ; $i++) {
	my $output = $n_aperiodics;
	my $s = bin($i);
	if ($s =~ m/^([01]+?)\1+$/) {
		$output = $s_aperiodic_bins_idx{$1};
	} else {
		$s_aperiodic_bins_idx{$s} = $n_aperiodics;
		$n_aperiodics++;
	}
	print $output, ", ";
	print $/ unless ($i+1) % 10;
}

sub bin {
	my ($n) = @_;
	my $ret = $n & 1;
	while ($n >>= 1) {
		$ret = ($n & 1) . $ret;
	}
	$ret;
}
