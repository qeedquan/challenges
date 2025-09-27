/*

Your start-up's BA has told marketing that your website has a large audience in Scandinavia and surrounding countries. Marketing thinks it would be great to welcome visitors to the site in their own language. Luckily you already use an API that detects the user's location, so this is an easy win.

The Task
Think of a way to store the languages as a database. The languages are listed below so you can copy and paste!
Write a 'welcome' function that takes a parameter 'language', with a type String, and returns a greeting - if you have it in your database. It should default to English if the language is not in the database, or in the event of an invalid input.
The Database
Please modify this as appropriate for your language.

[ ("english", "Welcome")
, ("czech", "Vitejte")
, ("danish", "Velkomst")
, ("dutch", "Welkom")
, ("estonian", "Tere tulemast")
, ("finnish", "Tervetuloa")
, ("flemish", "Welgekomen")
, ("french", "Bienvenue")
, ("german", "Willkommen")
, ("irish", "Failte")
, ("italian", "Benvenuto")
, ("latvian", "Gaidits")
, ("lithuanian", "Laukiamas")
, ("polish", "Witamy")
, ("spanish", "Bienvenido")
, ("swedish", "Valkommen")
, ("welsh", "Croeso")
]

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
welcome(const char *language)
{
	static const char *languages[][2] = {
		{ "english", "Welcome" },
		{ "czech", "Vitejte" },
		{ "danish", "Velkomst" },
		{ "dutch", "Welkom" },
		{ "estonian", "Tere tulemast" },
		{ "finnish", "Tervetuloa" },
		{ "flemish", "Welgekomen" },
		{ "french", "Bienvenue" },
		{ "german", "Willkommen" },
		{ "irish", "Failte" },
		{ "italian", "Benvenuto" },
		{ "latvian", "Gaidits" },
		{ "lithuanian", "Laukiamas" },
		{ "polish", "Witamy" },
		{ "spanish", "Bienvenido" },
		{ "swedish", "Valkommen" },
		{ "welsh", "Croeso" },
	};

	size_t i;

	for (i = 0; i < nelem(languages); i++) {
		if (!strcmp(language, languages[i][0]))
			return languages[i][1];
	}
	return languages[0][1];
}

int
main()
{
	puts(welcome("danish"));
	puts(welcome("dutch"));
	puts(welcome(""));
	puts(welcome("polish"));
	return 0;
}
