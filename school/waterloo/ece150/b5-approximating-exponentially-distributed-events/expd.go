/*

The standard normal distribution is defined by the probability density function

1/sqrt(2*pi) * exp(-x^2 / 2)

This function does not have a simple anti-derivative, so if we wish to compute the integral, we must use the error function (erf(x)):

Int[-oo, x] 1/sqrt(2*pi) exp(-tau^2 / 2) dtau = 0.5*(1 + erf(x/sqrt(2)))

Fortunately, this function is implemented in the standard mathematics library:

double std_normal_pdf( double x );
double std_normal_cdf( double x );

double std_normal_pdf( double x ) {
	double const PI{std::acos( -1 )};
	return std::exp( -0.5*x*x )/std::sqrt(2*PI);
}

double std_normal_cdf( double x ) {
	return 0.5 + 0.5*std::erf( x/std::sqrt(2.0) );
}

Now, we often must find when the integral of the standard normal equals a specified value. Unfortunately, this has no solution, so we must approximate the solution using Newton's method:

double inv_int_std_normal( double x );

double std_normal_icdf( double x ) {
	assert( (0 < x) && (x < 1) );
	double result{x - 0.5};

	double s{x - 0.5};
	double ss{s*s};

	double x0;
	double x1{s*(2.50662827463100051
               + ss*(2.62493499095373663
               + ss*(5.77253353861173460
               + ss*(15.6676089632851799
               + ss*47.0357874801131660))))};

	do {
		x0 = x1;
		x1 = x1 - std_normal_cdf( x1 )/std_normal_pdf( x1 );
	} while ( std::abs( x0 - x1 ) > 1e-15 );

	return x1;
}

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(normpdf(0.5))
	fmt.Println(normcdf(0.5))
	fmt.Println(normicdf(0.5))
}

func normpdf(x float64) float64 {
	return math.Exp(-0.5*x*x) / math.Sqrt(2*math.Pi)
}

func normcdf(x float64) float64 {
	return 0.5 + 0.5*math.Erf(x/math.Sqrt2)
}

func normicdf(x float64) float64 {
	const (
		eps = 1e-15

		k0 = 2.50662827463100051
		k1 = 2.62493499095373663
		k2 = 5.77253353861173460
		k3 = 15.6676089632851799
		k4 = 47.0357874801131660
	)

	s := x - 0.5
	s2 := s * s
	x1 := s * (k0 + s2*(k1+s2*(k2+s2*(k3+s2*k4))))

	for {
		x0 := x1
		x1 -= normcdf(x1) / normpdf(x1)
		if math.Abs(x0-x1) <= eps {
			break
		}
	}
	return x1
}
