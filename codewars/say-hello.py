#!/usr/bin/env python3

"""

Say hello!

Write a function to greet a person. Function will take name as input and greet the person by saying hello. Return null/nil/None if input is empty string or null/nil/None.

Example:

greet("Niks") === "hello Niks!";
greet("") === null; // Return null if input is empty string
greet(null) === null; // Return null if input is null

"""

def greet(name):
    if name == None or type(name) is not str or name == "":
        return None
    return f"hello {name}!"

def main():
    assert(greet("Niks") == "hello Niks!")
    assert(greet("") == None)
    assert(greet(None) == None)

main()
