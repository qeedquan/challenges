#!/usr/bin/env python3

r"""

In the context of quines, an intron (or payload) is a part of a quine that serves no purpose in producing output, but is still included in the data section. For example:

function quine() {
    const data = "function quine() {\n    const data=\"@\";\n    // Arr! This be an intron!\n    return data.replace(\"@\", JSON.stringify(data));\n}";
    // Arr! This be an intron!
    return data.replace("@", JSON.stringify(data));
}
My challenge is to write a quine that will normally run as a standard quine, but if an argument is passed in, then it returns a new quine with the argument placed somewhere in it. If that new quine is called with an argument, it should do the same. For example:

function quine(intron="") {
    const data = "function quine(intron=\"\0\") {\n    const data = \"%%%\";\n    //\0\n    return data.replace(/\u0000/g, intron).replace(\"%%%\", JSON.stringify(data));\n}";
    //
    return data.replace(/\u0000/g, intron).replace("%%%", JSON.stringify(data));
}
A few statements:

If you have no input, then the output should be identical to the source code. If you have input, then the output only needs to:
Be in the same language
Contain the input
Be a solution to this challenge in its own right
Quines only need to contain the latest intron. Introns from the program that generated it are optional.
If your program already contains the input, then the same program is fine. For example, if it's called with the same input twice.
The input can be assumed to be printable ASCII only.
The shortest program in bytes wins.

"""

# ported from @user202729 solution
t = ''
s = 't=input()or t;print(f"t={repr(t)};s={repr(s)};exec(s)#{t}")'
exec(s) #
