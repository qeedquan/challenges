#!/usr/bin/env python3

"""

Dirac notation: sparse representation
Vector notation: dense representation

Classical: n-bits is 2^n states
Quantum:   n-qubits is 2^(2^n) states because of superposition

https://en.wikipedia.org/wiki/Probability_amplitude
For a quantum state, it needs to obey the rule where the sum of the absolute value of the squares of the amplitudes need to add up to 1.
Each individual value of the amplitude of a state represents a "probability" of measuring the outcome once the collapse occurs.

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
