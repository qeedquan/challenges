#!/usr/bin/env python3

"""

Write a class decorator @remember which makes the class remember its own objects, storing them in a dictionary with the creating arguments as keys.

Also, you have to avoid creating a new member of the class with the same initial arguments as a previously remembered member.

Additionally, if the (decorated) class is A, you will have to reach that dictionary of remembered objects directly on A, i.e. by A[args] and by the loop for x in A over the keys.

Example
A sample usage:

@remember
class A(object):
  def __init__(self, x,y=0,z=0):
    pass

a = A(1)
b = A(2,3)
c = A(4,5,6)
d = A(1)

>>> A[1] is a is d
True
>>> A[2,3] is b
True
>>> A[4,5,6] is c
True
>>> for x in A: print x,
(2,3) (4,5,6) 1

Notes.

Other dict methods like items(), keys(), etc. are nice to have but not required to be implemented on the decorated class itself for this kata.
You don't have to deal with named arguments at creating an instance of your class (such as z in A(1,z=5)).
If the constructor is called with a single argument, the argument itself will be the key and not its 1-tuple.

"""

def remember(cls):
    class Meta(type(cls)):
        def __call__(cls, *args, **kwargs):
            key = args
            if len(args) == 1:
                key = args[0]
            
            if key in cls.remember:
                return cls.remember[key]
            
            obj = super().__call__(*args, **kwargs)
            cls.remember[key] = obj
            return obj
        
        def __getitem__(cls, key):
            return cls.remember[key]
        
        def __iter__(cls):
            return iter(cls.remember)
    
    d = dict(cls.__dict__)
    d['remember'] = {}
    d['__class_getitem__'] = classmethod(lambda c, k: c.remember[k])
    
    return Meta(cls.__name__, cls.__bases__, d)


@remember
class A(object):
    def __init__(self, x, y=0, z=0):
        pass

a = A(1)
b = A(2, 3)
c = A(4, 5, 6)
d = A(1)

assert(A[1] == a)
assert(A[2, 3] == b)
assert(A[4, 5, 6] == c)
assert(A[1] == d)
for x in A:
    print(x,)

