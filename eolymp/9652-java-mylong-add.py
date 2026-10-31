#!/usr/bin/env python3

"""

Implement a wrapper class MyLong.

class MyLong // Java
{
  private long a; // one private variable
  MyLong(long a) // Constructor
  public String toString() // Print a variable of type MyLong
  public MyLong Add(MyLong b) // Add MyLong value
  public MyLong Add(long b) // Add long value
};

Input
Two integers a and b (-10^18≤a,b≤10^18).

Output
Print the value of the expression a+b+10.

Examples

Input #1
2 3

Answer #1
15

"""

def solve(a, b):
    return a + b + 10

def main():
    assert(solve(2, 3) == 15)

main()
