#!/bin/bash

cat << EOF > /dev/null

This challenge is simple: Take a path to an png image file as input and overwrite that file with a copy of itself rotated 90 degrees clockwise. You may assume that the file has dimensions of 128x128 pixels. You may not use image metadata modifications (like Exif) to rotate the image; the pixels themselves must be transformed.

Examples
Input:

A cat

Output:

A weird cat

This is code-golf, so shortest answer wins.

EOF

if [[ $# != 2 ]]; then
	echo "usage: <input> <output>"
	exit 2
fi

convert $1 -rotate 90 $2
