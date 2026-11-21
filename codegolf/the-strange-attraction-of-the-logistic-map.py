#!/usr/bin/env python3

"""

The purpose of the challenge is to approximately plot the attractor of the logistic map as a function of its parameter r (also called bifurcation diagram), or a subregion of it. The appearance of the graph can be seen in the following image from Wikipedia:

Background
The logistic map is a mathematical function that takes an input xk and maps it to an output xk+1 defined as

             x[k+1] = r*x[k] (1-x[k])

where r is the parameter of the map, assumed to lie in the interval [0, 4].

Given r in [0,4], and an initial value x0 in the interval [0,1], it is interesting to repeatedly apply the function for a large number N of iterations, producing a final value xN. Note that xN will necessarily lie in [0,1] too.

As an example, consider r = 3.2, N = 1000. The initial value x0 = 0.01 gives x1000 = 0.5130. For x0 = 0.02 the result is x0 = 0.7995. For any other initial values x0 the final values x1000 are extremely close to either 0.5130 or 0.7995. This is seen in the graph as the height of the two lines at horizontal position r = 3.2.

This does not mean that for r = 3.2 each sequence converges to one of those two values. In fact, for the two initial values considered above, the sequences are (note the oscillating behaviour):

             x0 = 0.01, ..., x1000 = 0.5130, x1001 = 0.7995, x1002 = 0.5130, ...
             x0 = 0.02, ..., x1000 = 0.7995, x1001 = 0.5130, x1002 = 0.7995, ...

What is true is that for sufficiently large N, and for almost all initial values x0, the term xN will be close to one of the elements of the set {0.5130, 0.7995}. This set is called the attractor for this specific r.

For other values of the parameter r the size of the atractor set, or its elements, will change. The graph plots the elements in the attractor for each r.

The attractor for a specific r can be estimated by

testing a wide range of initial values x0;
letting the system evolve for a large number N of iterations; and
taking note of the final values xN that are obtained.
The challenge
Inputs
N: number of iterations.

r1, r2 and s. These define the set R of values of r, namely R = {r1, r1 + s, r1 + 2 s, ..., r2}.

Procedure
The set X of initial values x0 is fixed: X = {0.01, 0.02, ..., 0,99}. Optionally, 0 and 1 may also be included in X.

For each r in R and each x0 in X, iterate the logistic map N times to produce xN. Record the obtained tuples (r, xN).

Output
Plot each tuple (r, xN) as a point in the plane with r as horizontal axis and xN as vertical axis. Output should be graphic (not ASCII art).

Additional rules
The indicated procedure defines the required result, but is not enforced. Any other procedure that procudes the same set of (r, xN) tuples can be used.
Input is flexible as usual.
Floating point errors won't be held against the answerer.
Graphic output is required, in any of the accepted formats. In particular, output may be displayed on screen, or a graphics file may be produced, or an array of RGB values may be output. If outputting a file or an array, please post an example of what it looks like when displayed.
Graphics may be vector or raster. For raster graphics, the size of the image should be at least 400×400 pixels.
Each point should be shown as a single pixel, or as a mark with size of the order of one pixel (otherwise the graph quickly gets cluttered).
Axis range should be [0,4] for r (horizontal axis) and [0,1] for xN (vertical axis); or it may be smaller as long as it includes all obtained points.
Axis scales are arbitrary. In particular, the scale need not be the same for both axes.
Grid lines, axis labels, colors and similar elements are acceptable, but not required.
Shortest code in bytes wins.

Test cases
Click on each image for a high-resolution version.

N = 1000; r1 = 2.4; r2 = 4; s = 0.001;
https://i.sstatic.net/QakwE.png

N = 2000; r1 = 3.4; r2 = 3.8; s = 0.0002;
https://i.sstatic.net/1QHic.png

N = 10000; r1 = 3.56; r2 = 3.59; s = 0.00002;
https://i.sstatic.net/TEbWQ.png

Acknowledgment
Thanks to @FryAmTheEggman and @AndrasDeak for their helpful comments while the challenge was in the sandbox.

"""

import numpy as np
import matplotlib.pyplot as plt

def plot_logistic_map(name, N, r1, r2, s):
    n_intervals = round((r2 - r1) / s)
    iterations = N
    last_points = N

    r_values = np.linspace(r1, r2, n_intervals)
    x = 0.5 * np.ones(n_intervals)

    # Setup the plot layout
    plt.figure(figsize=(10, 7), dpi=150)
    plt.title("Bifurcation Diagram of the Logistic Map", fontsize=14)
    plt.xlabel("Growth Rate (r)", fontsize=12)
    plt.ylabel("Population Equilibrium (x)", fontsize=12)
    for i in range(iterations):
        x = r_values * x * (1 - x)
        if i >= (iterations - last_points):
            plt.plot(r_values, x, ',k', alpha=0.1)
    plt.xlim(r1, r2)
    plt.grid(True, alpha=0.3)
    plt.savefig(name)

def main():
    plot_logistic_map("logistic_map_1.png", 1000, 2.4, 4, 0.001)
    plot_logistic_map("logistic_map_2.png", 2000, 3.4, 3.8, 0.0002)
    plot_logistic_map("logistic_map_3.png", 10000, 3.56, 3.59, 0.00002)

main()
