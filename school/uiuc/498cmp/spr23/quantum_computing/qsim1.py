#!/usr/bin/env python3

"""

A quantum simulator based on matrix multiplication rather than applying gates to individual bits.

This method is good for thinking/reasoning about what the underlying transformations are mathematically.
Because the operations are represented by matrix multiplications, we can use all the tools from linear algebra for deeper understanding.

A N-Qubit system will have a square matrix and vector state of size 2^N.

Example:
3 qubit:
2^3 = 8x8 matrix and 8 element vector state

The square matrix will contain all the information about the gates due to how matrix multiplications work.
We just need to multiply all the matrix representing a gate together to get the transformation matrix to apply to the vector state.

To construct a unary gate matrix of N wires, use the tensor product to combine the wires together.

Example:
# of wires = 3
A 2x2 matrix represents the minimal size of the matrix as it represents 1-qubit (a complex number)
I = Identity matrix (2x2)
G = Gate matrix (2x2) This represents your hadamard/phase/x/y/z gates

(LSB)
100: G⊗I⊗I
010: I⊗G⊗I
001: I⊗I⊗G
and so on.

A 0 represents the identity matrix and a 1 represents the gate matrix to where it is supposed to be applied.
A tensor product will produce the square matrix 2^N size at the end when combining the gate matrix and identity together.

Some ways to speed up the simulator:
Use the matrix multiplication to combine gates together avoid building alot individual gate matrices.
Use sparse matrices since these gate matrices contains alot of zeros.
Instead of using matrices, have the gates take in a vector and output a vector (like the bit simulator does).

Properties of the gate matrix:
It is a unitary matrix, that is (U * U') = I where U' is the complex conjugate of the matrix.
They also preserve the norm under transformations (preserves the probability amplitudes).
A special unitary matrix is where det(U) = 1.

A more general class of matrices is hermitian matrices:
H * H' = H^2 = H' * H

Unitary and hermitian matrices are also normal matrices, this means that the spectral theorem applies and we can decompose
them into a orthonormal basis made of eigenvectors/eigenvalues (spectral decomposition)

"""

import numpy as np
import cmath

def unary(G, wire, size):
    I = np.eye(2)
    M = np.array([1])
    for bit in range(size):
        if bit == wire:
            M = np.kron(G, M)
        else:
            M = np.kron(I, M)
    return M

def paulix(wire, size):
    X = np.array([[0, 1], [1, 0]])
    return unary(X, wire, size)

def pauliy(wire, size):
    Y = np.array([[0, -1j], [1j, 0]])
    return unary(Y, wire, size)

def pauliz(wire, size):
    Z = np.array([[1, 0], [0, -1]])
    return unary(Z, wire, size)

def hadamard(wire, size):
    H = 1/np.sqrt(2) * np.array([[1, 1], [1, -1]])
    return unary(H, wire, size)

def phase(theta, wire, size):
    P = np.array([[1, 0], [0, cmath.exp(1j*theta)]])
    return unary(P, wire, size)

"""

CNOT takes two inputs so it isn't a unary gate like the others, need a different way to construct the matrix for it.
A simple way to construct the matrix is to view the CNOT matrix as a permutation matrix that permutes the elements of a state vector.

Example:
For 2 qubits we have the following transformation:

00) -> 00)
01) -> 01)
10) -> 11)
11) -> 10)

So we have the following permutation:
[0 1 2 3] -> [0 1 3 2]

The permutation matrix for this will be:

[1 0 0 0]
[0 1 0 0]
[0 0 0 1]
[0 0 1 0]

For bigger sizes matrix, we just have to enumerate through all the bit values and write down the permutation matrix for it.

"""
def cnot(control, xnot, size):
    N = 1 << size
    C = np.eye(N)

    P = []
    for index in range(N):
        bit = index
        if bit&(1<<control):
            bit ^= (1<< xnot)
        P.append(bit)

    for i in range(N):
        if i != P[i]:
            C[i][i] = 0
            C[i][P[i]] = 1
    return C

def load_state(name):
    state = []
    file = open(name)
    for line in file.readlines():
        line = line.rstrip()
        fields = line.split(" ")
        if len(fields) == 2:
            state.append(complex(float(fields[0]), float(fields[1])))
    file.close()
    return state

def load_circuit(name):
    file = open(name)
    
    state = []
    gates = []

    size = 0
    lineno = 0
    for line in file.readlines():
        if lineno == 0:
            size = int(line)
            lineno += 1
            continue

        line = line.rstrip()
        fields = line.split(' ')
        fields = fields[1:]
        if line.startswith("INITSTATE FILE"):
            state = load_state(fields[1])
        elif line.startswith("H"):
            gates.append(hadamard(int(fields[0]), size))
        elif line.startswith("CNOT"):
            gates.append(cnot(int(fields[0]), int(fields[1]), size))
        elif line.startswith("P"):
            gates.append(phase(float(fields[1]), int(fields[0]), size))
   
    file.close()
    
    return state, gates, size

def main():
    state, gates, size = load_circuit("rand.circuit")
    M = np.eye(1 << size)
    for G in gates:
        M = np.dot(M, G)
    print(np.dot(M, state))

main()
