#!/usr/bin/env python3

"""

Background
Variable declaration statement in C consists of three parts: the name of the variable, its base type, and the type modifier(s).

There are three kinds of type modifiers:

Pointer * (prefix)
Array [N] (postfix)
Function () (postfix)
You can specify a list of function arguments inside the parens, but for the sake of this challenge, let's ignore it and just use () (which technically means "the function can take any kind of arguments").
And a way to read out the notations is as follows:

int i;             // i is an int
float *f;          // f is a pointer to a float
my_struct_t s[10]; // s is an array of 10 my_struct_t
int func();        // func is a function returning an int
The catch is that we can mix all of these to form a more complicated type, such as array of arrays or array of function pointers or pointer to array of pointers:

int arr[3][4];
// arr is an array of 3 arrays of 4 ints

int (*fptrs[10])();
// fptrs is an array of 10 pointers to functions returning an int

float *(*p)[16];
// p is a pointer to an array of 16 pointers to float
How did I read these complicated statements?

Start from the variable name. (name) is ...
Select the modifier with the highest precedence.
Read it:
[N] -> array of N ...
() -> function returning ...
* -> pointer to ...
Repeat 2 and 3 until the modifiers are exhausted.
Finally, read the base type. ... (base type).
In C, postfix operators take precedence over prefix operators, and type modifiers are no exception. Therefore, [] and () bind first, then *. Anything inside a pair of parens (...) (not to be confused with function operator) binds first over anything outside.

Illustrated example:

int (*fptrs[10])();
      fptrs           fptrs is ...
           [10]       array of 10 ... // [] takes precedence over *
    (*         )      pointer to ...
                ()    function returning ...
int                   int
Task
Given a line of variable declaration statement written in C, output the English expression that describes the line, using the method shown above.

Input
The input is a single C statement that includes a single base type, a single variable name, zero or more type modifiers and the ending semicolon. You have to implement all the syntax elements covered above, plus:

Both the base type and the variable name match the regular expression [A-Za-z_][A-Za-z0-9_]*.
Theoretically, your program should support unlimited number of type modifiers.
You can simplify other C syntax elements in the following ways (full implementation is also welcome):

The base type is always a single word, e.g. int, float, uint32_t, myStruct. Something like unsigned long long won't be tested.
For the array notation [N], the number N will always be a single positive integer written in base 10. Things like int a[5+5], int a[SIZE] or int a[0x0f] won't be tested.
For the function notation (), no parameters will be specified at all, as pointed out above.
For whitespaces, only the space character 0x20 will be used. You can restrict your program to specific usage of whitespaces, e.g.
Use only one space after the base type
Use a space everywhere between tokens
However, you cannot use two or more consecutive spaces to convey more information than being a token separator.
According to C syntax, the following three combinations are invalid, and thus won't be tested:

f()() Function returning function
f()[N] Function returning array
a[N]() Array of N functions
C developers use these equivalent forms instead (and all of these are covered in the test cases):

(*f())() Function returning pointer to function
*f() Function returning pointer to array's first element
(*a[N])() Array of N pointers to function
Output
The output is a single English sentence. You don't need to (but you can if you wish) respect English grammar, e.g. the use of a, an, the, singular/plural forms, and the ending dot (period). Each word should be separated by one or more whitespaces (space, tab, newline) so the result is human-readable.

Again, here is the conversion process:

Start from the variable name. (name) is ...
Select the modifier with the highest precedence.
Read it:
[N] -> array of N ...
() -> function returning ...
* -> pointer to ...
Repeat 2 and 3 until the modifiers are exhausted.
Finally, read the base type. ... (base type).
Test cases
int i;              // i is int
float *f;           // f is pointer to float
my_struct_t s[10];  // s is array of 10 my_struct_t
int func();         // func is function returning int
int arr[3][4];      // arr is array of 3 array of 4 int
int (*fptrs[10])(); // fptrs is array of 10 pointer to function returning int
float *(*p)[16];    // p is pointer to array of 16 pointer to float

_RANdom_TYPE_123 (**(*_WTH_is_TH15)())[1234][567];
/* _WTH_is_TH15 is pointer to function returning pointer to pointer to array of
   1234 array of 567 _RANdom_TYPE_123 */

uint32_t **(*(**(*(***p)[2])())[123])[4][5];
/* p is pointer to pointer to pointer to array of 2 pointer to function returning
   pointer to pointer to array of 123 pointer to array of 4 array of 5 pointer to
   pointer to uint32_t */

uint32_t (**((*(**(((*(((**(*p)))[2]))())))[123])[4])[5]);
// Same as above, just more redundant parens

some_type (*(*(*(*(*curried_func())())())())())();
/* curried_func is function returning pointer to function returning pointer to
   function returning pointer to function returning pointer to
   function returning pointer to function returning some_type */

"""

import re

class Type(str):
    __pos__ = lambda self: Type(self + "pointer to ")
    __call__ = lambda self: Type(self + "function returning ")
    __getitem__ = lambda self, index: Type(self + f"array of {index} ")

"""

Ported from @Kateba solution

Requires that only one space is contained in the input (between the type and the expression).

I think this is a pretty unique approach to the problem. This mostly uses the fact that Python itself can evaluate strings like (**((*(**(((*(((**(*p)))[2]))())))[123])[4])[5]) and gets the correct sequence of function calls, array indexes and pointers - and that the user can overload these.

"""

def solve(input):
    typename, declaration = input.split()
    expression = re.sub(
        r"\*",
        "+",
        re.sub(r"(\w+)", r'Type("\1 is ")', declaration[:-1], count=1),
    )
    return eval(expression) + typename

def main():
    print(solve("int i;"))
    print(solve("float *f;"))
    print(solve("my_struct_t s[10];"))
    print(solve("int func();"))
    print(solve("int arr[3][4];"))
    print(solve("int (*fptrs[10])();"))
    print(solve("float *(*p)[16];"))
    print(solve("_RANdom_TYPE_123 (**(*_WTH_is_TH15)())[1234][567];"))
    print(solve("uint32_t **(*(**(*(***p)[2])())[123])[4][5];"))
    print(solve("uint32_t (**((*(**(((*(((**(*p)))[2]))())))[123])[4])[5]);"))
    print(solve("some_type (*(*(*(*(*curried_func())())())())())();"))

main()
