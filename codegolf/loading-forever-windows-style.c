/*

Make a Windows style Loading bar by the following instructions.

(notice that this is different than Loading... Forever)

Your output should start by [....      ].

Every tick, you should wait 100 ms, then move each dots by one character right. if the dot is on the tenth character, move it to the first. Notice that you should clear the screen before outputting again. The output is ordered as the following:

[....      ]
[ ....     ]
[  ....    ]
[   ....   ]
[    ....  ]
[     .... ]
[      ....]
[.      ...]
[..      ..]
[...      .]
..Then it loops forever.

Rules
This is code-golf, so the shortest answer wins I doubt I would even accept a winning answer tho
Please provide a gif file of the loading bar in action if possible.

*/

#include <stdio.h>
#include <time.h>
#include <threads.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
clear(void)
{
	printf("\033c");
}

void
loading(void)
{
	static const char *tab[] = {
	    "[....      ]",
	    "[ ....     ]",
	    "[  ....    ]",
	    "[   ....   ]",
	    "[    ....  ]",
	    "[     .... ]",
	    "[      ....]",
	    "[.      ...]",
	    "[..      ..]",
	    "[...      .]",
	};

	static const struct timespec delay = {
	    .tv_nsec = 100'000'000,
	};

	size_t i;

	i = 0;
	for (;;) {
		clear();
		printf("%s\n", tab[i]);
		i = (i + 1) % nelem(tab);
		thrd_sleep(&delay, NULL);
	}
}

int
main(void)
{
	loading();
	return 0;
}
