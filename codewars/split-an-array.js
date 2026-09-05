/*

Split an array of objects into 2 arrays based on truthiness of a provided property. The return value should be an array whose first element is an array of the truthy values, and whose second element is an array of the falsey values.

Javascript example:

var obj1 = { prop: true },
    obj2 = { prop: false };
    
split([obj1, obj2], 'prop');
// [[obj1], [obj2]]
CoffeeScript example:

obj1 = { prop: true }
obj2 = { prop: false }

split [obj1, obj2], 'prop'
# [[obj1], [obj2]]

*/

function split(array, property) {
	let result = [[], []];
	for (let i = 0; i < array.length; i++) {
		if (array[i][property])
			result[0].push(array[i]);
		else
			result[1].push(array[i]);
	}
	return result;
}

var obj1 = { prop: true };
var obj2 = { prop: false };

console.log(split([obj1, obj2], 'prop'));

