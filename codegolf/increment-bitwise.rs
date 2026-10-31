/*

Make a function that increments a number using only bitwise, loops, and conditions.

Rules:

All entries must be as per the language spec defined below.

Scoring is not of code length, but of the points for each operation given below.

The entry point is inc(a), for "increment and return a".

Lowest score wins.

See the example to help with scoring.

Language Spec (strict JS subset):

All input is assumed to be signed 32-bit integers, with input being in the range [-231+1, 231-2] (interval notation), with the upper bound to give room for the increment. All output is assumed to be within the range [-231+2, 231-1].

Whitespace is never syntactically significant beyond separating literals, keywords, and newline-ended comments. Booleans for conditions can and may be implicitly converted to integers, with 1 == true and 0 == false. All variables are passed by value (as they are all primitives).

Cost is given for each element, with "per use" implied.

Comments: (0 pts)

/* like this */
// or this
Numeric or variable literal: (0 pts)

i, someVariable, 2, etc.
Boolean literal: (0 pts)

true  // == 1, implicit conversion
false // == 0, implicit conversion
Note: Integer to boolean conversion is as follows (in pseudocode):

if 0: true
else: false
Grouping: (0 pts)

(foo && bar);
Function declaration: (0 pts)

function foo() { ... } // braces required
function bar(a) { ... }
Declare variable: (0 pts)

var a;
Assignment: (1 pt)

var a = 1; // semicolon required to terminate statement
a = 2; // only needs declared once
var b = a;
// b = a = 3; // cannot assign in right side of statement
var c = a << 5;
var d = a ^ (c << 5);
Equality/Inequality: (1 pt)

x == 1; // equality
x != 1; // inequality
x > y; // greater than
x >= y; // greater than or equal to
x < y; // less than
x <= y; // less than or equal to
Logical operators: (1 pt)

!a (not)
a && b (and, returns 1 if both are true, 0 otherwise)
a || b (or, returns 1 if either are true, 0 otherwise)
Bitwise operators: (1 pt)

~a (not)
a & b (and)
a | b (or)
a ^ b (exclusive or)
a << b (arithmetic left shift)
a >> b (arithmetic right shift)
a >>> b (logical right shift)
Augmented assignment: (2 pts)

a &= b; // example
If statement: (condition value + 1 pt)

if (condition) { ... }
if (x == 2) { ... } // worth 2 pts
if (x) { ... } // x is nonzero, worth 1 pt
If-Else statement: (condition value + 2 pts)

if (condition) { ... } else { ... }
While statement: (condition value + 2 pts)

while (condition) { ... }
while (x == 2) { ... } // worth 3 pts
while (x) { ... } // evaluation same as in if, worth 2 pts
Do-While statement: (condition value + 2 pts)

do { ... } while (condition); // semicolon required
Return statement: (number of points for statement on right + 1 pt)

return foo; // semicolon required, worth 1 pt
return a & b; // worth 2 pts
Function call: (number of parameters + 2 pts)

foo(); // worth 2 pts
bar(1, 2) // worth 2 + 2 = 4 pts
Operator precedence (first to last performed):

( ... )
~/! (right-to-left)
<</>>/>>> (left-to-right)
>/</>=/<= (left-to-right)
==/!= (left-to-right)
Note: 1 == 1 == 1 works out to 0 == 1 which is 0.
& (left-to-right)
^ (left-to-right)
| (left-to-right)
&& (left-to-right)
|| (left-to-right)
Example scoring:

This (ficticious) example would score 14 points. See comments for details.

function inc(a) {
  var b = a; // adds 1 pt for assignment
  if (!a) return 0; // adds 3 pts: 2 for if and 1 for return
  while (a & b) { // adds 3 pts: 2 for while and 1 for `&`
    b >>= a ^ b; // adds 3 pts: 2 for augmented assignment, 1 for `^`
    a = b << 1; // adds 2 pts: 1 for assignment, 1 for `<<`
  }
  return a ^ b; // adds 2 pts: 1 for return, 1 for `^`
}

*/

fn main() {
    for i in 0..1000000 {
        assert_eq!(inc(i), i + 1);
    }
    assert_eq!(inc(usize::MAX), 0);
}

fn inc(mut x: usize) -> usize {
    if x == usize::MAX {
        return 0;
    }

    let mut y = 1;
    loop {
        x ^= y;
        if x & y != 0 {
            break;
        }
        y <<= 1;
    }
    return x;
}
