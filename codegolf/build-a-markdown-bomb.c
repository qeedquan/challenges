/*

I'm sure most of us have heard of zip bombs and similar decompression bomb tricks, where a maliciously crafted input creates a massively disproportionate output. We even had a question on here to do that to a compiler at one point.

Well, it occurs to me that Markdown is a compression format of sorts, replacing bulky HTML tags with "compressed" MD tokens. Therefore, might it be possible to build a compression bomb in Markdown?

Challenge rules:
The submission should be a piece of markdown text, between 50 and 256 characters in length. (Imposing a minimum to head off some smart-aleck posting a 3-character response or similar.)

The submission will be processed by StackExchange's Markdown processor as implemented in this site.

Your score will be the ratio of character count in the resulting HTML to the character count of your Markdown text.

Highest score wins.

*/

#include <stdio.h>

/*

@Namaskar

Markdown sure handles nested block-quotes oddly. Each > character gets turned into <blockquote></blockquote> so a solid 1 to 25 ratio.
But wait! When rendering the HTML it also adds two spaces per nesting! Having this try to render causes my browser some grief, and I will keep it in the code-cage for now. Feel free to unlock it yourself!

Input: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>!

Output HTML:

...
  <blockquote>
    <blockquote class="spoiler">
      <p></p>
    </blockquote>
  </blockquote>

*/

const char *
bomb(void)
{
	return ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>!";
}

int
main()
{
	puts(bomb());
	return 0;
}
