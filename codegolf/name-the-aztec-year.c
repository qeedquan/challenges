/*

It's time for another Mesoamerican calendar! The Xiuhnelpilli was used by the Aztecs (more properly, the Mexica) to name their years. Each year has a number and a sign. Here's part of the cycle:

Input; Output
1089; 13 Calli
1090; 1 Tochtli
1091; 2 Acatl
1092; 3 Tecpatl
1093; 4 Calli
1094; 5 Tochtli
1095; 6 Acatl
1096; 7 Tecpatl
1097; 8 Calli
1098; 9 Tochtli
1099; 10 Acatl
1100; 11 Tecpatl
1101; 12 Calli
1102; 13 Tochtli
1103; 1 Acatl
1104; 2 Tecpatl
1105; 3 Calli
1106; 4 Tochtli
1107; 5 Acatl
1108; 6 Tecpatl
1109; 7 Calli
1110; 8 Tochtli
1111; 9 Acatl
1112; 10 Tecpatl
1113; 11 Calli
1114; 12 Tochtli
1115; 13 Acatl
1116; 1 Tecpatl
1117; 2 Calli
1118; 3 Tochtli
1119; 4 Acatl
1120; 5 Tecpatl
1121; 6 Calli
1122; 7 Tochtli
1123; 8 Acatl
1124; 9 Tecpatl
1125; 10 Calli
1126; 11 Tochtli
1127; 12 Acatl
1128; 13 Tecpatl
1129; 1 Calli
1130; 2 Tochtli
1131; 3 Acatl
1132; 4 Tecpatl
1133; 5 Calli
1134; 6 Tochtli
1135; 7 Acatl
1136; 8 Tecpatl
1137; 9 Calli
1138; 10 Tochtli
1139; 11 Acatl
1140; 12 Tecpatl
1141; 13 Calli
1142; 1 Tochtli
The pattern should be clear enough: the number is counting up to 13, and the sign goes Tochtli, Acatl, Tecpatl, Calli. After 52 years the pattern repeats itself.

The program will take as input an integer between 1064 (the year the Mexica left their mythological homeland of Aztlan) and 1521 (fall of Tenochtitlan to the Spaniards), inclusive, and output the corresponding year name. It can be a single string (in which case there needs to be a space between number and sign), or a tuple (e.g. ["2", "Calli"]) of your preferred format. The sign name is always capitalised.

Handling years outside the specified range is not necessary. It's code-golf, so the shortest code wins!

Test cases

The entire example list above, plus:

Input; Output
1064; 1 Tecpatl
1521; 3 Calli

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
aztecyear(unsigned y, char *b)
{
	static const char *tab[] = {"Tecpatl", "Calli", "Tochtli", "Acatl"};

	sprintf(b, "%d %s", ((y + 2) % 13) + 1, tab[y & 3]);
	return b;
}

void
test(unsigned y, const char *r)
{
	char b[128];

	aztecyear(y, b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(1089, "13 Calli");
	test(1090, "1 Tochtli");
	test(1091, "2 Acatl");
	test(1092, "3 Tecpatl");
	test(1093, "4 Calli");
	test(1094, "5 Tochtli");
	test(1095, "6 Acatl");
	test(1096, "7 Tecpatl");
	test(1097, "8 Calli");
	test(1098, "9 Tochtli");
	test(1099, "10 Acatl");
	test(1100, "11 Tecpatl");
	test(1101, "12 Calli");
	test(1102, "13 Tochtli");
	test(1103, "1 Acatl");
	test(1104, "2 Tecpatl");
	test(1105, "3 Calli");
	test(1106, "4 Tochtli");
	test(1107, "5 Acatl");
	test(1108, "6 Tecpatl");
	test(1109, "7 Calli");
	test(1110, "8 Tochtli");
	test(1111, "9 Acatl");
	test(1112, "10 Tecpatl");
	test(1113, "11 Calli");
	test(1114, "12 Tochtli");
	test(1115, "13 Acatl");
	test(1116, "1 Tecpatl");
	test(1117, "2 Calli");
	test(1118, "3 Tochtli");
	test(1119, "4 Acatl");
	test(1120, "5 Tecpatl");
	test(1121, "6 Calli");
	test(1122, "7 Tochtli");
	test(1123, "8 Acatl");
	test(1124, "9 Tecpatl");
	test(1125, "10 Calli");
	test(1126, "11 Tochtli");
	test(1127, "12 Acatl");
	test(1128, "13 Tecpatl");
	test(1129, "1 Calli");
	test(1130, "2 Tochtli");
	test(1131, "3 Acatl");
	test(1132, "4 Tecpatl");
	test(1133, "5 Calli");
	test(1134, "6 Tochtli");
	test(1135, "7 Acatl");
	test(1136, "8 Tecpatl");
	test(1137, "9 Calli");
	test(1138, "10 Tochtli");
	test(1139, "11 Acatl");
	test(1140, "12 Tecpatl");
	test(1141, "13 Calli");
	test(1142, "1 Tochtli");
	test(1064, "1 Tecpatl");
	test(1521, "3 Calli");

	return 0;
}
