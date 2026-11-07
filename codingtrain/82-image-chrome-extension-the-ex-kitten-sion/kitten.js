/*

To use as a chrome extension:

1. Open Extensions, turn on developer mode
2. Load unpacked extension, and point the folder to the directory with manifest.json at the top level
3. The file manifest.json represents the description of the extension,
   and specifies what code to run and other things such as permissions

*/

console.log('Kittens of the world, unite as one!');

let filenames = [
	'freddie-marriage-40645.jpg',
	'koen-eijkelenboom-353684.jpg',
	'mikhail-vasilyev-130018.jpg',
	'mikhail-vasilyev-253977.jpg',
	'roxanne-desgagnes-277568.jpg'
];

for (let image of document.getElementsByTagName('img')) {
	let index = Math.floor(Math.random() * filenames.length);
	let file = 'kittens/' + filenames[index];
	let url = chrome.runtime.getURL(file);
	image.src = url;
	console.log("KITTEN STRIKE: " + url);
}
