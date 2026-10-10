/*

Find the anonymous function in the array
Find the anonymous function in the given array and use the function to filter the array
Input
Your input. First Parameter will be an array with an anonymous function somewhere in the lot, The second Parameter will be an array which you will filter using the anonymous function you find.
Output
Your output. Output a filtered version of the second parameter using the function found in the first parameter.
Reference: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Arrow_functions

*/

function findFunction(func, array) {
	let index = func.findIndex((element) => typeof element === "function");
	return array.filter(func[index]);
}

console.log(findFunction([(a => a%2 == 0), 9, 3, 1, 0], [1, 2, 3, 4]));
console.log(findFunction([9, 3, (a => a%2), 1, 0], [1, 2, 3, 4]));

