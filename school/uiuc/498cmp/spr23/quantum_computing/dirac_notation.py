#!/usr/bin/env python3

"""

Dirac notation: sparse representation
Vector notation: dense representation

Classical: n-bits is 2^n states
Quantum:   n-qubits is 2^(2^n) states because of superposition

https://en.wikipedia.org/wiki/Probability_amplitude
For a quantum state, it needs to obey the rule where the sum of the absolute value of the squares of the amplitudes need to add up to 1.
Each individual value of the amplitude of a state represents a "probability" of measuring the outcome once the collapse occurs.
The dot product is the probability amplitude of one of the states transforming into another. The actual probability is obtained by the norm of the amplitude.

∣ψ⟩      = column vector (ket)
⟨ψ∣      = row vector    (bra)
⟨ψ1∣ψ2⟩  = inner/dot product
|ψ1⟩⟨ψ2| = tensor/outer product

Linear operators acting on bras (rule is to apply A to the right side first)
⟨ψ1∣A|ψ2) = ⟨ψ1∣(A|ψ2))

If the same state vector appears on both bra and ket side, this expression gives the expectation value, or mean or average value,
of the observable represented by operator A for the physical system in the state |ψ⟩.
⟨ψ1∣A|ψ1)

∣ψ⟩⊗∣ψ⟩⊗∣ψ⟩⊗∣ψ⟩ ... = ∣ψ⟩^(⊗n) (tensor product n times is written can be written using the power notation)

To convert a ket to a bra, we need to take the complex conjugate transpose of the ket elements:

Example:
|a⟩ = [2-3i 6+4i 3-i]
⟨a∣ = transpose([2+3i 6-4i 3+i])

In some sense, the tensor product can be viewed as a natural way to multiply things, hence this notation
|ψ1⟩|ψ2⟩ = |ψ1⊗ψ2⟩  = |ψ1⟩⊗ψ2|⟩ (column vector tensor product)

⟨ψ1∣ψ2⟩ = ⟨ψ2∣ψ1⟩* (Need to take complex conjugate since the space allows for complex numbers)

Examples:

Note that these are tensor products of column vectors
∣0⟩⊗∣0⟩ = ∣0⟩∣0⟩ = ∣00⟩ = [1 0]' ⊗ [1 0]' = [1 0 0 0]'
∣1⟩∣0⟩∣1⟩ = ∣101⟩ = |5⟩ = [0 0 0 0 0 1 0 0] (indexing starts at 0)

∣E⟩     = basis vector (the amplitude values is relative to this basis)
⟨Ei∣Ej⟩ = δij means that the basis vectors form an orthonormal basis set

The standard basis vectors commonly used is the spherical coordinates on a bloch sphere.
Note that you can express the basis vectos using other basis vectors:

X Basis:
|+⟩ = 1/sqrt(2)*(|0⟩ + |1⟩)
|-⟩ = 1/sqrt(2)*(|0⟩ - |1⟩)

Y Basis:
|+i⟩ = 1/sqrt(2)*(|0⟩ + i|1⟩)
|-i⟩ = 1/sqrt(2)*(|0⟩ - i|1⟩)

Z Basis:
|0⟩
|1⟩

The Z basis is the standard computational basis, generally the one we use to make measurements on the system.

The Pauli X/Y/Z rotation gate, Hadamard gates, etc are used to change the basis we are working with. 

|ψ1⟩⟨ψ1| can be thought of making a multiplication table, ie:
[1 2 3] ⊗ [1 2 3]' = [1 2 3 
                      2 4 6
                      3 6 9]

If |ψ1⟩ only contains 1/0 entries then:
[1 0 0] ⊗ [1 0 0] = [1 0 0; 0 0 0; 0 0 0]
[0 1 0] ⊗ [0 1 0] = [0 0 0; 0 1 0; 0 0 0]
So it is a way to generate an identity matrix if we sum up all of these (this is what notation like Sum[i=1, n] |ψi⟩⟨ψi| is doing)

The quantum state vector can only describe pure states, density operators can also represent mixed states.
A density operator is denoted as ρ
ρ is a matrix if complex numbers
ρ = ρ† (it is Hermitian)
Every eigenvalue of ρ is non-negative
All the eigenvalues of ρ sum to 1

In infinite dimensional and continous cases:
The dot product becomes an integral.
Kronecker delta becomes Dirac delta

The tensor product of two column vectors:
[a1 a2 ... an]' ⊗ [b1 b2 ... bm]' = [a1b1 a1b2 ... a2b1 a2b2 ... anbm]'

The tensor product of two vectors is bilinear (it is linear if you hold one of the arguments (vectors) fixed)
The tensor product of three or more vectors is multilinear (it is linear if you hold all arguments except one fixed)
The tensor product of quantum states gives you a quantum state (it is closed)
If we can write a linear combination of vectors as a tensor products of other different vectors, we can call that a product state

(This state represents entanglement of 2 qubits)
1/sqrt(2)∣00⟩ + 1/sqrt(2)|01⟩ is an example of something that *CANNOT* be written as a tensor product

Entangled states are states that are not indpendent of each other.
Product states are independent of each other.

These vectors live in Hilbert space, which means in some sense they are closed, the operations we do to the vectors don't give you something outside of the space.

Bell States/Basis are entangled states that are well known enough to have a name/notation for them:
|Φ+⟩ = 1/sqrt(2)∣00⟩ + 1/sqrt(2)|11⟩
|Φ-⟩ = 1/sqrt(2)∣00⟩ - 1/sqrt(2)|11⟩
|ψ+⟩ = 1/sqrt(2)∣01⟩ + 1/sqrt(2)|10⟩
|ψ-⟩ = 1/sqrt(2)∣01⟩ - 1/sqrt(2)|10⟩

GHZ State (Like Bell states but for 3 qubits instead of 2)
1/sqrt(2)∣000⟩ + 1/sqrt(2)|111⟩

W State (Like GHZ State)
1/sqrt(3)∣001⟩ + 1/sqrt(3)|010⟩ + 1/sqrt(3)∣100⟩

"""

