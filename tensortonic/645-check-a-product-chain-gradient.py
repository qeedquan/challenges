#!/usr/bin/env python3

"""

Compare analytic gradients with numerical estimates for a scalar computation graph:

e = a*b + c
L = e*f

Here 
a, b, c, and f are scalar inputs, e is an intermediate value, and L is the loss. Derive the analytic gradients using the chain rule. Numerical gradients use the supplied positive step h and forward differences, changing one input while keeping the others fixed.

Return a four-item tuple: the loss as a Python float, a list of four analytic Python-float gradients, a list of four numerical Python-float gradients, and their largest absolute pairwise difference as a Python float. Both lists use a, b, c, f order.

Examples
Input: a=2.0, b=-3.0, c=10.0, f=-2.0, h=0.001

Output: (-8.0, [6.0,-4.0,-2.0,4.0], [6.0,-4.0,-2.0,4.0], 0.0)

Explanation: The downstream multiplier affects the first three gradients; the two gradient lists agree to the displayed precision.

Input: a=0.0, b=0.0, c=0.0, f=0.0, h=0.01

Output: (0.0,[0.0,0.0,0.0,0.0],[0.0,0.0,0.0,0.0],0.0)

Input: a=0.5, b=-1.25, c=2.0, f=1.5, h=0.0001

Output: (2.0625, [-1.875,0.75,1.5,1.375], [-1.875,0.75,1.5,1.375], 0.0)

Hint 1
A fresh list.copy prevents perturbations from accumulating across checks.

Hint 2
zip pairs matching analytic and numerical gradients.

Hint 3
abs and max summarize the largest component error.

Requirements
Use 64-bit floating-point arithmetic; NumPy is available.
Compute numerical gradients using the supplied forward step.
Return both gradient lists without rounding their values.
Constraints
a, b, c, and f are finite numbers.
h is a finite positive number.
The loss, all gradients, and maximum disagreement must be finite.

"""

def loss(a: float, b: float, c: float, f: float) -> float:
    e = a*b + c
    L = e * f
    return L

def gradient_check_product_chain(
    a: float,
    b: float,
    c: float,
    f: float,
    h: float,
) -> tuple[float, list, list, float]:
    L = loss(a, b, c, f)
    DLA = [
        b*f,
        a*f,
        f,
        a*b + c,
    ]
    DLN = [
        (loss(a + h, b, c, f) - L) / h,
        (loss(a, b + h, c, f) - L) / h,
        (loss(a, b, c + h, f) - L) / h,
        (loss(a, b, c, f + h) - L) / h,
    ]

    err = float('inf')
    for i in range(len(DLA)):
        err = min(err, abs(DLA[i] - DLN[i]))
    return [L, DLA, DLN, err]

print(gradient_check_product_chain(2, -3, 10, -2, 0.001))
print(gradient_check_product_chain(0, 0, 0, 0, 0.01))
print(gradient_check_product_chain(0.5, -1.25, 2.0, 1.5, 0.0001))

