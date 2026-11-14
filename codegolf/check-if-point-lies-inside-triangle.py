#!/usr/bin/env python3

"""

Your goal is to determine whether a given 2D point X lies within the area of the triangle with given vertices A,B,C.

Write a function that takes in the coordinates of the test point X and the three triangle vertices (so that's 8 coordinates total) and returns True if the point lies inside that triangle, and False if it lies outside.

Don't worry about edge cases. If the point lies on the boundary of the triangle (edge or vertex) or the triangle is actually a line segment, your code can do whatever, including crashing. Also don't worry about numerical stability or floating-point precision.

Your code must be a named function. Code snippets will not be accepted.

Fewest characters wins.

Input:

Eight real numbers representing coordinates. The numbers will lie in the range (-1,1).

The exact input format is flexible. You could, for example, take in eight numbers, a list of eight numbers, a list of four points each given by a tuple, a 2*4 matrix, four complex numbers, two lists of the x-coordinates and y-coordinates, and so on.

The input needs to just be the numbers in some container, with no additional data. You can't use the input to do any preprocessing, nor may you require any constraints on the input, such as requiring the points be given in ascending y coordinate.
Your input must allow any eight coordinates (though your code can behave arbitrarily in the edge cases mentioned earlier).

Please state your input format.

Output:

Either the corresponding Boolean True/False, the corresponding number 1/0, or the analogues in your language.

Test cases

The inputs are given a list [X,A,B,C] of four tuples, the test point first, then the three triangle vertices. I've grouped them into those whose outputs should be True and those that should be False.

True instances:

[(-0.31961, -0.12646), (0.38478, 0.37419), (-0.30613, -0.59754), (-0.85548, 0.6633)]
[(-0.87427, -0.00831), (0.78829, 0.60409), (-0.90904, -0.13856), (-0.80685, 0.48468)]
[(0.28997, -0.03668), (-0.28362, 0.42831), (0.39332, -0.07474), (-0.48694, -0.10497)]
[(-0.07783, 0.04415), (-0.34355, -0.07161), (0.59105, -0.93145), (0.29402, 0.90334)]
[(0.36107, 0.05389), (0.27103, 0.47754), (-0.00341, -0.79472), (0.82549, -0.29028)]
[(-0.01655, -0.20437), (-0.36194, -0.90281), (-0.26515, -0.4172), (0.36181, 0.51683)]
[(-0.12198, -0.45897), (-0.35128, -0.85405), (0.84566, 0.99364), (0.13767, 0.78618)]
[(-0.03847, -0.81531), (-0.18704, -0.33282), (-0.95717, -0.6337), (0.10976, -0.88374)]
[(0.07904, -0.06245), (0.95181, -0.84223), (-0.75583, -0.34406), (0.16785, 0.87519)]
[(-0.33485, 0.53875), (-0.25173, 0.51317), (-0.62441, -0.90698), (-0.47925, 0.74832)]
False instances:

[(-0.99103, 0.43842), (0.78128, -0.10985), (-0.84714, -0.20558), (-0.08925, -0.78608)]
[(0.15087, -0.56212), (-0.87374, -0.3787), (0.86403, 0.60374), (0.01392, 0.84362)]
[(0.1114, 0.66496), (-0.92633, 0.27408), (0.92439, 0.43692), (0.8298, -0.29647)]
[(0.87786, -0.8594), (-0.42283, -0.97999), (0.58659, -0.327), (-0.22656, 0.80896)]
[(0.43525, -0.8923), (0.86119, 0.78278), (-0.01348, 0.98093), (-0.56244, -0.75129)]
[(-0.73365, 0.28332), (0.63263, 0.17177), (-0.38398, -0.43497), (-0.31123, 0.73168)]
[(-0.57694, -0.87713), (-0.93622, 0.89397), (0.93117, 0.40775), (0.2323, -0.30718)]
[(0.91059, 0.75966), (0.60118, 0.73186), (0.32178, 0.88296), (-0.90087, -0.26367)]
[(0.3463, -0.89397), (0.99108, 0.13557), (0.50122, -0.8724), (0.43385, 0.00167)]
[(0.88121, 0.36469), (-0.29829, 0.21429), (0.31395, 0.2734), (0.43267, -0.78192)]

"""

