/*

Given an object of likely nested objects, where the final element is an array containing positive integers, write a function that returns the name of the root property that a particular integer lives in.

E.g
Heres what the object looks like:

object = {
    "one": {
        "nest1": {
            "val1": [9, 34, 92, 100]
         }
    },
    "2f7": {
        "n1": [10, 92, 53, 71],
        "n2": [82, 34, 6, 19]
    }
}

getRootProperty(object, 9); //=> "one"
getRootProperty(object, 9) returns "one" because "one" is the root property name where the value 9 is buried in (in an array), other root properties may also have 9 buried in it but you should always return the first

Another Example
object = {
    "r1n": {
        "mkg": {
            "zma": [21, 45, 66, 111],
            "mii": {
                "ltf": [2, 5, 3, 9, 21]
             },
             "fv": [1, 3, 6, 9]
         },
         "rmk": {
             "amr": [50, 50, 100, 150, 250]
         }
    },
    "fik": {
        "er": [592, 92, 32, 13]
        "gp": [12, 34, 116, 29]
    }
}

getRootProperty(object, 250); //=> "r1n"
getRootProperty(object, 116); //=> "fik"
getRootProperty(object, 111); //=> "r1n"

getRootProperty(object, 999); //=> null
return null if the value isn't found.

*/

function getRootProperty(object, value) {
	for (let key in object) {
		if (Array.isArray(object[key])) {
			if (object[key].includes(value))
				return key;
		} else if (getRootProperty(object[key], value))
			return key;
	}
	return null;
}

object = {
	"one": {
		"nest1": {
			"val1": [9, 34, 92, 100]
		}
	},
	"2f7": {
		"n1": [10, 92, 53, 71],
		"n2": [82, 34, 6, 19]
	}
}

console.log(getRootProperty(object, 9));

object = {
	"r1n": {
		"mkg": {
			"zma": [21, 45, 66, 111],
			"mii": {
				"ltf": [2, 5, 3, 9, 21]
			},
			"fv": [1, 3, 6, 9]
		},
		"rmk": {
			"amr": [50, 50, 100, 150, 250]
		}
	},
	"fik": {
		"er": [592, 92, 32, 13],
		"gp": [12, 34, 116, 29]
	}
}

console.log(getRootProperty(object, 250));
console.log(getRootProperty(object, 116));
console.log(getRootProperty(object, 111));
console.log(getRootProperty(object, 999));
