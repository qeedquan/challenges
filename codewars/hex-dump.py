#!/usr/bin/env python3

"""

In computing, a hex dump is a hexadecimal view (on screen or paper) of computer data, from RAM or from a file or storage device.
Looking at a hex dump of data is commonly done as a part of debugging, or of reverse engineering.

In a hex dump, each byte (8-bits) is represented as a two-digit hexadecimal number.
Hex dumps are commonly organized into rows of 8 or 16 bytes, sometimes separated by whitespaces.
Some hex dumps have the hexadecimal memory address at the beginning and/or a checksum byte at the end of each line.

(source: https://en.wikipedia.org/wiki/Hex_dump)

Your Task
Your task is to complete the functions hexdump and dehex:

hexdump takes a binary input (a bytes object) and returns a hex dump (as a string) in the following format:

the memory address displayed as an 8-digit hexadecimal number (starting from 00000000), followed by a colon (:) and a space,
16 bytes displayed as 2-digit hexadecimal numbers, separated by a space,
two spaces,
the ASCII translation of the bytes if the ASCII values are between 32 and 126 (both included), otherwise a full stop (.)

Note: all hexadecimal values (data and addresses) should be presented in lowercase

If the last line is shorter than 16 bytes, then replace the byte values with spaces, but trim the trailing spaces from the end of the line. In other words, pad it so that the ASCII block is aligned, as in the below example:

00000000: 1d c4 15 25 91 e6 09 59 04 99 15 29 0a 45 21 29  ...%...Y...).E!)
00000010: 26 8e 74 a0 1a be 75 68 06 dd 70 33 a4 77 7a 5d  &.t...uh..p3.wz]
00000020: b1 ba 22 a7 cf cc f7 ef b1 e3 13 ed f1 89 ad ad  ..".............
00000030: b8 2a 52 32 65 79 43 99 6f c8 d3 8e b2 5f 50 c9  .*R2eyC.o...._P.
00000040: 08 4a 12 25 79 c2 dd 31 6b b8 77 74 4b 68 4b d4  .J.%y..1k.wtKhK.
00000050: db 4e 92 09 d5 4c 9f 0b fd a9 d1                 .N...L.....

dehex takes a string input, in the same format as the output described above, and returns binary output.

Note: all inputs will be valid, so validating it is not necessary.

My other katas
If you enjoyed this kata then please try my other katas! :-)

Translations are welcome!
(except for ruby)

"""

def hexdump(data):
    lines = []
    for i in range(0, len(data), 16):
        block = data[i:i+16]
        addr = f"{i:08x}"
        hexes = ' '.join(f"{b:02x}" for b in block)
        pad = ' ' * (47 - len(hexes))
        ascii_part = ''.join(chr(b) if 32 <= b <= 126 else '.' for b in block)
        lines.append(f"{addr}: {hexes}{pad}  {ascii_part}")
    return '\n'.join(lines)

def dehex(text):
    out = bytearray()
    for line in text.splitlines():
        if not line:
            continue
        hex_region = line[10:57]
        for t in hex_region.split():
            out.append(int(t, 16))
    return bytes(out)

def main():
    print(hexdump(list(range(256))))

main()

