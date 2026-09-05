#!/usr/bin/env python3

"""

If a moment-generating function exists for a random variable X, then:

The mean of X can be found by evaluating the first derivative of the moment-generating function at t = 0. That is:
mu = E(X) = M'(0)

The variance of X  can be found by evaluating the first and second derivatives of the moment-generating function at. That is:
sigma^2 = E(X^2) - [E(X)]^2 = M''(0) - |M'(0)|^2

E(X), E(X^2), E(X^3) ... E(X^r) is called moments about the origin and M(t) and it's derivative is the function that generate those moments.

M^r(0) = E(X^r)

In general the moment generating function is:

M(t) = E[exp(t*X)]

The moment generating function has an important property often called the uniqueness property.
The uniqueness property means that, if the mgf exists for a random variable, then there one and only one distribution associated with that mgf.
Therefore, the mgf uniquely determines the distribution of a random variable.

For linear combinations of independent random variables X
Y = Sum[i=1, n] a[i]*X[i]

The moment is of Y is:
M[Y](t) = Product[i=1, n] M[X[i]](a[i]*t)

"""
