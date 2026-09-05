#!/usr/bin/env python3

import re

"""

Ported from @Mukundan314 solution

The idea is replacing the M+/M-/MR with native +/-/= operations and evaluating it

"""

def casiom(s):
    s = re.sub("(.*?)(M[-+R])", r"\2=\1;", s)
    s = re.sub("R=", "*=0M", s)
    s = re.sub("(\d|M)M", "\\1*M", s)
    s = re.sub("M(?=\d|M)", "M*", s)
    s = "M=0;" + s
    try:
        r = exec(s)
    except:
        return None
    return eval("M")

def main():
    assert(casiom("9M+9M+") == 18)
    assert(casiom("9MR9M+") == 9)
    assert(casiom("81M+81M+56M-35M-12M+") == 83)
    assert(casiom("9M-9M-9M+") == -9)
    assert(casiom("9M+MMM+") == 90)
    assert(casiom("81M+81M+56M-35M-12M+") == 83)
    assert(casiom("9M+MRM+") == None)
    assert(casiom("9M+M+") == None)
    assert(casiom("9") == 0)
    assert(casiom("9M+MM") == 9)
    assert(casiom("9M+MM") == 9)
    assert(casiom("2M+2M2MM+") == 18)

main()
