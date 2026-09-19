#!/usr/bin/env python3

"""

Challenge
The cops created code challenges which result in certain wildly incorrect answers despite correct math. Choose an uncracked, not safe formula from the cop thread.

Your task is to find an incorrect answer and describe its underlying cause. The challenge author has the responsibility to confirm whether the explanation is valid, but the incorrect answer does not have to be the same one the challenge creator had in mind.

Scoring, Rules, and Notes
Score 1 point for each successfully cracked answer.
If the error is caused by a particular usage of an external library (or specific version of it), it is sufficient to simply state that there is a known bug with a particular usage of the library used by the cop challenge. Link to a relevant bug report or article.
This is to avoid having to pour through potentially millions of lines of source code in libraries (which may be closed source anyway) to find the exact cause of the error.

Example
Cop Challenge
Formula: The Pythagorean Theorem, a2+b2=c2
Inputs: 2 nonnegative real numbers
Off by more than either input number
Affects most inputs
WSL (Ubuntu 18.04) on Windows 10, Python 3.6.9

def badpythag(a, b):
    a2 = (a / 1e200) ** 2
    b2 = (b / 1e200) ** 2
    return math.sqrt(a2 + b2) * 1e200

Cracked Answer
This will fail on many inputs (e.g. 3, 4 => 0, but should be 5) due to floating point underflow and return 0. The answer is correct with very large inputs e.g. 3e150 and 4e150, however.

"""

from sympy.ntheory.primetest import mr
from sympy.ntheory.generate import primerange

"""

@water_ghosts

n is strongly pseudoprime for all prime bases below 1,000, which means the Miller-Rabin test will give a false positive for any bases in the (2, 800) range. As soon as you use a prime base above 1,000, the Miller-Rabin test correctly identifies it as composite.

I did not calculate this number myself. I took it from this answer from Joe53 on Mathematics Stack Exchange, which in turn was calculated using the technique in this paper.
https://math.stackexchange.com/questions/281107/constructing-arbitrary-sized-miller-rabin-primality-test-case-numbers/465314#465314
https://www.ams.org/journals/mcom/2005-74-250/S0025-5718-04-01693-X/S0025-5718-04-01693-X.pdf

"""
def badisprime(n):
    if n < 2:
        return False
    return mr(n, primerange(2, 800))

def badisprime2(n):
    if n < 2:
        return False
    return mr(n, [1009])

def main():
    N = 2809386136371438866496346539320857607283794588353401165473007394921174159995576890097633348301878401799853448496604965862616291048652062065394646956750323263193037964463262192320342740843556773326129475220032687577421757298519461662249735906372935033549531355723541168448473213797808686850657266188854910604399375221284468243956369013816289853351613404802033369894673267294395882499368769744558478456847832293372532910707925159549055961870528474205973317584333504757691137280936247019772992086410290579840045352494329434008415453636962234340836064927449224611783307531275541463776950841504387756099277118377038405235871794332425052938384904092351280663156507379159650872073401637805282499411435158581593146712826943388219341340599170371727498381901415081480224172469034841153893464174362543356514320522139692755430021327765409775374978255770027259819794532960997484676733140078317807018465818200888425898964847614568913543667470861729894161917981606153150551439410460813448153180857197888310572079656577579695814664713878369660173739371415918888444922272634772987239224582905405240454751027613993535619787590841842251056960329294514093407010964283471430374834873427180817297408975879673867

    assert(badisprime(N) == True)
    assert(badisprime2(N) == False)

main()
