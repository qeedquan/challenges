#!/usr/bin/env perl -w

=begin comment

The program should print every letter combination (lowercase or uppercase, it doesn't matter) in alphabetic order. It must start with a and the last printed combination should be password.

The output should be:

a b c d e f g h i j k l m n o p q r s t u v w x y z aa ab ac ... passwora passworb passworc password

=end comment
=cut

print $_, $" for a..password
