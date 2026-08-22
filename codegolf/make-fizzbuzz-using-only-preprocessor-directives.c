/*

I have a source file here:

#include <FizzBuzz.h>
fizzbuzz
And I want to make "fizzbuzz" turn into a FizzBuzz program solely through the preprocessor.

Your task is to write a FizzBuzz.h that uses only preprocessor directives (things like include, define, etc.) to create a working FizzBuzz program. Specifically, I want to see the use of macros, which will be required to make this work (at minimum, defining fizzbuzz to be some code).

However, to make sure people try and take full advantage of the power of macros, your score will be defined as the sum of the cubes of the length of the definition portion (the part after #define <symbol>) of each macro.

So, for example, the following file:

#define A 123
#define B A+A
#define C B*2+A
would have a total score of 179 (3^3 + 3^3 + 5^3). As a rule, I want multiple shorter lines instead of one long line.

*/

#include <stdio.h>

// ported from @breadbox solution

#define a int main
#define b for
#define c puts
#define d printf
#define e ""
#define f x Z
#define g y Z
#define h "%d"
#define x "Bu"
#define y "Fi"
#define z "z"
#define Z z z
#define A 101
#define B i++
#define C B%5
#define D C?e
#define E D:f
#define F i%3
#define G F?i
#define H G%5
#define I H?h
#define J I:e
#define K J:g
#define L K,i
#define M i<A
#define N M;c
#define O a(int i, char **k
#define P N(E
#define Q d(L
#define R O)
#define S b(
#define T P)
#define U Q)
#define V U;
#define W R{S
#define X W;T
#define Y X)V
#define fizzbuzz Y (void)k;}

fizzbuzz
