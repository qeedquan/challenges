/*

In es5, if the code point of a charactor is large than 0xFFFF will be treat as more than one charactor.

Even codewars can't display emoji correctly.

For example:

The code point of an emoji  （big laugh: '\u{1f602}'）is 0x1f602.

So you will see:

''.length
// 2

Note: some emoji have more than one codepoint like  (China: '\u{1F1E8}\u{1F1F3}')，which is 0x1F1E8 0x1F1F3. This kata do not consider this situation for now.

And some chinese characters like Y which code point is 0x20059.

'Y'.length
// 2

We want get the real length of string. 

You need to write a function named getRealLength to get it.

*/

function getRealLength(string) {
	return [...string].length;
}

console.log(getRealLength(''));
console.log(getRealLength('Y'));
