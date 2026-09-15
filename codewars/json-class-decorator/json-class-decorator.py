#!/usr/bin/env python3

"""

Lately you've fallen in love with JSON, and have used it to template different classes.

However you feel that doing it by hand is too slow, so you wanted to create a decorator that would do it auto-magically!

Explanation
Your task is to write a decorator that loads a given JSON file object and makes each key-value pair an attribute of the given class.

Example
Given the following data is written in the /tmp/myClass.json file:

{
  "foo": "bar",
  "an_int": 5,
  "this_kata_is_awesome": true
}

Here's how you would use the decorator:

@jsonattr("/tmp/myClass.json")
class MyClass:
    pass


MyClass.foo == "bar"
MyClass.an_int == 5
MyClass.this_kata_is_awesome == True

"""

import json

def jsonattr(filepath):
    def decorator(cls):
        with open(filepath) as f:
            data = json.load(f)
        for k, v in data.items():
            setattr(cls, k, v)
        return cls
    return decorator

@jsonattr("myClass.json")
class MyClass:
    pass

assert(MyClass.foo == "bar")
assert(MyClass.an_int == 5)
assert(MyClass.this_kata_is_awesome == True)

