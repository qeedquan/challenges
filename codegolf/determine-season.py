#!/usr/bin/env python3

"""

Introduction:
In the northern hemisphere (i.e. Europe, North America, etc.), the seasons are divided like this:
- Spring: March, April, May
- Summer: June, July, August
- Autumn: September, October, November
- Winter: December, January, February

In the southern hemisphere however (i.e. Australia, South America, etc.), the seasons are divided like this:
- Spring: September, October, November
- Summer: December, January, February
- Autumn: March, April, May
- Winter: June, July, August

This difference is due to the position of the sun regarding the equator, where the northern and southern hemispheres have opposite seasons.

Input:
In this challenge, we'll take two inputs:

One for the month (1 <= m <= 12 or 0 <= m <= 11) (examples and test cases are all 1-indexed).
And one for the five 'position-groups' at the latitudes of Earth (-2 <= p <= 2), where -2 is the Antarctic, -1 is the southern hemisphere excluding the Antarctic, 0 are the Tropics in proximity of the equator, 1 is the northern hemisphere excluding the Arctic, and 2 is the Arctic.
Although the Arctic, Antarctic and Tropics of course still have seasons, for the sake of this challenge we'll say the Arctic and Antarctic are in a constant state of Winter, and the Tropics are in a constant state of Summer.
Here a visual representation of these five groups, where -2 is the Antarctic Circle; -1 between the Tropic of Capricorn and Antarctic Circle; 0 between the Tropic of Capricorn and Tropic of Cancer; 1 between the Arctic Circle and Tropic of Cancer; and -2 the Arctic Circle.

https://i.sstatic.net/BB40hm.jpg
Source: COSMOS - The SAO Encyclopedia of Astronomy

Output:
One of Spring, Summer, Autumn, or Winter, following these rules:

Is the position input 2 or -2 (Arctic or Antarctic), always output Winter.
Is the position input 0 (Tropics), always output Summer.
Is the position input 1 (northern hemisphere), output one of the four seasons based on the month input: Spring (m = [3,5]); Summer (m = [6,8]); Autumn (m = [9,11]); Winter (m = 12 or m = [1,2]).
Is the position input -1 (southern hemisphere), output one of the four seasons based on the month input: Spring (m = [9,11]); Summer (m = 12 or m = [1,2]); Autumn (m = [3,5]); Winter (m = [6,8]).
Challenge rules:
Output any four distinct values of your choice indicating Spring, Summer, Autumn, or Winter (please state what you've used in your answer).
-15 bytes bonus if you output Spring, Summer, Autumn, or Winter as text (case-insensitive, so can be fully lowercase or fully uppercase as well, instead of the used title-case).
Month input can be in any reasonable format. Can be either a 0-indexed or 1-indexed integer, Date-object, Month-String, etc.
Position input will always be one of these possible five inputs -2, -1, 0, 1, 2.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.

Test cases:
Position    1-indexed Month    Output

-2          8  (August)        Winter
-2          12 (December)      Winter
-1          3  (March)         Autumn
-1          5  (May)           Autumn
-1          8  (August)        Winter
-1          12 (December)      Summer
0           1  (January)       Summer
0           7  (July)          Summer
1           1  (January)       Winter
1           4  (April)         Spring
1           7  (July)          Summer
1           12 (December)      Winter
2           2  (February)      Winter
2           9  (September)     Winter

"""

def season(position, month):
    seasons = ["Summer", "Autumn", "Winter", "Spring"]
    table = [0, month + 6, 6, month]
    index = (table[position] // 3) % 4
    return seasons[index]

def main():
    assert(season(-2, 8) == "Winter")
    assert(season(-2, 12) == "Winter")
    assert(season(-1, 3) == "Autumn")
    assert(season(-1, 5) == "Autumn")
    assert(season(-1, 8) == "Winter")
    assert(season(-1, 12) == "Summer")
    assert(season(0, 1) == "Summer")
    assert(season(0, 7) == "Summer")
    assert(season(1, 1) == "Winter")
    assert(season(1, 4) == "Spring")
    assert(season(1, 7) == "Summer")
    assert(season(1, 12) == "Winter")
    assert(season(2, 2) == "Winter")
    assert(season(2, 9) == "Winter")

main()
