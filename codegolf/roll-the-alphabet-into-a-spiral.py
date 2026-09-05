#!/usr/bin/env python3

"""

Write a program or function that, when given n, will print a spiral n characters long made up of the Latin alphabet ABCDEFGHIJKLMNOPQRSTUVWXYZ repeated as needed. This spiral should run through the alphabet only forwards.

Related to Alphabet Spiral, though the spiral runs through the alphabet forwards and backwards, and the spiral is constant.

Test cases

4   AB
    DC

40   UVWXYZ
     TGHIJA
    NSFABKB
    MREDCLC
    LQPONMD
    KJIHGFE

0

10  GHIJ
    FAB
    EDC

1000    UVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ
        TGHIJKLMNOPQRSTUVWXYZABCDEFGHIJA
        SFABCDEFGHIJKLMNOPQRSTUVWXYZABKB
        REZCDEFGHIJKLMNOPQRSTUVWXYZABCLC
        QDYBMNOPQRSTUVWXYZABCDEFGHIJCDMD
        PCXALEFGHIJKLMNOPQRSTUVWXYZKDENE
        OBWZKDEFGHIJKLMNOPQRSTUVWXALEFOF
        NAVYJCDMNOPQRSTUVWXYZABCDYBMFGPG
        MZUXIBCLCDEFGHIJKLMNOPQREZCNGHQH
        LYTWHABKBABCDEFGHIJKLMNSFADOHIRI
        KXSVGZAJAZGHIJKLMNOPQROTGBEPIJSJ
        JWRUFYZIZYFUVWXYZABCDSPUHCFQJKTK
        IVQTEXYHYXETQRSTUVWXETQVIDGRKLUL
        HUPSDWXGXWDSPUVWXYZYFURWJEHSLMVM
        GTORCVWFWVCROTGHIJAZGVSXKFITMNWN
        FSNQBUVEVUBQNSFABKBAHWTYLGJUNOXO
        ERMPATUDUTAPMREDCLCBIXUZMHKVOPYP
        DQLOZSTCTSZOLQPONMDCJYVANILWPQZQ
        CPKNYRSBSRYNKJIHGFEDKZWBOJMXQRAR
        BOJMXQRARQXMLKJIHGFELAXCPKNYRSBS
        ANILWPQZQPWVUTSRQPONMBYDQLOZSTCT
        ZMHKVOPYPONMLKJIHGFEDCZERMPATUDU
        YLGJUNOXONMLKJIHGFEDCBAFSNQBUVEV
        XKFITMNWVUTSRQPONMLKJIHGTORCVWFW
        WJEHSLMLKJIHGFEDCBAZYXWVUPSDWXGX
        VIDGRKJIHGFEDCBAZYXWVUTSRQTEXYHY
        UHCFQPONMLKJIHGFEDCBAZYXWVUFYZIZ
        TGBEDCBAZYXWVUTSRQPONMLKJIHGZAJA
        SFAZYXWVUTSRQPONMLKJIHGFEDCBABKB
        REDCBAZYXWVUTSRQPONMLKJIHGFEDCLC
        QPONMLKJIHGFEDCBAZYXWVUTSRQPONMD
                                LKJIHGFE
Rules

Your input will be a non-negative integer 0 <= n <= 1000, but your code should theoretically handle any non-negative integer.
Your output format may be in any sane format, with delimiters if necessary.
Rotations and reflections are equivalent.
Your alphabet may be uppercase or lowercase.
The empty spaces in your spiral may be filled in with whatever non-alphabetic nulls you see fit.
The spiral itself may be in any shape you see fit. Rectangular spirals work best with ASCII solutions, but graphical solutions may be shorter with circular spirals.
Leading and trailing spaces and newlines are allowed.
This is code golf. The shortest answer in bytes (or equivalent) wins.
As always, if anything is unclear or incorrect, please let me know in the comments. Good luck and good golfing!

"""

from turtle import Screen, Turtle
from PIL import Image
import sys

def spiral(turtle, n):
    turtle.up()
    for i in range(n):
        turtle.write(chr(i%26 + ord('A')))
        turtle.rt(9)
        turtle.fd(9 + i)

def main():
    if len(sys.argv) != 2:
        print("usage: n")
        exit(2)

    n = int(sys.argv[1])
    screen = Screen()
    screen.tracer(0)
    screen.title("Alphabet Spiral (N=%d)" % n)
    turtle = Turtle()
    spiral(turtle, n)
    canvas = screen.getcanvas()
    canvas.postscript(file="spiral_%d.ps" % (n))

main()

