#!/usr/bin/env python3

from qiskit.quantum_info import Statevector, Operator
from numpy import sqrt

# ∣0⟩ ⊗ ∣1⟩ = ∣01⟩
zero, one = Statevector.from_label("0"), Statevector.from_label("1")
print(zero.tensor(one).to_dict())

#  ∣+⟩ ⊗ 1/sqrt(2)*(∣0⟩ + i|1⟩)
plus = Statevector.from_label("+")
i_state = Statevector([1 / sqrt(2), 1j / sqrt(2)])
psi = plus.tensor(i_state)
print(psi.to_dict())

# Tensor product of two gates X and I
X = Operator([[0, 1], [1, 0]])
I = Operator([[1, 0], [0, 1]])
print(X.tensor(I))

# Applied the 2 gates (X⊗I) to the state vector psi
print(psi.evolve(I ^ X))

# Define our own operator as a matrix and apply it
CX = Operator(
    [
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 0, 1],
        [0, 0, 1, 0],
    ]
)
print(psi.evolve(CX))

# Define a state that we are going to measure
# By default, a measurement looks at ALL qubits
W = Statevector([0, 1, 1, 0, 1, 0, 0, 0] / sqrt(3))
print(W.to_dict())

# We can just measure one qubit and look at the new state
# Usually what this means is that one of the states gets outputted, so the full state loses that one state
result, new_sv = W.measure([0])  # measure qubit 0
print(result)
print(new_sv.to_dict())

result, new_sv = W.measure([1])  # measure qubit 1
print(new_sv.to_dict())
