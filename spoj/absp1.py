#!/usr/bin/env python3

"""

Recently Mr. Kopa Samsu is learning programming. On a very renowned online judge, he found a problem:

You are given an array of N numbers in non-decreasing order. You have to answer the summation of the absolute difference of all distinct pairs in the given array.

Do you know what distinct pair means? Suppose you have an array of 3 elements: 3 5 6

Then all the distinct pairs are:

3 5
3 6
5 6

For this problem, Mr. Kopa Samsu implemented an algorithm to find the summation of the absolute difference of all distinct pairs. His algorithm was:

int ABS(int a[], int n)
{
    int sum = 0;
    for (int i = 1; i <= n ;i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            sum += abs(a[i] - a[j]);
        }
    }
}
After a great hard work, he finished the code. But alas!!! Frustration came around him when he submitted his code, the judge gave the verdict “TLE” (Time Limit Exceeded). “How can I get rid of TLE?” he thought a lot but couldn't find any way. Then suddenly, he remembered about you that you (his friend) is very good at programming. So, he came to you seeking your help. Can you help him solving this problem?

Input
The input data set starts with an integer T (T ≤ 1000), the number of test cases. Then every test case starts with a integer N (N ≤ 10000), the number of elements in the array. After that, the next line contains N integers A[i], where 1 ≤ i ≤ N and 1 ≤ A[i] ≤ 1000000000 and A[i] ≤ A[i+1].

Output
Every test case should output an integer “X”, where X is the summation of the absolute difference of all the distinct pair.

Example
Input:
3
3
1 2 3
3
1 4 5
3
2 4 6

Output:
4
8
8
Problem Set: S.M. Shaheen Sha, Raihat Zaman Neloy

Data Set & Solution: Raihat Zamane Neloy

"""

def solve(a):
    r = 0
    n = len(a)
    for i in range(n):
        r += i*a[i] - (n-i-1)*a[i]
    return r

def main():
    assert(solve([1, 2, 3]) == 4)
    assert(solve([1, 4, 5]) == 8)
    assert(solve([2, 4, 6]) == 8)

main()
