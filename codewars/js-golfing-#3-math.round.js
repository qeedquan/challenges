/*

JS Golfing Series 
 
Task:

Return the rounded number with no more than 11 characters.

*/

x = a => (a + .5) | 0;
console.log(x(40.5));
console.log(x(320.4));
