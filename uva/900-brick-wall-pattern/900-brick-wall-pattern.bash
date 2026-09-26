#!/bin/bash

fib() {
	n=$1
	a=1
	b=1
	for ((i = 0; i < n; i++))
	do
		c=$((a + b))
		a=$b
		b=$c
	done
	echo $a
}

for i in $(seq 1 20)
do
	fib $i
done
