/*

A capacitor is an electrical device that stores electric charges. It essentially consists of two flat plates with an insulating material (the dielectric) between them.

The capacitance of a capacitor is defined as Capacitance = Charge / Volts

where Charge is the amount of charges stored in a capacitor in units of coulombs and Volts is the voltage between the two plates of the capacitor in volts. The units of capacitance are farads (F), with 1 farad = 1 coulomb per volt.

When a charge is present on the plates of the capacitor, there is an electric field between the two plates. The energy stored in this electric field is given by the equation:

Energy = 0.5 * Capacitance * Volts * Volts

where Energy is the energy in joules.

The number of electrons stored is given by

electrons = Charge * electrons_per_coulomb

where number of electrons_per_coulomb is 6.241461E18.

Task
For a known charge and voltage (positive floats), you have to calculate the capacitance of the capacitor in farads, the number of electrons stored, and the energy in joules stored in its electric field.

Example
Suppose for example that you are given parameters:

volt = 240.0 (volts), charge = 6.00E+00 (coulombs).

Your function calc(volts, charge) returns:

"Vl.     240.00V Cp.   2.50E-02F Ch.   6.00E+00C El.   3.74E+19 En.     720.00J"

with Vl. for volts, Cp. for capacitance, Ch. for charge, El. for Electrons, En. for Energy and V, F, C, J abbreviations for Volt, Farad, Coulomb and Joule. Each number is formatted in a 10-width field and has 2 decimals, some are in scientific format.

To better see blanks they have been replaced below by -

"Vl.-----240.00V-Cp.---2.50E-02F-Ch.---6.00E+00C-El.---3.74E+19-En.-----720.00J".

WARNING
This kata is only about formatting so:

use the given formulas or your results may be different with the expected ones caused by floating error.

*/

#include <stdio.h>

int
append(char *output, const char *name, double value, const char *unit)
{
	int length;

	length = sprintf(output, "%s. ", name);
	if (value < 100 || value >= 1000)
		length += sprintf(output + length, "%.2E%s ", value, unit);
	else
		length += sprintf(output + length, "%.2f%s ", value, unit);
	return length;
}

char *
format(double volts, double charge, char *output)
{
	double electrons;
	double capacitance;
	double energy;
	int length;

	electrons = charge * 6.241461E18;
	capacitance = charge / volts;
	energy = 0.5 * capacitance * volts * volts;

	length = 0;
	length += append(output + length, "Vl", volts, "V");
	length += append(output + length, "Cp", capacitance, "F");
	length += append(output + length, "Ch", charge, "C");
	length += append(output + length, "El", electrons, "");
	length += append(output + length, "En", energy, "J");
	output[length - 1] = '\0';
	return output;
}

void
test(double volts, double charge)
{
	char output[128];

	format(volts, charge, output);
	puts(output);
}

int
main()
{
	test(240, 6.00e00);

	return 0;
}
