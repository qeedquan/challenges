#!/usr/bin/env python3

"""

I will give you two strings. I want you to transform stringOne into stringTwo one letter at a time.

Example:

stringOne = 'bubble gum';
stringTwo = 'turtle ham';

Result:
bubble gum
tubble gum
turble gum
turtle gum
turtle hum
turtle ham

"""

def mutate(a, b):
    print(a)
    for i in range(len(a)):
        if i >= len(b):
            a = a[:-1]
            print(a)
        elif a[i] != b[i]:
            a = a[:i] + b[i] + a[i+1:]
            print(a)

def main():
    mutate("bubble gum", "turtle ham")

main()
