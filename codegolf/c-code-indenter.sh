#!/bin/sh

cat << EOF >/dev/null

Situation: You are a high school teacher, teaching your computing class how to write C programs. However, since it is just the beginning of the term, you haven't taught them about the importance of indentation and spacing. As you are marking their work, your eyes hurt so much you scream in agony, and realise that this can't go on.

Task: You have decided to write a program, in any language, that takes a valid C sourcecode as input and output it nicely formatted. You should decide what is a nicely formatted code, as it is a popularity contest. You are encouraged to implement as many features as you can, the following are some examples:

Add proper indentation at the front of each line
Add spaces after , and other operators, e.g. converting int a[]={1,2,3}; to int a[] = {1, 2, 3};. Remember not to process operators within string literals though.
Remove trailing spaces after each line
Separating statements into several lines, e.g. the student may write tmp=a;a=b;b=tmp; or int f(int n){if(n==1||n==2)return 1;else return f(n-1)+f(n-2);} all in one line, you can separate them into different lines. Be aware of for loops though, they have semicolons in them but I really don't think you should split them up.
Add a new line after defining each function
Another other features you can come up with the help you comprehend your students' codes.
Winning criteria: This is a popularity contest, so the answer with most upvotes wins. In case of a tie, the answer with the most features implemented wins. If that is a tie again then shortest code wins.

You are suggested to include in your answer a list of features that you have implemented, as well as a sample input and output.

Edit: As requested in the comments here is a sample input, though keep in mind that it is only for reference and you are recommended to implement as many features as possible.

Input:

#include <stdio.h>
#include<string.h>
int main() {
int i;
char s[99];
     printf("----------------------\n;;What is your name?;;\n----------------------\n"); //Semicolon added in the string just to annoy you
             /* Now we take the input: */
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){if(s[i]>='a'&&s[i]<='z'){
        s[i]-=('a'-'A'); //this is same as s[i]=s[i]-'a'+'A'
}}printf("Your name in upper case is:\n%s\n",s);
   return 0;}
This is how I would normally format this code: (I'm a lazy person)

#include <stdio.h>
#include <string.h>
int main() {
    int i;
    char s[99];
    printf("----------------------\n;;What is your name?;;\n----------------------\n"); //Semicolon added in the string just to annoy you
    /* Now we take the input: */
    scanf("%s",s);
    for(i=0;i<strlen(s);i++) {
        if(s[i]>='a'&&s[i]<='z') {
            s[i]-=('a'-'A'); //this is same as s[i]=s[i]-'a'+'A'
        }
    }
    printf("Your name in upper case is:\n%s\n",s);
    return 0;
}
This is how I think is easier to read:

#include <stdio.h>
#include <string.h>
int main() {
    int i;
    char s[99];
    printf("----------------------\n;;What is your name?;;\n----------------------\n"); //Semicolon added in the string just to annoy you
    /* Now we take the input: */
    scanf("%s", s);
    for(i = 0; i < strlen(s); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= ('a' - 'A'); //this is same as s[i]=s[i]-'a'+'A'
        }
    }
    printf("Your name in upper case is:\n%s\n", s);
    return 0;
}



Also, now that I start having answers, the answer with the highest vote count will be accepted 5 days after the last answer, i.e. if there are no more new answers within 5 days, this contest will end.

EOF

clang-format $@
