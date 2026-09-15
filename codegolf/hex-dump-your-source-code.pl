#!/usr/bin/env perl -wl

# When code-golfing there will be times where you need a Hex Dump of your code, usually because you've used unprintable characters. So, why not make a program that Hex Dumps itself?
#
# The Challenge
# This challenge is to, given no input, output a Hex Dump of your source code in the following formatting:
#
# 0000: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
# 0010: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
# 0020: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
# 0030: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
# Or, for example, if your program was print("SomeString"):rep(123)
#
# 0000: 70 72 69 6e 74 28 5c 22 53 6f 6d 65 53 74 72 69  print("SomeStrin
# 0010: 6e 67 5c 22 29 3a 72 65 70 28 31 32 33 29        g"):rep(123)
# Specifics
# The hex dump is split into rows of three parts, each row representing 16 bytes of your source code.
#
# The first part is the memory address. It specifies where the current row starts in your code. Written as a 2 Byte Hexadecimal number, followed by a :, then a space.
#
# The Second, is the Hex Dump itself. This is 16 bytes of your Source Code, written in Hexadecimal form separated by spaces. This should be an accurate byte representation using your code's encoding.
#
# Lastly, after a two space gap, is the code itself. This is simply 16 characters of your code, with Non printable characters written as .
#
# Notes
# This is a quine challenge, so Standard Quine Rules apply.
# And this is code-golf challenge too, so Standard Loopholes apply.
# As shown in the second example, do not write bytes after EOF, instead use whitespace.
# Trailing whitespace is fine.
# Inbuilts to Hex dump, if you happen to have one in this specific format, are not banned but are frowned upon.
# Non printable characters refer to any character that, represented as only a single byte, cannot be represented as a single spaced glyph. For UTF-8, this means 0-31, 128-255. For the Jelly Codepage, as all characters can be represented as a single spaced glyph, there are no Non printable characters.

# ported from @primo solution

$_=q($%+=print"00$%0: @{[unpack'(H2)*']}  $_"for"\$_=q($_);eval"=~/.{16}/g);eval
