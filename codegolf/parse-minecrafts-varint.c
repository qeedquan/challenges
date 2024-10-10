/*

If you look at the reverse-engineered Minecraft Java Edition server protocol, there is an interesting integer encoding method that is used quite often called VarInt.

It works like this:
You have an array of bytes. 7 bits of each byte is used to encode part of the integer,
with the most significant bit determining whether to continue to the next byte. The
longest a VarInt can be is 5 bytes long, though for the last byte, only the 3 least-significant bits are used. All these are used together to construct a 32-bit integer. Each VarInt is encoding using little-endian. If you need more of an explanation, a good one can be found on the reverse-engineering minecraft wiki

Examples:
0x81, 0x00: 1
0xFF, 0xFF, 0x7F: 2,097,151
0x80, 0x80, 0x80, 0x80, 0x08: -2,147,483,648
0xFF, 0xFE, 0x43, 0xFF, 0x32: 1113983

Method:
Here is an ungolfed method of doing this in JavaScript:

function parseVarInt(varInt) {
  let result = 0;
  let shift = 0;
  for(let byte of varInt) { // loop over every byte
    result |= (byte & 0x7F) << shift; // add the current 7 bits onto the pre-existing result
    shift += 7;
    if(!(byte & 0x80)) { // if the continue bit isn't enabled, break.
      break;
    }
  }
  return result;
}
Rules & Info:
This is a codegolfing challenge! Least amount of bytes win.
Return value can be in any format, but it must be some form of number
Functions count as a program. If you have a function with an input and a return value, that is as good as having a program which outputs directly to console
Bonus points* if you can also convert an integer to a VarInt!
Standard loopholes are not allowed.
The input can be any form of array of bits or bytes.
Though it does have it on the wiki, you do not need to have error parsing. Assume that all VarInts are a max of 5 bytes long.
* For cool factor only

*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int32_t
varint(uint8_t *b, size_t n)
{
	int32_t r;
	uint32_t s;
	size_t i;

	r = s = 0;
	for (i = 0; i < n; i++) {
		r |= (b[i] & 0x7f) << s;
		s += 7;
		if (!(b[i] & 0x80))
			break;
	}
	return r;
}

int
main()
{
	uint8_t b1[] = {0x81, 0x00};
	uint8_t b2[] = {0xFF, 0xFF, 0x7F};
	uint8_t b3[] = {0x80, 0x80, 0x80, 0x80, 0x08};
	uint8_t b4[] = {0xFF, 0xFE, 0x43, 0xFF, 0x32};

	assert(varint(b1, nelem(b1)) == 1);
	assert(varint(b2, nelem(b2)) == 2097151);
	assert(varint(b3, nelem(b3)) == -2147483648);
	assert(varint(b4, nelem(b4)) == 1113983);

	return 0;
}
