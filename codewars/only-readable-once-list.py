#!/usr/bin/env python3

"""

Attention Agent.

The White House is currently developing a mobile app that it can use to issue instructions to its undercover agents.

Part of the functionality of this app is to have messages that can be read only once, and are then destroyed.

As our best undercover developer, we need you to implement a SecureList class that will deliver this functionality.

Behaviour different to the traditional list is outlined below:

Accessing an item at any index should delete the item at that index eg:

messages=SecureList([1,2,3,4])
print(messages[1])  # prints 2
print(messages)     # prints [1,3,4]

Printing the whole list should clear the whole list eg:

messages=SecureList([1,2,3,4])
print(messages)     # prints [1,2,3,4]
print(messages)     # prints []

Viewing the representation of the list should also clear the list eg:

messages=SecureList([1,2,3,4])
print("my messages are: %r."%messages)     # prints "my messages are: [1,2,3,4].
print(messages)     # prints []

To complete this kata you need to be able to define a class that implements __getitem__(), __str__(), __repr__(), and possibly __len__().

Good luck Agent.

"""

class SecureList():
    def __init__(self, a=()):
        self.a = list(a)
    
    def __getitem__(self, i):
        if isinstance(i, slice):
            r = self.a[i]
            del self.a[i]
            return r
        return self.a.pop(i)
    
    def __len__(self):
        return len(self.a)
    
    def __str__(self):
        t = self.a
        self.a = []
        return str(t)
    
    __repr__ = __str__

messages = SecureList([1, 2, 3, 4])
print(messages[1])
print(messages)

messages = SecureList([1, 2, 3, 4])
print(messages)
print(messages)

messages = SecureList([1, 2, 3, 4])
print("my messages are: %r." % messages)
print(messages)

