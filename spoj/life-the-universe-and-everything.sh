#!/bin/sh

# Your program is to use the brute-force approach in order to find the Answer to Life, the Universe, and Everything. More precisely... rewrite small numbers from input to output.
# Stop processing input after reading in the number 42. All numbers at input are integers of one or two digits.

while read line
do
	if [ "$line" = "42" ]
	then
		break
	fi
	echo $line
done
