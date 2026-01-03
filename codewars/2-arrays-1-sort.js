/*

Imagine two arrays/lists where elements are linked by their positions in the array. For example:

HowMany = [ 1   ,   6  ,  5  ,   0  ];
Type = ['house', 'car','pen','jeans'];

Means I have 1 house, 6 cars,5 pens and 0 jeans.

Now if we sort one array we lose the connectivity. The goal is to create a sorting function that keeps the position link linkedSort(arrayToSort,linkedArray,compareFunction). So for every element that moves in arrayToSort(HowMany in the example), the corresponding element in linkedArray(Type in the example) needs to move similarly.

For example in Javascript:

//INPUT
HowMany = [ 1   ,   6  ,  5  ,   0  ];
Type = ['house', 'car','pen','jeans'];

//SORT
res = linkedSort(HowMany,Type,function(a,b){return a-b;})

//OUTPUT
HowMany === res === [ 0   ,   1   ,  5  ,  6  ];
Type       ===     ['jeans','house','pen','car'];
linkedSort(...) return the "arrayToSort" sorted only.

If no compare function is provided you should handle like an alphabetical sorting would do, e.g:

[-71,-6,35,0].sort() ===  [-6,-71,0,35] != [-71,-6,0,35]
ч
Note: it is assumed that array are same length.

*/

function linkedSort(array, linked, compare) {
	let combined = array.map((value, index) => ({
		value: value,
		linked: linked[index]
	}));

	combined.sort((element0, element1) => {
		if (compare)
			return compare(element0.value, element1.value);
		let string0 = String(element0.value);
		let string1 = String(element1.value);
		return string0.localCompare(string1);
	});

	for (let index = 0; index < combined.length; index++) {
		array[index] = combined[index].value;
		linked[index] = combined[index].linked;
	}

	return array;
}

let HowMany = [ 1   ,   6  ,  5  ,   0  ];
let Type = ['house', 'car','pen','jeans'];
let res = linkedSort(HowMany, Type, function (a, b) { return a - b; })
console.log(res);
console.log(Type);

