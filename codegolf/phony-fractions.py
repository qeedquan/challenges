#!/usr/bin/env python3

"""

Context
If a0 and b0 are two decimal numbers, with a and b representing the decimal expansion of all digits but the least significant one, then we know that

a0/b0 = a[0]/b[0] = a/b

Phony fraction
A phony fraction is a fraction where the numerator and denominator share a digit (other than a 0 in the units place) and, when that digit is erased from both numerator and denominator, the simplified fraction happens to be equal to the original one.

Example
16/64 is a phony fraction because if we remove the 6, we get 16/64 = 1[6]/[6]4 = 1/4, even though the intermediate step of removing both sixes is wrong.

Task
Given a fraction, determine if it is phony or not.

Note
Notice that 10/20 is not a phony fraction. Even though 10/20 = 1/2, the simplification here was mathematically sound, you divided numerator and denominator by 10, which amounts to "crossing out a 0 on the num. and the den.".

On the other hand, 102/204 = 12/24 is a phony fraction, because supposedly we can't cross out the 0s.

Because of this, when the input fraction is such that crossing out 0 gives an equivalent fraction to the original, the behaviour is unspecified.

Input
The fraction we care about, with positive numerator and denominator, in any sensible format. Some examples of sensible formats include:

a list [num, den] or [den, num]
a string of the form "num/den"
the exact fraction, if your language supports it
two different arguments to your function
Assume both are greater than 9. You can also assume the denominator is strictly larger than the numerator.

Output
A Truthy value if the fraction is phony and a Falsy value if it is not.

Test cases
(Please keep an eye out for the comments, as some people have really nice test case suggestions! I'll edit them in, but sometimes I don't do it immediately.)

Truthy
69/690 = 9/90
99/396 = 9/36
394/985 = 34/85
176/275 = 16/25
85/850 = 5/50
59/295 = 5/25
76/760 = 6/60
253/550 = 23/50
52/520 = 2/20
796/995 = 76/95
199/796 = 19/76
88/583 = 8/53
306/765 = 30/75
193/965 = 13/65
62/620 = 2/20
363/561 = 33/51
396/891 = 36/81
275/770 = 25/70
591/985 = 51/85
165/264 = 15/24
176/671 = 16/61
385/781 = 35/71
88/484 = 8/44
298/596 = 28/56
737/938 = 77/98
495/594 = 45/54
693/990 = 63/90
363/462 = 33/42
197/985 = 17/85
462/660 = 42/60
154/451 = 14/41
176/374 = 16/34
297/990 = 27/90
187/682 = 17/62
195/975 = 15/75
176/473 = 16/43
77/671 = 7/61
1130/4181 = 130/481
Falsy
478/674
333/531
309/461
162/882
122/763
536/616
132/570
397/509
579/689
809/912
160/387
190/388
117/980
245/246
54/991
749/892
70/311
344/735
584/790
123/809
227/913
107/295
225/325
345/614
506/994
161/323
530/994
589/863
171/480
74/89
251/732
55/80
439/864
278/293
514/838
47/771
378/627
561/671
43/946
1025/1312
You can check this reference implementation that I used to generate some phony fractions by brute-force.

This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it... And happy golfing!

"""

from fractions import *

def ratios(s):
    r = set()
    for i, x in enumerate(s):
        f = Fraction(int(s[:i] + s[i+1:]), int(s))
        r.add((f, x))
    return r

"""

@Jitse

lambda a,b:g(a)&g(b)
g=lambda s:{(int(s[:i]+s[i+1:])/int(s),x)for i,x in enumerate(s)}

Making use of the fact that the boolean value for a0/b0==a/b is equivalent to a0/a==b0/b. The helper function g generates all ratios a0/a and keeps track of the removed digit. Then it does the same for b0/b. The main function determines the intersection of the two sets.

Returns a non-empty set (boolean True in Python) if a match is found, and an empty set (boolean False in Python) otherwise.

"""

def phony(a, b):
    x = ratios(str(a))
    y = ratios(str(b))
    return len(x & y) > 0

def main():
    truthy = [[69, 690], [99, 396], [394, 985], [176, 275], [85, 850], [59, 295], [76, 760], [253, 550], [52, 520], [796, 995], [199, 796], [88, 583], [306, 765], [193, 965], [62, 620], [363, 561], [396, 891], [275, 770], [591, 985], [165, 264], [176, 671], [385, 781], [88, 484], [298, 596], [737, 938], [495, 594], [693, 990], [363, 462], [197, 985], [462, 660], [154, 451], [176, 374], [297, 990], [187, 682], [195, 975], [176, 473], [77, 671], [1130, 4181]]
    falsy = [[478, 674], [333, 531], [309, 461], [162, 882], [122, 763], [536, 616], [132, 570], [397, 509], [579, 689], [809, 912], [160, 387], [190, 388], [117, 980], [245, 246], [54, 991], [749, 892], [70, 311], [344, 735], [584, 790], [123, 809], [227, 913], [107, 295], [225, 325], [345, 614], [506, 994], [161, 323], [530, 994], [589, 863], [171, 480], [74, 89], [251, 732], [55, 80], [439, 864], [278, 293], [514, 838], [47, 771], [378, 627], [561, 671], [43, 946], [1025, 1312]]

    for n, d in truthy:
        assert(phony(n, d) == True)
    for n, d in falsy:
        assert(phony(n, d) == False)

main()
