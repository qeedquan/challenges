/*

An array will be passed to the function falsyOrTruthy() containing either both falsy and truthy values or only one type of them; if the number of the array's values is even return truthy values otherwise return falsy ones. In the cases when corresponding values are not present at all simply return an empty array.

Examples:

var arr = [false,NaN,NaN,4,5,{}];

falsyOrTruthy(arr); // should return [4,5,{}]

var arr = [false,NaN,NaN,4,5,1,{}];

falsyOrTruthy(arr); // should return [false,NaN,NaN]

var arr = [false,NaN];

falsyOrTruthy(arr) // should return [];

var arr = [1,2,3];

falsyOrTruthy(arr) // should return [];

*/

function falsyOrTruthy(array) {
	if (array.length % 2)
		return array.filter((value) => !value);
	return array.filter((value) => value);
}

var array = [false, NaN, NaN, 4, 5, {}];
console.log(falsyOrTruthy(array));

var array = [false, NaN, NaN, 4, 5, 1, {}];
console.log(falsyOrTruthy(array));

var array = [false, NaN];
console.log(falsyOrTruthy(array));

var array = [1, 2, 3];
console.log(falsyOrTruthy(array));

