/*

Asked on Stack Overflow, but they suggested to move it here

A while ago I was reading about quines. It made me wonder if it possible to write a macro in C which will print itself, without writing any function such as main. every piece of code should be only in macro. After a few attempts, I couldn't find the solution.

While searching the web for answer, I found the following code:

#define Q(x) #x;x
char *q=Q(main(){printf("#define Q(x) #x;x\nchar *q=Q(");printf(q);printf(")\n");})
Although part of the code isn't in the #define (isn't macro). Is it possible to implement a macro which will print the program ( quine type program )?

EDIT: if it isn't possible (because the macros are 'made' in the preprocessor step), is it possible to implement a quine which is mostly in macros?

*/

int printf(const char *, ...);
#define Q(x) #x; x
char *q = Q(int main(void) {printf("int printf(const char *, ...);\n#define Q(x) #x;x\nchar *q=Q(");printf("%s", q);printf(")\n"); })
