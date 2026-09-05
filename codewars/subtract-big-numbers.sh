#!/bin/sh

cat << EOF >/dev/null

Subtract big numbers passed as strings

Arguments are passed as strings
Result should be returned as string
3 - 2 should return 1 while 2 - 3 should return -1
Zeros should not preceed a number! 02, -02, 0001 are invalid
Very large numbers will be tested
Note: 100 randomly generated tests

EOF

sub() {
	echo "$1 - $2" | bc
}

sub 248284925892 21331238924842942
sub -248284925892 -213312389248429428982597395739875387549275017845027652
