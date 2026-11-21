#!/usr/bin/env python3

"""

Compute the input-gradient contributions for one saved scalar operation: add and mul take two inputs, while tanh takes one. The supplied output is its saved forward result.

add contributions = [g, g]
mul contributions = [gb, ga]
tanh contributions = [g*(1-t)^2]

Here a and b are the first and second inputs, g is upstream_gradient, and t is the saved tanh output. Return a Python list of 64-bit floating-point contributions, one per input in input order.

Examples
Input: operation = "add", inputs = [2.0, -3.0], output = -1.0, upstream_gradient = 4.0

Output: [4.0, 4.0]

Explanation: Both local derivatives of addition are one.

Input: operation = "mul", inputs = [-2.0, 3.0], output = -6.0, upstream_gradient = 0.5

Output: [1.5, -1.0]

Input: operation = "tanh", inputs = [1.0], output = 0.7615941559557649, upstream_gradient = 2.0

Output: [0.839949]

Hint 1
List indexing identifies the other operand in a multiplication.

Hint 2
The saved tanh output can be squared directly; no new activation call is needed.

Requirements
Use Python floating-point arithmetic (64-bit); NumPy is available.
Use the supplied saved output for the tanh derivative.
Leave inputs unchanged.
Constraints
operation is "add", "mul", or "tanh".
inputs contains two finite numbers for add or mul, or one for tanh.
output matches the operation applied to inputs; output and upstream_gradient are finite numbers.

"""

def local_vjp(operation: str, inputs: list, output: float, upstream_gradient: float) -> list:
    if operation == "add":
        return [upstream_gradient, upstream_gradient]
    if operation == "mul":
        return [upstream_gradient*inputs[1], upstream_gradient*inputs[0]]
    if operation == "tanh":
        return [upstream_gradient*(1-output**2)]
    raise ValueError("invalid operation")

def main():
    print(local_vjp("add", [2, -3], -1, 4))
    print(local_vjp("mul", [-2, 3], -6, 0.5))
    print(local_vjp("tanh", [1], 0.7615941559557649, 2))

main()
