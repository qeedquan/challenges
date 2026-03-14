/*

Write a function that takes an array that may have other arrays nested indefinitely within, and reverses that array and every array within.

Example:

//regular reverse shown only for comparison
//do NOT write a regular reverse function

var l = [[1,2],[3,4]];
l.reverse()        //produces [[3,4],[1,2]]
deepReverse(l)     //produces [[4,3],[2,1]]

var l = [[9,8,7],[6,5,4],[3,2,1]]
l.reverse()        //produces [[3,2,1],[6,5,4],[9,8,7]]
deepReverse(l)     //produces [[1,2,3],[4,5,6],[7,8,9]]

var l = [[50,51,[52,53]] , [[54,55],56,57]]
l.reverse()        //produces [[[54,55],56,57] , [[50,51,[52,53]]]
deepReverse(l)     //produces [[57,56,[55,54]] , [[53,52],51,50]]

*/

function deepReverse(list) {
	let items = [...list];
	items.reverse();
	for (let index = 0; index < items.length; index++) {
		if (Array.isArray(items[index]))
			items[index] = deepReverse(items[index]);
	}
	return items;
};


console.log(deepReverse([[1, 2], [3, 4]]));
console.log(deepReverse([[9, 8, 7], [6, 5, 4], [3, 2, 1]]));
console.log(deepReverse([[50, 51, [52, 53]] , [[54, 55], 56, 57]]));
