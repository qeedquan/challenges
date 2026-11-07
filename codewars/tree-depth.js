/*

Write a method that takes a nested hash (object in javascript) as input and returns that hash with added "depth" keys. So, for example, the following input:

{ a: 1, b: 2, c: { d: { e: 3 } } }

would yield the following return value:

{ a: 1, b: 2, c: { d: { e: 3, depth: 2 }, depth: 1 }, depth: 0 }

For Ruby, if the input is not a hash, then the function should return nil. For JavaScript, if the input is not an object (including an array), the function should return null.

*/

function record(tree, depth=0) {
	if (typeof tree !== 'object' || tree === null || Array.isArray(tree))
		return null;
	
	tree.depth = depth;
	for (let key in tree) {
		if (typeof tree[key] === 'object' && tree[key] !== null)
			record(tree[key], depth + 1);
	}
	return tree;
}

console.log(record({ a: 1, b: 2, c: { d: { e: 3 } } }))
