#!/bin/sh

cat << EOF >/dev/null

Create an identity matrix of the specified size( >= 0).

Some examples:

(1)  =>  [[1]]

(2) => [ [1,0],
         [0,1] ]

       [ [1,0,0,0,0],
         [0,1,0,0,0],
(5) =>   [0,0,1,0,0],
         [0,0,0,1,0],
         [0,0,0,0,1] ]

EOF

eye() {
	for i in $(seq 1 $1); do
		for j in $(seq 2 $i); do
			echo -n "0 "
		done
		echo -n "1 "
		for j in $(seq $((i+1)) $1); do
			echo -n "0 "
		done
		echo
	done
	echo
}

for i in $(seq 1 11); do
	eye $i
done

