/*

Challenge
Write a function that implements C printf-style string formatting.

Rules
You must implement at least %%, %c, %s, %d and %f.
You must not use a built-in string formatting method.
You must not run external programs or connect to the Internet from your program.
It's up to you to decide how to handle invalid input, but your program must not terminate abnormally.
You should write a variadic function if possible.
The key words "MUST", "MUST NOT", "REQUIRED", "SHALL", "SHALL NOT", "SHOULD", "SHOULD NOT", "RECOMMENDED", "MAY", and "OPTIONAL" in this document are to be interpreted as described in RFC 2119.

*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdarg>

using namespace std;

int xprintf(const char *fmt, ...)
{
	va_list ap;
	string str;
	int len;
	int ival;
	const char *sval;
	char cval;
	double dval;

	va_start(ap, fmt);
	for (len = 0; *fmt;)
	{
		switch (*fmt)
		{
		case '%':
			fmt++;
			switch (*fmt)
			{
			case '%':
			default:
				cout << *fmt;
				len++;
				break;

			case 'c':
				cval = va_arg(ap, int);
				cout << cval;
				len++;
				break;

			case 'd':
				ival = va_arg(ap, int);
				str = to_string(ival);
				cout << str;
				len += str.size();
				break;

			case 'f':
				dval = va_arg(ap, double);
				str = to_string(dval);
				cout << str;
				len += str.size();
				break;

			case 's':
				sval = va_arg(ap, const char *);
				cout << sval;
				len += strlen(sval);
				break;
			}
			fmt++;
			break;

		default:
			cout << *fmt++;
			len++;
			break;
		}
	}
	va_end(ap);

	return len;
}

int main()
{
	xprintf("Hello, World! %% %d %f %c %s\n", 23, 2.45, 'a', "ZDDQ@");

	return 0;
}
