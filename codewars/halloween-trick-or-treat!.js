/*

Description:
Halloween is coming, and many children are in front of your house. They are shouting: "trick or treat!" So you need to give them some candy, let them leave.

Arguments:

children: numbers of children, more than or equals to 2

candies: packets of items, like this:

[["candy","apple","candy"],["candy","candy"],["candy","candy"]]

Results:

If the children get what they want, return "Thank you, strange uncle!"
If not, return "Trick or treat!"

How to let the children satisfied?

1 - Each child has at least two candies;
2 - Each child gets the same amount of candy.
3 - No children get the "bomb" ;-)
4 - Packets cannot be divided, each child gets a full packet

Some Examples
trickOrTreat(3,[["candy","apple","candy"],["candy","candy"],["candy","candy"]])
should return: "Thank you, strange uncle!"(Don't mind apple)

trickOrTreat(3,[["candy","apple"],["apple","candy"],["candy","apple"]])
should return: "Trick or treat!"(Each child has only got 1 candy)

trickOrTreat(3,[["candy","apple","candy"],["candy","candy"],["candy","candy","candy"]])
should return: "Trick or treat!"(The amount of candy are diffrent)

trickOrTreat(3,[["candy","apple","candy"],["candy","candy"]])
should return: "Trick or treat!"(One child has no candy)

trickOrTreat(3,[["candy","apple","candy"],["candy","candy"],["candy","bomb","candy"]])
should return: "Trick or treat!"(Some child got a bomb)

You can assume that the arguments are valid arrays (like the examples above, no empty array).

*/

function trickOrTreat(children, candies) {
	if (candies.length !== children)
		return 'Trick or treat!';

	let counts = [];
	for (let pack of candies) {
		if (pack.includes('bomb'))
			return 'Trick or treat!';

		let count = pack.filter((item) => item === 'candy').length;
		if (count < 2)
			return 'Trick or treat!';

		counts.push(count);
	}

	if (counts.every((c) => c === counts[0]))
		return 'Thank you, strange uncle!';
	
	return 'Trick or treat!';
}

console.log(trickOrTreat(3, [["candy", "apple", "candy"], ["candy", "candy"], ["candy", "candy"]]));
console.log(trickOrTreat(3, [["candy", "apple"], ["apple", "candy"], ["candy", "apple"]]));
console.log(trickOrTreat(3, [["candy", "apple", "candy"], ["candy", "candy"], ["candy", "candy", "candy"]]));
console.log(trickOrTreat(3, [["candy", "apple", "candy"], ["candy", "candy"]]));
console.log(trickOrTreat(3, [["candy", "apple", "candy"], ["candy", "candy"], ["candy", "bomb", "candy"]]));

