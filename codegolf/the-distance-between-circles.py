#!/usr/bin/env python3

"""

Imagine you are given two lists of numbers which are to be interpreted as points on a circle of circumference 1000. Let us say

circleA = [10, 24, 44, 175, 321, 579, 618, 841, 871, 979]
circleB = [270, 283, 389, 406, 435, 457, 612, 684, 692, 732]
To measure the distance between these two circles we do the following.

For the first point in circleA, starting from the left, we find the next biggest point in circleB. So 10 finds 270 and is matched up with it. Now, using 270, we skip to the next biggest point in circle A which is 321. We then use 321 to find 389 and match up 321 and 389 and repeat until the end of circleA or we can't find a matching pair.

This gives us a list of pairs as follows.

[(10,270), (321, 389), (579,612), (618,684)]
We say the distance between circleA and circleB is just the average difference between pairs. That is (270-10 + 389-321+612-579+684-618)/4 = 106.75

Now comes the tricky part. As the point are on a circle, we can rotate circleB and recompute this distance. The task is to compute the following value.

For arbitrary inputs circleA and circleB, the task is to compute the average distance between circleA and all rotations of circleB.

In order to make it interesting I am setting this as fastest-code challenge. I will test with increasing size circles created using (in python)

import random
circumference = 1024
numberpoints = circumference/64
circleA = sorted(random.sample(range(circumference),numberpoints))
circleB = sorted(random.sample(range(circumference),numberpoints))
I will just double the size of circumference until the code takes more than 1 minute to run on my computer. You output should be accurate to machine precision.

Please provide full instructions for how to compile and run your code on a linux machine.

A rotation simply means adding an offset modulo circumference and then resorting. In python

rotatedcircleB = sorted([(c+offset)%circumference for c in circleB])

"""

from bisect import bisect_left

# ported from @BeetDemGuise solution
def circular_distance(circle_a, circle_b):
    total = 0
    count = 0
    value_on_a = circle_a[0]
    value_on_b = 0
    while 1:
        try:
            insertion_point = bisect_left(circle_b, value_on_a)
            value_on_b = circle_b[insertion_point]

            total += value_on_b - value_on_a
            count += 1

            value_on_a = circle_a[bisect_left(circle_a, value_on_b+1)]
        except IndexError:
            break
    return total/count

def rotate(circle, offset, circumference=1024):
    return sorted((point + offset) % circumference for point in circle)

def get_average_distance(circle_a, circle_b, circumference=1024):
    total = 0
    for iteration_num in range(circumference):
        total += circular_distance(circle_a, rotate(circle_b, iteration_num))
    return total/circumference

circleA = [10, 24, 44, 175, 321, 579, 618, 841, 871, 979]
circleB = [270, 283, 389, 406, 435, 457, 612, 684, 692, 732]
print(circular_distance(circleA, circleB))
print(get_average_distance(circleA, circleB))

