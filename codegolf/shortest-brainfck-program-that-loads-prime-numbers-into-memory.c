/*

Write the shortest Brainfuck program that loads all primes below 256 into memory consecutively. All other cells must be zero.

You may place them in whatever order you like, but they must be consecutive. Also, for the sake of standartization, the pointer must point to either very start or very end of the sequence by the end of the execution.

*/

#include <stdio.h>

// ported from @Юрыч BRO solution
const char bf[] = "+[[->+>+<<]>>+++++]<[<<]<<<<++>>+++>>+++++>>++++++>>+++++>>++>>+>>-->>--->>-->>----->>---->>----->>-------->>--------->>-------->>------->>---------->>--------->>---------->>------------->>----------->>------------->>------------>>--------->>---------->>------------->>-------------->>----------------->>------------------>>--------->>---------->>--------->>------------>>------->>---------->>--------->>-------->>--------->>-------->>------->>---------->>----->>-------->>--------->>------------>>----->>++>>+>>-->>--->>-->>----->>";

int
main()
{
	puts(bf);
	return 0;
}
