#!/usr/bin/env python3

"""

Challenge:
Input: A positive integer n

Output:

Create a list in the range [1,n], and join it together to a string (i.e. n=13 would be the string 12345678910111213).

Now we output a triangle using the prefixes or suffixes of this string, in one of the following four orientations based on the input integer:

If n≡0(mod4), output it in the triangle shape ◣
If n≡1(mod4), output it in the triangle shape ◤
If n≡2(mod4), output it in the triangle shape ◥
If n≡3(mod4), output it in the triangle shape ◢

Example:

Input: n=13

Because 13≡1(mod4), the shape will be ◤. Here three possible valid outputs:

12345678910111213    11111111111111111    12345678910111213
1234567891011121     2222222222222222     2345678910111213
123456789101112      333333333333333      345678910111213
12345678910111       44444444444444       45678910111213
1234567891011        5555555555555        5678910111213
123456789101         666666666666         678910111213
12345678910          77777777777          78910111213
1234567891           8888888888           8910111213
123456789            999999999            910111213
12345678             11111111             10111213
1234567              0000000              0111213
123456               111111               111213
12345                11111                11213
1234                 1111                 1213
123                  222                  213
12                   11                   13
1                    3                    3

Challenge rules:
As you can see at the three valid outputs above, only the correct shape and using all the digits in the correct order is important.
Apart from that you're free to use prefixes or suffixes; reverses/reflects; diagonal printing; etc. etc.
Any of the six possible outputs for each shape is allowed (see the test case below to see all valid outputs based on the shape).
This allows languages with rotation builtins to use it,but those without can also use an alternative approach of using the prefixes
in the correct size from top-to-bottom, or using the prefixes for two of the shapes but suffixes for the other two shapes.
Choosing the most appropriate output options for your language is part of the golfing process. :)
Input is guaranteed to be a positive integer. For n=1 we simply output 1.
Any amount of leading/trailing newlines/spaces are allowed,
as long as it prints the correct triangle (without vertical nor horizontal delimiters!) somewhere on the screen.

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages.
Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT,
functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.

Test cases:
Input: n=5

All possible valid outputs:

12345    54321    12345    54321    11111    55555
1234     5432     2345     4321     2222     4444
123      543      345      321      333      333
12       54       45       21       44       22
1        5        5        1        5        1
Input: n=6

All possible outputs:

123456    654321    123456    654321    111111    666666
 12345     65432     23456     54321     22222     55555
  1234      6543      3456      4321      3333      4444
   123       654       456       321       444       333
    12        65        56        21        55        22
     1         6         6         1         6         1
Input: n=7

All possible outputs:

      1          1          7          7          7          1
     12         21         67         76         66         22
    123        321        567        765        555        333
   1234       4321       4567       7654       4444       4444
  12345      54321      34567      76543      33333      55555
 123456     654321     234567     765432     222222     666666
1234567    7654321    1234567    7654321    1111111    7777777
Input: n=8

All possible outputs:

1           1           8           8           8           1
12          21          78          87          77          22
123         321         678         876         666         333
1234        4321        5678        8765        5555        4444
12345       54321       45678       87654       44444       55555
123456      654321      345678      876543      333333      666666
1234567     7654321     2345678     8765432     2222222     7777777
12345678    87654321    12345678    87654321    11111111    88888888
Input: n=1

Only possible output:

1
Input: n=2

All possible outputs:

12    21    12    21    11    22
 1     2     2     1     2     1

"""

def digit_triangles(n):
    m = 0
    s = ""
    for _ in range(n):
        m += 1
        s += str(m)
    
    K = k = len(s)
    print(f"n={n}")
    while k > 0:
        k -= 1
        i = k ^ ((m // -2) % -2)
        w = ((m % 4) // 2) * K
        print(s[i:].rjust(w))
    print()

def main():
    digit_triangles(1)
    digit_triangles(2)
    digit_triangles(5)
    digit_triangles(6)
    digit_triangles(7)
    digit_triangles(8)
    digit_triangles(13)

main()
