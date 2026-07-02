/*

Modify the kebabize function so that it converts a camel case string into a kebab case.

"camelsHaveThreeHumps"  -->  "camels-have-three-humps"
"camelsHave3Humps"  -->  "camels-have-humps"
"CAMEL"  -->  "c-a-m-e-l"
Notes:

the returned string should only contain lowercase letters

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
kebabize(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (!isalpha(s[i]))
			continue;

		if (isupper(s[i]) && i > 0)
			b[j++] = '-';

		b[j++] = tolower(s[i]);
	}
	b[j] = '\0';
}

void
test(const char *s, const char *r)
{
	char b[128];

	kebabize(s, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("camelsHaveThreeHumps", "camels-have-three-humps");
	test("camelsHave3Humps", "camels-have-humps");
	test("CAMEL", "c-a-m-e-l");
	test("MyCamelCasedString", "my-camel-cased-string");
	test("myCamelCasedString", "my-camel-cased-string");
	test("MyCamelHas3Humps", "my-camel-has-humps");
	test("myCamelHas3Humps", "my-camel-has-humps");
	test("SOS", "s-o-s");
	test("42", "");
	test("CodeWars", "code-wars");
	test("AbstractSingletonProxyFactoryBean", "abstract-singleton-proxy-factory-bean");
	test("abstractSingletonProxyFactoryBean", "abstract-singleton-proxy-factory-bean");

	return 0;
}
