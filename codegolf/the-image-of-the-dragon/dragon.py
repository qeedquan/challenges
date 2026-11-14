#!/usr/bin/env python3

"""

I saw a cool gif of the twin dragon curve made from a square, and wondered what would happen if we started from another base image. So I wrote a program to do this.

https://giphy.com/gifs/oMEwTCaYezkNa

It's so cool that I thought it would be fun to do it as a challenge.

Task
You will take in a square image with an edge length that is a power of 2 (greater than 4).

To make this image you should start by dividing your image into 4 vertical bands of equal size and shifting adjacent bands one 8th of the size of the image in opposite directions (shifted bands should wrap around to the other side). You should then repeat this process each time splitting the image into twice as many divisions and shifting by half as far as the previous time. Each iteration you should alternate between vertical and horizontal shifts. You should iterate until the shift requires you to shift by a fractional number of pixels (this will always be 1/2) at which point you are done.

When shifting vertically odd numbered bands from the left (zero-indexed) should shift down while even shift up. When shifting horizontally odd numbered bands from the top should shift left while even numbered bands should shift right.

You need only output/display the end result of the transformation, not all the intermediate steps like in the gif.

This is code-golf so the goal is to minimize the length of you source code as measured in bytes.

Test cases
I have a working script that can make these images so I thought I would let you guys choose the images for the test cases. So if you have a square image that is a power of 2 wide that you would like to see become dragonified. Feel free to send it to me and I'll make it a test case.

You should also test on a plain white or solid black image so that you can determine whether or not pixels are disappearing or not.

"""

from PIL import Image
import sys

if len(sys.argv) < 2:
    print("usage: file")
    sys.exit(0)

# Ported from @dieter solution
image = Image.open(sys.argv[1])
width, height = image.size

blocks_per_round = 4
step = width // 8
direction = 1
orientation = 1

while step > 1:
    output = image.copy()
    if direction == 1:
        output.paste(image, (0, width - step))
        output.paste(image, (0, step - width))
    else:
        output.paste(image, (width - step, 0))
        output.paste(image, (step - width, 0))

    direction *= -1
    offset = 0

    for _ in range(blocks_per_round):
        if orientation % 2:
            crop_box = (offset, 0, offset + 2 * step, width)
            destination = (offset, direction * step)
        else:
            crop_box = (0, offset, width, offset + 2 * step)
            destination = (direction * step, offset)

        output.paste(image.crop(crop_box), destination)
        direction *= -1
        offset += 2 * step

    step //= 2
    image = output
    orientation += 1
    blocks_per_round *= 2

image.show()
