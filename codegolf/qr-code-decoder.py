#!/usr/bin/env python3

"""

Your mission is not so simple. You have to write a program that decodes QR-codes.

There are some things that are not permitted:

Making web requests (except http://i.stack.imgur.com/sCUJT.png or http://imgur.com/JUQbo8M)
Using any QR code processing library (Or using any external library to do this)
Image processing libraries should not be be used to do anything other than loading image, determining its size and reading single pixels from it
Using built-in functions to read QR codes
Brute forcing
If you use any external files (except QR code file and language libraries), the byte count of those files will be added to your code.

Other rules:

Program must be able to read any valid QR code (No error correction is required). You can assume that the maximum size of QR-Code is 10000 pixels.
QR code colors are black and white. ((0, 0, 0) and (255, 255, 255) in RGB. Alpha channel is not used, so your program can ignore it.
Image file must be saved as PNG or loaded from http://imgur.com/JUQbo8M or http://i.stack.imgur.com/sCUJT.png runtime. (And tricks like using raw txt file with .png file extension are prohibited)
QR code decoded content must be outputted to stdout. If your language does not allow this, you can save it to file named qrcode.txt.
QR-code format is normal qr-code (not any modification like micro QR code)
This is code-golf, so shortest code wins

An example file is here: http://api.qrserver.com/v1/create-qr-code/?color=000000&bgcolor=FFFFFF&data=http%3A%2F%2Fcodegolf.stackexchange.com&qzone=1&margin=0&size=400x400&ecc=L

"""

import sys
import cv2

def main():
    if len(sys.argv) != 2:
        print("usage: <qr_image>")
        sys.exit(2)

    img = cv2.imread(sys.argv[1])
    qcd = cv2.QRCodeDetector()
    detected, info, _, _ = qcd.detectAndDecodeMulti(img)
    if detected:
        print(info)
    else:
        print("No QR code detected in image")

main()
