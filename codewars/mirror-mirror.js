/*

Write a function evilTwin(obj) which returns a new object with all the same properties as obj, and with an additional property hasGoatee set to true.

For example:

var orig = {x: 5};
console.log(orig.x) // -> 5
console.log(orig.hasGoatee) // -> undefined
var twin = evilTwin(orig);
console.log(twin.x) // -> 5
console.log(twin.hasGoatee) // -> true
If the original object is modified, its twin should reflect the changes so:

orig.z = 12
console.log(twin.z) // -> 12

*/

const evilTwin = (obj) => Object.create(obj, { hasGoatee: { value: true } });

var orig = { x: 5 };
console.log(orig.x);
console.log(orig.hasGoatee);
var twin = evilTwin(orig);
console.log(twin.x);
console.log(twin.hasGoatee);

