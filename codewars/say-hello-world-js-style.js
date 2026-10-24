/*

Write the definition of the function "say" such that calling this:

say("Hello")("World")

returns "Hello World"

*/

const say = (string1) => (string2) => `${string1} ${string2}`;

console.log(say("Hello")("World"));