import numpy
import math

def PrettyPrint(states, base):
    states = sorted(states, key=lambda x: x[1])
    print("( ", end="")
    for i in range(len(states)):
        print("%s |%s>" % (str(states[i][0]), str(int(states[i][1], base))), end="")
        if i+1 < len(states):
            print(" + ", end="")
    print(")")

def PrettyPrintBinary(states):
    PrettyPrint(states, 10)

def PrettyPrintInteger(states):
    PrettyPrint(states, 2)

def StateToVec(states):
    length = 0
    for state in states:
        length = max(length, int(state[1], 2))
    length = 1 << math.ceil(math.log2(length))
    
    vector = [0] * length
    for state in states:
        index = int(state[1], 2)
        vector[index] = state[0]
    return vector

def VecToState(vector):
    states = []
    for index in range(len(vector)):
        if vector[index] == 0:
            continue

        location = bin(index)[2:]
        location = "0" * (int(math.log2(len(vector))) - len(location)) + location
        states.append((vector[index], location))
    return states

def VerifyProbability(states):
    value = 0
    for state in states:
        value += abs(state[0]**2)
    return value

myState1 = [
    (numpy.sqrt(0.1), '00'),
    (numpy.sqrt(0.4), '01'),
    (-numpy.sqrt(0.5), '11'),
]

myState2 = [
    (numpy.sqrt(0.1)*1.j, '101'),
    (numpy.sqrt(0.5), '000'),
    (-numpy.sqrt(0.4), '010'),
]

myState3 = [
    (0.977668244563 + 0.147760103331j, '000'),
    (0.0223317554372 - 0.147760103331j, '101'),
]

print(VerifyProbability(myState1))
print(VerifyProbability(myState2))
print(VerifyProbability(myState3))

PrettyPrintBinary(myState2)
PrettyPrintInteger(myState2)

print(StateToVec(myState2))
print(VecToState(StateToVec(myState2)))
