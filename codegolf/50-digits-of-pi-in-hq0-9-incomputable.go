/*

Background
HQ0-9+-INCOMPUTABLE?! is a half-joke programming language introduced in Internet Problem Solving Contest 2011, Problem H.

HQ9+ is an esoteric programming language specialized for certain tasks. For example, printing “Hello, world!” or writing a quine (a program that prints itself) couldn’t be any simpler. Unfortunately, HQ9+ doesn’t do very well in most other situations. This is why we have created our own variant of the language, HQ0-9+-INCOMPUTABLE?!.

A HQ0-9+-INCOMPUTABLE?! program is a sequence of commands, written on one line without any whitespace (except for the trailing newline). The program can store data in two memory areas: the buffer, a string of characters, and the accumulator, an integer variable. Initially, the buffer is empty and the accumulator is set to 0. The value of the buffer after executing all the commands becomes the program’s output.

HQ0-9+-INCOMPUTABLE?! supports the following commands:

command	description
h, H	appends helloworld to the buffer
q, Q	appends the program source code to the buffer (not including the trailing newline)
0-9	replaces the buffer with n copies of its old value – for example, 2 doubles the buffer (aab would become aabaab, etc.)
+	increments the accumulator
-	decrements the accumulator
i, I	increments the ASCII value of every character in the buffer
n, N	applies ROT13 to the letters and numbers in the buffer (for letters ROT13 preserves case; for digits we define ROT13(d) = (d + 13) mod 10)
c, C	swaps the case of every letter in the buffer; doesn’t change other characters
o, O	removes all characters from the buffer whose index, counted from the end, is a prime or a power of two (or both); the last character has index 1 (which is a power of 2)
m, M	sets the accumulator to the current buffer length
p, P	removes all characters from the buffer whose index is a prime or a power of two (or both); the first character has index 1 (which is a power of 2)
u, U	converts the buffer to uppercase
t, T	sorts the characters in the buffer by their ASCII values
a, A	replaces every character in the buffer with its ASCII value in decimal (1–3 digits)
b, B	replaces every character in the buffer with its ASCII value in binary (exactly eight 0/1 characters)
l, L	converts the buffer to lowercase
e, E	translates every character in the buffer to l33t using the following table:
ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 0123456789
48(03=6#|JXLM~09Q257UVW%Y2 a6<d3f9hijk1m^0p9r57uvw*y2 O!ZEA$G/B9
?	removes 47 characters from the end of the buffer (or everything if it is too short)
!	removes 47 characters from the beginning of the buffer (or everything if it is too short)
To prevent code injection vulnerabilities, during the execution of your program the buffer must never contain non-alphanumeric characters, i.e. characters other than A-Z, a-z, and 0-9. Should this happen, the program fails with a runtime error, and your submission will be rejected.

The original problem statement contains limits about the code length and buffer length, but I removed them in this challenge. This is also reflected in the interpreter link below. (If you need even larger buffer, you can change the MAX_BUFFER constant near the top. I doubt using a longer buffer will give reasonably short code though.)

Task
Output the string (which is 50 digits of Pi without leading 3.)

14159265358979323846264338327950288419716939937510
in HQ0-9+-INCOMPUTABLE?!.

An answer is scored as follows:

Each occurrence of Q/q adds 1,000,000 points.
Each occurrence of E/e adds 10,000 points.
Each occurrence of any other valid command adds 1 point.
Lowest score wins.

Bonus: +500 bounty to the first answer that achieves the score of 9,999 points or lower. I have confirmed that this is possible. claimed by dingledooper

C++ interpreter
#include <cstdio>
#include <cctype>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

#define MAX_CODE   10000000
#define MAX_BUFFER 10000000

string code;
string buffer;
bool keep[MAX_BUFFER+47];

#define fail(...) (printf(__VA_ARGS__), exit(1))

int rot13(int c) {
  if(c >= 'a' && c <= 'z') return 'a' + ((c-'a') + 13)%26;
  if(c >= 'A' && c <= 'Z') return 'A' + ((c-'A') + 13)%26;
  if(c >= '0' && c <= '9') return '0' + ((c-'0') + 13)%10;
  return c;
}

int swapcase(int c) {
  if(c >= 'a' && c <= 'z') return c - 'a' + 'A';
  if(c >= 'A' && c <= 'Z') return c - 'A' + 'a';
  return c;
}

int show(int c) {
  return c >= 32 && c <= 126 ? c : '?';
}

int to1337(int c) {
  const char* digit = "O!ZEA$G/B9";
  const char* lower = "a6<d3f9hijk1m^0p9r57uvw*y2";
  const char* upper = "48(03=6#|JXLM~09Q257UVW%Y2";
  if(c >= '0' && c <= '9') return digit[c-'0'];
  if(c >= 'a' && c <= 'z') return lower[c-'a'];
  if(c >= 'A' && c <= 'Z') return upper[c-'A'];
  return c;
}

int main() {
  keep[0] = 1;
  keep[1] = 1;
  for(int i = 2; i < MAX_BUFFER+42; i++)
    if(!keep[i])
      for(int j = i+i; j < MAX_BUFFER+42; j += i)
        keep[j] = 1;
  for(int i = 1; i < MAX_BUFFER+42; i *= 2)
    keep[i] = 0;

  int c;
  while((c = getchar()) != EOF && code.size() < MAX_CODE+47)
    code.push_back(c);
  if(c != EOF) fail("Program too long\n");
  while(code.size() > 0 && (code[code.size()-1] == '\n' || code[code.size()-1] == '\r'))
    code.resize(code.size()-1);
  if(code.size() > MAX_CODE) fail("Program too long\n");

  for(int pc = 0; pc < code.size(); pc++) {
    int cmd = toupper(code[pc]);
    int unhandled = false;
    switch(cmd) {
      case 'H':
        buffer.append("helloworld");
        break;

      case 'Q':
        buffer.append(code);
        break;

      case 'N':
        for(int i = 0; i < buffer.size(); i++)
          buffer[i] = rot13(buffer[i]);
        break;

      case 'A':
        {
          stringstream ss;
          for(int i = 0; i < buffer.size(); i++)
            ss << ((int)buffer[i]);
          buffer = ss.str();
        }
        break;

      case 'B':
        {
          string newbuffer;
          for(int i = 0; i < buffer.size(); i++)
            for(int j = 7; j >= 0; j--)
              newbuffer.push_back((buffer[i] & (1<<j)) ? '1' : '0');
          buffer = newbuffer;
        }
        break;

      case 'I':
        for(int i = 0; i < buffer.size(); i++)
          buffer[i]++;
        break;

      case 'U':
        for(int i = 0; i < buffer.size(); i++)
          buffer[i] = toupper(buffer[i]);
        break;

      case 'L':
        for(int i = 0; i < buffer.size(); i++)
          buffer[i] = tolower(buffer[i]);
        break;

      case 'C':
        for(int i = 0; i < buffer.size(); i++)
          buffer[i] = swapcase(buffer[i]);
        break;

      case 'O':
      case 'P':
        {
          string newbuffer;
          for(int i = 0; i < buffer.size(); i++)
            if (cmd == 'P' ? keep[i+1] : keep[buffer.size()-i])
              newbuffer.push_back(buffer[i]);
          buffer = newbuffer;
        }
        break;

      case '?':
        buffer.resize(buffer.size() >= 47 ? buffer.size()-47 : 0);
        break;

      case '!':
        buffer.erase(0, buffer.size() >= 47 ? 47 : buffer.size());
        break;

      case 'E':
        for(int i = 0; i < buffer.size(); i++)
          buffer[i] = to1337(buffer[i]);
        break;

      case 'T':
        sort(buffer.begin(), buffer.end());
        break;

      case '+':
      case '-':
      case 'M':
        break;

      default:
        unhandled = true;
        break;
    }
    if(unhandled && cmd >= '0' && cmd <= '9') {
      string newbuffer;
      for(int i = 0; i < cmd-'0'; i++) newbuffer.append(buffer);
      buffer = newbuffer;
      unhandled = false;
    }
    if(unhandled) fail("Unknown command %c (ASCII %d)\n", show(cmd), cmd);
    if(buffer.size() > MAX_BUFFER) fail("Buffer size exceeded %d\n", MAX_BUFFER);
    for(int i = 0; i < buffer.size(); i++)
      if(!isalnum(buffer[i]))
        fail("Code injection check failed: buffer contains %c (ASCII %d)\n", show(buffer[i]), buffer[i]);
  }

  for(int i = 0; i < buffer.size(); i++)
    putchar(buffer[i]);
  putchar('\n');
  return 0;
}

If you're wondering about the role of the accumulator, you're right: it still does nothing useful.

*/

