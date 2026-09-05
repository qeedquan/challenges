#!/usr/bin/env python3

"""

DefaultList
The collections module has defaultdict, which gives you a default value for trying to get the value of a key which does not exist in the dictionary instead of raising an error. Why not do this for a list?

Your job is to create a class (or a function which returns an object) called DefaultList. The class will have two parameters to be given: a list, and a default value. The list will obviously be the list that corresponds to that object. The default value will be returned any time an index of the list is called in the code that would normally raise an error (i.e. i > len(list) - 1 or i < -len(list)). This class must also support the regular list functions extend, append, insert, remove, and pop.

Because slicing a list never raises an error (slicing a list between two indexes that are not a part of the list returns [], slicing will not be tested for.

Example

lst = DefaultList(['hello', 'abcd', '123', 123, True, False], 'default_value')

lst[4] = True

lst[80] = 'default_value'

lst.extend([104, 1044, 4066, -2])

lst[9] = -2

"""

class DefaultList:
    def __init__(self, initial, value):
        self.data = list(initial)
        self.default = value

    def __getitem__(self, index):
        if -len(self.data) <= index < len(self.data):
            return self.data[index]
        return self.default

    def __setitem__(self, index, value):
        if index >= len(self.data):
            self.data.extend([self.default] * (index - len(self.data) + 1))
        elif index < -len(self.data):
            self.data = [self.default] * (-index - len(self.data)) + self.data
            index = 0
        self.data[index] = value

    def extend(self, iterable):
        self.data.extend(iterable)

    def append(self, item):
        self.data.append(item)

    def insert(self, index, item):
        self.data.insert(index, item)

    def remove(self, item):
        self.data.remove(item)

    def pop(self, index=-1):
        return self.data.pop(index)

    def __repr__(self):
        return repr(self.data)

def main():
    lst = DefaultList(['hello', 'abcd', '123', 123, True, False], 'default_value')
    assert(lst[4] == True)
    assert(lst[80] == 'default_value')
    lst.extend([104, 1044, 4066, -2])
    assert(lst[9] == -2)

main()
