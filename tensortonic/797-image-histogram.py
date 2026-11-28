#!/usr/bin/env python3

"""

Count grayscale pixel intensities and return a compact sparse histogram. Scan every pixel, count each intensity, then return only intensities that appear. Each output entry is a two-element list containing the intensity followed by its count. Sort entries by increasing intensity.

Examples
Input: image = [[0, 1], [1, 2]]

Output: [[0, 1], [1, 2], [2, 1]]

Explanation: Intensities zero and two occur once, while intensity one occurs twice.

Input: image = [[128, 128], [128, 128]]

Output: [[128, 4]]

Hint 1
Use a 256-element count list or a dictionary while scanning the pixels.

Hint 2
Build the result in increasing intensity order and skip zero counts.

Requirements
Count every pixel exactly once
Omit intensities whose count is zero
Sort entries by increasing intensity
Return a list of two-element intensity and count lists
Constraints
The image is a nonempty rectangular list
Every pixel is an integer between zero and 255

"""

def image_histogram(image: list) -> list:
    count = {}
    for y in range(len(image)):
        for x in range(len(image[y])):
            pixel = image[y][x]
            if pixel not in count:
                count[pixel] = 0
            count[pixel] += 1
    
    histogram = []
    for pixel in count:
        histogram.append([pixel, count[pixel]])
    return histogram

print(image_histogram([[0, 1], [1, 2]]))
print(image_histogram([[128, 128], [128, 128]]))
