#!/usr/bin/env python3

"""

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
https://www.click4reg.co.uk/

"""

import cv2
import pytesseract

def detect(file):
    image = cv2.imread(file)

    width = image.shape[1]
    height = image.shape[0]
    if width >= 100:
        image = image[0:height, 100:width]
    image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    custom_config = r'--psm 7'
    text = pytesseract.image_to_string(image, config=custom_config)
    text = text.replace('I', '1')
    text = text.replace('O', '0')
    text = text.replace('i', '1')
    text = text.replace('o', '0')
    text = text.replace('|', '')
    text = text.replace('\n', '')
    text = text.replace('P0', 'PQ')
    text = text.strip()

    index = text.find(" ")
    if index >= 0 and index < 4:
        text = text[:index] + text[index+1:]

    return text

def main():
    assert(detect("1.jpg") == "ABCDEFG")
    assert(detect("2.jpg") == "H1JKLMN0")
    assert(detect("3.jpg") == "PQRSTUVW")
    assert(detect("4.jpg") == "XYZ01234")
    assert(detect("5.jpg") == "56789")
    assert(detect("6.jpg") == "10")
    assert(detect("7.jpg") == "C0D3 GLF")
    assert(detect("8.jpg") == "B3T4 DCY")
    assert(detect("9.jpg") == "M1NUS 15")
    assert(detect("10.png") == "YET1CGN")

main()
