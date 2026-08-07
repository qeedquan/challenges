/*

Description
You're working in the devils language. Looser than PHP, more forgiving than Javascript, and more infuriating than LOLCODE.

You've had it up to here with this language (and you're a tall guy) so you sit down and think of a solution and then all of a sudden it smacks you straight in the face. Figuratively.

Your comparisons are all over the place since you can't really tell what types evaluate to True and what types evaluate to False. It is in this slightly worrying and dehydrated state that you declare you'll output a truth table for that language in the language!

Armed with a paper cup of saltwater and a lovely straw hat, you set about the task! Metaprogramming ain't easy but you're not phased, you're a programmer armed with nimble fingers and a spongy brain. You sit down and start typing, type type type

...Oh did I mention you're on an island? Yeah there's that too...

Formal Inputs & Outputs
Given a programming language, output its corresponding truth table. Only the most basic of types need to be included (If you're in a language that doesn't have any of these types, ignore them).

Int

Float

Char

String

Array

Boolean

Input description
N/A

Output description
A truth table for the language that you're programming in.

e.g.

Expression	Bool
"Hello World!"	True
''	False
'0'	True
1	True
0	False
0.0	False
[]	False
[1,2,3]	True
True	True
False	False
Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

*/

#include <cxxabi.h>
#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>
#include <iomanip>

// ported from @wadehn solution

using namespace std;

template <typename T>
typename enable_if<!is_convertible<T, bool>::value, const char *>::type
to_bool(const T &value)
{
	return "not implicitly convertible to bool";
}

template <typename T>
typename enable_if<is_convertible<T, bool>::value, const char *>::type
to_bool(const T &value)
{
	return static_cast<bool>(value) ? "true" : "false";
}

template <typename T>
void print_truth(const string &expr, const T &value)
{
	int status;
	cout << left << setw(25) << expr
		 << setw(20) << abi::__cxa_demangle(typeid(T).name(), 0, 0, &status)
		 << to_bool(value) << endl;
}

#define PRINT_TRUTH(x) print_truth((#x), (x))

int main()
{
	PRINT_TRUTH("Hello world!");
	PRINT_TRUTH("");
	PRINT_TRUTH(string("Hello world!"));
	PRINT_TRUTH(string(""));
	PRINT_TRUTH('0');
	PRINT_TRUTH(1);
	PRINT_TRUTH(0);
	PRINT_TRUTH(nullptr);
	PRINT_TRUTH(((int[]){ 1, 2, 3 }));
	PRINT_TRUTH(true);
	PRINT_TRUTH(false);

	return 0;
}
