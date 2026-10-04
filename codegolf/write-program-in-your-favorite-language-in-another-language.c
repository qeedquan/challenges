/*

The determined Real Programmer can write Fortran programs in any language.

from Real Programmers Don't Use Pascal

Your task is to write program in your programming language of choice, but you are allowed to use only another language. That is, throw away all coding conventions from one language and replace them with coding conventions from other language. The more the better. Make your program look as if it was written in another language.

For example, Python fan who hates Java could write following Python program in Java:

void my_function()                                                             {
    int i = 9                                                                  ;
    while(i>0)                                                                 {
        System.out.println("Hello!")                                           ;
        i = i - 1                                                              ;}}
Pascal enthusiast forced to use C could write this:

#define begin {
#define end }
#define then
#define writeln(str) puts(str)

if (i == 10) then
begin
    writeln("I hate C");
end
You have to write complete program. The program desn't have to do anything useful.

Good Luck. This is a popularity contest so the code with the most votes wins!

*/

#include <stdio.h>

#define IF      if(
#define THEN    ){
#define ELSE    } else {
#define ELIF    } else if (
#define FI      ;}

#define BEGIN   {
#define END     }
#define SWITCH  switch(
#define IN      ){
#define ENDSW   }
#define FOR     for(
#define WHILE   while(
#define DO      ){
#define OD      ;}
#define REP     do{
#define PER     }while(
#define DONE    );
#define LOOP    for(;;){
#define POOL    }

#define PROCEDURE int
#define MAIN main(void)
#define RETURN return
#define WRITELN(x) puts(x)

PROCEDURE MAIN
BEGIN
	WRITELN("I hate C++");
	RETURN(0);
END
