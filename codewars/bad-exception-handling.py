#!/usr/bin/env python3

"""

We all know how to handle exceptions in Python. Just use:

try:
    num = float(input())
except ValueError:
    print("That's not a number!")
else:
    print(num)

Code such as this

def factorial(x, n = 1):
    if x == 0:
      raise ValueError(n)
    factorial(x - 1, n * x)

relies on ridiculous exception misuse, but you can't change it because that would require a complete refactor. Code such as this

try:
    return int(input("Input a number: ")
except ValueError:
    return 4 # random number

relies on reasonable exception use - almost all of the Python documentation examples are written in this way.

What if you are using a faulty implementation of Embedded Python that doesn't implement the try statement? Where sys.excepthook is a hard-coded, unoverrideable value? Where even __file__ is not defined? How do you use basic functions like list.index?

Your task is to write a function that can handle exceptions raised in a program or function without using try or except. Somehow.

The first argument of your function handle will be a lambda requiring no parameters. You will call this function and handle any exceptions raised. The second argument will be a callable success:

def success(func, val):
    pass

The third argument will be a callable failure:

def failure(func, exc):
    pass

Subsequent arguments will be exceptions. If instances of these exceptions are raised, you must call the handler and no error message must be printed to stderr. If the exception raised is not provided as an argument, it should appear as though the exception was never caught.

Pass the return value of func to success unless it raises an exception. If it raises an exception that isinstance of an exception class passed to handle, call failure with an instance of the raised exception.

Don't worry about the little things like dealing with the extra arguments to exceptions or maintaining the call stack. Whoever writes code like that deserves the extra work.

What does "catching an exception" mean?

It means:

The exception will not be printed to stderr.
Code can continue to be executed.
The failure callable knows what the exception was.

"""

def handle(func, success, failure, *exceptions):
    class Handler:
        def __enter__(self):
            pass
        
        def __exit__(self, exc_type, exc_val, exc_tb):
            if exc_type and any(isinstance(exc_val, e) for e in exceptions):
                failure(func, exc_val)
                return True
    
    with Handler():
        success(func, func())

def run():
    print("Running")

def win(*args):
    print("Win")

def lose(*args):
    print("Lose")

handle(run, win, lose)
