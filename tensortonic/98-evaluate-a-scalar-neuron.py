#!/usr/bin/env python3

"""

Evaluate one scalar tanh neuron using the supplied input vector, aligned weights, and scalar bias.

a = Sum[i=1, n] w[i]*x[i] + b
y = tanh(a)

Here n is the vector length, x is inputs, w is weights, i indexes their entries, b is bias, a is the preactivation, and y is the neuron output. For empty input and weight vectors, a equals b.

Return a tuple of two zero-dimensional PyTorch tensors: a first, then y. Both must preserve the inputs’ floating-point dtype and device.

Examples
Input: inputs = [2, 0], weights = [-3, 1], bias = 6.881373587

Output: (0.881374, 0.707107)

Explanation: The weighted inputs sum to -6; adding the bias gives the preactivation.

Input: inputs = [1.5], weights = [2], bias = -0.5

Output: (2.5, 0.986614)

Input: inputs = [], weights = [], bias = 0.75

Output: (0.75, 0.635149)

Hint 1
torch.sum reduces a vector to a scalar tensor, including an empty vector.

Hint 2
torch.tanh accepts a zero-dimensional tensor.

Requirements
Use PyTorch with the supplied weights and bias.
Preserve the supplied float16, float32, or float64 dtype; examples use float64.
Do not modify inputs, weights, or bias.
Constraints
inputs and weights are finite one-dimensional tensors of equal length, which may be zero.
bias is a finite zero-dimensional tensor.
All tensors share float16, float32, or float64 dtype and the same device; vectors may be noncontiguous.

"""

import torch

def neuron_forward(inputs: torch.Tensor, weights: torch.Tensor, bias: torch.Tensor) -> tuple:
    a = torch.dot(inputs, weights) + bias
    y = torch.tanh(a)
    return (a, y)

def main():
    print(neuron_forward(torch.Tensor([2, 0]), torch.Tensor([-3, 1]), torch.Tensor([6.881373587])))
    print(neuron_forward(torch.Tensor([1.5]), torch.Tensor([2]), torch.Tensor([-0.5])))
    print(neuron_forward(torch.Tensor([]), torch.Tensor([]), torch.Tensor([0.75])))

main()
