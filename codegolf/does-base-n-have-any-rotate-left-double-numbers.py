#!/usr/bin/env python3

r"""

Task
A Rotate-Left-Double number in base n is a number m, when its base-n digits are rotated left once, equals 2m.
The base-n representation of m cannot have leading zeros.

One example in base 7 is the number 480, or 12547. When rotated left once, the value becomes 25417=960.

Given the base n≥2, determine if there exists a Rotate-Left-Double number in base n.

You can use your language's convention to represent truthy/falsy, or use two distinct values for truthy and falsy respectively.

Scoring and winning criterion
Standard code-golf rules apply. Shortest code in bytes wins.

Test cases
n -> answer (example if true)
-----------------------------
2 -> false
3 -> false
4 -> false
5 -> true (13 x 2 = 31)
6 -> false
7 -> true (1254 x 2 = 2541)
8 -> true (25 x 2 = 52)
9 -> true (125 x 2 = 251)
10 -> false
11 -> true [3,7]
12 -> true [2,4,9,7]
13 -> true [1,2,4,9,5,11,10,8,3,7]
14 -> true [4,9]
15 -> true [1,2,4,9,3,6,13,12,10,5,11,8]
16 -> true [2,4,9]
17 -> true [1,2,4,9]

Reference implementation in Python.
https://tio.run/##bVFdb4IwFH3nV5xkWQSsRvBlqfGXNH2ga9VmeGEIW/317BbJcMlemvbm3PPV9t5fGirH0boT@sZUN5eSMJlMEHCE0gm@L752IEnC8sT6r2tjJ8wBYVu1rSOb2ixB5/qhIwQl5abQSSQ8dc31mXKGdM4O7y6tq6uxFYK4S4TcrO8CJLDLkuTUdDDwjKzo7NJSFG9xve089TAiwefgBhf9qaAR0WFBF6yl4U/M8IoSrr65f3GlMKLMfgNOlCwCYt7psW2bNmU7iGR/oiBn4uPxaagKqbEGKVloAQ47m6UDTOeqDyZ5mSd8jU784mTqhoWZk9XXUF4/3iFO5l9ZtNh4lscjgtgalZM6@4kbKrYv5wTz91A5p6jqOg1qs2c4qyu10/leQBleyfdPDU3bmVx6ZkOxyOjzEWNFTX/xdF6N4w8

def tobase(n,b):
 x = []
 while n:n,d = divmod(n,b); x.append(d)
 return x[::-1]
def frombase(n,b):
 return reduce(lambda x,y: x*b+y, n, 0)

for b in range(2,18):
 print b,
 queue = [[x] for x in range(1,b)] if b % 2 else [[x] for x in range(2,b,2)]
 while queue:
  n = queue.pop(0)
  if frombase(n,b) * 2 == frombase(n[1:] + n[:1], b): print n; break
  #print n
  for i in range(b):
   n2 = n + [i]
   n2x2 = tobase(frombase(n2,b)*2,b)
   if n2[1:] == n2x2[:-1]: queue.append(n2)
  if all(x[-3:] in [[0]*3, [b-1]*3] for x in queue): queue = []
 else:
  print 'nothing'

"""

from functools import reduce

def tobase(n, b):
    x = []
    while n:
        n, d = divmod(n, b)
        x.append(d)
    return x[::-1]

def frombase(n, b):
    return reduce(lambda x, y: x * b + y, n, 0)

for b in range(2, 18):
    print(b, end=" -> ")
    queue = [[x] for x in range(1, b)] if b % 2 else [[x] for x in range(2, b, 2)]
    while queue:
        n = queue.pop(0)
        if frombase(n, b) * 2 == frombase(n[1:] + n[:1], b):
            print(n)
            break
        for i in range(b):
            n2 = n + [i]
            n2x2 = tobase(frombase(n2, b) * 2, b)
            if n2[1:] == n2x2[:-1]:
                queue.append(n2)
        if all(x[-3:] in [[0] * 3, [b - 1] * 3] for x in queue):
            queue = []
    else:
        print("nothing")

