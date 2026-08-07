#!/usr/bin/env python3

"""

Write code to generate a PDF file containing 6 bingo cards. Winner is the one that uses the shortest code and needs no actions except for installing a library and running the code. (No Save As PDF). Rules are as follows.

The generated PDF file should display accurately in Adobe's PDF reader, Google Chrome and Moxilla Firefox.
Page size should be either Letter or A4.
Cards should be arranged in 3 rows and 2 columns.
Each card should be 3 inches in width and height.
Each card should contain numbers 1 to 25 in random order, arranged in 5x5 squares. The numbers in all 6 cards should be generated independently.
Text size should be 20 points.
Text font should be Helvetica, Arial, Calibri or Open Sans. Text should be centered in each cell.
The bingo cards should have borders with lines having thickness either 0.5 or 1 points.
You can use a pre-existing, publicly available library or package to create a PDF file but the code to generate and arrange bingo cards should be your own.
These is a margin of 20% allowed in each dimension, but all cards should be strictly equal in size.
Reference Answer
Install reportlab using pip install reportlab

from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import letter
from random import shuffle
my_canvas = canvas.Canvas("Bingo Cards.pdf", pagesize=letter)
my_canvas.setLineWidth(1)
my_canvas.setFont('Helvetica', 20)
a = [i for i in range(1, 26)]
for row in range(0, 3):
    for col in range (0, 2):
        shuffle(a)
        rowplace = 252*row
        colplace = 276*col
        my_canvas.line(60+colplace, 36+rowplace, 276+colplace, 36+rowplace)
        my_canvas.line(276+colplace, 36+rowplace, 276+colplace, 246+rowplace)
        my_canvas.line(60+colplace, 36+rowplace, 60+colplace, 246+rowplace)
        my_canvas.line(60+colplace, 246+rowplace, 276+colplace, 246+rowplace)
        for grid in range(0, 5):
            gridplace = grid*43.2
            my_canvas.line(60+colplace, 36+rowplace+gridplace, 276+colplace, 36+rowplace+gridplace)
            my_canvas.line(60+colplace+gridplace, 36+rowplace, 60+colplace+gridplace, 246+rowplace)
            for i in range(0, 5):
                my_canvas.drawCentredString(81.6+colplace+gridplace, 47.6+rowplace+i*43.2, str(a[i+5*grid]))
my_canvas.save()

The result is shown in the following image.

https://i.stack.imgur.com/faqrp.png

"""

from reportlab.pdfgen import canvas
import random

# ported from @SevC_10 solution
def bingo(name):
    b = canvas.Canvas(name)
    b.setLineWidth(1)
    b.setFont('Helvetica', 20)
    n = list(range(25))
    w = 216
    d = 43
    for y in (48, 313, 577):
        for x in (54, 325):
            random.shuffle(n)
            b.lines([(x, y, x + w, y),(x, y, x, y + w)])
            for i in range(25):
                f, g = x + d*(i%5), y + d*(i//5)
                b.lines([(x, g + d, x + w, g + d), (f + d, y, f + d, y + w)])
                b.drawCentredString(f + 22, g + 12, str(n[i] + 1))
    b.save()

def main():
    bingo('bingo.pdf')

main()
