#!/bin/sh

cat << EOF >/dev/null

The code provided is meant to return how many seconds there are in a given number of hours.

But it's not working properly.

## Task

Fix the bug so we can all go home early.

## Notes

The hours passed will be in the range 0 - 1000000

EOF

hours_to_seconds() {
	echo "3600 * $1" | bc
}

hours_to_seconds 0
hours_to_seconds 1
hours_to_seconds 2
hours_to_seconds 3
hours_to_seconds 24

