#!/usr/bin/env python3

"""

You are given an array of positive integers price where price[i] denotes the price of the ith candy and a positive integer k.

The store sells baskets of k distinct candies. The tastiness of a candy basket is the smallest absolute difference of the prices of any two candies in the basket.

Return the maximum tastiness of a candy basket.

Example 1:

Input: price = [13,5,1,8,21,2], k = 3
Output: 8
Explanation: Choose the candies with the prices [13,5,21].
The tastiness of the candy basket is: min(|13 - 5|, |13 - 21|, |5 - 21|) = min(8, 8, 16) = 8.
It can be proven that 8 is the maximum tastiness that can be achieved.

Example 2:

Input: price = [1,3,1], k = 2
Output: 2
Explanation: Choose the candies with the prices [1,3].
The tastiness of the candy basket is: min(|1 - 3|) = min(2) = 2.
It can be proven that 2 is the maximum tastiness that can be achieved.

Example 3:

Input: price = [7,7,7,7], k = 2
Output: 0
Explanation: Choosing any two distinct candies from the candies we have will result in a tastiness of 0.
 

Constraints:

2 <= k <= price.length <= 10^5
1 <= price[i] <= 10^9

Hint:
The answer is binary searchable.
For some x, we can use a greedy strategy to check if it is possible to pick k distinct candies with tastiness being at least x.
Sort prices and iterate from left to right. For some price[i] check if the price difference between the last taken candy and price[i] is at least x. If so, add the candy i to the basket.
So, a candy basket with tastiness x can be achieved if the basket size is bigger than or equal to k.

"""

def maxsize(price, m):
    size = 0
    prev = -m
    for p in price:
        if p >= prev + m:
            prev = p
            size += 1
    return size

def tastiness(price, k):
    price.sort()

    l = 0
    r = max(price) - min(price) + 1
    while l < r:
        m = (l + r) // 2
        if maxsize(price, m) >= k:
            l = m + 1
        else:
            r = m
    return l - 1

def main():
    assert(tastiness([13, 5, 1, 8, 21, 2], 3) == 8)
    assert(tastiness([1, 3, 1], 2) == 2)
    assert(tastiness([7, 7, 7, 7], 2) == 0)

main()
