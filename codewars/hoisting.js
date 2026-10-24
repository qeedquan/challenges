/*

The sort function is supposed to set the global variable to 1 when it has been executed at least once but it does not.

Can you figure out why?

You should not modify the behavior of the sort function.

*/

let sorted = 0;

function swap(array, i, j) {
	let temp = array[j];
	array[j] = array[i];
	array[i] = temp;
}

function sort(array) {
	// Mark function as called through the global variable
	sorted = 1;

	// Transform the input data
	for (let i = 0; i < array.length; i++) {
		array[i] = 3 * array[i] + 2;
	}

	// Remove middle value
	let n = array.length;
	let mid = Math.floor(n / 2);
	array = array.slice(0, mid).concat(array.slice(mid + 1));

	// Sort the array
	let s = false;
	for (let i = array.length - 1; i >= 0 && !s; i--) {
		s = true;
		for (let j = 0; j < i; j++) {
			if (array[j] > array[j + 1]) {
				swap(array, j, j + 1);
				s = false;
			}
		}
	}
	return array;
};

console.log(sorted);
console.log(sort([7, 6, 5, 4, 3]));
console.log(sorted);
console.log(sort([0, 0, 0]));
console.log(sorted);

