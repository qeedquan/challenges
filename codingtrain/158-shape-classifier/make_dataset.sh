#!/bin/sh

set -e

make_dataset() {
	dir=$1
	frames=$2
	
	rm -rf $dir
	go run gen_dataset.go -frames $frames -dataset $dir

	cd $dir
	for i in *.svg; do
		ffmpeg -i $i $(basename $i .svg).png
	done
	rm -f *.svg

	mkdir circle square triangle
	mv circle*.png circle
	mv square*.png square
	mv triangle*.png triangle
	cd -
}

make_dataset "train" 5000
make_dataset "test" 1000

