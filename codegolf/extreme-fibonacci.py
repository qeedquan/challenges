#!/usr/bin/env python3

"""

There have been a billion iterations of Fibonacci challenges on this website, so lets spice things up with a Fibonacci challenge of a billion iterations!

Your challenge is to output the first 1000 decimal digits of the 1,000,000,000th Fibonacci number with as short a program as possible. This may then optionally be followed by any additional output of your choosing, including but not limited to the rest of the digits.

I am using the convention that fib 0 = 0, fib 1 = 1.

Your program must be fast enough for you to run it and verify its correctness. For this purpose, here are the first 1000 digits:

7952317874554683467829385196197148189255542185234398913453039937343246686182519370050999626136556779332482035723222451226291714456275648259499530612111301255499879639516053459789018700567439946844843034599802419924043753401950114830107234265037841426980398387360784284231996457340782784200767760907777703183185744656536253511502851715963351023990699232595471322670365506482435966586886048627159716916351448788527427435508113909167963907380398242848033980110276370544264285032744364781198451825462130529529633339813483105771370128111851128247136311414208318983802526907917787094802217750859685116363883374847428036737147882079956688807509158372249451437519320162582002000530798309887261257028201907509370554232931107084976854715833585623910450679449120011564762925649144509531904684984417002512086504020779012501356177874199605085558317190905395134468919443313026824813363234190494375599262553025466528838122639433600483849535070647711986769279568548796855207684897741771784375859496425384355879105799

"""

"""

@xnor

The core is the divide-and-conquer identity:

f(2*n)   = 2*f(n)*f(n+1) - f(n)^2
f(2*n+1) = f(n)^2 + f(n+1)^2
This lets us update (a,b) = (f(n),f(n+1)) to double n -> 2*n. Since we want to get n=10**9, this takes only log_2(10**9)=30 iterations. We build n up to 10**9 by repeatedly doing n->2*n+c for each digit c of its binary expansion. When c==1, the doubled value is shifted up 2*n -> 2*n+1 with a one-step Fibonacci shift (a,b)=(b+a,b)

To keep the values a,b manageable, we store only their first 1006 digits by floor-dividing by 10 until they are under 2**3340 ~ 1e1006.

"""

def solve():
    a, b = 0, 1
    for i in bin(10**9):
        a, b = 2*a*b - a*a, a*a + b*b
        if i == '1':
            a, b = b, a + b
        while a>>3340 != 0:
            a, b = a//10, b//10
    return a

def main():
    v = solve()
    r = str(v)[:1000]
    assert(r == "7952317874554683467829385196197148189255542185234398913453039937343246686182519370050999626136556779332482035723222451226291714456275648259499530612111301255499879639516053459789018700567439946844843034599802419924043753401950114830107234265037841426980398387360784284231996457340782784200767760907777703183185744656536253511502851715963351023990699232595471322670365506482435966586886048627159716916351448788527427435508113909167963907380398242848033980110276370544264285032744364781198451825462130529529633339813483105771370128111851128247136311414208318983802526907917787094802217750859685116363883374847428036737147882079956688807509158372249451437519320162582002000530798309887261257028201907509370554232931107084976854715833585623910450679449120011564762925649144509531904684984417002512086504020779012501356177874199605085558317190905395134468919443313026824813363234190494375599262553025466528838122639433600483849535070647711986769279568548796855207684897741771784375859496425384355879105799")

main()