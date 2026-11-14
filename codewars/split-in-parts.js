/*

The aim of this kata is to split a given string into different strings of equal size (note size of strings is passed to the method)

Example:

Split the below string into other strings of size #3

'supercalifragilisticexpialidocious'

Will return a new string
'sup erc ali fra gil ist ice xpi ali doc iou s'
Assumptions:

String length is always greater than 0
String has no spaces
Size is always positive

*/

function splitInParts(string, partLength) {
	let regex = new RegExp('.{' + partLength + '}', 'g');
	string = string.replace(regex, (match) => match + ' ');
	string = string.trim();
	return string;
}

console.log(splitInParts("supercalifragilisticexpialidocious", 3));

