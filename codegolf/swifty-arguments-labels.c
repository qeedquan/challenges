/*

For the purpose of this challenge, arguments are things you pass to a function at the call site, while parameters are what the function uses in its implementation. Or, more succinctly: arguments = external, parameters = internal.

While there are several modern languages that have support for argument labels for functions at the call site, Swift's implementation of argument labels is unique. In essence, the argument label (external) and the parameter name (internal) are not necessarily related to each other. (There's also the fact that argument labels are required to be used at the call site, but that's unimportant for this challenge.)

The Challenge
Write a program or function that receives two strings as input (an argument label, and a parameter name); and outputs (or returns) a single string containing a valid Swift function parameter declaration (sans the type annotation).

Requirements
Here's the official documentation for Swift parameter declarations, if you’re curious. You only have to implement a very small subset of this.

If argumentLabel and parameterName are equal, simply output their shared value.
If argumentLabel and parameterName are not equal, output argumentLabel, followed by a space, followed by parameterName.
If argumentLabel and/or parameterName are empty, replace the empty value(s) with an underscore (_), then follow the rules above.
Here's an example implementation in (what else?) Swift.

func parameterDeclaration(
  label argumentLabel: String,
  name parameterName: String
) -> String {
  switch (argumentLabel, parameterName) {
  case ("", ""):
    "_"
  case ("", _):
    "_ \(parameterName)"
  case (_, ""):
    "\(argumentLabel) _"
  case _ where argumentLabel == parameterName:
    parameterName
  default:
    "\(argumentLabel) \(parameterName)"
  }
}

Rules
All the usual IO methods are allowed.
Standard loopholes are, of course, forbidden.
You may assume that both input strings consist exclusively of ASCII letters (uppercase and lowercase) and digits. (That is, they match this regex: /[a-zA-Z0-9]* /.) You may not assume, however, that the strings will be nonempty.
You may take input as a tuple, a list, two separate arguments, a single string with a separator, or any other method that allows you to receive two separate strings as input.
Please mention your input method in your answer, as well as the order of inputs (argument label before parameter name, or vice versa).
Test Cases
In these test cases, the first item is the argument label, the second is the parameter name, and the third is the expected output.

("do",     "body")   -> "do body"
("a123",   "b456")   -> "a123 b456"
("count",  "count")  -> "count"
("arg1",   "arg1")   -> "arg1"
("",       "number") -> "_ number"
("unused", "")       -> "unused _"
("",       "")       -> "_"
Scoring
This is code-golf, so, as per usual, shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
decl(const char *s, const char *t, char *b)
{
	if (!strcmp(s, "") && !strcmp(t, ""))
		sprintf(b, "_");
	else if (!strcmp(s, ""))
		sprintf(b, "_ %s", t);
	else if (!strcmp(t, ""))
		sprintf(b, "%s _", s);
	else if (!strcmp(s, t))
		sprintf(b, "%s", t);
	else
		sprintf(b, "%s %s", s, t);

	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	decl(s, t, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("do", "body", "do body");
	test("a123", "b456", "a123 b456");
	test("count", "count", "count");
	test("arg1", "arg1", "arg1");
	test("", "number", "_ number");
	test("unused", "", "unused _");
	test("", "", "_");

	return 0;
}
