#!/usr/bin/env python3

"""

How many times we create a python class and in the init method we just write:

self.name1 = name1
self.name2 = name2
.....

for all arguments.....

How boring!!!!

Your task here is to implement a metaclass that let this instantiation be done automatically. But let's see an example:

class Person(metaclass=LazyInit):
  def __init__(self, name, age): pass

When we create a Person object like:

a_person = Person('John', 25)
The expected behavior will be:

print(a_person.name) # this will print John
print(a_person.age)  # this will print 25

Obviously the number of arguments might be different from class to class.

Don't worry about **kwargs you will never be given keyword arguments in this kata!!!

A little hint: a decorator could help you out doing the job!!!

Good luck lazy folks.....

"""

from inspect import signature

class LazyInit(type):
    def __new__(m, n, b, d):
        f = d.get('__init__')
        if f:
            names = [p.name for p in signature(f).parameters.values()][1:]
            def __init__(self, *a):
                for k, v in zip(names, a):
                    setattr(self, k, v)
                f(self, *a)
            d['__init__'] = __init__
        return super().__new__(m, n, b, d)

class Person(metaclass=LazyInit):
    def __init__(self, name, age):
        pass

a_person = Person('John', 25)
print(a_person.name)
print(a_person.age)
