#!/usr/bin/env python3

r"""

Create a decorator expected_type() that checks if what the decorated function returns is of expected type. An UnexpectedTypeException should be raised if the type returned by the decorated function doesn't match the ones expected.

Requirements:

expected_type() should accept a tuple of many types that may be valid

UnexpectedTypeException should be raised if decorated function returns object of type that wasn't defined in expected_type()'s arguments (you have to implement that class)

return_something will be decorated with expected_type in the tests and will look exactly like in the example below

Example:

@expected_type((str,))
def return_something(input):
    # do stuff here with the input...
    return something

>>> return_something('The quick brown fox jumps over the lazy dog.')

'The quick brown fox jumps over the lazy dog.'

>>> return_something('The quick brown fox jumps over the lazy dog.')

'Maybe you'll output another string...'

>>> return_something(None)

UnexpectedTypeException: Was expecting instance of: str    <<< if the returned type isn't one of the expected ones.q

"""

class UnexpectedTypeException(Exception):
    pass

def expected_type(t):
    def d(f):
        def w(*a, **k):
            r = f(*a, **k)
            if not isinstance(r, t):
                raise UnexpectedTypeException('Was expecting instance of: ' + ', '.join(i.__name__ for i in t))
            return r
        return w
    return d

seen = {}

@expected_type((str,))
def return_something(input):
    global seen
    if input in seen:
        return "Maybe you'll output another string..."
    seen[input] = True
    return input

print(return_something('The quick brown fox jumps over the lazy dog.'))
print(return_something('The quick brown fox jumps over the lazy dog.'))
try:
    return_something(None)
except Exception as e:
    print(e)

