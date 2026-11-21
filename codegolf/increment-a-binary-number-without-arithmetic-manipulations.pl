#!/usr/bin/perl -wpl

# Input: binary string
#
# Output: binary string that represents the binary input + 1
#
# Example: Given 10111 as an input, output 11000
#
# Limitations: Can't use arithmetic operators or functions (like + - * /)
#
# Criterion: code-golf, the shortest code wins the big imaginary award.

# ported from @Kjetil S solution
s/0$/1/ || s/0?(1+)$/1 . (0 x length $1)/e
