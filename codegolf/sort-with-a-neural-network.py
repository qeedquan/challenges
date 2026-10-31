#!/usr/bin/env python3

"""

The previous neural net golfing challenges (this and that) inspired me to pose a new challenge:

The challenge
Find the smallest feedforward neural network such that, given any 4-dimensional input vector (a,b,c,d) with integer entries in [−10,10], the network outputs sort(a,b,c,d) with a coordinate-wise error strictly smaller than 0.5.

Admissibility
For this challenge, a feedforward neural network is defined as a composition of layers. A layer is a function L:Rn→Rm that is specified by a matrix A∈Rm×n of weights, a vector b∈Rm of biases, and an activation function f:R→R that is applied coordinate-wise:

L(x):=f(Ax+b),x∈Rn.

Since activation functions can be tuned for any given task, we need to restrict the class of activation functions to keep this challenge interesting. The following activation functions are permitted:


Identity. f(t)=t
ReLU. f(t)=max(t,0)
Softplus. f(t)=ln(et+1)
Hyperbolic tangent. f(t)=tanh(t)
Sigmoid. f(t)=e^t/(e^t+1)

Overall, an admissible neural net takes the form Lk∘Lk−1∘⋯∘L2∘L1 for some k, where each layer Li is specified by weights Ai, biases bi, and an activation function fi from the above list. For example, the following neural net is admissible (while it doesn't satisfy the performance goal of this challenge, it may be a useful gadget):

[ min(a, b)
  max(a, b)] = 

[ 1 -1 -1/2 -1/2
  1 -1  1/2  1/2 ] * RELU [1/2   1/2
                           -1/2 -1/2
                            1    -1
                           -1     1] * [a b]

This example exhibits two layers. Both layers have zero bias. The first layer uses ReLU activation, while the second uses identity activation.

Scoring
Your score is the total number of nonzero weights and biases.

(E.g., the above example has a score of 16 since the bias vectors are zero.)

"""

import numpy as np

def relu(u):
    return np.maximum(u, 0)

def identity(u):
    return u

"""

@flawr

This 6-layer neural net is essentially a 3-step sorting network built from a very simple min/max network as a component.
It is basically the example network from wikipedia as shown below, with a small modification: The first two comparisons are done in parallel.
To bypass negative numbers though the ReLU, we just add 100 first, and then subtract 100 again at the end.

max/min-component
There is a (way more elegant now, thanks @xnor!) way to find the minimum and maximum of two numbers using less parameters:
min = a - RELU(a - b)
max = b + RELU(a - b)

This means we have to use a lot less weights and biases.

"""
def sort4(u):
    a1 = np.array([100, 100, 0, 100, 100, 0])
    A1 = np.array([[1, 0, 0, 0], [0, 0, 1, 0], [1, 0, -1, 0], [0, 1, 0, 0], [0, 0, 0, 1], [0, 1, 0, -1]])
    B1 = np.array([[1, 0, -1, 0, 0, 0], [0, 0, 0, 1, 0, -1], [0, 1, 1, 0, 0, 0], [0, 0, 0, 0, 1, 1]])
    A2 = np.array([[1, 0, 0, 0], [0, 1, 0, 0], [1, -1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1], [0, 0, 1, -1]])
    A3 = np.array([[1, 0, -1, 0, 0, 0], [0, 1, 1, 0, 0, 0], [0, 0, 0, 1, 0, -1], [0, 1, 1, -1, 0, 1], [0, 0, 0, 0, 1, 1]])
    B3 = np.array([[1, 0, 0, 0, 0], [0, 1, 0, -1, 0], [0, 0, 1, 1, 0], [0, 0, 0, 0, 1]])
    b3 = -np.array([[100, 100, 100, 100]])
    v = relu(np.dot(A1, np.transpose(u)) + a1)
    w = identity(np.dot(B1, v))
    x = relu(np.dot(A2, w))
    y = relu(np.dot(A3, x))
    z = identity(np.dot(B3, y) + b3)
    return z

def main():
    N = 10
    for a in range(N):
        for b in range(N):
            for c in range(N):
                for d in range(N):
                    u = np.array([a, b, c, d])
                    assert(np.allclose(sort4(u), sorted(u)))

main()
