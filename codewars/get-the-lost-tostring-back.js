/*

There are some functions whose toString methods have been modified.

function foo() {}
foo.toString = function() {
  return 'blablabla';
};

Write a function _originalToString which takes a function as the argument, and returns a string which is as same as the argument's original toString's.

Note: You should not change the argument.

For example, the following statement should return function foo() {} instead of blablabla:

_originalToString(foo); // function foo() {}

*/

const _originalToString = (func) => Function.prototype.toString.call(func);

function foo() {}
foo.toString = function() { return 'blablabla'; };

console.log(_originalToString(foo));

