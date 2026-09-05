# Given a number n, you must output a golden spiral with the number of quarter turns being n.
#
# The spiral must be completely black and the background must be completely white. This must be output as a φ⌊n/4⌋*4 by φ⌊n/4⌋*4 PNG file (you may output a PPM and convert it later). The shortest code wins.
#
# The radius of the smallest quarter turn should be φ-3.
#
# In geometry, a golden spiral is a logarithmic spiral whose growth factor is φ, the golden ratio.That is, a golden spiral gets wider (or further from its origin) by a factor of φ for every quarter turn it makes.

# https://en.wikipedia.org/wiki/Golden_spiral
set polar
set trange [-4*pi:4*pi]
phi = (1 + sqrt(5)) / 2
plot phi**(2*t / pi)
pause -1
