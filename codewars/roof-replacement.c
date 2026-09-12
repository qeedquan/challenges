/*

The sports centre needs repair. Vandals have been kicking balls so hard into the roof that some of the tiles have started sticking up. The roof is represented by r.

As a quick fix, the committee have decided to place another old roof over the top, if they can find one that fits. This is your job.

A "new" roof (f) will fit if it currently has a hole in it at the location where the old roof has a tile sticking up.

Sticking up tiles are represented by either "\" or "/". Holes in the "new" roof are represented by spaces (" "). Any other character can not go over a sticking up tile.

Return true if the new roof fits, false if it does not.

*/

#include <assert.h>
#include <stdio.h>

bool
rooffix(const char *fix, const char *roof)
{
	size_t i;

	for (i = 0; fix[i] && roof[i]; i++) {
		if ((roof[i] == '\\' || roof[i] == '/') && fix[i] != ' ')
			return false;
	}
	return !fix[i] && !roof[i];
}

int
main()
{
	assert(rooffix("  l   f l k djmi k", "___\\_____//_____/_") == false);
	assert(rooffix("    ikm il  h  llmmc   a i", "__\\_______________________") == true);
	assert(rooffix("   h c ", "__/____") == true);
	assert(rooffix("q h", "_/_") == true);
	assert(rooffix(" cg dg   em  lfh cdam", "_______/____\\_____/_/") == false);

	return 0;
}
