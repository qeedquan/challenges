#!/usr/bin/env python3

"""

The city of Hackerland has formed a new football club and wants to participate in the upcoming Football League of their country. The coach is worried that they will not be able to qualify because they don't have a famous footballer in their team. The assistant coach suggests that the team should buy Cristiano Ronaldo as he can single-handedly get their team qualified.

On day 1, today, the club has to pay 'A' HackerCoins in order to buy Ronaldo. After each passing day, the price of buying Ronaldo becomes A times the price on the previous day. Any normal person would buy him on the 1st day itself as the price will be the lowest but since the coach always failed in high school Mathematics, he wants 'B' days to think before making him an offer.

As the coach doesn't know how to calculate the price of Ronaldo on the Bth day, he has asked for your help.

Your task is to tell the price of Ronaldo on the Bth day. Since, the price can be a very large number, please tell him the price modulo 10^9 + 7.

Input Format
The first line contains an integer T, the number of testcases. It's followed by T lines.
Each testcase will contain two integers A & B separated by a space.

Output Format
Output T lines, each corresponding to the answer of the testcase.

Constraints
1 <= T <= 10
1 <= A,B <= 10100000
A % (10^9 + 7) != 0

Note
Both integers will have a maximum of 100000 digits.

Sample Input #00:
5
3 2
4 5
7 4
34534985349875439875439875349875 93475349759384754395743975349573495
34543987529435983745230948023948 3498573497543987543985743989120393097595572309482304

Sample Output #00:
9
1024
2401
735851262
985546465
Explanation #00:

As value of 32 = 9, So output for first case will be 9.

Similarly 45 modulo (10^9 + 7) = 1024
Similarly 74 modulo (10^9 + 7) = 2401
Similarly we can do for others.

"""

def solve(a, b):
    return pow(a, b, 10**9 + 7)

def main():
    assert(solve(3, 2) == 9)
    assert(solve(4, 5) == 1024)
    assert(solve(7, 4) == 2401)
    assert(solve(34534985349875439875439875349875, 93475349759384754395743975349573495) == 735851262)
    assert(solve(34543987529435983745230948023948, 3498573497543987543985743989120393097595572309482304) == 985546465)

main()