def area(x1, y1, x2, y2, x3, y3):
    return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))) * 0.5

# https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
def intri(p):
    x, y = p[0][0], p[0][1]
    x1, y1 = p[1][0], p[1][1]
    x2, y2 = p[2][0], p[2][1]
    x3, y3 = p[3][0], p[3][1]

    A = area(x1, y1, x2, y2, x3, y3)
    A1 = area(x, y, x2, y2, x3, y3)
    A2 = area(x1, y1, x, y, x3, y3)
    A3 = area(x1, y1, x2, y2, x, y)
    
    return abs(A - (A1 + A2 + A3)) < 1e-12

def main():
    assert(intri([(-0.31961, -0.12646), (0.38478, 0.37419), (-0.30613, -0.59754), (-0.85548, 0.6633)]) == True)
    assert(intri([(-0.87427, -0.00831), (0.78829, 0.60409), (-0.90904, -0.13856), (-0.80685, 0.48468)]) == True)
    assert(intri([(0.28997, -0.03668), (-0.28362, 0.42831), (0.39332, -0.07474), (-0.48694, -0.10497)]) == True)
    assert(intri([(-0.07783, 0.04415), (-0.34355, -0.07161), (0.59105, -0.93145), (0.29402, 0.90334)]) == True)
    assert(intri([(0.36107, 0.05389), (0.27103, 0.47754), (-0.00341, -0.79472), (0.82549, -0.29028)]) == True)
    assert(intri([(-0.01655, -0.20437), (-0.36194, -0.90281), (-0.26515, -0.4172), (0.36181, 0.51683)]) == True)
    assert(intri([(-0.12198, -0.45897), (-0.35128, -0.85405), (0.84566, 0.99364), (0.13767, 0.78618)]) == True)
    assert(intri([(-0.03847, -0.81531), (-0.18704, -0.33282), (-0.95717, -0.6337), (0.10976, -0.88374)]) == True)
    assert(intri([(0.07904, -0.06245), (0.95181, -0.84223), (-0.75583, -0.34406), (0.16785, 0.87519)]) == True)
    assert(intri([(-0.33485, 0.53875), (-0.25173, 0.51317), (-0.62441, -0.90698), (-0.47925, 0.74832)]) == True)

    assert(intri([(-0.99103, 0.43842), (0.78128, -0.10985), (-0.84714, -0.20558), (-0.08925, -0.78608)]) == False)
    assert(intri([(0.15087, -0.56212), (-0.87374, -0.3787), (0.86403, 0.60374), (0.01392, 0.84362)]) == False)
    assert(intri([(0.1114, 0.66496), (-0.92633, 0.27408), (0.92439, 0.43692), (0.8298, -0.29647)]) == False)
    assert(intri([(0.87786, -0.8594), (-0.42283, -0.97999), (0.58659, -0.327), (-0.22656, 0.80896)]) == False)
    assert(intri([(0.43525, -0.8923), (0.86119, 0.78278), (-0.01348, 0.98093), (-0.56244, -0.75129)]) == False)
    assert(intri([(-0.73365, 0.28332), (0.63263, 0.17177), (-0.38398, -0.43497), (-0.31123, 0.73168)]) == False)
    assert(intri([(-0.57694, -0.87713), (-0.93622, 0.89397), (0.93117, 0.40775), (0.2323, -0.30718)]) == False)
    assert(intri([(0.91059, 0.75966), (0.60118, 0.73186), (0.32178, 0.88296), (-0.90087, -0.26367)]) == False)
    assert(intri([(0.3463, -0.89397), (0.99108, 0.13557), (0.50122, -0.8724), (0.43385, 0.00167)]) == False)
    assert(intri([(0.88121, 0.36469), (-0.29829, 0.21429), (0.31395, 0.2734), (0.43267, -0.78192)]) == False)

main()
