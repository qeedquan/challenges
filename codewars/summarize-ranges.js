/*

Given a sorted array of numbers, return the summary of its ranges.

Examples
summaryRanges([1, 2, 3, 4]) === ["1->4"]
summaryRanges([1, 1, 1, 1, 1]) === ["1"]
summaryRanges([0, 1, 2, 5, 6, 9]) === ["0->2", "5->6", "9"]
summaryRanges([0, 1, 2, 3, 3, 3, 4, 5, 6, 7]) === ["0->7"]
summaryRanges([0, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7, 7, 9, 9, 10]) === ["0->7", "9->10"]
summaryRanges([-2, 0, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7, 7, 9, 9, 10, 12]) === ["-2", "0->7", "9->10", "12"]

*/

function summaryRanges(numbers) {
	if (numbers.length == 0)
		return [];
	
	let ranges = [[numbers[0]]];
	let current = numbers[0];
	for (let i = 1; i < numbers.length; i++) {
		if (numbers[i] <= current + 1)
			ranges[ranges.length - 1].push(numbers[i]);
		else
			ranges.push([numbers[i]]);
		current = numbers[i];
	}
	return ranges.map((r) => {
		let unique = Array.from(new Set(r));
		if (unique.length == 1)
			return unique[0].toString();
		return unique[0].toString() + '->' + unique[unique.length - 1].toString();
	});
}

console.log(summaryRanges([1, 2, 3, 4]));
console.log(summaryRanges([1, 1, 1, 1, 1]));
console.log(summaryRanges([0, 1, 2, 5, 6, 9]));
console.log(summaryRanges([0, 1, 2, 3, 3, 3, 4, 5, 6, 7]));
console.log(summaryRanges([0, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7, 7, 9, 9, 10]));
console.log(summaryRanges([-2, 0, 1, 2, 3, 3, 3, 4, 4, 5, 6, 7, 7, 9, 9, 10, 12]));

