/*

Order People by age Using Arrow Function

Sort and Order people by their age using Arrow Functions

Task
Your task is to order a list containg people objects by age using the new Javascript Arrow Functions

Input
Input will be a valid array with People objects containing an Age and Name

Output
Output will be a valid sorted array with People objects sorted by Age in ascending order

Reference: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Arrow_functions

*/

const OrderPeople = function (people) {
	return people.sort((a, b) => a.age - b.age);
};

console.log(OrderPeople([
	{ age: 83, name: 'joel' },
	{ age: 46, name: 'roger' },
	{ age: 99, name: 'vinny' },
	{ age: 26, name: 'don' },
	{ age: 74, name: 'brendan' }
]));

