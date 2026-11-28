"""

a + b + c = 0

Rearrange to find the following relation:

a + b = -c
a + c = -b
b + c = -a

Square both sides to get the following relation:

(a + b)^2 = c^2
(a + c)^2 = b^2
(b + c)^2 = a^2

Then use the above identify to plug in the equation to get:

(a + b)^2 + (a + c)^2 + (b + c)^2 = a^2 + b^2 + c^2 =>

(a^2 + b^2 + c^2) / (a^2 + b^2 + c^2) = 1

"""

N = 10
for a in range(-N, N):
    for b in range(-N, N):
        for c in range(-N, N):
            if a + b + c != 0:
                continue
            n = (a+b)**2 + (b+c)**2 + (a+c)**2
            d = (a**2 + b**2 + c**2)
            if d == 0:
                continue
            print(a, b, c, n/d)

