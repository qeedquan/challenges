#!/bin/sh

cat << EOF >/dev/null

The Hamming weight of a string is the number of symbols that are different from the zero-symbol of the alphabet used. There are several algorithms for efficient computing of the Hamming weight for numbers. In this Kata, speaking technically, you have to find out the number of '1' bits in a binary representation of a number. Thus,

hamming_weight(10) # 1010  => 2
hamming_weight(21) # 10101 => 3

The interesting part of this task is that you have to do it without string operation (hey, it's not really interesting otherwise)

;)

EOF

hamming_weight() {
	echo "obase=2; ibase=10; $1" | bc | tr -d -C '1' | wc -c
}

hamming_weight 10
hamming_weight 21
hamming_weight 65535
hamming_weight 5
hamming_weight 543

