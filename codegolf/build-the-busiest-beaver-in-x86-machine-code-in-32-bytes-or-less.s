/*

Your task is to write a program in x86 machine language (any version you like) that will run through as many instructions as possible and then halt, using a maximum of 32 bytes of code and starting with zeroed-out registers.

You can assume anything about the random-access memory you like, as long as it's in a usable format for the x86 machine.

*/

// ported from @Keith Randall solution
start:
	movq    $0x1a,%rax
	stc

loop:
	adcb    %cl, (%rax)
	incq    %rax
	jnz     loop
	jnc     start
	hlt

