#!/usr/bin/env python3

"""

Not a dupe to this. That question asks specifically for counting up forever, while this question allows many other approaches.
https://codegolf.stackexchange.com/questions/63834/count-up-forever

Write a program or function which, given infinite time and memory, would print an infinite non-periodic output.

Clarifications
'Infinite' means the solution keeps outputting something without any further inputs or operations after successfully started the program or function.
'Non-periodic' means the output has no possibility of eventually repeating the same section forever (regardless of how long that period is). An example of a valid solution would be printing the digits of an irrational number.
Random solutions would not count unless you can prove that it fits the requirements. Date/time-based solutions may also be invalid if they are not stored with arbitrary precision.
Winner
Shortest code (in bytes) wins.

"""

"""

@xnor

Prints

<built-in function id>
(<built-in function id>,)
((<built-in function id>,),)
(((<built-in function id>,),),)
((((<built-in function id>,),),),)
and so on. Starts with the built-in function id, the shortest pre-initialized variable name, and repeatedly turns it into a tuple of itself.

"""
while 1:
    print(id)
    id=id,

