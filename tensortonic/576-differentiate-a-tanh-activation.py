#!/usr/bin/env python3

"""

Evaluate scalar tanh and manually propagate upstream_gradient through the activation.

y = tanh(x)
dL/dx = g*(1 - y^2)

Here x is the scalar input, y is its tanh output, L is the final loss, and g is upstream_gradient, the derivative of L with respect to y.

Return a tuple of two zero-dimensional PyTorch tensors: y first, then the gradient with respect to x. Both must preserve the inputs’ floating-point dtype and device.

Examples
Input: x = 0.5, upstream_gradient = 2.0

Output: (0.462117, 1.572895)

Explanation: The upstream gradient scales the local tanh derivative by two.

Input: x = 0.0, upstream_gradient = -3.0

Output: (0.0, -3.0)

Input: x = 8.0, upstream_gradient = 1.25

Output: (1.0, 0.000001)

Hint 1
torch.tanh preserves a tensor’s shape and dtype.

Hint 2
Requirements
Use PyTorch and compute the gradient manually, without automatic differentiation.
Preserve the supplied float16, float32, or float64 dtype; examples use float64.
Do not modify x or upstream_gradient.
Constraints
x and upstream_gradient are finite zero-dimensional tensors sharing a dtype and device.
The dtype is float16, float32, or float64.

"""

import torch

def tanh_forward_backward(x: torch.Tensor, upstream_gradient: torch.Tensor) -> tuple:
    y = torch.tanh(x)
    dL_dx = upstream_gradient * (1 - torch.square(y))
    return (y, dL_dx)

def main():
    print(tanh_forward_backward(torch.Tensor([0.5]), 2.0))
    print(tanh_forward_backward(torch.Tensor([0.0]), -3.0))
    print(tanh_forward_backward(torch.Tensor([8.0]), 1.25))

main()
