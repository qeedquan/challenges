'
' Write a program which PRINTS ITSELF, i.e. its own source code!
'
' Do this in BASIC - since we, regretfully, can't execute code in any possible language to check result (and also because in some languages there are features making task trivial). Anyway it's about principle rather than specific language constructs.
'
' You may find CHR function useful - it works the same in BASIC, Python, Pascal and probably some other languages - returns character by its ASCII code.

a$ = "a$ = : PRINT LEFT$(a$, 5); CHR$(34); a$; CHR$(34); MID$(a$, 6)"
PRINT LEFT$(a$, 5); CHR$(34); a$; CHR$(34); MID$(a$, 6)
