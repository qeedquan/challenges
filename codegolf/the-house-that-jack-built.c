/*

So, there's a famous children's rhyme...

This is the house that Jack built.

This is the malt
That lay in the house that Jack built.

This is the rat
That ate the malt
That lay in the house that Jack built.

This is the cat
That killed the rat
That ate the malt
That lay in the house that Jack built.

This is the dog
That worried the cat
That killed the rat
That ate the malt
That lay in the house that Jack built.

This is the cow with the crumpled horn
That tossed the dog
That worried the cat
That killed the rat
That ate the malt
That lay in the house that Jack built.

This is the maiden all forlorn
That milked the cow with the crumpled horn
That tossed the dog that worried the cat
That killed the rat that ate the malt
That lay in the house that Jack built.

This is the man all tattered and torn
That kissed the maiden all forlorn
That milked the cow with the crumpled horn
That tossed the dog that worried the cat
That killed the rat that ate the malt
That lay in the house that Jack built.

This is the judge all shaven and shorn
That married the man all tattered and torn
That kissed the maiden all forlorn
That milked the cow with the crumpled horn
That tossed the dog
That worried the cat
That killed the rat
That ate the malt
That lay in the house that Jack built.

This is the rooster that crowed in the morn
That woke the judge all shaven and shorn
That married the man all tattered and torn
That kissed the maiden all forlorn
That milked the cow with the crumpled horn
That tossed the dog
That worried the cat
That killed the rat
That ate the malt
That lay in the house that Jack built.

This is the farmer sowing his corn
That kept the rooster that crowed in the morn
That woke the judge all shaven and shorn
That married the man all tattered and torn
That kissed the maiden all forlorn
That milked the cow with the crumpled horn
That tossed the dog
That worried the cat
That killed the rat
That ate the malt
That lay in the house that Jack built.

This is the horse and the hound and the horn
That belonged to the farmer sowing his corn
That kept the rooster that crowed in the morn
That woke the judge all shaven and shorn
That married the man all tattered and torn
That kissed the maiden all forlorn
That milked the cow with the crumpled horn
That tossed the dog
That worried the cat
That killed the rat
That ate the malt
That lay in the house that Jack built.
Obviously, it's pretty process-based, you could totally write code for this, right?

Write some code which outputs the full text of "The house that Jack built".
Standard rules and loopholes and stuff.
Any language you like.
Try to do it in the smallest number of bytes.
I always like to see TIO links.
The case must match the rhyme.
Each line of the rhyme must be on a new line of text.
White-space before and after the line is fine.
No punctuation, except the full stop at the end of each verse.
Edit:

Earlier versions of this question contained an issue with this line

This is the rooster that crowed the morn

It was inconsistently applied.

To be clear; this should be one line on every occurrence, and should be added at once.

Further edit:

It's been declared that this question is a duplicate of:

We're no strangers to code golf, you know the rules, and so do I

However, while you could take the same approach, compressing the text as much as possible. There's also a chance to take a procedural approach to this rhyme, following the structure of the rhyme itself. Some of the solutions take this approach, so I'd say it is a similar, but distinct challenge for this reason.

This answer suggests that it's actually better to take the approach to this question which would not work for Rick Astley.

It is, however, a duplicate of the old lady song, and the 12 days of Christmas. I've voted to close it. (although, those two were not declared duplicate of each other).

*/

#include <stdio.h>

void
rhyme(void)
{
	puts("This is the house that Jack built.");
	puts("");
	puts("This is the malt");
	puts("That lay in the house that Jack built.");
	puts("");
	puts("This is the rat");
	puts("That ate the malt");
	puts("That lay in the house that Jack built.");
	puts("");
	puts("This is the cat");
	puts("That killed the rat");
	puts("That ate the malt");
	puts("That lay in the house that Jack built.");
	puts("");
	puts("This is the dog");
	puts("That worried the cat");
	puts("That killed the rat");
	puts("That ate the malt");
	puts("That lay in the house that Jack built.");
	puts("");
	puts("This is the cow with the crumpled horn");
	puts("That tossed the dog");
	puts("That worried the cat");
	puts("That killed the rat");
	puts("That ate the malt");
	puts("That lay in the house that Jack built.");
	puts("");
	puts("This is the maiden all forlorn");
	puts("That milked the cow with the crumpled horn");
	puts("That tossed the dog that worried the cat");
	puts("That killed the rat that ate the malt");
	puts("That lay in the house that Jack built.");
	puts("");
	puts("This is the man all tattered and torn");
	puts("That kissed the maiden all forlorn");
	puts("That milked the cow with the crumpled horn");
	puts("That tossed the dog that worried the cat");
	puts("That killed the rat that ate the malt");
	puts("That lay in the house that Jack built.");
	puts("");
	puts("This is the judge all shaven and shorn");
	puts("That married the man all tattered and torn");
	puts("That kissed the maiden all forlorn");
	puts("That milked the cow with the crumpled horn");
	puts("That tossed the dog");
	puts("That worried the cat");
	puts("That killed the rat");
	puts("That ate the malt");
	puts("That lay in the house that Jack built.");
	puts("");
	puts("This is the rooster that crowed in the morn");
	puts("That woke the judge all shaven and shorn");
	puts("That married the man all tattered and torn");
	puts("That kissed the maiden all forlorn");
	puts("That milked the cow with the crumpled horn");
	puts("That tossed the dog");
	puts("That worried the cat");
	puts("That killed the rat");
	puts("That ate the malt");
	puts("That lay in the house that Jack built.");
	puts("");
	puts("This is the farmer sowing his corn");
	puts("That kept the rooster that crowed in the morn");
	puts("That woke the judge all shaven and shorn");
	puts("That married the man all tattered and torn");
	puts("That kissed the maiden all forlorn");
	puts("That milked the cow with the crumpled horn");
	puts("That tossed the dog");
	puts("That worried the cat");
	puts("That killed the rat");
	puts("That ate the malt");
	puts("That lay in the house that Jack built.");
	puts("");
	puts("This is the horse and the hound and the horn");
	puts("That belonged to the farmer sowing his corn");
	puts("That kept the rooster that crowed in the morn");
	puts("That woke the judge all shaven and shorn");
	puts("That married the man all tattered and torn");
	puts("That kissed the maiden all forlorn");
	puts("That milked the cow with the crumpled horn");
	puts("That tossed the dog");
	puts("That worried the cat");
	puts("That killed the rat");
	puts("That ate the malt");
	puts("That lay in the house that Jack built.");
}

int
main(void)
{
	rhyme();
	return 0;
}
