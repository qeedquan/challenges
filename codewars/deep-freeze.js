/*

Create a complement to the Object.freeze function, Object.deepFreeze

This method should apply the Object.freeze function to an object and, recursively, all of its properties that are objects.

The freeze operation should prevent objects from being modified.

*/

Object.deepFreeze = function (object) {
	for (let key in object) {
		if (typeof object[key] === 'object')
			Object.deepFreeze(object[key]);
	}
	Object.freeze(object);
};

