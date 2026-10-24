/*

The challenge is programming a program that prints following lyrics of Louis Armstrong's What A Wonderful World with as few characters as possible. The key is obviously kind of a 'compression'. I encourage to use and enhance ideas of previous answers, but please declare if you do so!

Rules: No information can be stored externally, everything must be contained in the code itself. Only ASCII characters allwed in the code. The text must be reproduced exactly. Output to console or text file.

I see trees of green, red roses, too,
I see them bloom, for me and you
And I think to myself
What a wonderful world.

I see skies of blue, and clouds of white,
The bright blessed day, the dark sacred night
And I think to myself
What a wonderful world.

The colors of the rainbow, so pretty in the sky,
Are also on the faces of people going by.
I see friends shaking hands, sayin', "How do you do?"
They're really sayin', "I love you."

I hear babies cryin'. I watch them grow.
They'll learn much more than I'll ever know
And I think to myself
What a wonderful world

Yes, I think to myself
What a wonderful world
PS: Why I think this is different to other encoded songs: Longer text; ASCII-only; a lot of repeating text/similar text.

EDIT: FEWEST of course. Ending will be 22th of June!

*/

#include <iostream>

using namespace std;

const auto LYRICS = R"(
I see trees of green, red roses, too,
I see them bloom, for me and you
And I think to myself
What a wonderful world.

I see skies of blue, and clouds of white,
The bright blessed day, the dark sacred night
And I think to myself
What a wonderful world.

The colors of the rainbow, so pretty in the sky,
Are also on the faces of people going by.
I see friends shaking hands, sayin', "How do you do?"
They're really sayin', "I love you."

I hear babies cryin'. I watch them grow.
They'll learn much more than I'll ever know
And I think to myself
What a wonderful world

Yes, I think to myself
What a wonderful world
)";

int main()
{
	cout << LYRICS << endl;
	return 0;
}
