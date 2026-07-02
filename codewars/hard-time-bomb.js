/*

A bomb has been set to go off! You have to find the wire and cut it in order to stop the timer.
There is a global var that holds the numeric ID to which wire to cut.
Find that and then you can Bomb.CutTheWire(wireKey);

*/

class Bomb {
	static CutTheWire(code) {
		console.log(code);
	}
}

function wireCode() {
	let keys = this.Object.keys(this);
	let values = this.Object.values(this);
	for (let i = 0; i < keys.length; i++) {
		if (keys[i] === "boom")
			return values[i];
	}
	return null;
}

global.boom = "BOOM!";
Bomb.CutTheWire(wireCode());

