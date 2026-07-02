/*

Implement all required functions in order to create the following sentences by calling those functions:

Adam(has(a(dog()))); // must return "Adam has a dog."
The(name(of(the(dog(is(also(Adam()))))))); // must return "The name of the dog is also Adam."

*/

const Adam = (s = '.') => 'Adam' + (s === '.' ? '' : ' ') + s;
const has = (s = '.') => 'has' + (s === '.' ? '' : ' ') + s;
const a = (s = '.') => 'a' + (s === '.' ? '' : ' ') + s;
const dog = (s = '.') => 'dog' + (s === '.' ? '' : ' ') + s;
const The = (s = '.') => 'The' + (s === '.' ? '' : ' ') + s;
const name = (s = '.') => 'name' + (s === '.' ? '' : ' ') + s;
const of = (s = '.') => 'of' + (s === '.' ? '' : ' ') + s;
const the = (s = '.') => 'the' + (s === '.' ? '' : ' ') + s;
const is = (s = '.') => 'is' + (s === '.' ? '' : ' ') + s;
const also = (s = '.') => 'also' + (s === '.' ? '' : ' ') + s;

console.log(Adam(has(a(dog()))));
console.log(The(name(of(the(dog(is(also(Adam()))))))));
