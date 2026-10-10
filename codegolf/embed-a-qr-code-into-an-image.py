#!/usr/bin/env python3

"""

QR codes are useful, but ugly. They're artistically visually noisy and illegible to humans. That's why I was fascinated to run across this image by reddit user antarctican:

https://i.sstatic.net/nSgFR8tP.png

This is a drawing of the character Invoker, from the video game Dota 2, with an embedded QR code that scans to a link to the character's page on the Dota 2 website. Today, let's do this for arbitrary strings and images.

Your program will take as input an image and a string of no more than 2953 bytes, 4296 alphanumeric characters, or 7089 digits. It will encode the string into a QR code, then embed that QR code into the image in the way that maintains the greatest possible visual congruence between the code and image. Colour is allowed, though the above image does not use it.

As with the example image, the codes as embedded need not be aligned to the x and y axes, nor be standards-compliant (according to antarctican, the code above isn't either). You are free to rotate, scale, and modify generated codes in order to take advantage of their error correction capacities. But the foremost requirement is that they be scannable in the output. This is a popularity contest, so you will be judged purely by the quality of your images.

"""

import argparse
import cv2
import numpy as np
import qrcode

def embed_qr_code(background_path, output_path, qr_data, position=(50, 50), qr_size=(150, 150)):
    bg_img = cv2.imread(background_path)
    if bg_img is None:
        raise FileNotFoundError(f"Could not load background image from {background_path}")
        
    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_H,
        box_size=10,
        border=1,
    )
    qr.add_data(qr_data)
    qr.make(fit=True)
    
    qr_pil = qr.make_image(fill_color="black", back_color="white").convert('RGB')
    qr_cv = cv2.cvtColor(np.array(qr_pil), cv2.COLOR_RGB2BGR)
    
    qr_resized = cv2.resize(qr_cv, qr_size, interpolation=cv2.INTER_NEAREST)
    
    x, y = position
    h, w, _ = qr_resized.shape
    
    if y + h > bg_img.shape[0] or x + w > bg_img.shape[1]:
        raise ValueError("The QR code position or size exceeds the background image boundaries.")
    
    bg_img[y:y+h, x:x+w] = qr_resized
    
    cv2.imwrite(output_path, bg_img)

def main():
    parser = argparse.ArgumentParser(description='QR code generation')
    parser.add_argument('argv', metavar='', type=str, nargs='+', help='input/output files')
    parser.add_argument('--text', type=str, default='Lorem Ipsum', help='text to embed')
    parser.add_argument('--size', type=int, default=200, help='qr code size')
    parser.add_argument('--xoff', type=int, default=50, help='qr code x image offset')
    parser.add_argument('--yoff', type=int, default=50, help='qr code y image offset')
    args = parser.parse_args()
    if len(args.argv) != 2:
        parser.print_usage()
        return

    embed_qr_code(args.argv[0], args.argv[1], args.text, (args.xoff, args.yoff), (args.size, args.size))

main()