package main

import "fmt"

func main() {
	fmt.Println(CODE)
}

/*

@tjjfvi

This uses a much different approach from dingledooper's answer – notably, it only uses h1-9a?!. The initial hahaha fills the buffer with a pool containing all digits, and then it uses careful duplications and slices to construct the string in a contiguous stretch in the buffer, at which point it chops off the surrounding character pool.

*/

const CODE = `hahaha!!4?????3?????????h?2!!????2!!!h?2!!!2!!!!!hh2????2???2hhhhh?hhh2!!!!!!!!h?2!!?????!6!!!!!!!!!!!!hhh?hhhhh?hhhh?2!!?????!!2hhhhh?3!!!!!!hhhh?2??2!hh2????2???h?2!???!2hhhh?2!!!h3??????hh?2!??!2!h?3!!!2?2!hhhh?hhh2!!!h?2!!h2??h2??h?2?!6!!!!!!!h?2!!2!?4!!!!h?2?h?2??2?!2!3!!!!!3!!!!h?5????2?h?2?2hhhhh?2!!!h2!!2??2?2!hhh?hhh2!!!hh?hhhh2????2??!2h2!!!hhhh?hhhh?2??!2!3!!!2!!3???2??2?6????????2!???!2!hhh2!!!h?3!!!!!3????h3??????2?!2h?2!!!2!!!!hh2!!!hh?2!??2hh3!!!!!!!!hh?h2??2???h?2??!2hhhh?2!??2!hh2!!!!h?hhhh?2??!2!2!!hhhh?2?4???h2???2???2!??2hh?2!!!!2!!!!!hhhh2?????2!???!2!4!!!!!2!!!3???h?2?2!!hh?2!!2??2?!2h?hhh2!!!!3??????h?2!??2hhhh?2!!!hh2!!!!2???h2???2??!2!h2!hh2!!!!2??2???2?4!!!!h2!!!h2???2????2??!2!hhhh?hhhh?2??!6!!!!!2!!h2??2?2!hh2!!!!h?2??3????2?2!2!!!!!2????2????h?2!???!3!!hhh2!!!h3?????`
