/*

The basis vectors for geometric algebra are

(e0=1),e1,e2,…,en

They all square to 1 (we do not consider vectors which square to -1 or zero)

ei⋅ei=1

They are associative and anticommutative (except e0=1 which is associative and commutative)

ei⋅ej=−ej⋅ei(i≠j);andi,j>0

For example, this product is simplified to

e1⋅e3⋅e3⋅e5⋅e4⋅e5=e1⋅(e3⋅e3)⋅(e5⋅e4)⋅e5=e1⋅(1)⋅(−e4⋅e5)⋅e5=e1⋅(−e4)⋅(e5⋅e5)=e1⋅(−e4)⋅(1)=−e1⋅e4

(note that the simplified product is sorted by the index of e)

Challenge

If a product of basis vectors is represented by a signed integer where each bit is 1 if the vector is present, or 0 if the vector is not present

0101011 = e0⋅e1⋅e3⋅e5 = e10⋅e11⋅e02⋅e13⋅e04⋅e15⋅e06
−0101011 = −e0⋅e1⋅e3⋅e5

Given two signed integers a, b (you can choose the numeric encoding for negative values), output the product c=a.b

The input is only 2 signed integers. There are many ways to encode signed integers. You can pick anyone, but the input is only 2 variables.

Note that |c|=|a|XOR|b|, but the tricky part is to find the sign.

If the language doesn't allow its integer type to encode signed zeros (−00000), the code should return −00001 (because −e00=−e10=−1)

Because x=e0⋅x=x⋅e0, then x=xOR1, so is equally valid to return 0 or 1 for e0

You should at least calculate for 4 basis vectors e0=1,e1,e2,e3

Here is a multiplication table generator (to check the right answers), which also offers code in C++, C#, Python and Rust (the webpage requires to manually specify how many vectors square to 1,-1 and 0. You can set 3 (or more) positive, 0 negative, and 0 Zero)

Here is Rosetta code in many languages for geometric algebra

Example:

given a, b:
a=e1⋅e2=00110

b=e2⋅e3=01100

possible products are:

c=a.b=e1⋅e3=01010

c=b.a=−e1⋅e3=−01010

note that
b.b=−e00=−1=−00000

So, the sign has to be calculated even if the number is 00000, because +00000≠−00000

Example:
a=−e2=−00100
b=−e1⋅e2=−00110
c=a.b=(−1⋅e2)(−1⋅e1⋅e2)=(−1)⋅(e2)(−1)⋅(e1⋅e2)=(e2⋅e1)⋅e2=(−e1⋅e2)⋅e2=(−e1)⋅(e2⋅e2)=−e1=−00010

but b.a=00010

e0=1 and -1 are scalars and commute with any basis vector (do not anticommute), so negative signs on the input can be treated as in standard multiplication of integers:
−∗−=+
+∗−=−∗+=−

Example:
a=e1⋅e2⋅e3=01110
b=−e1⋅e2=−00110
c=a.b=(e1e2e3)(−e1e2) =−(e1e2e3)(e1e2)=−(−e1e2e1e3e2)=−(e1e1e2e3e2)=−(e1e1)(−e2e2e3)=e3=01000
b.a=e3=01000

Note that on this case, b.a=a.b, so the basis vectors ei anticommute, but it doesn't means that always b.a=−a.b

This is not part of the challenge, but I would appreciate suggestions on how should be encoded vectors which square to -1 or 0

This Python code generates the right answers

Python 3, 11427 bytes

This is not part of the challenge, but I would appreciate suggestions on how should be encoded vectors which square to -1 or 0

This Python code generates the right answers

Python 3, 11427 bytes


"""3D Projective Geometric Algebra.

Written by a generator written by enki.
"""

__author__ = 'Enki'

import math

class R300:
    def __init__(self, value=0, index=0):
        """Initiate a new R300.

        Optional, the component index can be set with value.
        """
        self.mvec = [0] * 8
        self._base = ["1", "e1", "e2", "e3", "e12", "e13", "e23", "e123"]
        #self._base = ["0001", "0010", "0100", "1000", "0110", "1010", "1100", "1110"]
        if (value != 0):
            self.mvec[index] = value

    @classmethod
    def fromarray(cls, array):
        """Initiate a new R300 from an array-like object.

        The first axis of the array is assumed to correspond to the elements
        of the algebra, and needs to have the same length. Any other dimensions
        are left unchanged, and should have simple operations such as addition
        and multiplication defined. NumPy arrays are therefore a perfect
        candidate.

        :param array: array-like object whose length is the dimension of the algebra.
        :return: new instance of R300.
        """
        self = cls()
        if len(array) != len(self):
            raise TypeError('length of array must be identical to the dimension '
                            'of the algebra.')
        self.mvec = array
        return self

    def __str__(self):
        if isinstance(self.mvec, list):
            res = ' + '.join(filter(None, [("%.7f" % x).rstrip("0").rstrip(".") + (["",self._base[i]][i > 0]) if abs(x) > 0.000001 else None for i,x in enumerate(self)]))
            #res = ' + '.join([x for i,x in enumerate(self)])
        else:  # Assume array-like, redirect str conversion
            res = str(self.mvec)
        if (res == ''):
            return "0"
        return res

    def __getitem__(self, key):
        return self.mvec[key]

    def __setitem__(self, key, value):
        self.mvec[key] = value

    def __len__(self):
        return len(self.mvec)

    def __invert__(a):
        """R300.Reverse

        Reverse the order of the basis blades.
        """
        res = a.mvec.copy()
        res[0] = a[0]
        res[1] = a[1]
        res[2] = a[2]
        res[3] = a[3]
        res[4] = -a[4]
        res[5] = -a[5]
        res[6] = -a[6]
        res[7] = -a[7]
        return R300.fromarray(res)

    def Dual(a):
        """R300.Dual

        Poincare duality operator.
        """
        res = a.mvec.copy()
        res[0] = -a[7]
        res[1] = -a[6]
        res[2] = a[5]
        res[3] = -a[4]
        res[4] = a[3]
        res[5] = -a[2]
        res[6] = a[1]
        res[7] = a[0]
        return R300.fromarray(res)

    def Conjugate(a):
        """R300.Conjugate

        Clifford Conjugation
        """
        res = a.mvec.copy()
        res[0] = a[0]
        res[1] = -a[1]
        res[2] = -a[2]
        res[3] = -a[3]
        res[4] = -a[4]
        res[5] = -a[5]
        res[6] = -a[6]
        res[7] = a[7]
        return R300.fromarray(res)

    def Involute(a):
        """R300.Involute

        Main involution
        """
        res = a.mvec.copy()
        res[0] = a[0]
        res[1] = -a[1]
        res[2] = -a[2]
        res[3] = -a[3]
        res[4] = a[4]
        res[5] = a[5]
        res[6] = a[6]
        res[7] = -a[7]
        return R300.fromarray(res)

    def __mul__(a,b):
        """R300.Mul

        The geometric product.
        """
        if type(b) in (int, float):
            return a.muls(b)
        res = a.mvec.copy()
        res[0] = b[0] * a[0] + b[1] * a[1] + b[2] * a[2] + b[3] * a[3] - b[4] * a[4] - b[5] * a[5] - b[6] * a[6] - b[7] * a[7]
        res[1] = b[1] * a[0] + b[0] * a[1] - b[4] * a[2] - b[5] * a[3] + b[2] * a[4] + b[3] * a[5] - b[7] * a[6] - b[6] * a[7]
        res[2] = b[2] * a[0] + b[4] * a[1] + b[0] * a[2] - b[6] * a[3] - b[1] * a[4] + b[7] * a[5] + b[3] * a[6] + b[5] * a[7]
        res[3] = b[3] * a[0] + b[5] * a[1] + b[6] * a[2] + b[0] * a[3] - b[7] * a[4] - b[1] * a[5] - b[2] * a[6] - b[4] * a[7]
        res[4] = b[4] * a[0] + b[2] * a[1] - b[1] * a[2] + b[7] * a[3] + b[0] * a[4] - b[6] * a[5] + b[5] * a[6] + b[3] * a[7]
        res[5] = b[5] * a[0] + b[3] * a[1] - b[7] * a[2] - b[1] * a[3] + b[6] * a[4] + b[0] * a[5] - b[4] * a[6] - b[2] * a[7]
        res[6] = b[6] * a[0] + b[7] * a[1] + b[3] * a[2] - b[2] * a[3] - b[5] * a[4] + b[4] * a[5] + b[0] * a[6] + b[1] * a[7]
        res[7] = b[7] * a[0] + b[6] * a[1] - b[5] * a[2] + b[4] * a[3] + b[3] * a[4] - b[2] * a[5] + b[1] * a[6] + b[0] * a[7]
        return R300.fromarray(res)
    __rmul__ = __mul__

    def __xor__(a,b):
        res = a.mvec.copy()
        res[0] = b[0] * a[0]
        res[1] = b[1] * a[0] + b[0] * a[1]
        res[2] = b[2] * a[0] + b[0] * a[2]
        res[3] = b[3] * a[0] + b[0] * a[3]
        res[4] = b[4] * a[0] + b[2] * a[1] - b[1] * a[2] + b[0] * a[4]
        res[5] = b[5] * a[0] + b[3] * a[1] - b[1] * a[3] + b[0] * a[5]
        res[6] = b[6] * a[0] + b[3] * a[2] - b[2] * a[3] + b[0] * a[6]
        res[7] = b[7] * a[0] + b[6] * a[1] - b[5] * a[2] + b[4] * a[3] + b[3] * a[4] - b[2] * a[5] + b[1] * a[6] + b[0] * a[7]
        return R300.fromarray(res)


    def __and__(a,b):
        res = a.mvec.copy()
        res[7] = 1 * (a[7] * b[7])
        res[6] = 1 * (a[6] * b[7] + a[7] * b[6])
        res[5] = -1 * (a[5] * -1 * b[7] + a[7] * b[5] * -1)
        res[4] = 1 * (a[4] * b[7] + a[7] * b[4])
        res[3] = 1 * (a[3] * b[7] + a[5] * -1 * b[6] - a[6] * b[5] * -1 + a[7] * b[3])
        res[2] = -1 * (a[2] * -1 * b[7] + a[4] * b[6] - a[6] * b[4] + a[7] * b[2] * -1)
        res[1] = 1 * (a[1] * b[7] + a[4] * b[5] * -1 - a[5] * -1 * b[4] + a[7] * b[1])
        res[0] = 1 * (a[0] * b[7] + a[1] * b[6] - a[2] * -1 * b[5] * -1 + a[3] * b[4] + a[4] * b[3] - a[5] * -1 * b[2] * -1 + a[6] * b[1] + a[7] * b[0])
        return R300.fromarray(res)


    def __or__(a,b):
        res = a.mvec.copy()
        res[0] = b[0] * a[0] + b[1] * a[1] + b[2] * a[2] + b[3] * a[3] - b[4] * a[4] - b[5] * a[5] - b[6] * a[6] - b[7] * a[7]
        res[1] = b[1] * a[0] + b[0] * a[1] - b[4] * a[2] - b[5] * a[3] + b[2] * a[4] + b[3] * a[5] - b[7] * a[6] - b[6] * a[7]
        res[2] = b[2] * a[0] + b[4] * a[1] + b[0] * a[2] - b[6] * a[3] - b[1] * a[4] + b[7] * a[5] + b[3] * a[6] + b[5] * a[7]
        res[3] = b[3] * a[0] + b[5] * a[1] + b[6] * a[2] + b[0] * a[3] - b[7] * a[4] - b[1] * a[5] - b[2] * a[6] - b[4] * a[7]
        res[4] = b[4] * a[0] + b[7] * a[3] + b[0] * a[4] + b[3] * a[7]
        res[5] = b[5] * a[0] - b[7] * a[2] + b[0] * a[5] - b[2] * a[7]
        res[6] = b[6] * a[0] + b[7] * a[1] + b[0] * a[6] + b[1] * a[7]
        res[7] = b[7] * a[0] + b[0] * a[7]
        return R300.fromarray(res)


    def __add__(a,b):
        """R300.Add

        Multivector addition
        """
        if type(b) in (int, float):
            return a.adds(b)
        res = a.mvec.copy()
        res[0] = a[0] + b[0]
        res[1] = a[1] + b[1]
        res[2] = a[2] + b[2]
        res[3] = a[3] + b[3]
        res[4] = a[4] + b[4]
        res[5] = a[5] + b[5]
        res[6] = a[6] + b[6]
        res[7] = a[7] + b[7]
        return R300.fromarray(res)
    __radd__ = __add__

    def __sub__(a,b):
        """R300.Sub

        Multivector subtraction
        """
        if type(b) in (int, float):
            return a.subs(b)
        res = a.mvec.copy()
        res[0] = a[0] - b[0]
        res[1] = a[1] - b[1]
        res[2] = a[2] - b[2]
        res[3] = a[3] - b[3]
        res[4] = a[4] - b[4]
        res[5] = a[5] - b[5]
        res[6] = a[6] - b[6]
        res[7] = a[7] - b[7]
        return R300.fromarray(res)

    def __rsub__(a,b):
        """R300.Sub

        Multivector subtraction
        """
        return b + -1 * a


    def smul(a,b):
        res = a.mvec.copy()
        res[0] = a * b[0]
        res[1] = a * b[1]
        res[2] = a * b[2]
        res[3] = a * b[3]
        res[4] = a * b[4]
        res[5] = a * b[5]
        res[6] = a * b[6]
        res[7] = a * b[7]
        return R300.fromarray(res)


    def muls(a,b):
        res = a.mvec.copy()
        res[0] = a[0] * b
        res[1] = a[1] * b
        res[2] = a[2] * b
        res[3] = a[3] * b
        res[4] = a[4] * b
        res[5] = a[5] * b
        res[6] = a[6] * b
        res[7] = a[7] * b
        return R300.fromarray(res)


    def sadd(a,b):
        res = a.mvec.copy()
        res[0] = a + b[0]
        res[1] = b[1]
        res[2] = b[2]
        res[3] = b[3]
        res[4] = b[4]
        res[5] = b[5]
        res[6] = b[6]
        res[7] = b[7]
        return R300.fromarray(res)


    def adds(a,b):
        res = a.mvec.copy()
        res[0] = a[0] + b
        res[1] = a[1]
        res[2] = a[2]
        res[3] = a[3]
        res[4] = a[4]
        res[5] = a[5]
        res[6] = a[6]
        res[7] = a[7]
        return R300.fromarray(res)


    def ssub(a,b):
        res = a.mvec.copy()
        res[0] = a - b[0]
        res[1] = -b[1]
        res[2] = -b[2]
        res[3] = -b[3]
        res[4] = -b[4]
        res[5] = -b[5]
        res[6] = -b[6]
        res[7] = -b[7]
        return R300.fromarray(res)


    def subs(a,b):
        res = a.mvec.copy()
        res[0] = a[0] - b
        res[1] = a[1]
        res[2] = a[2]
        res[3] = a[3]
        res[4] = a[4]
        res[5] = a[5]
        res[6] = a[6]
        res[7] = a[7]
        return R300.fromarray(res)


    def norm(a):
        return abs((a * a.Conjugate())[0]) ** 0.5

    def inorm(a):
        return a.Dual().norm()

    def normalized(a):
        return a * (1 / a.norm())

e1 = R300(1.0, 1)
e2 = R300(1.0, 2)
e3 = R300(1.0, 3)
e12 = R300(1.0, 4)
e13 = R300(1.0, 5)
e23 = R300(1.0, 6)
e123 = R300(1.0, 7)

if __name__ == '__main__':
    #print("e1*e1         :", str(e1*e1))
    #print("pss           :", str(e123))
    #print("pss*pss       :", str(e123*e123))


    a = [R300(1.0, i) for i in range(0, 8) ]
    b = [-1 * x for x in a]
    a = a + b
    print("Vectors:")
    [print(str(x)) for x in a ]
    print("Products")

    def javascriptCode(a,b):
        def ArnauldEncoding(x):
            answer= str(x)
            if answer[0]=="-":
                return answer[1:]+"1"
            else:
                return answer+"0"
        return "".join(["console.log(\"0b",ArnauldEncoding(a) , "\",\"*\",\"0b" , ArnauldEncoding(b),"\",\"=\",","f(0b" , ArnauldEncoding(a) , ")(0b" , ArnauldEncoding(b) , ").toString(2), \"== \",\"" , ArnauldEncoding(a * b),"\")"])

    def RubyCode(a,b):
        return "".join(["[","0b",str(a),",","0b",str(b),"],"]).replace("0b-","-0b")

    if True:
        Productos = ["".join([str(x),"*",str(y),"=",str(x * y)]) for x in a for y in a]
        #Productos = [javascriptCode(x,y) for x in a for y in a]
        #Productos = [RubyCode(x,y) for x in a for y in a]
        #Productos = [str(x*y) for x in a for y in a]

        Origen = ["1e1", "1e2", "1e3", "1e12", "1e13", "1e23", "1e123"]
        Destino = ["0010", "0100", "1000", "0110", "1010", "1100", "1110"]

        Reemplazo = dict(zip(Origen, Destino))
        Binario = Productos
        for key in sorted(Reemplazo, key=len, reverse=True): # Through keys sorted by length
            Binario = [x.replace(key,Reemplazo[key]) for x in Binario]
        [print(x) for x in Binario]
    a = a

*/

#include <assert.h>

/*

ported from @Gere solution

The lowest bit of b is used as an aggregator of all its bits with XOR. It's tracking the parity - comparable to counting tail bits in more direct solutions. It took some thought to show that this equivalent.

*/
int
mul(int a, int b)
{
	int r;

	r = a ^ b;
	b &= -2;
	while (a != 0) {
		a >>= 1;
		r ^= a & b & 1;
		b = (b >> 1) ^ (b & 1);
	}
	return r;
}

int
main()
{
	assert(mul(0b00110, 0b01100) == 10);

	return 0;
}
