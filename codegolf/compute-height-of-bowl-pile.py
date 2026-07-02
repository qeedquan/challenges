#!/usr/bin/env/python3

"""

Bowl Pile Height
The goal of this puzzle is to compute the height of a stack of bowls.

https://i.sstatic.net/9dZsZm.jpg
A stack of bowls

A bowl is defined to be a radially symmetric device without thickness. Its silhouette shape is an even polynomial
The stack is described by a list of radii, each associated with an even polynomial, given as input as a list of coefficients (e.g. the list 3.1 4.2 represents the polynomial 3.1x^2 + 4.2x^4).

The polynomial may have arbitrary degree. For simplicity, the height of the pile is defined as the altitude of the center of the top-most bowl (see plot of Example 3 for an illustration).

Test cases are in the format radius:coeff1 coeff2 ...: each line starts with a float number representing the radius of the bowl,
followed by a colon and a space-separated list containing the coefficients for the even powers, starting with power 2 (zero constant part is implied).
For example, the line 2.3:3.1 4.2 describes a bowl of radius 2.3 and the shape-polynomial 3.1 * x^2 + 4.2 * x^4.

Example 1
42:3.141
describes a pile of zero height since a single bowl has no height.

Example 2
1:1 2
1.2:5
1:3
describes a pile of height 2.0 (see plot).

https://i.sstatic.net/eyrxF.png
Plot of a stack of three bowls

Example 3
1:1.0
0.6:0.2
0.6:0.4
1.4:0.2
0.4:0 10
describes a pile of height 0.8 (see green arrow in the plot).

https://i.sstatic.net/9wFYRm.png
Plot of a stack of three bowls

This is code golf, so the shortest code wins.

I have reference code.
https://gist.github.com/pasbi/89f86df9fb1049bd3dfb6cffeac093b2

Edit:
The reference implementation relies on a library to compute the roots of polynomials. You may do that as well but you don't need to. Since the reference implementation is only a (quite good) numerical approximation, I will accept any code which produces correct results within common floating-point tolerances.

The idea counts. I don't care if there are small erros <ε
.

Another variant of this puzzle is to minimize the height by reordering the bowls. I'm not sure if there's a fast solution (I guess it's NP-hard). If anyone has a better idea (or can prove NP-completeness), please tell me!

"""

import numpy as np
import sys
import matplotlib.pylab as plt

# p(x) = sum([ p * x**i for i, p in enumerate(ps)])
def differentiate(ps):
    return [p * i for i, p in enumerate(ps)][1:]


def roots(ps):
    return np.roots(ps[::-1])

def evaluate(ps, x):
    return sum([p * x**i for i, p in enumerate(ps)])

def distance(dish_a, dish_b):
    radius_0, shape_0 = dish_a
    radius_1, shape_1 = dish_b
    radius = min(radius_0, radius_1)
    diff = shape_0 - shape_1
    dd = differentiate(diff)
    p_roots = roots(dd)

    def is_maximum(root):
        return evaluate(dd, root) > 0.0

    def is_in_range(root):
        return 0.0 < root <= radius

    def is_real(root):
        return abs(root.imag) <= 0.00000001

    def root_filter(root):
        return is_maximum(root) and is_in_range(root) and is_real(root)

    #  print("roots: ", p_roots)
    p_roots = [root for root in p_roots if root_filter(root)]
    distances = [evaluate(diff, root) for root in p_roots]
    distances += [evaluate(diff, 0.0), evaluate(diff, radius)]
    min_distances = max(distances)
    return min_distances

def read_dish(line):
    radius, ps = line.split(":")
    radius = float(radius)
    even_ps = np.array([float(c) for c in ps.split(" ")])
    ps = np.zeros(2 * len(even_ps) + 1)
    ps[2::2] = even_ps
    return radius, ps

def pad(ps, n):
    padded_ps = np.zeros(n)
    padded_ps[: len(ps)] = ps
    return padded_ps

def plot_dishes(dishes):
    assert len(dishes) > 0
    for radius, shape in dishes:
        n = 100
        xs = np.linspace(-radius, radius, n)
        ys = [evaluate(shape, x) for x in xs]
        plt.plot(xs, ys)
    plt.legend(range(len(dishes)))
    plt.show()

def solve(lines):
    dishes = [read_dish(line) for line in lines]

    n = max([len(shape) for r, shape in dishes])
    dishes = [(r, pad(shape, n)) for r, shape in dishes]

    y_offsets = [0.0]
    for i in range(1, len(dishes)):
        distances = [distance(dishes[j], dishes[i]) for j in range(i)]
        y_offsets.append(max(distances))
        dishes[i][1][0] += y_offsets[i]

    stack_height = y_offsets[-1]
    print(stack_height)
    plot_dishes(dishes)

def main():
    solve(['42:3.141'])
    solve(['1:1 2', '1.2:5', '1:3'])
    solve(['1:1.0', '0.6:0.2', '0.6:0.4', '1.4:0.2', '0.4:0 10'])

main()

