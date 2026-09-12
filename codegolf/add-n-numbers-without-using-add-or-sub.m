%{

Given N integers, output the sum of those integers.

Input
You may take the integers in any reasonable format, including:

stdin
arguments
an array or list
Rules
Your code must not include the characters + or -.

Standard loopholes apply. Take note of Abusing native number types to trivialize a problem.

This is code-golf. The shortest code in each language wins, which means that I will not be accepting an answer.

Testcases
n=2, 1, 2 -> 3
n=2, 2, 2 -> 4
n=2, 9, 10 -> 19
n=2, 7, 7 -> 14
n=2, 8, 8 -> 16
n=2, -5, 3 -> -2
n=2, -64, -64 -> -128
n=2, -3, 0 -> -3
n=2, 0, 3 -> 3
n=2, 0, 0 -> 0
n=2, -1, -1 -> -2
n=2, -315, -83 -> -398
n=2, 439, 927 -> 1366
n=3, 1, 2, 3 -> 6
n=3, 2, 2, 5 -> 9
n=3, 0, 9, 10 -> 19
n=3, 7, 0, 7 -> 14
n=3, 8, 8, 0 -> 16
n=3, -5, 3, -2 -> -4
n=3, -64, -64, 16 -> -112
n=3, -3, 0, 0 -> -3
n=3, 0, 3, 0 -> 3
n=3, 0, 0, 0 -> 0
n=3, -1, -1, -1 -> -3
n=3, -315, -83, -34 -> -432
n=3, 439, 927, 143 -> 1509
n=17, -74, 78, 41, 43, -20, -72, 89, -78, -12, -5, 34, -41, 91, -43, -23, 7, -44 -> -29
Testcases with partial sums that exceed 8 bits are only required if your integer type supports each partial sum (if any) and the final result. As a special case, n=2, -64, -64 -> -128 is only required if your integer type can represent -128.

Testcases involving negative integers are only required if your language natively supports negative integers.

%}

function r = add(a)
	r = trace(diag(a));
end

assert(add([1, 2]) == 3);
assert(add([2, 2]) == 4);
assert(add([9, 10]) == 19);
assert(add([7, 7]) == 14);
assert(add([8, 8]) == 16);
assert(add([-5, 3]) == -2);
assert(add([-64, -64]) == -128);
assert(add([-3, 0]) == -3);
assert(add([0, 3]) == 3);
assert(add([0, 0]) == 0);
assert(add([-1, -1]) == -2);
assert(add([-315, -83]) == -398);
assert(add([439, 927]) == 1366);
assert(add([1, 2, 3]) == 6);
assert(add([2, 2, 5]) == 9);
assert(add([0, 9, 10]) == 19);
assert(add([7, 0, 7]) == 14);
assert(add([8, 8, 0]) == 16);
assert(add([-5, 3, -2]) == -4);
assert(add([-64, -64, 16]) == -112);
assert(add([-3, 0, 0]) == -3);
assert(add([0, 3, 0]) == 3);
assert(add([0, 0, 0]) == 0);
assert(add([-1, -1, -1]) == -3);
assert(add([-315, -83, -34]) == -432);
assert(add([439, 927, 143]) == 1509);
assert(add([-74, 78, 41, 43, -20, -72, 89, -78, -12, -5, 34, -41, 91, -43, -23, 7, -44]) == -29);
