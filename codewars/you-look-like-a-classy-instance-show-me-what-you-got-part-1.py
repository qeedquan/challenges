#!/usr/bin/env python3

"""

The built-in print function for Python class instances is not very entertaining.

In this kata, we will implement a function show_me(instance) that takes an instance as parameter and returns the string "Hi, I'm one of those (classname)s! Have a look at my (attrs)." , where (classname) is the class name and (attrs) are the class's attributes. If (attrs) contains only one element, just write it. For more than one element (e.g. a, b, c), it should list all elements sorted by name in ascending order (e.g. "... look at my a, b and c.").

Example: For an instance porsche = Vehicle(2, 4, 'gas') of the class

class Vehicle:

    def __init__(self, seats, wheels, engine):
        self.seats = seats
        self.wheels = wheels
        self.engine = engine

the function call show_me(porsche) should return the string "Hi, I'm one of those Vehicles! Have a look at my engine, seats and wheels.".

"""

class Vehicle:
    def __init__(self, seats, wheels, engine):
        self.seats = seats
        self.wheels = wheels
        self.engine = engine

def show_me(instance):
    class_name = instance.__class__.__name__
    attrs = sorted(vars(instance).keys())
    
    if len(attrs) == 1:
        attrs_str = attrs[0]
    elif len(attrs) == 2:
        attrs_str = f"{attrs[0]} and {attrs[1]}"
    else:
        attrs_str = ", ".join(attrs[:-1]) + f" and {attrs[-1]}"
    return f"Hi, I'm one of those {class_name}s! Have a look at my {attrs_str}."

print(show_me(Vehicle(1, 2, 3)))

