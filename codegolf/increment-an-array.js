/*

Given a nonempty array of positive integers, "increment" it once as follows:

If all the array elements are equal, append a 1 to the end of the array. For example:

[1] -> [1, 1]
[2] -> [2, 1]
[1, 1] -> [1, 1, 1]
[3, 3, 3, 3, 3] -> [3, 3, 3, 3, 3, 1]
Else, increment the first element in the array that is the array's minimum value. For example:

[1, 2] -> [2, 2]
[2, 1] -> [2, 2]
[3, 1, 1] -> [3, 2, 1] -> [3, 2, 2] -> [3, 3, 2] -> [3, 3, 3]
[3, 4, 9, 3] -> [4, 4, 9, 3] -> [4, 4, 9, 4] -> [5, 4, 9, 4] -> [5, 5, 9, 4] -> ...
(Each -> represents one increment, which is all your program needs to do.)

Output the resulting incremented array.

The shortest code in bytes wins.

*/

function inc(a) {
	let n = a.length;
	if (n == 0) {
		return [1];
	}

	let r = [];
	let f = 0;
	let j = 0;
	let m = a[0];
	for (let i = 0; i < n; i++) {
		r.push(a[i]);
		if (a[0] != a[i])
			f = 1;
		if (m > a[i]) {
			j = i;
			m = a[i];
		}
	}
	if (!f)
		r.push(1);
	else
		r[j] += 1;
	
	return r;
}

function main() {
	console.log(inc([1]));
	console.log(inc([2]));
	console.log(inc([1, 1]));
	console.log(inc([3, 3, 3, 3, 3]));

	console.log(inc([1, 2]));
	console.log(inc([2, 1]));
	console.log(inc([3, 1, 1]));
	console.log(inc([3, 4, 9, 3]));
}

main();
