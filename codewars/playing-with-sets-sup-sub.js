/*

Set ( https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set ) objects are new JavaScript built-in objects defined since ECMAScript 2015 ( http://www.ecma-international.org/ecma-262/6.0/#sec-set-objects. )

A Set lets you store unique values of any type. It comes with some useful methods like .add, .clear, .has . . . BUT some "Set operations" are missing, like . . .

Subset and Superset

https://upload.wikimedia.org/wikipedia/commons/thumb/b/b0/Venn_A_subset_B.svg/225px-Venn_A_subset_B.svg.png

If every member of set A is also a member of set B, then A is said to be a subset of B, written A ⊆ B (also pronounced "A is contained in B"). Equivalently, we can write B ⊇ A, read as "B is a superset of A", "B includes A", or "B contains A".

Example:
  {1, 3} ⊆ {1, 2, 3, 4}.
  {1, 2, 3, 4} ⊆ {1, 2, 3, 4}.
  
  {1, 2, 3, 4} ⊇ {1, 3}.
  {1, 2, 3, 4} ⊇ {1, 2, 3, 4}.

Task
Create 2 functions:

isSubsetOf getting 2 sets as arguments and returning true if 2d set contains all elements of 1st one.

isSupersetOf getting 2 sets as arguments and returning true if 1st set contains all elements of 2d one.

Examples:
A = new Set([1,2]);
B = new Set([1,2,3]);

isSubsetOf(A,B) // -> true
isSubsetOf(B,A) // -> false

isSupersetOf(A,B) // -> false
isSupersetOf(B,A) // -> true
 

" May the Code be with you ! "

*/

var assert = require('assert');

function isSubsetOf(s1, s2) {
	return Array.from(s1).every((el) => s2.has(el));
}

function isSupersetOf(s1, s2) {
	return isSubsetOf(s2, s1);
}

A = new Set([1, 2]);
B = new Set([1, 2, 3]);

assert(isSubsetOf(A, B) == true);
assert(isSubsetOf(B, A) == false);

assert(isSupersetOf(A, B) == false);
assert(isSupersetOf(B, A) == true);

