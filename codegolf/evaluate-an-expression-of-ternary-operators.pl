#!/usr/bin/env perl

=begin comment

Consider a grammar over the alphabet {0, 1, ?, :} defined by the production rule

s → 0 ┃ 1 ┃ 0 ? s : s ┃ 1 ? s : s

Given a string generated from s, parse it as an expression where ?: is right-associative (for example, a?B?X:Y:c?d:e?f:g means a?(B?X:Y):(c?d:(e?f:g))) and evaluate it with the following semantics:

eval(0) = 0
eval(1) = 1
eval(0?a:b) = eval(b)
eval(1?a:b) = eval(a)
If the result is 0, output some fixed value; if the output is 1, output a different fixed value. Specify your chosen output values (e.g. 0/1, or False/True) in your answer.

Test cases
0 -> 0
1 -> 1
0?0:1 -> 1
0?1:0 -> 0
1?0:1 -> 0
1?1:0 -> 1
0?1?0:1:1 -> 1
1?0?1:1:1 -> 1
1?0:1?0:1?1:1 -> 0
1?1?1:0?1?0:0:0:0 -> 1
1?0:1?0?1:1?1:0:1?1?1:1:1?0:1 -> 0
1?1?1:0?0?1:1:0?1:0:1?1?0?0:0:1?1:0:0?1?0:1:1?0:1 -> 1
0?0?1?0?0:1:0?0:0:0?0?1:1:1?0:1:0?0?0?1:0:0?1:1:1?1?0:1:1 -> 0

Rules
You may not use language built-ins that interpret strings as code in some programming language and run it (such as JavaScript/Perl/Ruby/Python’s eval).
That said, your code doesn’t actually have to parse and then evaluate the input string. You can take any approach the achieves equivalent results and doesn’t violate the previous rule.
Your program will be checked against perl -le 'print eval<>'.
The shortest code (in bytes) wins.

=end comment
=cut

use strict;
use warnings;

sub assert($) {
    die "Assertion failed\n" unless $_[0];
}

assert(eval("0") == 0);
assert(eval("1") == 1);
assert(eval("0?0:1") == 1);
assert(eval("0?1:0") == 0);
assert(eval("1?0:1") == 0);
assert(eval("1?1:0") == 1);
assert(eval("0?1?0:1:1") == 1);
assert(eval("1?0?1:1:1") == 1);
assert(eval("1?0:1?0:1?1:1") == 0);
assert(eval("1?1?1:0?1?0:0:0:0") == 1);
assert(eval("1?0:1?0?1:1?1:0:1?1?1:1:1?0:1") == 0);
assert(eval("1?1?1:0?0?1:1:0?1:0:1?1?0?0:0:1?1:0:0?1?0:1:1?0:1") == 1);
assert(eval("0?0?1?0?0:1:0?0:0:0?0?1:1:1?0:1:0?0?0?1:0:0?1:1:1?1?0:1:1") == 0);

