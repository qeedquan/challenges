#!/usr/bin/env python3

"""

Task
Your goal is to find two numbers(>= 0), the greatest common divisor of which is divisor and the number of iterations taken by Euclid's algorithm is iterations.

Euclid's GCD
BigInteger FindGCD(BigInteger a, BigInteger b) {
  // Swapping `a` and `b`
  if (a < b)
  {
    var tmp = a;
    a = b;
    b = tmp;
  }

  while (b > 0)
  {
    // An iteration of calculation
    BigInteger c = a % b;
    a = b;
    b = c;
  }

  // `a` is now the greatest common divisor
  return a;
}
Restrictions
Your program should work for:

0 < divisor < 1000
0 <= iterations <= 50'000

"""

def solve(d, n):
    a, b = d, 0
    if n > 0:
        b = d
    
    for _ in range(n):
        a, b = a + b, a
    return (a, b)

def main():
    assert(solve(5, 0) == (5, 0))
    assert(solve(222, 22) == (10293696, 6361854))
    assert(solve(172, 30) == (374669148, 231558268))

main()
