{-

Description

Jiajia and Wind have a very cute daughter called Autumn. She is so clever that she can do integer additions when she was just 2 years old! Since a lot of people suspect that Autumn may make mistakes, please write a program to prove that Autumn is a real genius.

Input

The first line contains a single integer T, the number of test cases. The following lines contain 2 integers A, B(A, B < 32768) each. The size of input will not exceed 50K.

Output

The output should contain T lines, each with a single integer, representing the corresponding sum.

Sample Input

1
1 2

Sample Output

3
Hint

There may be '+' before the non-negative number!
Source

POJ Monthly--2006.02.26,zgl & twb

-}

add :: Integer -> Integer -> Integer
add x y = x + y

main = do
    print(add 1 2)

