#!/usr/bin/env python3

"""

Simple and low precision of the phase estimation problem for pedagogy.

"""

from math import pi
from qiskit.primitives import Sampler
from qiskit import QuantumCircuit

theta = 0.7

# 3 quantum wires and 2 classical wires
# the classical wires are used for saving the measurement, 2 outputs in this case
qc = QuantumCircuit(3, 2)

# Prepare the eigenvector
qc.x(2)
qc.barrier()

# The initial Hadamard gates
qc.h(0)
qc.h(1)
qc.barrier()

# The controlled unitary gates
qc.cp(2 * pi * theta, 0, 2)
qc.cp(2 * pi * (2 * theta), 1, 2)
qc.barrier()

# An implementation of the inverse of the two-qubit QFT
qc.swap(0, 1)
qc.h(0)
qc.cp(-pi / 2, 0, 1)
qc.h(1)
qc.barrier()

# And finally the measurements
qc.measure([0, 1], [0, 1])
print(qc)

result = Sampler().run(qc).result()
print(result.quasi_dists)
