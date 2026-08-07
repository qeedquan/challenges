#!/usr/bin/env python3

"""

You all know the Newton method to approximate the roots of a function, don't you? My goal in this task is to introduce you into an interesting aspect of this algorithm.

Newton's algorithm converges only for certain, but most of all complex input values. If you picture the convergence of the method for all input values over the complex plane, you usually get a beautiful fractal like this:

Newton fractal for f(x) = x^3-1 Image from Wikimedia commons

Specifications
The goal of this task is, to generate such fractals. This means, that you get a polynomial as the input and have to print out the corresponding fractal as an image in a format of your choice as the output.

Input
The input is a whitespace-separated list of complex numbers. They are written down in the style <Real part><iImaginary part>, like this number: 5.32i3.05. You may assume, that the input number has no more than 4 decimal places and is smaller than 1000. The first of them must not be zero. For example, this could be an input to your program:

1 -2i7.5 23.0004i-3.8 i12 0 5.1233i0.1
The numbers are interpreted as the coefficients of a polynomial, beginning with the highest power. Throughout the rest of this specification, the input polynomial is called P. The above input is equal to this polynomial:

f(x) = x^5 + (-2 + 7.5i)x^4 + (23.0004 - 3.8i)x^3 + 12ix^2 + 5.1233+0.1i
The input may come to you either from stdin, from an argument passed to the program or from a prompt displayed to your program. You may assume, that the input does not contain any leading or trailing whitespace characters.

Rendering
You have to render the fractal in the following way:

Choose as many COLORS as roots of P plus an extra color for divergence
For each number in the visible plane, determine whether the method converges and if yes to which root. Color the point according to the result.
Do not print rulers or other fancy things
Print a black point at the points, that are the polynomials roots for orientation. You may print up to four pixels around each root.
Find a way to choose the visible plane in a way, that all roots are distinguishable and spread widely across it, if possible. Although a perfect placement of the output frame is not required, I reserve the right to refuse to accept an answer that chooses the frame in an unacceptable way, eg. always at the same coordinates, all roots are in one point, etc.
The output image should have a size of 1024*1024 pixels.
Rendering time is 10 minutes maximum
Using single precision floating-point values is enough
Output
The output should be a raster graphics image in a file format of your choice, readable by standard software for a brand X operating system. If you want to use a rare format, consider adding a link to a website where one can download a viewer for it.

Output the file to stdout. If your language does not support putting something to stdout or if you find this option less convenient, find another way. In any way, it must be possible to save the generated image.

Restrictions
No image processing libraries
No fractal generating libraries
The shortest code wins

Extensions
If you like this task, you could try to color the points according to the speed of convergence or some other criteria. I'd like to see some interesting results.

"""

"""

https://scipython.com/book2/chapter-8-scipy/examples/the-newton-fractal/
https://matplotlib.org/stable/gallery/color/named_colors.html

"""

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import *

COLORS = ['lightgreen', 'royalblue', 'crimson', 'pink', 'gold', 'aqua']

def newton(z0, f, df, iterations=1000, tol=1.e-8):
    z = z0
    for i in range(iterations):
        dz = f(z) / df(z)
        if abs(dz) < tol:
            return z
        z -= dz
    return False

def get_root_index(roots, r, tol=1.e-8):
    try:
        return np.where(np.isclose(roots, r, atol=tol))[0][0]
    except:
        roots.append(r)
        return len(roots) - 1

def plot_newton_fractal(filename, f, df, n=500, domain=(-1, 1, -1, 1)):
    roots = []
    m = np.zeros((n, n))
    xmin, xmax, ymin, ymax = domain
    for ix, x in enumerate(np.linspace(xmin, xmax, n)):
        for iy, y in enumerate(np.linspace(ymin, ymax, n)):
            z0 = x + y*1j
            r = newton(z0, f, df)
            if r is not False:
                ir = get_root_index(roots, r)
                m[iy, ix] = ir
    nroots = len(roots)
    if nroots > len(COLORS):
        cmap = 'hsv'
    else:
        cmap = ListedColormap(COLORS[:nroots])

    plt.imshow(m, cmap=cmap, origin='lower')
    plt.axis('off')
    plt.savefig(filename)
    print("Save figured to %s" % (filename))

def main():
    f1 = lambda z: z**5 + (-2 + 7.5j)*z**4 + (23.0004 - 3.8j)*z**3 + 12j*z**2 + 5.1233 + 0.1j
    df1 = lambda z: 5*z*(z*(13.8002 - 1.6*z + z**2) + 1j*(4.8 - 2.28*z + 6*z**2))

    f2 = lambda z: z**3 - 1
    df2 = lambda z: 3*z**2

    plot_newton_fractal("newton_1.png", f1, df1)
    plot_newton_fractal("newton_2.png", f2, df2)

main()
