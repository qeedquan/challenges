/*

No Story

No Description

Only by Thinking and Testing

Look at result of testcase, guess the code!

*/

var assert = require('assert');

class Phone {
	constructor() {
		this.ring = '';
		this.screen = '';
		this.microphone = '';
		this.currentCall = null;
	}

	incomingcall(number) {
		const contact = contacts.find((c) => c.number === number);
		if (contact) {
			this.ring = contact.ring;
			this.screen = `Call: ${contact.name}\nNumber: ${contact.number}`;
			this.currentCall = contact;
		} else {
			this.ring = 'Di Da Di';
			this.screen = `Call: stranger\nNumber: ${number}`;
			this.currentCall = { name: 'stranger', number };
		}
		this.microphone = '';
	}

	connect() {
		if (this.currentCall) {
			this.microphone = (this.currentCall.name === 'stranger')
				? 'Hello, who is speaking, please?'
				: `Hello, ${this.currentCall.name}!`;
			this.ring = '';
			this.screen = '';
		}
	}

	hangup() {
		this.ring = '';
		this.screen = '';
		this.microphone = '';
		this.currentCall = null;
	}
}

function assertSimilar(value1, value2) {
	assert(value1 === value2);
}

contacts=[
	{ name: "John", number: 11111111, ring: "Do Re Mi" },
	{ name: "Tom", number: 22222222, ring: "Mi Re Do" },
	{ name: "Jack", number: 33333333, ring: "Fa So La Ti" }
]

// Waiting for a call...
var aPhone = new Phone();
assertSimilar(aPhone.ring, "", "");
assertSimilar(aPhone.screen, "", "");
assertSimilar(aPhone.microphone, "", "");

// Someone callin, is your friend John
aPhone.incomingcall(11111111);
assertSimilar(aPhone.ring, "Do Re Mi", "");
assertSimilar(aPhone.screen, "Call: John\nNumber: 11111111", "");
assertSimilar(aPhone.microphone, "", "");

// Connect the call
aPhone.connect();
assertSimilar(aPhone.microphone, "Hello, John!", "");
assertSimilar(aPhone.ring, "", "");
assertSimilar(aPhone.screen, "", "");

// Hangup the call
aPhone.hangup();
assertSimilar(aPhone.ring, "", "");
assertSimilar(aPhone.screen, "", "");
assertSimilar(aPhone.microphone, "", "");

// And next...
aPhone.incomingcall(33333333);
assertSimilar(aPhone.ring, "Fa So La Ti", "");
assertSimilar(aPhone.screen, "Call: Jack\nNumber: 33333333", "");
assertSimilar(aPhone.microphone, "", "");
aPhone.connect();
assertSimilar(aPhone.microphone, "Hello, Jack!", "");
aPhone.hangup();

// A stranger call in
aPhone.incomingcall(44444444);
assertSimilar(aPhone.ring, "Di Da Di", "");
assertSimilar(aPhone.screen, "Call: stranger\nNumber: 44444444", "");
assertSimilar(aPhone.microphone, "", "");
aPhone.connect();
assertSimilar(aPhone.microphone, "Hello, who is speaking, please?", "");
aPhone.hangup();

