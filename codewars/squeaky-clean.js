/*

Write a solution to cleanup arrays. This can exist entirely in the squeakyClean function or contain multiple helper functions.

Your squeakyClean function should accept an input array of values and return a new array with all empty strings, 0, null and undefined removed.

Example:

var originalArray = ['click1','click2',null,'','','submitForm'];

the solution you write should return this:

var cleanedArray = ['click1', 'click2','submitForm'] 

*/

function squeakyclean(array) {
	return array.filter((value) => value !== '' && value !== 0 && value != null);
}

var originalArray = ['click1', 'click2', null, '', '', 'submitForm'];
console.log(squeakyclean(originalArray));
