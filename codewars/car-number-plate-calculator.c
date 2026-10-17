/*

## Introduction

Let’s assume that when you register a car you are assigned two numbers:

1. Customer ID – number between `0` and `17558423` inclusively. It is assigned to car buyers in the
   following order: the first customer receives an ID of `0`, the second customer receives an ID
   of `1`, the third - `2`, and so on;

2. A Number Plate – 6-character combination composed of the __series__ - three Latin lowercase
   letters from a to z; and the __serial number__ - three digits from 0 to 9. __
   Example:__ `aaa001, xyz123, tok469`;

Each Number Plate is related to the given Customer ID. For example:

Customer ID of 0: `aaa001`

Customer ID of 21: `aaa022`

Customer ID of 169: `aaa170`

## Your Task

Write a function

```
`findTheNumberPlate`
```

which takes the Customer ID as an argument, calculates the Number Plate corresponding to this ID and
returns it as a string;

## Rules

1. The serial number changes first. For each 3-letter series it goes through 001 to 999, such as:
   `aaa001, aaa002, aaa003, ......, aaa998, aaa999`

2. The leftmost letter in the series switches alphabetically each time after the serial number has
   moved through 001 to 999 inclusively;

   ```
   aaa001...aaa999
   ```

   _at this point the leftmost letter will switch alphabetically, while the serial number repeats
   the same cycle again;_

   ```
   baa001...baa999,
   ...... ,
   zaa001...zaa999
   ```

3. The middle letter switches alphabetically each time after the leftmost letter has moved through a
   to z and the __z**__ series has moved through 001 to 999.

   ```
   zaa001...zaa999
   ```

   _at this point the middle letter will switch alphabetically, while the leftmost letter and
   the serial number repeat the same cycle again;_

   ```
   aba001...aba999,
   bba001...bba999,
   ......,
   zza001...zza999
   ```

4. The rightmost letter switches alphabetically each time after the middle letter has moved through
   a to z and the __zz*__ series has moved through 001 to 999.

   ```
   zza001...zza999
   ```

   _at this point the rightmost letter will switch alphabetically, while the middle letter, the
   leftmost letter, and the serial number repeat the same cycle again;_

   ```
   aab001...aab999,
   bab001...bab999,
   ......,
   zab001...zab999,
   abb001...abb999,
   bbb001...bbb999,
   ......,
   zbb001...zbb999,
   acb001...acb999,
   ......,
   zzz001...zzz999
   ```

## Note

If the serial number has less than 3 digits, the missing places should be adjusted with zeroes.

__i.e:__ `12` should equal `012`; `4` should equal `004`.

Once again, the customer ID starts with 0.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long ulong;

char *
numberplate(ulong id, char *buf)
{
	int c0, c1, c2;
	int val;

	c0 = ((id / 999) % 26) + 'a';
	c1 = ((id / 25974) % 26) + 'a';
	c2 = ((id / 675324) % 26) + 'a';
	val = (id % 999) + 1;
	sprintf(buf, "%c%c%c%03d", c0, c1, c2, val);
	return buf;
}

void
test(ulong id, const char *res)
{
	char buf[128];

	numberplate(id, buf);
	puts(buf);
	assert(!strcmp(buf, res));
}

int
main()
{

	test(3, "aaa004");
	test(1487, "baa489");
	test(40000, "oba041");
	test(43056, "rba100");
	test(234567, "aja802");
	test(17558423, "zzz999");

	return 0;
}
