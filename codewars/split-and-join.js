/*

"When no more interesting kata can be resolved, I just choose to create the new kata, to solve their own, to enjoy the process --myjinxin2015 said

Description:
There is a 2D array arr:

[[1],[2,3],[4,5,6],[7,8,9,10]]

Task1: Write a function split. Split 2D array to two arrays:

 Result:
 array 1: all numbers in 2D array   array 2: Leave all subarrays and
                                              fill in the length of
                                              each subarray
   [  [1,2,3,4,5,6,7,8,9,10],            [[1],[2],[3],[4]]  ]

Task2: Write a function join. Join two array(like the result above) to one array(like the arr above)

Some Examples

split:

arr= [[1],[2,3],[4,5,6],[7,8,9,10]]
split(arr) === [  [1,2,3,4,5,6,7,8,9,10],  [[1],[2],[3],[4]]  ]

arr= [[1,3,5],[2,4,6],[7,8,9]]
split(arr) === [  [1,3,5,2,4,6,7,8,9],  [[3],[3],[3]]  ]

join:

arr1=[1,2,3,4,5,6,7,8,9,10],  arr2=[[1],[2],[3],[4]]
join(arr1,arr2) === [[1],[2,3],[4,5,6],[7,8,9,10]]

arr1=[1,3,5,2,4,6,7,8,9],  arr2=[[3],[3],[3]]
join(arr1,arr2) === [[1,3,5],[2,4,6],[7,8,9]]

*/

function split(array) {
	const array1 = array.flat();
	const array2 = array.map((subarray) => [subarray.length]);
	return [array1, array2];
}

function join(array1, array2) {
	let result = [];
	let index = 0;
	array2.forEach((subarray) => {
		result.push(array1.slice(index, index + subarray[0]));
		index += subarray[0];
	});
	return result;
}

arr = [[1], [2, 3], [4, 5, 6], [7, 8, 9, 10]];
console.log(split(arr));

arr = [[1, 3, 5], [2, 4, 6], [7, 8, 9]];
console.log(split(arr));

arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
arr2 = [[1], [2], [3], [4]];
console.log(join(arr1, arr2));

arr1 = [1, 3, 5, 2, 4, 6, 7, 8, 9];
arr2 = [[3], [3], [3]];
console.log(join(arr1, arr2));

