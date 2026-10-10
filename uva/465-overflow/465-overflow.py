#!/usr/bin/env python3

def check(a, op, b):
    INF = 2**31 - 1

    print("%d %s %d" % (a, op, b))
    if a > INF:
        print("first number too big")
    if b > INF:
        print("second number too big")
    if (op == '+' and a+b > INF) or (op == '*' and a*b > INF):
        print("result too big")

def main():
    check(300, '+', 3)
    check(9999999999999999999999, '+', 11)
    check(2**30, '*', 2**30)

main()

