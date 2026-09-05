#!/usr/bin/env python3

"""

Implement the validate_args decorator, which raises an error (InvalidArgument) when the decorated function is called with arguments of the wrong type. Validate_args takes in a sequence of argument types as a variable number of arguments. You do not have to check that the number of arguments matches, only their type (number of arguments will not be tested).

Your decorator must be well-behaved, i.e. the returned function must have the same name and docstring as the original, and must be able to handle the same arguments.

Example :

@validate_args(str)
def say_hello(name):
    return "Hello, " + name

say_hello(1)  # Raises InvalidArgument
say_hello("Python")  # Returns "Hello, Python"

InvalidArgument is preloaded for you. You may use it as if you had defined it in your own code.

"""

from functools import wraps

def validate_args(*types):
    def decorator(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            for arg, expected in zip(args, types):
                if not isinstance(arg, expected):
                    raise InvalidArgument
            return func(*args, **kwargs)
        return wrapper
    return decorator

@validate_args(str)
def say_hello(name):
    return "Hello, " + name

try:
    say_hello(1)
except Exception as ex:
    print("Exception: ", ex)

print(say_hello("Python"))

