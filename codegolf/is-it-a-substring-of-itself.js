/*

Given a string, return whether the string is a substring of the program's source code.

Standard quine rules apply, meaning you cannot read your own source code. The length of the input is guaranteed to be less than or equal to the length of the program. You may return any two distinct values, not necessarily truthy and falsey values. You may also submit a function, rather than a full program.

This is a code-golf so shortest code wins!

An example
If your source code is print(input() = False), it should return True for nt(i but False for tupn.

*/

// Ported from @totallyhuman solution
f = s => s.test('f=' + f)

console.log(f(/tes/))
