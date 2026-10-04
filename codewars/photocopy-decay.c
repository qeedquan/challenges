/*

Background
Every time you photocopy something the quality of the copy is never quite as good as the original.

But then you make a copy of copy, and then a copy of that copy, et cetera... And the results get worse each time.

This kind of degradation is called Generation Loss.

Here is a fun example of generation loss copying VHS tapes.

Kata task
In this Kata you will be given 2 sheets of paper.

The first one is the original, and the second one is the result of copying many times. Let's call these papers orig and copy.

Only a small % of generation loss happens at each copy, but the effect is cummulative and the copies quickly become more like gibberish.

Your task is to return true/false if orig is a possible ancestor of copy.

Notes
The orig document may include any kind of character
Copied characters will degrade as follows: A-Z ⇒ a-z ⇒ # ⇒ + ⇒ : ⇒ . ⇒
Any other character not mentioned above (e.g. digits) do not degrade
For the uppercase to lowercase degradation the letters must be the same (i.e. A ⇒ a ... Z ⇒ z)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool
generation_loss(const char *orig, const char *copy)
{
	static const char order[] = "#+:. ";

	int c0, c1;
	char *p0, *p1;

	while (*orig && *copy) {
		c0 = *orig++;
		c1 = *copy++;
		if (c0 == c1 || tolower(c0) == c1)
			continue;

		p0 = strchr(order, c0);
		p1 = strchr(order, c1);
		if (!isalpha(c0) && !p0)
			return false;
		if ((isalpha(c1) && isupper(c1)) || !p1)
			return false;
		if (p0 > p1)
			return false;
	}
	return !*orig && !*copy;
}

void
test_true(const char *orig, const char *copy)
{
	assert(generation_loss(orig, copy) == true);
}

void
test_false(const char *orig, const char *copy)
{
	assert(generation_loss(orig, copy) == false);
}

int
main()
{
	const char *orig =
	    "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG.\n"
	    "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG.\n"
	    "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG.\n"
	    "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG.\n"
	    "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG.\n"
	    "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG.\n"
	    "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG.\n"
	    "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG.\n"
	    "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG.\n"
	    "THE QUICK BROWN FOX JUMPS OVER A LAZY DOG.\n";

	const char *gen10 =
	    "THE QUIcK BRoWN Fo# JUmPs OV#r A LAZY DOG \n"
	    "THE QUIcK #ROwN FOX JUmpS O#eR + ##ZY DOG.\n"
	    "THe +uIcK BroWN #Ox jUmPs OVER a LAZ# Dog \n"
	    "thE qUiCk BR#WN FOX #UMPS OVe# A La#Y dog.\n"
	    "TH# QUICK brOWn FOX JUMpS OVEr A LaZY dog \n"
	    "tHe QuICk BR#WN FOX J#M#+ o##r a lAZY DOg \n"
	    "THe QUiCK bRowN FOX JuMp# OvER A laZY Dog.\n"
	    "THE QUicK B#OWN FOx JuMPS OVER A LAZy DoG.\n"
	    "ThE qUIC# bROwN FO# JUMPS OVEr A LAzY dOG \n"
	    "T#E QuICK bROwN fOX JUmP# oVER A lazy #o#.\n";

	const char *gen20 =
	    "tHe qUicK BRoW+ F## #umPs OV#r A lAzY dOG \n"
	    "THE qu#cK +R#wN fOX jU#ps O#e# + ##zY DOG.\n"
	    "THe +uic# broW# #Ox jUm#s oVER a LA+# Dog \n"
	    "t+# qU#Ck bR#WN FO# #uMpS OVe# A ###Y #og.\n"
	    "tH# Qu#C# bro+: FOX jumpS Over A lazY d## \n"
	    "#He #uiC+ BR##N fOX J+M#+ #+#r # #aZY DO: \n"
	    "tHe Qu+CK bRowN fOx #uM## ##eR a lazY D#+ \n"
	    "tHe QUi+k B#oWN FOx J#mPs O##R A lAz# doG.\n"
	    "T#E quIC# bRO#n fO# JUMP+ oVer a lA#Y doG \n"
	    "T#e Q#i#K bR+wN #OX JumP# #Ver A laz# #++.\n";

	const char *gen50 =
	    "#:e #u:cK #R##: F.: :+mP+ o#++ a #azy #o+ \n"
	    "T:e :u##k  .#w+ +ox +#+:. +:+# : ++:y d:G \n"
	    "T+: .+i+: b#++  .ox #U#+# +### # LA.+ #++ \n"
	    ":+. #u+C+ #r#Wn f++ #uM#s o+e. A :++y :## \n"
	    "#:. q##+# #++:  +++ #+#p# ov#+ a :a:# ++# \n"
	    ":h# ++#c. b#++n +oX + :.. #+#+ + #+#y do  \n"
	    "t#e Q++.k bro## ### +:+#. +:#+ . :### d+: \n"
	    "#H# q##.# B:#++ F## j++P# o+:# # .#z: #+g.\n"
	    "t#e :u+c# +:o+n fo+ +umP: ::#r + #++# +og \n"
	    "T.: q#::+ ++::n +o# jum#+ +V#. # ++## :+  \n";

	const char *gen75 =
	    ":.+ ++.+K #R+:  f :  +.p  +#:. + #++y ++  \n"
	    "t.+ .u +    +#+ :++ .+  . + +# . ++.: #.: \n"
	    "T.. .+#:: ++.+   #x #U+++ +:+. : La + ++: \n"
	    "  . +:.#: +r#++ #:+ +#m+# #:e. +  .:+ :#+ \n"
	    ".   q++:# +++   +.: :.+#: :#++ # :a:+ ..+ \n"
	    ":#+ ::+#  +#+ # ::X + .   #:+. + ::++ d:  \n"
	    "#.e #+  # ##+:: #++ :.:   .::+ .  :#+ # : \n"
	    "#H. #.+ : B.:++ F.: j++p# +:.+ +  :z. :.# \n"
	    "++e  u.:+ :.::+ #o+ .+#p: :.:+   #.:: ::+ \n"
	    "+   q:. :  :  n :++ ju##  .v#  + :+##  +  \n";

	const char *gen99 =
	    "..:  + +K .r+:  f      +  :+.  . +:+# ::  \n"
	    "# :  #      ::+ .++ ..  . + .+   :: . +   \n"
	    "#.   .#    . +   :: .U.:: +:+    ## + ::: \n"
	    "    :. :. :#: : # + +#+.# +.e.      . .#: \n"
	    "    q::.# +++   +    ...   #++ # :a:    + \n"
	    "::. :::.  .++ # : X       +... + :.:  d   \n"
	    "+.+ ::  + +:... ::+ . :     :+ .  :#: : : \n"
	    ".h  # : : b ::: f . j+.p# ::.:    .z  . # \n"
	    "..e  u    . ::+ +++ .::#.    :   :  :   : \n"
	    "    q.. .  :  + .+: ju:#   v#  + .:.+  :  \n";

	test_true(orig, gen10);
	test_true(orig, gen20);
	test_true(orig, gen50);
	test_true(orig, gen75);
	test_true(orig, gen99);

	test_true(gen10, gen20);
	test_true(gen10, gen50);
	test_true(gen10, gen75);
	test_true(gen10, gen99);

	test_true(gen20, gen50);
	test_true(gen20, gen75);
	test_true(gen20, gen99);

	test_true(gen50, gen75);
	test_true(gen50, gen99);

	test_true(gen75, gen99);

	test_false(gen99, gen75);
	test_false(gen99, gen50);
	test_false(gen99, gen20);
	test_false(gen99, gen10);
	test_false(gen99, orig);

	test_false(gen75, gen50);
	test_false(gen75, gen20);
	test_false(gen75, gen10);
	test_false(gen75, orig);

	test_false(gen50, gen20);
	test_false(gen50, gen10);
	test_false(gen50, orig);

	test_false(gen20, gen10);
	test_false(gen20, orig);

	test_false(gen10, orig);

	return 0;
}
