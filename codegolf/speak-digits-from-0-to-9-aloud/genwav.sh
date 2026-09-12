#!/bin/sh

for i in $(seq 0 9); do
	echo $i | espeak-ng -w $i.wav
done
