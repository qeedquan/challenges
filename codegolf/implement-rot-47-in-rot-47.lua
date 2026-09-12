#!/usr/bin/env lua

--[[

Challenge: Implement ROT-47 in code that works as both itself and as the ROT-47 version of itself.

Scoring:
Your score is calculated as a percentage of used, ROT-47 eligible bytes in total of both versions of the program divided by total bytes (all characters) of both versions.

A used, ROT-47 eligible byte is any character that would be converted by the ROT-47 cipher that is not part of a comment or ignored by the compiler/interpreter. For example, any character in a brainfuck program that is not +-<>[],.  is not considered a used byte, and any character in a C program including and after // or inside /* */ is not considered a used byte. All special symbols in APL are not considered used, as are all characters in a Whitespace program (sorry).

Ties will be broken by the program with the most upvotes. If there is still a tie, then the shortest program wins.

Example scoring:

C: 62/64 = 96.875%
Notice there is a space in this program. Obviously also, this program is not a valid entry because it doesn't even compile, but I wanted to show how scoring works.

main(){printf("Hello World!");}

--]]

function rot47(s)
	b = ""
	for i = 1, #s do
		c = string.byte(s:sub(i, i))
		if c > 32 and c <= 126 then
			c = 33 + ((c + 14) % 94)
		end
		b = b .. string.char(c)
	end
	return b
end

assert(rot47("Hello, World!") == "w6==@[ (@C=5P")
assert(rot47("This page provides a Javascript online web-based ROT47 Encoder/Decoder.") == "%9:D A286 AC@G:56D 2 y2G2D4C:AE @?=:?6 H63\\32D65 #~%cf t?4@56C^s64@56C]")
assert(rot47("ROT47 is the easiest and yet powerful cipher! ROT47 basically makes text unreadable and does not require addtional space.") == "#~%cf :D E96 62D:6DE 2?5 J6E A@H6C7F= 4:A96CP #~%cf 32D:42==J >2<6D E6IE F?C62523=6 2?5 5@6D ?@E C6BF:C6 255E:@?2= DA246]")
