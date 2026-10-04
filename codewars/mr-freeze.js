/*

There is an object/class already created called MrFreeze. Mark this object as frozen so that no other changes can be made to it.

*/

class MrFreeze {
	constructor() {
		this.attribute = 2045;
	}
}

freeza = new MrFreeze();
Object.freeze(freeza);
console.log(freeza);

freeza.attribute = "XVF";
freeza.newthing = "old";
console.log(freeza);

