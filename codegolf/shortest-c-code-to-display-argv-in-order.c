/*

I recently tried to produce the shortest C code possible to display all its command line arguments (which are stored in argv).

I ended with a relatively small piece of code, and I was wondering if there was some trick I'm not aware of.
Here's my try (I compile with C17, but any standard before C23 is very likely to compile/link/run as intended, probably with some warnings though):

main(c,v)int**v;{for(;*v;)puts(*v++);}
First, main(c,v)int**v. In C, every variable and function must have a type, but if it isn't specified at the declaration, then int is assumed. For now, it means main function returns an int, and both c and v (argc and argv) are also of int type. But, the int**v right after the closing parenthesis is actually changing the type of v to int**. This syntax is the old-style function definition, back from the K&R book. However, C23 standard plans to remove this feature from the language (see on cppreference). So we end up with c being an int (as a normal argc is), and v being an int** (contrary to a normal argv which is char** or char*[] (but char*[] is treated as a char** in a function)).

Then, the for loop for(;*v;) (note: a while(*v) does the same thing). As a remainder, v is filled with a list of char pointers to the command line arguments, but they're treated as integer pointers and not character pointers here. Thus, the loop runs until the first pointer in v is NULL (is equal to 0).

puts(*v++); does two things ; writing down the first string (it takes the first pointer in v, a int*, but puts expects a char*, so it can correctly deal with it) in the console and increases v (instead of having an iterator variable i, then doing v[i], here I use *v and v++ to save some characters). I also haven't used curly brackets around the for loop because when omitting them, the loop body is the first statement below it. I used int instead of char to declare v, in order to save a char. But is there a platform where those pointer types aren't the same size ? I once saw that function pointers may have a different size than ordinary pointers, but I don't know if this may be true for two pointers of different types.

It is guaranteed that argv[argc] is NULL, thus the code is guaranteed not to have an infinite loop (see here).

Then no need to add a return 0; because it is guaranteed main will return 0 if I don't put a return statement.

Some may wonder why I was able to call puts without including stdio.h, it's because in C, the whole library is linked to the binary (this question is a duplicate, but I put it here because the answer better explains this point than the original question). It also not seems to have a standard behavior (hence the warning), thus be aware of that (never rely on an undefined behavior). Same thing seems to apply for implicit int type.
Can someone confirm or not ?

Thus, my final question, is there any way to shorten this code ? I'm asking either for standard or platform-specific ways.

Sorry for the long post, but I wanted to explain for any interested beginner.

*/

#include <stdio.h>

int
main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		puts(argv[i]);
	return 0;
}
