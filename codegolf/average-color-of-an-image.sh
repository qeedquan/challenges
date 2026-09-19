#!/bin/sh

cat << EOF >/dev/null

Average color of an image
Scientists have been able to determine the average color of the universe but in how many bytes can we find the average color on an image?

Your task
Your input will be a single image which you will need to find the average of the colors in the image and output a hex color-string (#??????). The image can be any of the following formats

JPEG/JFIF
JPEG 2000
TIFF
GIF
BMP
PNG
PNM
PPM
The input can also be taken as a URL/URI to the image.

Build-in functions which calculate averages or sample the image at once such as ImageMeasurements are not allowed.

Examples
Results will differ slightly depending on how you calculate the average and which color models you use. I've added RGB and LCH (HSV) values for the images below.

https://i.sstatic.net/dkShg.jpg
output: #53715F RGB, may also be #3B7D3D LCH (HSV)

https://i.sstatic.net/V5VAR.jpg
output: #8B7D41 RGB, #96753C LCH (HSV)

EOF

if [ $# -eq 0 ]; then
	echo "usage: <image>"
	exit 2
fi

# @SteelRaven
# ImageMagick scales image to one pixel which contains average of the colors in the image then outputs it as text.
convert $1 -scale 1x1\! txt:- | egrep -o '#\w+'
