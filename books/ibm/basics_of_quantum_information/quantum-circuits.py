#!/usr/bin/env python3

from qiskit import QuantumCircuit, QuantumRegister, ClassicalRegister
from qiskit.primitives import Sampler
from qiskit.visualization import plot_histogram

# define a circuit
circuit = QuantumCircuit(1)

circuit.h(0)
circuit.s(0)
circuit.h(0)
circuit.t(0)

print(circuit)

# this gives the state some other name for better readability
X = QuantumRegister(1, "X")
circuit = QuantumCircuit(X)

circuit.h(X)
circuit.s(X)
circuit.h(X)
circuit.t(X)

print(circuit)

# measure the circuit after applying the gates to it
# the classical registers represent the location of the output where the values gets stored
X = QuantumRegister(1, "X")
Y = QuantumRegister(1, "Y")
A = ClassicalRegister(1, "A")
B = ClassicalRegister(1, "B")

circuit = QuantumCircuit(Y, X, B, A)
circuit.h(Y)
circuit.cx(Y, X)
circuit.measure(Y, B)
circuit.measure(X, A)

print(circuit)

# run the above circuit for a number of time and get the statistics of what value we get
results = Sampler().run(circuit).result()
statistics = results.quasi_dists[0].binary_probabilities()
print(statistics)


