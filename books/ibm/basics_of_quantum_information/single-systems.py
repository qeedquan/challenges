#!/usr/bin/env python3

from qiskit.visualization import plot_histogram
from qiskit.quantum_info import Statevector, Operator
from qiskit import QuantumCircuit
from numpy import array, matmul, sqrt

# Represent a pure qubit state 0 and 1
ket0 = array([1, 0])
ket1 = array([0, 1])
print(ket0 / 2 + ket1 / 2)

# Represent a linear operator (matrix in a given basis)
M1 = array([[1, 1], [0, 0]])
M2 = array([[1, 1], [1, 0]])

M1 / 2 + M2 / 2

# Apply a linear operator (matrix multiplication)
print(matmul(M1, ket1))
print(matmul(M1, M2))
print(matmul(M2, M1))

# Another way to represent a state vector, one with more builtin methods
u = Statevector([1 / sqrt(2), 1 / sqrt(2)])
v = Statevector([(1 + 2.0j) / 3, -2 / 3])
w = Statevector([1 / 3, 2 / 3])
print(u, v, w)

# Check if it is a valid state vector (Euclidean norm equal to 1)
print(u.is_valid())
print(w.is_valid())

# Peform a measurement, the output is probabilistic and can change every time based on the amplitudes of the bits
for i in range(10):
    print(v.measure())

# Sample lots of times using builtin methods
statistics = v.sample_counts(1000)
print(statistics)
plot_histogram(statistics)

# Define operators (quantum gates) and apply it to the state 
X = Operator([[0, 1], [1, 0]])
Y = Operator([[0, -1.0j], [1.0j, 0]])
Z = Operator([[1, 0], [0, -1]])
H = Operator([[1 / sqrt(2), 1 / sqrt(2)], [1 / sqrt(2), -1 / sqrt(2)]])
S = Operator([[1, 0], [0, 1.0j]])
T = Operator([[1, 0], [0, (1 + 1.0j) / sqrt(2)]])

v = Statevector([1, 0])

v = v.evolve(H)
v = v.evolve(T)
v = v.evolve(H)
v = v.evolve(T)
v = v.evolve(Z)
print(v)

# Define a quantum circuit, which is a combination of all the ideas above (states, gates, etc)
circuit = QuantumCircuit(1)
circuit.h(0)
circuit.t(0)
circuit.h(0)
circuit.t(0)
circuit.z(0)
print(circuit)
ket0 = Statevector([1, 0])
v = ket0.evolve(circuit)
print(v)

statistics = v.sample_counts(4000)
print(statistics)
plot_histogram(statistics)
