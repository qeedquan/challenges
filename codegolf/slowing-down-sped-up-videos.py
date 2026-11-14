#!/usr/bin/env python3

"""

Summary
Videos which are sped up every time a particular word is said exist for everything from the Bee Movie to the classic Rick Roll. The goal for this challenge is to figure out how much you'd have to slow down the sped-up video in order to match the duration of the original video.

For example, the original Bee Movie has a duration of 95 minutes. The sped up version is 5:40 or ~5.667 minutes. 95/5.667 = 16.76. We'd have to play the sped up version 16.76x slower in order for the overall duration to match the original movie.

Inputs
Your program must take in 3 inputs:

The duration of the original video (Bee Movie was 95 minutes)
The speedup factor per occurence (Bee Movie was 15% or .15)
A list of timestamps of occurrences (Bee movie has more than I care to look up/list)
The exact way these are passed in is flexible: 3 separate parameters is my default assumption, but if you want to take in a single list of values and pop the duration/speedup factor off the front that's fine, or take a single string in JSON or whatever format floats your boat, etc.

For the duration: seconds, minutes, or some builtin duration type are all fine.

For the speedup factor of the bee movie, any of 15, .15, or 1.15 could be used to represent the 15% speedup.

You can assume the occurrences are ordered in the most convenient manner, but there can be duplicate values (such as multiple characters talking over one another in a movie).

Output
A scaling factor to make the durations of the original and sped-up video match. The exact format is flexible.

Examples
{"duration": 10, "speedup-factor": 2, "occurrences": [1,2,3,4,5,6,7,8,9]} -> {"slowdown-factor": 5.004887585532747}
{"duration": 500, "speedup-factor": 1.15, "occurrences": [1,2,3, ..., 497, 498, 499]} -> {"slowdown-factor": 65.21739130434779}
{"duration": 100, "speedup-factor": 3, "occurrences": [0]} -> {"slowdown-factor": 3}
{"duration": 100, "speedup-factor": 3, "occurrences": [0, 0, 0]} -> {"slowdown-factor": 27}
{"duration": 100, "speedup-factor": 100, "occurrences": [99.99]} -> {"slowdown-factor": 1.0000990098}
Notes: First two generated programmatically with 100/(sum(1/(2**i) for i in range(10))) and 500/(sum(1/(1.15**i) for i in range(500))). 4th example: 3 * 3 * 3 = 27x speedup, occurring right at the start of the video. Last example calculated by hand with 100/(99.99 + .01/100)

Note
I've kept most of the examples fairly simple, but I believe they cover all the relevant edge cases (a program which solves all of them should be totally correct). If I've left things ambiguous or difficult to parse, let me know and I'll add comments!

"""

from functools import reduce

"""

Ported from @xnor solution

Takes timestamps sorted in descending order.

The idea is to compute the video duration as a polynomial in the inverse speedup rate 1/r using
Horner's method with coefficients given by the sorted timestamps.
This avoids needing to explicitly take the differences of consecutive timestamps.
We then divide the duration of the original video by the resulting duration to get the desired slowdown factor.

"""

def sped(m, r, l):
    return m//reduce(lambda u, x: u//r + x - x//r, l, m)

print(sped(10.0, 2.0, [9, 8, 7, 6, 5, 4, 3, 2, 1]))
print(sped(500.0, 1.15, [499, 498, 497, 496, 495, 494, 493, 492, 491, 490, 489, 488, 487, 486, 485, 484, 483, 482, 481, 480, 479, 478, 477, 476, 475, 474, 473, 472, 471, 470, 469, 468, 467, 466, 465, 464, 463, 462, 461, 460, 459, 458, 457, 456, 455, 454, 453, 452, 451, 450, 449, 448, 447, 446, 445, 444, 443, 442, 441, 440, 439, 438, 437, 436, 435, 434, 433, 432, 431, 430, 429, 428, 427, 426, 425, 424, 423, 422, 421, 420, 419, 418, 417, 416, 415, 414, 413, 412, 411, 410, 409, 408, 407, 406, 405, 404, 403, 402, 401, 400, 399, 398, 397, 396, 395, 394, 393, 392, 391, 390, 389, 388, 387, 386, 385, 384, 383, 382, 381, 380, 379, 378, 377, 376, 375, 374, 373, 372, 371, 370, 369, 368, 367, 366, 365, 364, 363, 362, 361, 360, 359, 358, 357, 356, 355, 354, 353, 352, 351, 350, 349, 348, 347, 346, 345, 344, 343, 342, 341, 340, 339, 338, 337, 336, 335, 334, 333, 332, 331, 330, 329, 328, 327, 326, 325, 324, 323, 322, 321, 320, 319, 318, 317, 316, 315, 314, 313, 312, 311, 310, 309, 308, 307, 306, 305, 304, 303, 302, 301, 300, 299, 298, 297, 296, 295, 294, 293, 292, 291, 290, 289, 288, 287, 286, 285, 284, 283, 282, 281, 280, 279, 278, 277, 276, 275, 274, 273, 272, 271, 270, 269, 268, 267, 266, 265, 264, 263, 262, 261, 260, 259, 258, 257, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]))
print(sped(100.0, 3.0, [0]))
print(sped(100.0, 3.0, [0, 0, 0]))
print(sped(100.0, 100.0, [99.99]))

