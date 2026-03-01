/*

Summary:
For any given language, what is the smallest amount of unique characters for your language to be Turing-Complete?

Challenge:
For any language of your choice, find the smallest subset of characters that allows your language to be Turing-Complete. You may reuse your set of characters as many times as you want.

Examples:
JavaScript: +!()[] (http://www.jsfuck.com)

Brainfuck: +<>[] (assumes a wrapping cell size)

Python 2: ()+1cehrx (made from scripts like exec(chr(1+1+1)+chr(1)))

Scoring:
This challenge is scored in characters, not bytes. For example, The scores for the examples are 6, 5, and 9.

Notes:
This challenge differentiates from others in the sense that you only your language to be Turing-Complete (not necessarily being able to use every feature of the language.)

Although you can, please do not post answers without reducing the characters used. Example: Brainfuck with 8 characters (since every other character is a comment by default.)

You MUST provide at least a brief explanation as to why your subset is Turing-Complete.

*/

/*

@ceilingcat

+,1;=aimn[]{}

This covers all programs of the form

main[]={<sequence of constants>};
...where the sequence of constants (of the form 1...+1...+1...) contains the machine code representation of your program.
This assumes that your environment permits all memory segments to be executed (apparently true for tcc [thanks @Dennis!] and some machines without NX bit).
Otherwise, for Linux and OSX you may have to prepend the keyword const and for Windows you may have to add a #pragma explicitly marking the segment as executable.

Sample x86 assembly: 0xc3 (ret)

*/

__attribute__((section(".text#"))) int main[] = {
	111 + 111 - 11 - 11 - 11 + 1 + 1 + 1 + 1 + 1 + 1
};
