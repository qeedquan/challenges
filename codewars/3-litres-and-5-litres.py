#!/usr/bin/env python3

"""

The leader of the village sends you to carry back exactly c litres from the mountain shrine holy water, but you can only bring back one of the 2 jars a or b (a and b are known values) in the shrine. You also have to do that in one travel... you can't risk going to the shrine and die trying to fill one of the jars with c litres. So help yourself by precalculating if it's possible to do that in any way and inform the leader about the possibility of you been able to achieve the task (You are very trustworthy and won't like to disappoint your leader) :)


INPUT
a, b the volumes of jars you are given and c the volume of the water you have to carry back

Output
true or false depending upon if it's possible to fill one of the a or b litre jar with demand c litre.

Example
My favorite explanation
https://www.youtube.com/watch?v=6cAbgAaEOVE

OR (For those who like to read) ;)
For a = 3, b = 5 and c = 4 litre

Fill the jar a full and pour that in jar b now jar a contains 0 litres and jar b contains 3 litres of water

Repeat 1st step once again and now you have jar b full with 5 litres and jar a left with 1 litre.

Now empty the jar b and pour the water left in jar a (1 litre) into jar b, now jar a is empty and jar b contains 1 litre of water.

Now just fill again the jar a and pour that back into jar b to get 4 litres (Hope you understand)

"""

from math import gcd

def measurable(a, b, c):
    return c <= max(a, b) and c%gcd(a, b) == 0

def main():
    assert(measurable(3, 5, 4) == True)
    assert(measurable(5, 8, 3) == True)
    assert(measurable(6, 10, 5) == False)
    assert(measurable(10, 20, 15) == False)

main()
