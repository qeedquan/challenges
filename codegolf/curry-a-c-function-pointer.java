/*

Objective
Given a type signature of a C function pointer represented as a string, output the (fully) curried version of it, also as a string.

I/O format
It is assumed that:

There is at least one parameter.
The return type and the parameter types are titlecased alphabetic identifiers. (That is, those matching the regex [A-Z][a-z]*)
The input and the output have no whitespaces.
Otherwise flexible.

Examples
Input -> Output

Foo(*)(Foo) -> Foo(*)(Foo)
Foo(*)(Bar) -> Foo(*)(Bar)
Bar(*)(Foo,Bar) -> Bar(*(*)(Foo))(Bar)
Bar(*)(Foo,Bar,Baz) -> Bar(*(*(*)(Foo))(Bar))(Baz)

*/

class Curry {
	public static void main(String[] args) {
		assert(curry("Foo(*)(Foo)").equals("Foo(*)(Foo)"));
		assert(curry("Foo(*)(Bar)").equals("Foo(*)(Bar)"));
		assert(curry("Bar(*)(Foo,Bar)").equals("Bar(*(*)(Foo))(Bar)"));
		assert(curry("Bar(*)(Foo,Bar,Baz)").equals("Bar(*(*(*)(Foo))(Bar))(Baz)"));
	}

	public static String curry(String string) {
		var string0 = string.split(",");
		var string1 = "(*".repeat(string0.length);
		var string2 = string.replace("(*", string1);
		var string3 = string2.replace(",", "))(");
		return string3;
	}
}
