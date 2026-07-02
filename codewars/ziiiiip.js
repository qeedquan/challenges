/*

Let's implement the zipObject function that enables such results

zipObject(['fred', 'barney'], [30, 40])
=> { 'fred': 30, 'barney': 40 }

zipObject([['fred', 30], ['barney', 40]])
=> { 'fred': 30, 'barney': 40 }

The zipObject creates an object composed from arrays of keys and values. It is provided with either a single two dimensional array, i.e. [[key1, value1], [key2, value2]] or with two arrays, one of keys and one of corresponding values.

If only keys are given, then set the values to undefined.

zipObject(['fred', 'barney'])
{ fred: undefined, barney: undefined }

If neither keys nor values are specified, then return {}

zipObject()
{}

*/

function zipObject(keys=[], values=[]) {
	let result = {};
	if (Array.isArray(keys[0])) {
    	keys.forEach((pair) => {
      		if (Array.isArray(pair) && pair.length > 0)
        		result[pair[0]] = pair.length > 1 ? pair[1] : undefined;
    	});
	} else {
		keys.forEach((key, index) => {
			result[key] = index < values.length ? values[index] : undefined;
		});
	}
	return result;
}

console.log(zipObject(['fred', 'barney'], [30, 40]));
console.log(zipObject([['fred', 30], ['barney', 40]]));
console.log(zipObject(['fred', 'barney']));
console.log(zipObject());
