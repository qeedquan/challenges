#!/bin/sh

cat << EOF >/dev/null

Inspired by both the challenge "Unique is Cheap" by @Laikoni, where the score is based on the challenge itself, as well as the JavaScript (ES6) answer of @ETHproductions for the "Palindrome Compression" challenge, where he uses a pretty cool compression method for the palindrome-flag, upper/lower case indication, and letters.

Challenge:
You will create two programs/function: a compress program/function, and a decompress program/function.

Compress program/function:
Given the characters used in your own source code (both the compress and decompress source code combined) as only possible input, use any kind of bit-compression method of your choice and output the resulting 0s and 1s of the bit-compression of this input.

The amount of bits (0s and 1s) outputted must be as short as possible, and this amount will be the score of your answer.

The idea is to have a nice balance between the different kind of characters used in your own source code, the size of your programs/functions, and the type of bit-compression you've used. Or to quote @RobertFraser in this comment:

This is a great example of the fundamentals of engineering. Taking a problem description, thinking about different ways to solve it, and making tradeoffs between requirements (ie how many bits to dedicate to various styles), etc

Challenge rules:
The compressor and decompressor program/function should be in the same programming language.
You must provide both a compression and decompression program/function, and the amount of 0s and 1s your compression program outputs for both programs/functions combined (concatted) as input will be your score.
The compression must - obviously - work for all characters used in your source code of both your compression and decompression program/function, in any order or amount. (It can have undefined behavior for any characters not in your source code.)
Input-type doesn't necessarily have to be a string. It could also be a list/array/stream of characters, and it can be as program argument, STDIN, etc. Your call.
Same applies to the output. Can be returned from a function or printed to STDOUT. Can be a single string, integer-array, etc.
Your compression program must output at least one 0 or 1 (so an empty cat program for both the compression and decompression program isn't possible).
Your source code may not only contain 0s and 1s already, excluding no-ops (to prevent programming languages that print their own source code by default, where both the compression and decompression programs can be a single 0 or 1, and the no-ops part is to prevent this behavior with an unused comment; sorry binary-based programming languages which only use 0s and 1s as source code).
Although you'll have to support an input of 0 or more of the character-pool used in your programs/functions, you don't have to support an empty input. So you can assume every input will be at least 1 character.
A possible input can be larger than your compression and decompression sizes combined.
If for whatever reason your compression method is order-depended and has a shorter output when your input is DecompressionProgramCompressionProgram instead of CompressionProgramDecompressionProgram, you are allowed to choose either order of concatting of your programs/function for your score.
Example:
Let's say the compression program is ABC, and the decompression program is 123aBc. For any input containing zero or more of the character-pool 123ABCab, it should be able to correctly compress those characters to 0s and 1s, and be able to decompress these 0s and 1s back into the correct characters. Some valid example inputs for these two programs can be: ABC123aBc (of course); A; 1Ca; 22222b1121221b; etc.

General rules:
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.
Example of an answer:
Java 8, score 1440 bits, 180 (87 + 93) bytes
Here a very bad implementation in Java 8, where each character is simply printed as 8-bit binary String.

Compression function:

Input provided as java.util.stream.IntStream.

s->s.forEach(c->System.out.print("".format("%8s",Long.toString(c,2)).replace(' ','0')))
Try it online.

Decompression function:

Input provided as String.

s->{for(Integer i=0;i<s.length();System.out.printf("%c",i.parseInt(s.substring(i,i+=8),2)));}

EOF

echo $@ | compress | uncompress
