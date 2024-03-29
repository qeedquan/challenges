/*

Inspired by this video by Matt Parker

The distances between the letter keys of a QWERTY keyboard are somewhat standardised. The keys are square and both the horizontal and vertical spacing are 19.05mm (so if there were no gaps between the keys, their side lengths would be 19.05mm), and the three rows of keys are offset by ¼ and ½ a key size. Here is a diagram:

Diagram of a QWERTY keyboard with the non-letter keys blurred and the distances between the letter keys annotated

Your task is simple: given two letters, output the Euclidean distance between their centres (or between any two equivalent relative positions, for that matter) on a QWERTY keyboard as described above.

The rows of the QWERTY keyboard in a more easily copyable format are:

QWERTYUIOP
ASDFGHJKL
ZXCVBNM

Q, A, and Z are aligned to the left with only the ¼ and ½ offsets described above; the keys at the rightmost end (P, L, and M) do not line up as well.

Of course, given the same letter twice, your output should be 0.
Rules

    You may accept input in uppercase or lowercase, and as characters, strings, or ASCII codepoints, but this must be consistent
        You may assume the input will always be valid; behaviour for non-Latin-letters is undefined
    Your output must be in millimeters, and accurate to at worst 0.1mm
    You may use any reasonable I/O method
    Standard loopholes are forbidden
    This is code-golf, so the shortest code in bytes wins

Test cases

A full list can be found here (original list calculated by Matt Parker, published here)

In  Out

A B 87.82
B Q 98.18
G C 34.34
H J 19.05
L J 38.10
P X 143.27
Y Y 0
4 K [behaviour undefined]

Note: of course your keyboard has different measurements. Of course your keyboard uses AZERTY, or Dvorak, or something else. Of course your keyboard is 3-dimensional with keys that aren't completely flat, so the distances vary a little. Of course your keyboard has wobbly keys that mean the distances aren't even constants. Of course you live in a universe with Heisenberg's Uncertainty Principle in which you cannot truly know that the keys are that far apart. This is obviously an idealised model of a keyboard; please don't argue about these things in the comments!

Image above modified from work by Denelson83 on English Wikipedia, used under CC-BY-SA 3.0.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char pair[8];
	double distance;
} Keypair;

int
cmp(const void *a, const void *b)
{
	const Keypair *p, *q;

	p = a;
	q = b;
	return strcmp(p->pair, q->pair);
}

double
keydistance(char a, char b)
{
	static const Keypair tab[] = {
	    {"AA", 0},
	    {"AB", 87.82},
	    {"AC", 51.29},
	    {"AD", 38.10},
	    {"AE", 38.40},
	    {"AF", 57.15},
	    {"AG", 76.20},
	    {"AH", 95.25},
	    {"AI", 129.99},
	    {"AJ", 114.30},
	    {"AK", 133.35},
	    {"AL", 152.40},
	    {"AM", 125.28},
	    {"AN", 106.49},
	    {"AO", 148.86},
	    {"AP", 167.77},
	    {"AQ", 19.64},
	    {"AR", 55.74},
	    {"AS", 19.05},
	    {"AT", 73.93},
	    {"AU", 111.18},
	    {"AV", 69.34},
	    {"AW", 23.81},
	    {"AX", 34.34},
	    {"AY", 92.47},
	    {"AZ", 21.30},
	    {"BA", 87.82},
	    {"BB", 0},
	    {"BC", 38.10},
	    {"BD", 51.29},
	    {"BE", 64.78},
	    {"BF", 34.34},
	    {"BG", 21.30},
	    {"BH", 21.30},
	    {"BI", 57.35},
	    {"BJ", 34.34},
	    {"BK", 51.29},
	    {"BL", 69.34},
	    {"BM", 38.10},
	    {"BN", 19.05},
	    {"BO", 72.70},
	    {"BP", 89.48},
	    {"BQ", 98.18},
	    {"BR", 50.63},
	    {"BS", 69.34},
	    {"BT", 40.69},
	    {"BU", 44.93},
	    {"BV", 19.05},
	    {"BW", 80.96},
	    {"BX", 57.15},
	    {"BY", 38.40},
	    {"BZ", 76.20},
	    {"CA", 51.29},
	    {"CB", 38.10},
	    {"CC", 0},
	    {"CD", 21.30},
	    {"CE", 40.69},
	    {"CF", 21.30},
	    {"CG", 34.34},
	    {"CH", 51.29},
	    {"CI", 89.48},
	    {"CJ", 69.34},
	    {"CK", 87.82},
	    {"CL", 106.49},
	    {"CM", 76.20},
	    {"CN", 57.15},
	    {"CO", 107.02},
	    {"CP", 125.01},
	    {"CQ", 64.78},
	    {"CR", 38.40},
	    {"CS", 34.34},
	    {"CT", 44.93},
	    {"CU", 72.70},
	    {"CV", 19.05},
	    {"CW", 50.63},
	    {"CX", 19.05},
	    {"CY", 57.35},
	    {"CZ", 38.10},
	    {"DA", 38.10},
	    {"DB", 51.29},
	    {"DC", 21.30},
	    {"DD", 0},
	    {"DE", 19.64},
	    {"DF", 19.05},
	    {"DG", 38.10},
	    {"DH", 57.15},
	    {"DI", 92.47},
	    {"DJ", 76.20},
	    {"DK", 95.25},
	    {"DL", 114.30},
	    {"DM", 87.82},
	    {"DN", 69.34},
	    {"DO", 111.18},
	    {"DP", 129.99},
	    {"DQ", 46.91},
	    {"DR", 23.81},
	    {"DS", 19.05},
	    {"DT", 38.40},
	    {"DU", 73.93},
	    {"DV", 34.34},
	    {"DW", 30.49},
	    {"DX", 21.30},
	    {"DY", 55.74},
	    {"DZ", 34.34},
	    {"EA", 38.40},
	    {"EB", 64.78},
	    {"EC", 40.69},
	    {"ED", 19.64},
	    {"EE", 0},
	    {"EF", 30.49},
	    {"EG", 46.91},
	    {"EH", 64.78},
	    {"EI", 95.25},
	    {"EJ", 83.17},
	    {"EK", 101.81},
	    {"EL", 120.58},
	    {"EM", 98.18},
	    {"EN", 80.96},
	    {"EO", 114.30},
	    {"EP", 133.35},
	    {"EQ", 38.10},
	    {"ER", 19.05},
	    {"ES", 23.81},
	    {"ET", 38.10},
	    {"EU", 76.20},
	    {"EV", 50.63},
	    {"EW", 19.05},
	    {"EX", 38.40},
	    {"EY", 57.15},
	    {"EZ", 44.93},
	    {"FA", 57.15},
	    {"FB", 34.34},
	    {"FC", 21.30},
	    {"FD", 19.05},
	    {"FE", 30.49},
	    {"FF", 0},
	    {"FG", 19.05},
	    {"FH", 38.10},
	    {"FI", 73.93},
	    {"FJ", 57.15},
	    {"FK", 76.20},
	    {"FL", 95.25},
	    {"FM", 69.34},
	    {"FN", 51.29},
	    {"FO", 92.47},
	    {"FP", 111.18},
	    {"FQ", 64.78},
	    {"FR", 19.64},
	    {"FS", 38.10},
	    {"FT", 23.81},
	    {"FU", 55.74},
	    {"FV", 21.30},
	    {"FW", 46.91},
	    {"FX", 34.34},
	    {"FY", 38.40},
	    {"FZ", 51.29},
	    {"GA", 76.20},
	    {"GB", 21.30},
	    {"GC", 34.34},
	    {"GD", 38.10},
	    {"GE", 46.91},
	    {"GF", 19.05},
	    {"GG", 0},
	    {"GH", 19.05},
	    {"GI", 55.74},
	    {"GJ", 38.10},
	    {"GK", 57.15},
	    {"GL", 76.20},
	    {"GM", 51.29},
	    {"GN", 34.34},
	    {"GO", 73.93},
	    {"GP", 92.47},
	    {"GQ", 83.17},
	    {"GR", 30.49},
	    {"GS", 57.15},
	    {"GT", 19.64},
	    {"GU", 38.40},
	    {"GV", 21.30},
	    {"GW", 64.78},
	    {"GX", 51.29},
	    {"GY", 23.81},
	    {"GZ", 69.34},
	    {"HA", 95.25},
	    {"HB", 21.30},
	    {"HC", 51.29},
	    {"HD", 57.15},
	    {"HE", 64.78},
	    {"HF", 38.10},
	    {"HG", 19.05},
	    {"HH", 0},
	    {"HI", 38.40},
	    {"HJ", 19.05},
	    {"HK", 38.10},
	    {"HL", 57.15},
	    {"HM", 34.34},
	    {"HN", 21.30},
	    {"HO", 55.74},
	    {"HP", 73.93},
	    {"HQ", 101.81},
	    {"HR", 46.91},
	    {"HS", 76.20},
	    {"HT", 30.49},
	    {"HU", 23.81},
	    {"HV", 34.34},
	    {"HW", 83.17},
	    {"HX", 69.34},
	    {"HY", 19.64},
	    {"HZ", 87.82},
	    {"IA", 129.99},
	    {"IB", 57.35},
	    {"IC", 89.48},
	    {"ID", 92.47},
	    {"IE", 95.25},
	    {"IF", 73.93},
	    {"IG", 55.74},
	    {"IH", 38.40},
	    {"II", 0},
	    {"IJ", 23.81},
	    {"IK", 19.64},
	    {"IL", 30.49},
	    {"IM", 38.40},
	    {"IN", 44.93},
	    {"IO", 19.05},
	    {"IP", 38.10},
	    {"IQ", 133.35},
	    {"IR", 76.20},
	    {"IS", 111.18},
	    {"IT", 57.15},
	    {"IU", 19.05},
	    {"IV", 72.70},
	    {"IW", 114.30},
	    {"IX", 107.02},
	    {"IY", 38.10},
	    {"IZ", 125.01},
	    {"JA", 114.30},
	    {"JB", 34.34},
	    {"JC", 69.34},
	    {"JD", 76.20},
	    {"JE", 83.17},
	    {"JF", 57.15},
	    {"JG", 38.10},
	    {"JH", 19.05},
	    {"JI", 23.81},
	    {"JJ", 0},
	    {"JK", 19.05},
	    {"JL", 38.10},
	    {"JM", 21.30},
	    {"JN", 21.30},
	    {"JO", 38.40},
	    {"JP", 55.74},
	    {"JQ", 120.58},
	    {"JR", 64.78},
	    {"JS", 95.25},
	    {"JT", 46.91},
	    {"JU", 19.64},
	    {"JV", 51.29},
	    {"JW", 101.81},
	    {"JX", 87.82},
	    {"JY", 30.49},
	    {"JZ", 106.49},
	    {"KA", 133.35},
	    {"KB", 51.29},
	    {"KC", 87.82},
	    {"KD", 95.25},
	    {"KE", 101.81},
	    {"KF", 76.20},
	    {"KG", 57.15},
	    {"KH", 38.10},
	    {"KI", 19.64},
	    {"KJ", 19.05},
	    {"KK", 0},
	    {"KL", 19.05},
	    {"KM", 21.30},
	    {"KN", 34.34},
	    {"KO", 23.81},
	    {"KP", 38.40},
	    {"KQ", 139.42},
	    {"KR", 83.17},
	    {"KS", 114.30},
	    {"KT", 64.78},
	    {"KU", 30.49},
	    {"KV", 69.34},
	    {"KW", 120.58},
	    {"KX", 106.49},
	    {"KY", 46.91},
	    {"KZ", 125.28},
	    {"LA", 152.40},
	    {"LB", 69.34},
	    {"LC", 106.49},
	    {"LD", 114.30},
	    {"LE", 120.58},
	    {"LF", 95.25},
	    {"LG", 76.20},
	    {"LH", 57.15},
	    {"LI", 30.49},
	    {"LJ", 38.10},
	    {"LK", 19.05},
	    {"LL", 0},
	    {"LM", 34.34},
	    {"LN", 51.29},
	    {"LO", 19.64},
	    {"LP", 23.81},
	    {"LQ", 158.31},
	    {"LR", 101.81},
	    {"LS", 133.35},
	    {"LT", 83.17},
	    {"LU", 46.91},
	    {"LV", 87.82},
	    {"LW", 139.42},
	    {"LX", 125.28},
	    {"LY", 64.78},
	    {"LZ", 144.14},
	    {"MA", 125.28},
	    {"MB", 38.10},
	    {"MC", 76.20},
	    {"MD", 87.82},
	    {"ME", 98.18},
	    {"MF", 69.34},
	    {"MG", 51.29},
	    {"MH", 34.34},
	    {"MI", 38.40},
	    {"MJ", 21.30},
	    {"MK", 21.30},
	    {"ML", 34.34},
	    {"MM", 0},
	    {"MN", 19.05},
	    {"MO", 44.93},
	    {"MP", 57.35},
	    {"MQ", 134.11},
	    {"MR", 80.96},
	    {"MS", 106.49},
	    {"MT", 64.78},
	    {"MU", 40.69},
	    {"MV", 57.15},
	    {"MW", 115.97},
	    {"MX", 95.25},
	    {"MY", 50.63},
	    {"MZ", 114.30},
	    {"NA", 106.49},
	    {"NB", 19.05},
	    {"NC", 57.15},
	    {"ND", 69.34},
	    {"NE", 80.96},
	    {"NF", 51.29},
	    {"NG", 34.34},
	    {"NH", 21.30},
	    {"NI", 44.93},
	    {"NJ", 21.30},
	    {"NK", 34.34},
	    {"NL", 51.29},
	    {"NM", 19.05},
	    {"NN", 0},
	    {"NO", 57.35},
	    {"NP", 72.70},
	    {"NQ", 115.97},
	    {"NR", 64.78},
	    {"NS", 87.82},
	    {"NT", 50.63},
	    {"NU", 38.40},
	    {"NV", 38.10},
	    {"NW", 98.18},
	    {"NX", 76.20},
	    {"NY", 40.69},
	    {"NZ", 95.25},
	    {"OA", 148.86},
	    {"OB", 72.70},
	    {"OC", 107.02},
	    {"OD", 111.18},
	    {"OE", 114.30},
	    {"OF", 92.47},
	    {"OG", 73.93},
	    {"OH", 55.74},
	    {"OI", 19.05},
	    {"OJ", 38.40},
	    {"OK", 23.81},
	    {"OL", 19.64},
	    {"OM", 44.93},
	    {"ON", 57.35},
	    {"OO", 0},
	    {"OP", 19.05},
	    {"OQ", 152.40},
	    {"OR", 95.25},
	    {"OS", 129.99},
	    {"OT", 76.20},
	    {"OU", 38.10},
	    {"OV", 89.48},
	    {"OW", 133.35},
	    {"OX", 125.01},
	    {"OY", 57.15},
	    {"OZ", 143.27},
	    {"PA", 167.77},
	    {"PB", 89.48},
	    {"PC", 125.01},
	    {"PD", 129.99},
	    {"PE", 133.35},
	    {"PF", 111.18},
	    {"PG", 92.47},
	    {"PH", 73.93},
	    {"PI", 38.10},
	    {"PJ", 55.74},
	    {"PK", 38.40},
	    {"PL", 23.81},
	    {"PM", 57.35},
	    {"PN", 72.70},
	    {"PO", 19.05},
	    {"PP", 0},
	    {"PQ", 171.45},
	    {"PR", 114.30},
	    {"PS", 148.86},
	    {"PT", 95.25},
	    {"PU", 57.15},
	    {"PV", 107.02},
	    {"PW", 152.40},
	    {"PX", 143.27},
	    {"PY", 76.20},
	    {"PZ", 161.71},
	    {"QA", 19.64},
	    {"QB", 98.18},
	    {"QC", 64.78},
	    {"QD", 46.91},
	    {"QE", 38.10},
	    {"QF", 64.78},
	    {"QG", 83.17},
	    {"QH", 101.81},
	    {"QI", 133.35},
	    {"QJ", 120.58},
	    {"QK", 139.42},
	    {"QL", 158.31},
	    {"QM", 134.11},
	    {"QN", 115.97},
	    {"QO", 152.40},
	    {"QP", 171.45},
	    {"QQ", 0},
	    {"QR", 57.15},
	    {"QS", 30.49},
	    {"QT", 76.20},
	    {"QU", 114.30},
	    {"QV", 80.96},
	    {"QW", 19.05},
	    {"QX", 50.63},
	    {"QY", 95.25},
	    {"QZ", 40.69},
	    {"RA", 55.74},
	    {"RB", 50.63},
	    {"RC", 38.40},
	    {"RD", 23.81},
	    {"RE", 19.05},
	    {"RF", 19.64},
	    {"RG", 30.49},
	    {"RH", 46.91},
	    {"RI", 76.20},
	    {"RJ", 64.78},
	    {"RK", 83.17},
	    {"RL", 101.81},
	    {"RM", 80.96},
	    {"RN", 64.78},
	    {"RO", 95.25},
	    {"RP", 114.30},
	    {"RQ", 57.15},
	    {"RR", 0},
	    {"RS", 38.40},
	    {"RT", 19.05},
	    {"RU", 57.15},
	    {"RV", 40.69},
	    {"RW", 38.10},
	    {"RX", 44.93},
	    {"RY", 38.10},
	    {"RZ", 57.35},
	    {"SA", 19.05},
	    {"SB", 69.34},
	    {"SC", 34.34},
	    {"SD", 19.05},
	    {"SE", 23.81},
	    {"SF", 38.10},
	    {"SG", 57.15},
	    {"SH", 76.20},
	    {"SI", 111.18},
	    {"SJ", 95.25},
	    {"SK", 114.30},
	    {"SL", 133.35},
	    {"SM", 106.49},
	    {"SN", 87.82},
	    {"SO", 129.99},
	    {"SP", 148.86},
	    {"SQ", 30.49},
	    {"SR", 38.40},
	    {"SS", 0},
	    {"ST", 55.74},
	    {"SU", 92.47},
	    {"SV", 51.29},
	    {"SW", 19.64},
	    {"SX", 21.30},
	    {"SY", 73.93},
	    {"SZ", 21.30},
	    {"TA", 73.93},
	    {"TB", 40.69},
	    {"TC", 44.93},
	    {"TD", 38.40},
	    {"TE", 38.10},
	    {"TF", 23.81},
	    {"TG", 19.64},
	    {"TH", 30.49},
	    {"TI", 57.15},
	    {"TJ", 46.91},
	    {"TK", 64.78},
	    {"TL", 83.17},
	    {"TM", 64.78},
	    {"TN", 50.63},
	    {"TO", 76.20},
	    {"TP", 95.25},
	    {"TQ", 76.20},
	    {"TR", 19.05},
	    {"TS", 55.74},
	    {"TT", 0},
	    {"TU", 38.10},
	    {"TV", 38.40},
	    {"TW", 57.15},
	    {"TX", 57.35},
	    {"TY", 19.05},
	    {"TZ", 72.70},
	    {"UA", 111.18},
	    {"UB", 44.93},
	    {"UC", 72.70},
	    {"UD", 73.93},
	    {"UE", 76.20},
	    {"UF", 55.74},
	    {"UG", 38.40},
	    {"UH", 23.81},
	    {"UI", 19.05},
	    {"UJ", 19.64},
	    {"UK", 30.49},
	    {"UL", 46.91},
	    {"UM", 40.69},
	    {"UN", 38.40},
	    {"UO", 38.10},
	    {"UP", 57.15},
	    {"UQ", 114.30},
	    {"UR", 57.15},
	    {"US", 92.47},
	    {"UT", 38.10},
	    {"UU", 0},
	    {"UV", 57.35},
	    {"UW", 95.25},
	    {"UX", 89.48},
	    {"UY", 19.05},
	    {"UZ", 107.02},
	    {"VA", 69.34},
	    {"VB", 19.05},
	    {"VC", 19.05},
	    {"VD", 34.34},
	    {"VE", 50.63},
	    {"VF", 21.30},
	    {"VG", 21.30},
	    {"VH", 34.34},
	    {"VI", 72.70},
	    {"VJ", 51.29},
	    {"VK", 69.34},
	    {"VL", 87.82},
	    {"VM", 57.15},
	    {"VN", 38.10},
	    {"VO", 89.48},
	    {"VP", 107.02},
	    {"VQ", 80.96},
	    {"VR", 40.69},
	    {"VS", 51.29},
	    {"VT", 38.40},
	    {"VU", 57.35},
	    {"VV", 0},
	    {"VW", 64.78},
	    {"VX", 38.10},
	    {"VY", 44.93},
	    {"VZ", 57.15},
	    {"WA", 23.81},
	    {"WB", 80.96},
	    {"WC", 50.63},
	    {"WD", 30.49},
	    {"WE", 19.05},
	    {"WF", 46.91},
	    {"WG", 64.78},
	    {"WH", 83.17},
	    {"WI", 114.30},
	    {"WJ", 101.81},
	    {"WK", 120.58},
	    {"WL", 139.42},
	    {"WM", 115.97},
	    {"WN", 98.18},
	    {"WO", 133.35},
	    {"WP", 152.40},
	    {"WQ", 19.05},
	    {"WR", 38.10},
	    {"WS", 19.64},
	    {"WT", 57.15},
	    {"WU", 95.25},
	    {"WV", 64.78},
	    {"WW", 0},
	    {"WX", 40.69},
	    {"WY", 76.20},
	    {"WZ", 38.40},
	    {"XA", 34.34},
	    {"XB", 57.15},
	    {"XC", 19.05},
	    {"XD", 21.30},
	    {"XE", 38.40},
	    {"XF", 34.34},
	    {"XG", 51.29},
	    {"XH", 69.34},
	    {"XI", 107.02},
	    {"XJ", 87.82},
	    {"XK", 106.49},
	    {"XL", 125.28},
	    {"XM", 95.25},
	    {"XN", 76.20},
	    {"XO", 125.01},
	    {"XP", 143.27},
	    {"XQ", 50.63},
	    {"XR", 44.93},
	    {"XS", 21.30},
	    {"XT", 57.35},
	    {"XU", 89.48},
	    {"XV", 38.10},
	    {"XW", 40.69},
	    {"XX", 0},
	    {"XY", 72.70},
	    {"XZ", 19.05},
	    {"YA", 92.47},
	    {"YB", 38.40},
	    {"YC", 57.35},
	    {"YD", 55.74},
	    {"YE", 57.15},
	    {"YF", 38.40},
	    {"YG", 23.81},
	    {"YH", 19.64},
	    {"YI", 38.10},
	    {"YJ", 30.49},
	    {"YK", 46.91},
	    {"YL", 64.78},
	    {"YM", 50.63},
	    {"YN", 40.69},
	    {"YO", 57.15},
	    {"YP", 76.20},
	    {"YQ", 95.25},
	    {"YR", 38.10},
	    {"YS", 73.93},
	    {"YT", 19.05},
	    {"YU", 19.05},
	    {"YV", 44.93},
	    {"YW", 76.20},
	    {"YX", 72.70},
	    {"YY", 0},
	    {"YZ", 89.48},
	    {"ZA", 21.30},
	    {"ZB", 76.20},
	    {"ZC", 38.10},
	    {"ZD", 34.34},
	    {"ZE", 44.93},
	    {"ZF", 51.29},
	    {"ZG", 69.34},
	    {"ZH", 87.82},
	    {"ZI", 125.01},
	    {"ZJ", 106.49},
	    {"ZK", 125.28},
	    {"ZL", 144.14},
	    {"ZM", 114.30},
	    {"ZN", 95.25},
	    {"ZO", 143.27},
	    {"ZP", 161.71},
	    {"ZQ", 40.69},
	    {"ZR", 57.35},
	    {"ZS", 21.30},
	    {"ZT", 72.70},
	    {"ZU", 107.02},
	    {"ZV", 57.15},
	    {"ZW", 38.40},
	    {"ZX", 19.05},
	    {"ZY", 89.48},
	    {"ZZ", 0},
	};

	Keypair k, *p;

	memset(&k, 0, sizeof(k));
	k.pair[0] = a;
	k.pair[1] = b;

	p = bsearch(&k, tab, nelem(tab), sizeof(*tab), cmp);
	if (!p)
		return -1;
	return p->distance;
}

int
main(void)
{
	assert(keydistance('A', 'B') == 87.82);
	assert(keydistance('B', 'Q') == 98.18);
	assert(keydistance('G', 'C') == 34.34);
	assert(keydistance('H', 'J') == 19.05);
	assert(keydistance('L', 'J') == 38.10);
	assert(keydistance('P', 'X') == 143.27);
	assert(keydistance('Y', 'Y') == 0);
	assert(keydistance('4', 'K') == -1);

	return 0;
}
