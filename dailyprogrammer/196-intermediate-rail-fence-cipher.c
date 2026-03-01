/*

Before the days of computerised encryption, cryptography was done manually by hand. This means the methods of encryption were usually much simpler as they had to be done reliably by a person, possibly in wartime scenarios.

One such method was the rail-fence cipher. This involved choosing a number (we'll choose 3) and writing our message as a zig-zag with that height (in this case, 3 lines high.) Let's say our message is REDDITCOMRDAILYPROGRAMMER. We would write our message like this:
R   I   M   I   R   A   R
 E D T O R A L P O R M E
  D   C   D   Y   G   M

See how it goes up and down? Now, to get the ciphertext, instead of reading with the zigzag, just read along the lines instead. The top line has RIMIRAR, the second line has EDTORALPORME and the last line has DCDYGM. Putting those together gives you RIMIRAREDTORALPORMEDCDYGM, which is the ciphertext.
You can also decrypt (it would be pretty useless if you couldn't!). This involves putting the zig-zag shape in beforehand and filling it in along the lines. So, start with the zig-zag shape:

?   ?   ?   ?   ?   ?   ?
 ? ? ? ? ? ? ? ? ? ? ? ?
  ?   ?   ?   ?   ?   ?

The first line has 7 spaces, so take the first 7 characters (RIMIRAR) and fill them in.

R   I   M   I   R   A   R
 ? ? ? ? ? ? ? ? ? ? ? ?
  ?   ?   ?   ?   ?   ?

The next line has 12 spaces, so take 12 more characters (EDTORALPORME) and fill them in.
R   I   M   I   R   A   R
 E D T O R A L P O R M E
  ?   ?   ?   ?   ?   ?

Lastly the final line has 6 spaces so take the remaining 6 characters (DCDYGM) and fill them in.
R   I   M   I   R   A   R
 E D T O R A L P O R M E
  D   C   D   Y   G   M

Then, read along the fence-line (zig-zag) and you're done!

Input Description
You will accept lines in the format:
enc # PLAINTEXT
or
dec # CIPHERTEXT
where enc # encodes PLAINTEXT with a rail-fence cipher using # lines, and dec # decodes CIPHERTEXT using # lines.
For example:
enc 3 REDDITCOMRDAILYPROGRAMMER

Output Description
Encrypt or decrypt depending on the command given. So the example above gives:
RIMIRAREDTORALPORMEDCDYGM

Sample Inputs and Outputs
enc 2 LOLOLOLOLOLOLOLOLO
Result: LLLLLLLLLOOOOOOOOO

enc 4 THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG
Result: TCNMRZHIKWFUPETAYEUBOOJSVHLDGQRXOEO

dec 4 TCNMRZHIKWFUPETAYEUBOOJSVHLDGQRXOEO
Result: THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG

dec 7 3934546187438171450245968893099481332327954266552620198731963475632908289907
Result: 3141592653589793238462643383279502884197169399375105820974944592307816406286 (pi)

dec 6 AAPLGMESAPAMAITHTATLEAEDLOZBEN
Result: ?

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
crypt(int type, int nrails, const char *src, char *dst)
{
	int *rpos, *dpos;
	int pos0, pos1;
	int cycles;
	int rail;
	int len;
	int step;

	len = sprintf(dst, "%s", src);
	cycles = 2 * (nrails - 1);
	pos0 = 0;
	if (type == 'D') {
		rpos = &pos1;
		dpos = &pos0;
	} else if (type == 'E') {
		rpos = &pos0;
		dpos = &pos1;
	} else
		return NULL;

	for (rail = 0; rail < nrails; rail++) {
		step = 2 * rail;
		for (pos1 = rail; pos1 < len; pos1 += step) {
			if (step != cycles) {
				dst[*rpos] = src[*dpos];
				pos0 += 1;
			}
			step = cycles - step;
		}
	}
	return dst;
}

void
test(int type, int nrails, const char *src, const char *res)
{
	char dst[128];

	crypt(type, nrails, src, dst);
	puts(dst);
	assert(!strcmp(dst, res));
}

int
main()
{
	test('E', 3, "REDDITCOMRDAILYPROGRAMMER", "RIMIRAREDTORALPORMEDCDYGM");
	test('E', 2, "LOLOLOLOLOLOLOLOLO", "LLLLLLLLLOOOOOOOOO");
	test('E', 4, "THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG", "TCNMRZHIKWFUPETAYEUBOOJSVHLDGQRXOEO");
	test('D', 4, "TCNMRZHIKWFUPETAYEUBOOJSVHLDGQRXOEO", "THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG");
	test('D', 7, "3934546187438171450245968893099481332327954266552620198731963475632908289907", "3141592653589793238462643383279502884197169399375105820974944592307816406286");
	test('D', 6, "AAPLGMESAPAMAITHTATLEAEDLOZBEN", "ALPHABETAGAMMADELTAEPSILONZETA");

	return 0;
}
