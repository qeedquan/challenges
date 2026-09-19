#!/usr/bin/env python3

"""

You've been called to implement an image detection routine for the ASCII dice roller. Write a program or function so that each time two ASCII dice are rolled, you return the total value shown. To make things trickier, sometimes defective ASCII dice get into the system which have the spots in the wrong positions. That's a possible indicator of fraud, so we need to call a supervisor if that happens.

Input
Lines of text (array of arrays, single string with newlines, stdin, etc) representing two dice side by side in this format:

 ---   ---
|o o| |o  |
|o o| |   |
|o o| |  o|
 ---   ---
Each die is 5x5 characters, with 3 - on the top and bottom, 3 | on each side, and spaces in the corners and filling the middle. The spots are o characters. There is one space between the two dice.

Each die may be rotated. (This only visibly affects the 6, 2 and 3.)

You can assume the structure of the two dice (the | and - and spaces) is correct, and that each face will contain only spaces and o. There may be any number of spots on each face from 0 to 9.

The correct layouts of spots on each die face are as follows:

 ---
|o o|
|o o|
|o o|
 ---
 ---
|ooo|
|   |
|ooo|
 ---
 ---
|o o|
| o |
|o o|
 ---
 ---
|o o|
|   |
|o o|
 ---
 ---
|o  |
| o |
|  o|
 ---
 ---
|  o|
| o |
|o  |
 ---
 ---
|o  |
|   |
|  o|
 ---
 ---
|  o|
|   |
|o  |
 ---
 ---
|   |
| o |
|   |
 ---
Output
If the spots on both faces matches a correct layout (including rotations), return the sum of the two values (8 in the example above). Otherwise, return anything other than a number between 2 and 12. It is acceptable for your program to throw an exception or crash (but not hang) or produce no output in this case.

Scoring
Code golf. Standard rules apply.

Sample data
 ---   ---
|  o| |o  |
|   | |   |
|o  | |  o|
 ---   ---
=> 4

 ---   ---
| o | |o  |
|   | |   |
| o | |  o|
 ---   ---
=> 0

 ---   ---
|o o| |   |
| o | | o |
|o o| |   |
 ---   ---
=> 6

 ---   ---
|  o| |   |
| o | | o |
|o o| |   |
 ---   ---
=> 0

 ---   ---
|   | |   |
|   | | o |
|   | |   |
 ---   ---
=> 0

 ---   ---
|ooo| |o  |
|   | | o |
|ooo| |  o|
 ---   ---
=> 9


 ---   ---
|o o| |  o|
| o | | o |
|o o| |o  |
 ---   ---
=> 8


 ---   ---
|ooo| |o  |
|   | | o |
|o o| |  o|
 ---   ---
=> 0

"""

import cv2
import numpy as np
import glob
import re

class Template:
  def __init__(self, image, value):
    self.image = image
    self.value = value

def load(name):
  file = open(name, "rb")
  text = file.read()
  file.close()
  
  height = text.count(b"\n")
  text = text.replace(b"\n", b"")
  width = len(text) // height 

  image = np.frombuffer(text, dtype=np.uint8)
  image = image.reshape((height, width))
  return image

def load_templates(directory):
  names = glob.glob(directory + "/*.txt")
  templates = []
  for name in names:
    match = re.search(r'\d', name)
    if match == None:
      continue
    image = load(name)
    value = int(match[0])
    templates.append(Template(image, value))
  return templates

def solve(image, templates):
  mask = np.zeros(image.shape)
  total = 0
  for template in templates:
    height, width = template.image.shape[:2]
    matches = cv2.matchTemplate(image, template.image, cv2.TM_SQDIFF)

    (y_coords, x_coords) = np.where(matches == 0)
    for (x, y) in zip(x_coords, y_coords):
        mask[y:y+height, x:x+width+1] = 1

    if len(x_coords) > 0:
      total += template.value

  if np.any(mask == 0):
    return 0

  return total

def main():
  image_1 = load("tests/test_1.txt")
  image_2 = load("tests/test_2.txt")
  image_3 = load("tests/test_3.txt")
  image_4 = load("tests/test_4.txt")
  image_5 = load("tests/test_5.txt")
  image_6 = load("tests/test_6.txt")
  image_7 = load("tests/test_7.txt")
  image_8 = load("tests/test_8.txt")

  templates = load_templates("templates")
  assert(solve(image_1, templates) == 4)
  assert(solve(image_2, templates) == 0)
  assert(solve(image_3, templates) == 6)
  assert(solve(image_4, templates) == 0)
  assert(solve(image_5, templates) == 0)
  assert(solve(image_6, templates) == 9)
  assert(solve(image_7, templates) == 8)
  assert(solve(image_8, templates) == 0)

main()
