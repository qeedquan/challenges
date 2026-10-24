#!/usr/bin/env python3

"""

Problem:
Your task is to write a program that takes as input a height (in meters) and weight (in kilograms), and outputs the corresponding BMI category.

BMI is a measure of the ratio of your weight to your height. It's dated and inaccurate for many people, but that doesn't matter here!

BMI can be calculated using the following equation:

BMI = (mass in kilograms) / (height in meters)^2
The categories will be defined as follows:

BMI < 18.5: "Underweight"

18.5 <= BMI < 25: "Normal"

25 <= BMI: "Overweight"

For the sake of the challenge, I'm ignoring all the "extreme" categories. Also, since some numbers like "25" sit between 2 categories, I adjusted the bounds slightly so there's a definite answer.

You can write either a function, or a full program.

Input:
Input can be in any reasonable form. Two numbers (or strings), either as 2 separate arguments, or as a single string. An array/list of 2 numbers, a dictionary with "weight" and "height" keys... Decimal values should be supported. You can assume the input will always be valid (no negative values, and height will never be 0).

Output:
Output will be a string containing the case-insensitive category names. The strings must match the category names exactly as above, ignoring case. It can be output to the stdout, returned (in the case of a function), or written to file.

Test Cases (weight, height => result):
80, 1 =>   "Overweight"
80, 2 =>   "Normal"
80, 3 =>   "Underweight"

50, 1 =>   "Overweight"
50, 1.5 => "Normal"
50, 2 =>   "Underweight"

Edge Cases:

41, 1.5 => "Underweight" (18.2 BMI)
42, 1.5 => "Normal" (18.667 BMI)

56, 1.5 => "Normal" (24.889 BMI)
57, 1.5 => "Overweight" (25.3 BMI)

73, 2 =>   "Underweight" (18.25 BMI)
74, 2 =>   "Normal" (18.5 BMI)

99, 2 =>  "Normal" (24.75 BMI)
100, 2 => "Overweight" (25 BMI)
Here's some pseudocode that shows an example implementation:

function bmi_category(weight, height):
    var bmi = (weight / (height**2))

    if (bmi < 18.5):
        return "Underweight"

    if (18.5 <= bmi < 25):
        return "Normal"

    if (25 <= bmi):
        return "Overweight"
This is code-golf, so the fewest number of bytes wins.

(Yes, this task is exceedingly trivial in most languages. Most of the challenges lately seem to be harder than normal, so I thought I'd post a more accessible one).

NOTE! An hour after I posted this challenge, I had to modify the ranges slightly since the ranges as stated had "holes" as pointed out in the comments. Please see the new ranges.

"""

def bmi_category(weight, height):
    bmi = (weight / (height**2))
    if bmi < 18.5:
        return "Underweight"
    if 18.5 <= bmi and bmi < 25:
        return "Normal"
    return "Overweight"

def main():
    assert(bmi_category(80, 1) == "Overweight")
    assert(bmi_category(80, 2) == "Normal")
    assert(bmi_category(80, 3) == "Underweight")

    assert(bmi_category(50, 1) == "Overweight")
    assert(bmi_category(50, 1.5) == "Normal")
    assert(bmi_category(50, 2) == "Underweight")

    assert(bmi_category(41, 1.5) == "Underweight")
    assert(bmi_category(42, 1.5) == "Normal")

    assert(bmi_category(56, 1.5) == "Normal")
    assert(bmi_category(57, 1.5) == "Overweight")
    
    assert(bmi_category(73, 2) == "Underweight")
    assert(bmi_category(74, 2) == "Normal")

    assert(bmi_category(99, 2) == "Normal")
    assert(bmi_category(100, 2) == "Overweight")

main()
