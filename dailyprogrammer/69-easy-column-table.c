/*

Write a program that takes a title and a list as input and outputs the list in a nice column. Try to make it so the title is centered. For example:

title: 'Necessities'
input: ['fairy', 'cakes', 'happy', 'fish', 'disgustipated', 'melon-balls']

output:

    +---------------+
    |  Necessities  |
    +---------------+
    | fairy         |
    | cakes         |
    | happy         |
    | fish          |
    | disgustipated |
    | melon-balls   |
    +---------------+
Bonus: amend the program so that it can output a two-dimensional table instead of a list. For example, a list of websites:

titles: ['Name', 'Address', 'Description']
input:  [['Reddit', 'www.reddit.com', 'the frontpage of the internet'],
        ['Wikipedia', 'en.wikipedia.net', 'The Free Encyclopedia'],
        ['xkcd', 'xkcd.com', 'Sudo make me a sandwich.']]

output:

    +-----------+------------------+-------------------------------+
    |   Name    |     Address      |          Description          |
    +-----------+------------------+-------------------------------+
    | Reddit    | www.reddit.com   | the frontpage of the internet |
    +-----------+------------------+-------------------------------+
    | Wikipedia | en.wikipedia.net | The Free Encyclopedia         |
    +-----------+------------------+-------------------------------+
    | xkcd      | xkcd.com         | Sudo make me a sandwich       |
    +-----------+------------------+-------------------------------+
Thanks to Medicalizawhat for suggesting this problem at r/dailyprogrammer_ideas (a version of this problem was originally posted here). If you have a problem you think would be good for us, head over there and post it!

*/

#include <stdio.h>
#include <string.h>

int
max(int a, int b)
{
	return (a > b) ? a : b;
}

void
print_seperator(int width)
{
	int i;

	printf("+");
	for (i = 0; i <= width + 1; i++)
		printf("-");
	printf("+\n");
}

void
print_title(int width, const char *title)
{
	int space;

	space = (width - strlen(title)) / 2;
	if ((width - strlen(title) + 1) % 2 == 1)
		printf("| %*s%s%*s |\n", space, "", title, space, "");
	else
		printf("| %*s%s%*s |\n", space, "", title, space + 1, "");
}

void
print_item(int width, const char *item)
{
	printf("| %-*s |\n", width, item);
}

int
main(int argc, char **argv)
{
	int i, width;

	if (argc < 3) {
		printf("usage: title item1 item2 ... itemN\n");
		return 2;
	}

	width = 0;
	for (i = 1; i < argc; i++)
		width = max(width, strlen(argv[i]));

	print_seperator(width);
	print_title(width, argv[1]);
	print_seperator(width);
	for (i = 2; i < argc; i++)
		print_item(width, argv[i]);
	print_seperator(width);
	return 0;
}
