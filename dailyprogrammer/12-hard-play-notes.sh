#!/bin/sh

cat << EOF >/dev/null

Write a program which will take string inputs "A", "B", "C", "D", "E", "F", and "G", and make the corresponding notes, in any method of your choosing.

Thanks to electric_machinery for this challenge!

EOF

for n in A1 A2 A3 A4 A5 B1 B2 B3 B4 B5 C1 C2 C3 C4 C5 D1 D2 D3 D4 D5 F1 F2 F3 F4 F5 G1 G2 G3 G4 G5; do
	sox -n $n.wav synth 1 pluck $n repeat 1
done

