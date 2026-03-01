/*

Up to this point, we have hard-coded polynomials or used Taylor series to calculate them. We will now create a polynomial-as-array class where the coefficients of the polynomial are stored in an array.

Intuitively, one may think that coefficient_array[k] should store the coefficient of x[k]; however, Matlab does it the other way around:

The last entry of the array is the constant term, each preceding term is the coefficient of the next higher degree term. Thus, if we were to have an array coefficient_array of capacity n, then this stores a polynomial of degree n-1 and the entry coefficient_array[k] stores the coefficient of the term x[n-k-1].

There are good reasons for doing this:

We normally think of polynomials with the leading term first, so having the data structure be intuitive in nature is beneficial, and
Horner's rule for evaluating a polynomial is easier to implement using this order.
After all, your teacher would usually write 3.2x^3 - 1.5x^2 + 2.5x - 0.9 and not -0.9 + 2.5x - 1.5x^2 + 3.2x^3.

Thus, our class definition would be:

// Class declaration
class Polynomial_as_array;

// Class definition
class Polynomial_as_array {
        public:
                Polynomial_as_array( unsigned int max_degree );
                ~Polynomial_as_array();

        private:
                unsigned int array_capacity;
                double      *coefficient_array;
};
Now, here is an interesting question: note that the maximum degree is actual one less than the necessary capacity. Consequently, we should always ask ourselves: is the interface designed for the programmer or the user? In this case, if a mathematician was using this tool, it would be natural to use

        Polynomial_as_array my_quadratic{2}; to allocate sufficient memory for a polynomial of degree two (i.e., a quadratic polynomial). The constructor will have to deal with this discrepancy between the semantics of the constructor and the the underlying data structure. Internally, however, it would make no sense to force the idea of degree on the programmer, as the programmer of the class should be focused on using the programming language correctly. If we were to store degree and not the capacity of the array, the programmer is more likely to introduce errors.

Polynomial_as_array::Polynomial_as_array( size_t max_degree ):
array_capacity{max_degree + 1},
coefficient_array{new double[array_capacity]} {
        for ( unsigned int k{0}; k < array_capacity; ++k ) {
                coefficient_array[k] = 0.0;
        }
}

Polynomial_as_array::~Polynomial_as_array() {
        delete[] coefficient_array;
        coefficient_array = nullptr;     // To avoid dangling pointers in case of other programming errors
}
In the next lesson, we will describe a polynomial-as-linked-list approach.

Warning:
Notice that in both the class definition and the constructor definition, we listed the the member variables in the same order: array_capacity first, and then coefficient_array. It is necessary to assign the value of array_capacity before allocating memory for such an array; otherwise, the value of array_capacity would be arbitrarily defined.

Weaknesses
Notice that this data structure would be ideal for storing a dense polynomial such as 3.2x3−1.5x2+2.5x−0.9; however, it would not be so ideal for storing a polynomial such as 3.2x1023−1.5x511+2.5x63−0.9, for this would require you to maintain an array of capacity at least 1024. Also, we cannot (easily) increase the capacity of the array (not without copying over all the coefficients in the original array). Thus, we will continue this topic by looking at a polynomial-as-linked-list implementation.

Questions and practice:

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	size_t degree;
	double coeffs[];
} Polynomial;

Polynomial *
newpolynomial(size_t degree)
{
	Polynomial *p;

	p = calloc(1, sizeof(*p) + ((degree + 1) * sizeof(*p->coeffs)));
	if (!p)
		return NULL;
	p->degree = degree;
	return p;
}

void
printpolynomial(Polynomial *p)
{
	double c;
	size_t i;

	for (i = 0; i <= p->degree; i++) {
		c = p->coeffs[i];
		if (i)
			c = fabs(c);
		printf("%.2f", c);

		if (i < p->degree) {
			printf("x^%zu", p->degree - i);
			if (p->coeffs[i] < 0)
				printf(" + ");
			else
				printf(" - ");
		}
	}
	printf("\n");
}

int
main(void)
{
	Polynomial *p;

	p = newpolynomial(3);
	assert(p);
	p->coeffs[0] = 3.2;
	p->coeffs[1] = -1.5;
	p->coeffs[2] = 2.5;
	p->coeffs[3] = -0.9;
	printpolynomial(p);
	free(p);
	return 0;
}
