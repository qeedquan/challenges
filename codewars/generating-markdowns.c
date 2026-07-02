/*

Your friend has recently started using Codewars to learn more advanced coding. They have just created their first kata, and they want to write a proper description for it, using codeblocks, images and hyperlinks.

However, they are struggling to understand how to use Markdown formatting properly, so they decide to ask for your help, by having you write a program that will generate some of the syntaxes for you.

Markdown syntaxes
links: [displayed text](url address)
images: ![replacement message](url address)
codeblocks: we'll use multiline codeblocks like the following

```language
code
```
Task
Your task is to create a function called generate_markdowns or generateMarkdowns. It will take three parameters:

markdown - The type of markdown to return. It can be "link", "img" or "code".
text - The text,message or code to display
url_or_language or urlOrLanguage - gives either the url address to use or the name of the language for the codeblock.

Examples
generate_markdowns('link','Github Codewars','https://github.com/codewars')
# returns: "[Github Codewars](https://github.com/codewars)"

When used in the description: Github Codewars ( https://github.com/codewars )

generate_markdowns('img','this should be a picture','https://github.com/codewars/gna.jpg')
# returns: "![this should be a picture](https://github.com/codewars/gna.jpg)"

When used in the description (no image, sorry... ;o ):

this should be a picture

code = '''\
def generate_markdowns(markdown, text, url_or_language):
    # Your code here!
    pass'''
generate_markdowns('code', code, 'python')
# returns: "```python\ndef generate_markdowns(markdown, text, url_or_language):\n    # Your code here!\n    pass\n```"

When used in the description:

def generate_markdowns(markdown, text, url_or_language):
    # Your code here!
    pass

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
generate_markdown(const char *markdown, const char *text, const char *url_or_language, char *output)
{
	if (!strcmp(markdown, "link"))
		sprintf(output, "[%s](%s)", text, url_or_language);
	else if (!strcmp(markdown, "img"))
		sprintf(output, "![%s](%s)", text, url_or_language);
	else if (!strcmp(markdown, "code"))
		sprintf(output, "```%s\n%s\n```", url_or_language, text);
	else
		return NULL;
	return output;
}

void
test(const char *markdown, const char *text, const char *url_or_language, const char *expected)
{
	char output[128];

	generate_markdown(markdown, text, url_or_language, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("link", "Github Codewars", "https://github.com/codewars", "[Github Codewars](https://github.com/codewars)");
	test("img", "this should be a picture", "https://github.com/codewars/gna.jpg", "![this should be a picture](https://github.com/codewars/gna.jpg)");

	return 0;
}
