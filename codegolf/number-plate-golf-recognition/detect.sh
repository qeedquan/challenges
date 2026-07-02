#!/bin/sh

cat << EOF >/dev/null

Introduction
You're working on a government programming team, who have been programming the speed cameras. However, the group of people who have programmed the speed calculator have taken up too much space, so you have to make the number plate recognition software as small as possible.

Challenge
Given an image of a number plate, return the text on the plate.

Number plates
The following are all of the characters which your program must recognise:

ABCDEFG
https://i.sstatic.net/sMT8h.jpg

H1JKLMN0
https://i.sstatic.net/mlGmd.jpg

PQRSTUVW
https://i.sstatic.net/9PplD.jpg

XYZ01234
https://i.sstatic.net/MT3Xb.jpg

56789
https://i.sstatic.net/RDbR0.jpg

Note
On British number plates, the characters for I (i) and 1 (one) are the same and the characters for O (o) and 0 (zero) are the same. For that reason, always assume characters are the numbers. I.e. the following number plate is 10 (one zero):

10
https://i.sstatic.net/Qatfa.jpg

Examples
C0D3 GLF
https://i.sstatic.net/njTF4.jpg

B3T4 DCY
https://i.sstatic.net/Eoh40.jpg

M1NUS 15
https://i.sstatic.net/EQcA0.jpg

YET1CGN
https://i.sstatic.net/SuYt0.png

Other rules
Internet access and OCR libraries and functions are disallowed.

The number plates will always look identical to the ones shown above. All number plates will be roughly same size (there will be some inaccuracies due to cropping method).

If you require lossless PNG versions of any number plates, I will supply them to you.

Scoring
The shortest program in bytes wins.

All number plates are screenshots of the search bar at this site
http://www.click4reg.co.uk/

EOF

for i in *.png *.jpg; do
	echo "$i: "
	echo "Tesseract: " $(tesseract $i stdout -l eng --psm 13 | cut -d ' ' -f2)
	echo "EasyOCR: " $(easyocr -l en -f $i --detail=0 --gpu=False)
	echo
done
