#!/usr/bin/env Rscript

comment <- r"[

The "Look and say" or "Say what you see" sequence is a series of numbers where each describes the last.

1
11 (one one)
21 (two ones)
1211 (one two, one one)
111221 (one one, one two, two ones)
312211 (three ones, two twos, one one)
and on and on... https://oeis.org/A005150

Anyway, this is a regular code golf challenge (least byte count wins) to make a program that takes two arguments, an initial number and the amount of iterations. For example if you plugged in "1" and "2" the result would be "21". If you plugged in "2" and "4" the result would be "132112". Have fun!

]"

# Ported from @Billywob solution
# https://oeis.org/A005150
looksay <- function(a, n) {
	if (n < 1)
		return (a)
    for (i in 1:n) { 
        r = rle(el(strsplit(a, "")))
        a = paste0(r$l, r$v, collapse="")
    };
	a
}

for (i in 0:5) {
	print(looksay('1', i))
}
