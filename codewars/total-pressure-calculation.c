/*

Given the molecular mass of two molecules M1 and M2, their masses present m1 and m2 in a vessel of volume V at a specific temperature T,
find the total pressure Ptotal exerted by the molecules. Formula to calculate the pressure is:

Ptotal = ((m1/M1 + m2/M2) * R * T) / V

Input
Six values:

M1, M2: molar masses of both gases, in g*mol^-1
m1, m2: present mass of both gases, in grams (g)
V: volume of the vessel, in dm^3
T: temperature, in C

Output:
One value: Ptotal, in units of atm

Notes
Remember: Temperature is given in Celsius while SI unit is Kelvin (K).
0 C = 273.15 K

The gas constant R = 0.082 dm^3 * atm * K^-1 * mol^-1

*/

#include <stdio.h>

/*

Ideal Gas Law

PV = NRT

P = NRT/V
N = Sums of ratios of present masses / molar masses

*/

double
pressure(double M1, double M2, double m1, double m2, double V, double T)
{
	static const double R = 0.082;

	double N1, N2;

	T += 273.15;
	N1 = m1 / M1;
	N2 = m2 / M2;
	return (N1 + N2) * R * T / V;
}

int
main()
{
	printf("%f\n", pressure(1, 2, 3, 4, 5, 6));
	return 0;
}
