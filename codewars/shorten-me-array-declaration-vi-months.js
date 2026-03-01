/*

Shorten Me: Array Declaration VI (Months)

Task
You have to write an array() function returning an array object with elements as follow:

[ 'January', 'February', 'March', 'April', 'May', 'June',
  'July', 'August', 'September', 'October', 'November', 'December',
  'January', 'February', 'March', 'April', 'May', 'June',
  'July', 'August', 'September', 'October', 'November', 'December' ]

Coding Limitation:
Less than 120 characters

*/

function months() {
	let datetime = new Intl.DateTimeFormat("en-US", { month: 'long' });
	let result = [];
	for (let month = 0; month < 24; month++) {
		result.push(datetime.format(new Date(2000, month % 12, 1)));
	}
	return result;
}

console.log(months());

