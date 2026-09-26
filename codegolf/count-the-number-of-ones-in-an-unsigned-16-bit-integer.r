#!/usr/bin/env Rscript

comment <- "

Write some statement(s) which will count the number of ones in an unsigned sixteen-bit integer.

For example, if the input is 1337, then the result is 6 because 1337 as a sixteen bit binary number is 0000010100111001, which contains six ones.

"

popcnt <- function(number) {
	sum(intToBits(number) > 0)
}

print(popcnt(1337))
print(popcnt(0xffff))
