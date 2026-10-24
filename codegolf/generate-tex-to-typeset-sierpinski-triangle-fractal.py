#!/usr/bin/env python3

"""

Challenge
Write code that outputs TeX (LaTeX) math-equation code (given below) that will typeset Sierpinski Triangle Fractal of 5 levels. Shortest code wins.

Details
TeX (and friends like LaTeX, etc.) is a sophisticated typesetting system. It can render arbitrary nested complex expressions for mathematical formulas. Coincidentally this "nested complex" is also descriptive of fractals. The following is rendered with MathJaX

by the following plain-text math-equation code consisting of nested super- and sub-scripts:

{{{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}^{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}_{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}}^{{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}^{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}_{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}}_{{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}^{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}_{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}}}

Note this is just a 5-level nesting. You do not need to generate $...$ or $$...$$ or other markup required to start/end a math equation in TeX & Co. You can preview generated TeX in many online editors, for instance: http://www.hostmath.com but you can find many others too. This question was inspired by a discussion with friends.

Update
There is a similar question but it much more general and will produce different solutions. I wanted to see really kolmogorov-complexity for a very fixed simple code that in one system (TeX) is completely explicit while in another compressed. This also address the n instead of 5 levels comment.

"""

from functools import *

# ported from @hakr14 solution
def gentex(n):
    s = ["x"] + n*["{^_}"]
    return reduce(lambda x, y: x.join(y), s)

def main():
    assert(gentex(5) == "{{{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}^{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}_{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}}^{{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}^{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}_{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}}_{{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}^{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}_{{{x^x_x}^{x^x_x}_{x^x_x}}^{{x^x_x}^{x^x_x}_{x^x_x}}_{{x^x_x}^{x^x_x}_{x^x_x}}}}}")

main()
