#!/usr/bin/env python3

"""

Lately there have been quite a number of questions regarding the recreation of xkcd-style graphs like the following one (1064) in various languages.

https://i.sstatic.net/DFocL.png

Your goal is to recreate any existing xkcd comic as close to the original as possible. The comic has to have at least one simple graph or pie chart or similar element.

The highest voted answer wins, not sooner than 10 days after the first valid answer.

Your entry must contain code that displays an xkcd-comic as described above in a graphing language, making at least some use of its plotting tool (Mathematica, MatLab, etc.)

the comic must not be stored as an image, it has to be generated procedulally
there must not be any link whatsoever to the original website, or a mirror of it, or its contents on your hard drive, etc.
Votes should evaluate the similarity of the results to the original, and to a lesser extent, the beauty of the solution. No code golf here, but a solution as short and simple as possible is expected.

"""

import numpy as np
import matplotlib.pyplot as plt
from scipy.ndimage import gaussian_filter1d

# ported from @Kieran Hunt solution

plt.xkcd()

x = np.linspace(0, 10, 1000)
unit = np.linspace(0, 1, 100)

speed = np.r_[
    np.ones(500) * 3,
    3 + 5 * unit**4.0,
    np.ones(100) * 8,
    1 + 7 * unit[::-1] ** 2,
    np.ones(200),
]
speed = gaussian_filter1d(speed, 18)

fear = np.r_[
    np.linspace(0.5, 2, 450),
    2 + 6 * unit**4,
    np.ones(100) * 8,
    8 * unit[::-1] ** 2,
    np.zeros(250) + 0.1,
]
fear = gaussian_filter1d(fear, 18)
fear_gauss_bump = 0.8 * np.exp(-np.power(x - 2.5, 2.0) / (2 * np.power(1, 2.0)))
fear += fear_gauss_bump

embarrassment = np.r_[
    np.zeros(600) + 0.1, 9.5 * unit**2, 9.5 - np.linspace(0, 1.5, 300)
]
embarrassment = gaussian_filter1d(embarrassment, 60)

plt.figure(figsize=(12, 6))
plt.plot(x, speed, c="gray")
plt.plot(x, fear, c="#1E9FDB")
plt.plot(x, embarrassment, c="r")

plt.plot([2.5, 2.7], [3.9, 2.3], c="k")
plt.plot([4.3, 4.5], [3.6, 3.1], c="k")
plt.plot(
    np.linspace(7.3, 7.8, 15),
    (0.25 - (np.linspace(7.3, 7.8, 15) - 7.3) ** 2) ** 0.5 + 7,
    c="k",
)

ax = plt.gca()
ax.spines["top"].set_visible(False)
ax.spines["right"].set_visible(False)
ax.get_xaxis().tick_bottom()
ax.get_yaxis().tick_left()
# plt.ylim([0, 10])
ax.set_xticks([6, 7])
ax.set_xticklabels(["STEPS", "DOOR"])
ax.set_yticks([])

ax.text(2, 4, "FEAR\nTHAT THERE'S\nSOMETHING\nBEHIND ME", horizontalalignment="center")
ax.text(3.9, 3.4, "FORWARD\nSPEED", horizontalalignment="center")
ax.text(7.4, 6.6, "EMBARRASSMENT")
ax.text(
    1,
    8,
    "WALKING BACK TO MY\nFRONT DOOR AT NIGHT:",
    bbox={"facecolor": "none", "edgecolor": "black"},
)
ax.annotate(
    "YARD",
    xy=(0.5, -0.3),
    xytext=(4.5, -0.4),
    annotation_clip=False,
    arrowprops={"facecolor": "black", "shrink": 0.01, "width": 0.5},
)
ax.annotate(
    "INSIDE",
    xy=(10, -0.3),
    xytext=(7.5, -0.4),
    annotation_clip=False,
    arrowprops={"facecolor": "black", "shrink": 0.01, "width": 0.5},
)

plt.show()

