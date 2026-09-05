#!/bin/sh

set -x

go run dataset.go
cd dataset
for i in *.svg; do
	ffmpeg -i $i $(basename $i .svg).png
done
