#!/usr/bin/env python3

"""

It's possible to find such a boolean function f with 6 inputs that, any 3-input boolean function g can be expressed with a single f whose input are only constant(0,1) or direct input of g, e.g. for one possible g, g(x,y,z)=f(0,1,0,x,y,z). An example f and expressions for all g can be found here.

Now golf such a function f. You needn't use the exact same function as one given in link, but you need to prove correctness(e.g. provide expressions for all g).

Shortest code in each language wins.

"""

from itertools import product

"""

Ported from @Jonathan Allan solution

function accepting a string of zero/one characters of length six which returns an integer, either zero or one.

How?
Ran some ugly simulated annealing code which found the slightly shorter lookup string (59 bits rather than 64, saving one hexadecimal digit).

"""

def f(s):
    return (0x6c15ea974590cdc >> int(s, 2)) & 1

print('e.g. NOR as f("zzy10x"):')
print("x y z NOR")
for x, y, z in product("01", repeat=3):
    print(x, y, z, f(f"{z}{z}{y}10{x}"))
print()

FORMS = "000000 zzy10x zyxz01 yyx100 yzxy01 zzx100 zzxy00 zyxx11 zzyx01 1zzxy0 z0x000 yyx1z0 y0x000 zzx1y0 zyx000 10x000 xzyx01 zzy100 zzyx00 zxyy11 yyzx00 yxzz11 z1zy1x 0zyx11 yxzy00 1xzy00 xyyz00 x1yz00 xyzy00 x1zy00 zy00x0 zxy011 zy0x01 1zzyx0 z0y000 xxy1z0 xyzx00 1yzx00 yxxz00 y1xz00 yx1z00 yxzz10 xxyxz0 x1yzxx xzzyx0 xyz100 xyxz00 xzzy10 x0y000 zzy1x0 zxy000 10y000 yxzx00 y1zx00 zzxyx0 zyx011 yzzxy0 yxz100 yxyz00 yzzx10 yx1100 zzyx10 yz0x00 xyx100 yz0x01 1yyzx0 xzyx00 1zyx00 y0z000 xxz1y0 zxxy00 z1xy00 zx1y00 zxyy10 zxyyx0 xzy100 xxzxy0 x1zyxx xzxy00 xyyz10 x0z000 yyz1x0 zxyx00 z1yx00 yxz000 10z000 z00yx0 yzx011 1zx1y0 zxy100 zx1100 yyzx10 zxzy00 zyyx10 zy0x00 xzx100 zy1x00 zyxx10 1yz1x0 yzx100 1zy1x0 zyx100 zy1100 xxzy10 yxzyx0 1xzyx0 1yzx10 yzx110 1zyx10 zyx110 zyxx00 zy1x10 yyzyx0 zy001x yzyx00 yxxz10 zyzx00 zxxy10 zx0y00 yzy100 1zxy10 zxy110 zxyy00 yxzx10 yxzz00 zxyx10 xzxyx0 z0zy1x 0zyx01 1x0zyx y10xz1 1z0yx0 z10xy1 1y0zx0 z0xy00 xy0z1y z01y00 110zyx yx0xz1 xy0z10 zx0xy1 xz0y10 0zxy00 xz01y0 z10yx1 1x0zy0 z0yx00 yx0z1x y0zx00 zx0y1x zx0yxx z10yxx yxz0y0 z0y100 z0yyx0 y0zx10 y0zzx0 z0yx10 z0yxy0 zx0y11 z01x00 110zxy yy0xz1 yx0z10 yxz0x0 z0x100 yx0zx0 x0zy10 z0y0zx 10zyx0 z00000 yxz010 z01xy0 zy01yx yx0yz1 0zx100 zy0xx1 yz0x10 0zyx00 yz01x0 y0z0x0 z0xy10 z0xyx0 zy0x11 z01yx0 zx01xy xy0xz1 0zy100 y0z0xz 0zyx10 yz0xx0 xy01zx y01x00 110yxz zxy0x0 y0x100 yz0xy1 zx0y10 zx0yx0 x0yz10 y0z0yx 10yzx0 0yxzy0 yz01yx y00000 zxy010 zx0zy1 0yx100 yz0xx1 zy0x10 z0y0x0 y0xz10 0yzx00 zy01x0 zy0yx0 yz0x11 y01zx0 z001xy z0y0xy 0yzx10 xz0xy1 0yz100 zy0xx0 xz01yx x0z0xy 10xzy0 0xyzx0 y001zx 0xzyx0 z001yx z0x0yx 0xzy10 zy0zyx 10z0yx y0x0z1 01yzx0 z0x0y1 01zyx0 zy0000 x0z01y x00000 zyx010 zy0zx1 0xy100 yz0yx1 0xz100 0z0xy0 yz01xy z0y0x1 01zxy0 zx0000 y0z01x yx0000 z0y01x zyx0x0 100000".split()

print("assert all...")
count = 0
for n, s in enumerate(FORMS):
    for k, (x, y, z) in enumerate(product("01", repeat=3)):
        assert f("".join(str(eval(c)) for c in s)) == int(n) >> k & 1, f"Failed at {n}: {s}"
        count += 1
assert count == 256 * 8, "Expected 2048 evaluations"
print(f"evaluated {count} successfully")
