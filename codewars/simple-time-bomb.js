/*

A bomb has been set to go off! You have to find the wire and cut it in order to stop the timer. There is a global property that holds the key to which wire to cut. Find that and then you can CutTheWire(wireKey);

*/

const globalKeys = [
	"console",
	"global",
	"process",
	"Buffer",
	"clearImmediate",
	"clearInterval",
	"clearTimeout",
	"setImmediate",
	"setInterval",
	"setTimeout",
	"__filename",
	"exports",
	"module",
	"__dirname",
	"require",
];

function CutTheWire(wire) {
	console.log(wire);
}

var wire;
for (const key in global) {
	if (!globalKeys.includes(key))
		wire = key;
}

CutTheWire(this[wire]);
