/*

You're probably familiar with zip bombs, XML bombs, etc. Put simply, they are (relatively) small files which produce enormous output when interpreted by naïve software. The challenge here is to abuse a compiler in the same way.

Challenge
Write some source code which occupies 512 bytes or less and which compiles into a file which occupies the most possible space. Largest output file wins!

Rules
OK, so there are a few important clarifications, definitions and restrictions;

The output of the compilation must be an ELF file, a Windows Portable Executable (.exe), or virtual bytecode for the JVM or .Net's CLR (other types of virtual bytecode are also likely to be OK if asked for). Update: Python's .pyc / .pyo output also counts.
If your language-of-choice can't be compiled directly into one of those formats, transpilation followed by compilation is also allowed (Update: you can transpile multiple times, just so long as you never use the same language more than once).
Your source code can consist of multiple files, and even resource files, but the summed size of all these files must not exceed 512 bytes.
You cannot use any other input than your source file(s) and the standard library of your language-of-choice. Static linking standard libraries is OK when it's supported. Specifically, no third party libraries or OS libraries.
It must be possible to invoke your compilation using a command or series of commands. If you require specific flags when compiling, these count towards your byte limit (e.g. if your compile line is gcc bomb.c -o bomb -O3 -lm, the -O3 -lm part (7 bytes) will be counted (note the initial leading space isn't counted).
Preprocessors are permitted only if they are a standard compilation option for your language.
The environment is up to you, but in the interests of making this verifiable, please stick to recent (i.e. available) compiler versions and operating systems (and obviously specify which you're using).
It must compile without errors (warnings are OK), and crashing the compiler doesn't count for anything.
What your program actually does is irrelevant, though it can't be anything malicious. It doesn't even have to be able to start.
Example 1
The C program

main(){return 1;}
Compiled with Apple LLVM version 7.0.2 (clang-700.1.81) on OS X 10.11 (64-bit):

clang bomb.c -o bomb -pg
Produces a file of 9228 bytes. The total source size is 17+3 (for the -pg) = 20 bytes, which is easily within size limit.

Example 2
The Brainfuck program:

++++++[->++++++++++++<]>.----[--<+++>]<-.+++++++..+++.[--->+<]>-----.--
-[-<+++>]<.---[--->++++<]>-.+++.------.--------.-[---<+>]<.[--->+<]>-.
Transpiled with awib to c with:

./awib < bomb.bf > bomb.c
Then compiled with Apple LLVM version 7.0.2 (clang-700.1.81) on OS X 10.11 (64-bit):

clang bomb.c
Produces a file of 8464 bytes. The total input here is 143 bytes (since @lang_c is the default for awib it didn't need to be added to the source file, and there are no special flags on either command).

Also note that in this case, the temporary bomb.c file is 802 bytes, but this counts towards neither the source size nor the output size.

Final Note
If an output of more than 4GB is achieved (perhaps if somebody finds a turing complete preprocessor), the competition will be for the smallest source which produces a file of at least that size (it's just not practical to test submissions which get too big).

*/

/*

@Digital Trauma

This defines the main function as a large array and initialises its first element. This causes GCC to store the entire array in the resulting executable.

*/

int main[-1u] = { 1 };
