#!/usr/bin/env python3

from math import *
from random import random

"""

Q: If a current of 3A is divided by the following circuit, the current flowing through 4 Ohm is
A: 2 A 

"""

def p1():
    R1 = 8
    R2 = 4
    It = 3
    Rt = 1/(1/R1 + 1/R2)
    Et = It * Rt
    E1 = Et
    E2 = Et
    I1 = E1 / R1
    I2 = E2 / R2
    print("P1")
    print(I2)
    print()

"""

Q: The diagram at the right shows part of a circuit into which a current I is flowing. Which ammeter shows the highest reading?
A: The ammeter will read the same current at all points

"""

def p2():
    R1 = 6
    R2 = 4
    R3 = 10
    R12 = R1 + R2
    Rt = 1/(1/R12 + 1/R3)
    It = random()
    Et = Rt * It
    E12 = Et
    E3 = Et
    I3 = E3 / R3
    I1 = I3
    I2 = I3
    E1 = I1 * R1
    E2 = I2 * R2
    print("P2")
    print(I1, I2, I3)
    print()

"""

Q: The diagram to the right represents a part of a circuit containing an ohmic resistor, a voltmeter and an ammeter.
   If the reading on the ammeter A increases the reading on voltmeter V…
A: increases in the same ratio.

"""

def p3():
    I = random()
    s = random()
    R = random()
    E = I * R
    Es = E * s
    Is = I * s
    print("P3")
    print(Es/E, Is/I)
    print()

"""

Q: A battery is connected to two identical light bulbs in parallel as well as another identical bulb in series.
   An ammeter and a voltmeter are also connected as shown in the circuit diagram below. 
   One of the light bulbs connected in parallel is unscrewed. How will the ammeter and the voltmeter readings change? 
A: Voltmeter reading increases, Ammeter reading decreases

"""

def p4():
    print("P4")
    print("V up, A down")
    print()

"""

Q: A student connects a circuit as shown in the diagram to the right. They use a source of electricity with an electromotive force (emf) of 12V.
   Which one of the following best gives the ammeter and voltmeter readings which the student is most likely to get with this circuit?
A: Ammeter reads 0 A, Voltmeter reads 12 V

"""

def p5():
    print("P5")
    print("A 0, V 12")
    print()

"""

Q: 9V battery is composed of six 1.5V cells, which are connected in series.
   Each cell has an internal resistance of 0.2W.
   What is the highest current that can be obtained from such a battery? 
A: 6*1.5 V = 9 V
   Treat the internal resistance of the batteries as a series of resistors, so we have
   0.2 * 6 = 1.2 R
   I = 9 / 1.2 = 7.5 A

"""

def p10():
    E = 1.5 * 6
    R = 0.2 * 6
    I = E / R
    print("P10")
    print(I)
    print()

p1()
p2()
p3()
p4()
p5()
p10()
