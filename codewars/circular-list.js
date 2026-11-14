/*

Create a Circular List

A circular list is of finite size, but can infititely be asked for its previous and next elements. This is because it acts like it is joined at the ends and loops around.

For example, imagine a CircularList of [1, 2, 3, 4]. Five invocations of next() in a row should return 1, 2, 3, 4 and then 1 again. At this point, five invocations of prev() in a row should return 4, 3, 2, 1 and then 4 again.

Your CircularList is created by passing a vargargs parameter in, e.g. new CircularList(1, 2, 3). Your list constructor/init code should throw an Exception if nothing is passed in.

*/

class CircularList {
	constructor(...args) {
		if (!args.length)
			throw new Error("Wrong input!");
		
		this.list = [...args];
		this.index = -1;
	}

	next() {
		this.index = (this.index + 1) % this.list.length;
		return this.list[this.index];
	}

	prev() {
		if (this.index < 1)
			this.index = this.list.length - 1;
		else
			this.index -= 1;
		return this.list[this.index];
	}
}

var ring = new CircularList(1, 2, 3, 4);
for (let i = 0; i < 5; i++)
	console.log(ring.next());
for (let i = 0; i < 5; i++)
	console.log(ring.prev());

