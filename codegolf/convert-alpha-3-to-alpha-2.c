/*

I've been developing some programs involving me fetching a vector from a url using Alpha-2 country codes (such as GET /jp.svg for Japan). Except, oh no! All the country data on my computer uses Alpha-3! That just won't do...

The task is simple: Take an Alpha-3 country code (e.g. UKR) and return its Alpha-2 equivalent (e.g. UA). And because my hard drive is smaller than the Vatican (and because this is code-golf), the program must be as small as possible.

Codes can be found here
and below.

[["AFG", "AF"],["ALA", "AX"],["ALB", "AL"],["DZA", "DZ"],["ASM", "AS"],["AND", "AD"],["AGO", "AO"],["AIA", "AI"],["ATA", "AQ"],["ATG", "AG"],["ARG", "AR"],["ARM", "AM"],["ABW", "AW"],["AUS", "AU"],["AUT", "AT"],["AZE", "AZ"],["BHS", "BS"],["BHR", "BH"],["BGD", "BD"],["BRB", "BB"],["BLR", "BY"],["BEL", "BE"],["BLZ", "BZ"],["BEN", "BJ"],["BMU", "BM"],["BTN", "BT"],["BOL", "BO"],["BIH", "BA"],["BWA", "BW"],["BVT", "BV"],["BRA", "BR"],["VGB", "VG"],["IOT", "IO"],["BRN", "BN"],["BGR", "BG"],["BFA", "BF"],["BDI", "BI"],["KHM", "KH"],["CMR", "CM"],["CAN", "CA"],["CPV", "CV"],["CYM", "KY"],["CAF", "CF"],["TCD", "TD"],["CHL", "CL"],["CHN", "CN"],["HKG", "HK"],["MAC", "MO"],["CXR", "CX"],["CCK", "CC"],["COL", "CO"],["COM", "KM"],["COG", "CG"],["COD", "CD"],["COK", "CK"],["CRI", "CR"],["CIV", "CI"],["HRV", "HR"],["CUB", "CU"],["CYP", "CY"],["CZE", "CZ"],["DNK", "DK"],["DJI", "DJ"],["DMA", "DM"],["DOM", "DO"],["ECU", "EC"],["EGY", "EG"],["SLV", "SV"],["GNQ", "GQ"],["ERI", "ER"],["EST", "EE"],["ETH", "ET"],["FLK", "FK"],["FRO", "FO"],["FJI", "FJ"],["FIN", "FI"],["FRA", "FR"],["GUF", "GF"],["PYF", "PF"],["ATF", "TF"],["GAB", "GA"],["GMB", "GM"],["GEO", "GE"],["DEU", "DE"],["GHA", "GH"],["GIB", "GI"],["GRC", "GR"],["GRL", "GL"],["GRD", "GD"],["GLP", "GP"],["GUM", "GU"],["GTM", "GT"],["GGY", "GG"],["GIN", "GN"],["GNB", "GW"],["GUY", "GY"],["HTI", "HT"],["HMD", "HM"],["VAT", "VA"],["HND", "HN"],["HUN", "HU"],["ISL", "IS"],["IND", "IN"],["IDN", "ID"],["IRN", "IR"],["IRQ", "IQ"],["IRL", "IE"],["IMN", "IM"],["ISR", "IL"],["ITA", "IT"],["JAM", "JM"],["JPN", "JP"],["JEY", "JE"],["JOR", "JO"],["KAZ", "KZ"],["KEN", "KE"],["KIR", "KI"],["PRK", "KP"],["KOR", "KR"],["KWT", "KW"],["KGZ", "KG"],["LAO", "LA"],["LVA", "LV"],["LBN", "LB"],["LSO", "LS"],["LBR", "LR"],["LBY", "LY"],["LIE", "LI"],["LTU", "LT"],["LUX", "LU"],["MKD", "MK"],["MDG", "MG"],["MWI", "MW"],["MYS", "MY"],["MDV", "MV"],["MLI", "ML"],["MLT", "MT"],["MHL", "MH"],["MTQ", "MQ"],["MRT", "MR"],["MUS", "MU"],["MYT", "YT"],["MEX", "MX"],["FSM", "FM"],["MDA", "MD"],["MCO", "MC"],["MNG", "MN"],["MNE", "ME"],["MSR", "MS"],["MAR", "MA"],["MOZ", "MZ"],["MMR", "MM"],["NAM", "NA"],["NRU", "NR"],["NPL", "NP"],["NLD", "NL"],["ANT", "AN"],["NCL", "NC"],["NZL", "NZ"],["NIC", "NI"],["NER", "NE"],["NGA", "NG"],["NIU", "NU"],["NFK", "NF"],["MNP", "MP"],["NOR", "NO"],["OMN", "OM"],["PAK", "PK"],["PLW", "PW"],["PSE", "PS"],["PAN", "PA"],["PNG", "PG"],["PRY", "PY"],["PER", "PE"],["PHL", "PH"],["PCN", "PN"],["POL", "PL"],["PRT", "PT"],["PRI", "PR"],["QAT", "QA"],["REU", "RE"],["ROU", "RO"],["RUS", "RU"],["RWA", "RW"],["BLM", "BL"],["SHN", "SH"],["KNA", "KN"],["LCA", "LC"],["MAF", "MF"],["SPM", "PM"],["VCT", "VC"],["WSM", "WS"],["SMR", "SM"],["STP", "ST"],["SAU", "SA"],["SEN", "SN"],["SRB", "RS"],["SYC", "SC"],["SLE", "SL"],["SGP", "SG"],["SVK", "SK"],["SVN", "SI"],["SLB", "SB"],["SOM", "SO"],["ZAF", "ZA"],["SGS", "GS"],["SSD", "SS"],["ESP", "ES"],["LKA", "LK"],["SDN", "SD"],["SUR", "SR"],["SJM", "SJ"],["SWZ", "SZ"],["SWE", "SE"],["CHE", "CH"],["SYR", "SY"],["TWN", "TW"],["TJK", "TJ"],["TZA", "TZ"],["THA", "TH"],["TLS", "TL"],["TGO", "TG"],["TKL", "TK"],["TON", "TO"],["TTO", "TT"],["TUN", "TN"],["TUR", "TR"],["TKM", "TM"],["TCA", "TC"],["TUV", "TV"],["UGA", "UG"],["UKR", "UA"],["ARE", "AE"],["GBR", "GB"],["USA", "US"],["UMI", "UM"],["URY", "UY"],["UZB", "UZ"],["VUT", "VU"],["VEN", "VE"],["VNM", "VN"],["VIR", "VI"],["WLF", "WF"],["ESH", "EH"],["YEM", "YE"],["ZMB", "ZM"],["ZWE", "ZW"]]

Rules
Your answer must work with all countries and territories
You may not fetch any data from the internet.
Standard loopholes apply.
This is code-golf, so the shortest code in bytes in each language wins.
Input/Output may be a string, list of characters, or list of character codes. Text case does not matter
Test Cases
Countries
USA -> US     # United States
AUS -> AU     # Australia
BIH -> BA     # Bosnia and Herzegovina
ISL -> IS     # Iceland
FSM -> FM     # Micronesia
SYC -> SC     # Seychelles
Territories
UMI -> UM     # US Minor Outlying Islands
SPM -> PM     # Saint Pierre and Miquelon
GUF -> GF     # French Guiana
ATF -> TF     # French Southern Territories
HKG -> HK     # Hong Kong
IOT -> IO     # British Indian Ocean Territory

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
convert(const char *code)
{
	static const char tab[][2][4] = {
	    {"AFG", "AF"},
	    {"ALA", "AX"},
	    {"ALB", "AL"},
	    {"DZA", "DZ"},
	    {"ASM", "AS"},
	    {"AND", "AD"},
	    {"AGO", "AO"},
	    {"AIA", "AI"},
	    {"ATA", "AQ"},
	    {"ATG", "AG"},
	    {"ARG", "AR"},
	    {"ARM", "AM"},
	    {"ABW", "AW"},
	    {"AUS", "AU"},
	    {"AUT", "AT"},
	    {"AZE", "AZ"},
	    {"BHS", "BS"},
	    {"BHR", "BH"},
	    {"BGD", "BD"},
	    {"BRB", "BB"},
	    {"BLR", "BY"},
	    {"BEL", "BE"},
	    {"BLZ", "BZ"},
	    {"BEN", "BJ"},
	    {"BMU", "BM"},
	    {"BTN", "BT"},
	    {"BOL", "BO"},
	    {"BIH", "BA"},
	    {"BWA", "BW"},
	    {"BVT", "BV"},
	    {"BRA", "BR"},
	    {"VGB", "VG"},
	    {"IOT", "IO"},
	    {"BRN", "BN"},
	    {"BGR", "BG"},
	    {"BFA", "BF"},
	    {"BDI", "BI"},
	    {"KHM", "KH"},
	    {"CMR", "CM"},
	    {"CAN", "CA"},
	    {"CPV", "CV"},
	    {"CYM", "KY"},
	    {"CAF", "CF"},
	    {"TCD", "TD"},
	    {"CHL", "CL"},
	    {"CHN", "CN"},
	    {"HKG", "HK"},
	    {"MAC", "MO"},
	    {"CXR", "CX"},
	    {"CCK", "CC"},
	    {"COL", "CO"},
	    {"COM", "KM"},
	    {"COG", "CG"},
	    {"COD", "CD"},
	    {"COK", "CK"},
	    {"CRI", "CR"},
	    {"CIV", "CI"},
	    {"HRV", "HR"},
	    {"CUB", "CU"},
	    {"CYP", "CY"},
	    {"CZE", "CZ"},
	    {"DNK", "DK"},
	    {"DJI", "DJ"},
	    {"DMA", "DM"},
	    {"DOM", "DO"},
	    {"ECU", "EC"},
	    {"EGY", "EG"},
	    {"SLV", "SV"},
	    {"GNQ", "GQ"},
	    {"ERI", "ER"},
	    {"EST", "EE"},
	    {"ETH", "ET"},
	    {"FLK", "FK"},
	    {"FRO", "FO"},
	    {"FJI", "FJ"},
	    {"FIN", "FI"},
	    {"FRA", "FR"},
	    {"GUF", "GF"},
	    {"PYF", "PF"},
	    {"ATF", "TF"},
	    {"GAB", "GA"},
	    {"GMB", "GM"},
	    {"GEO", "GE"},
	    {"DEU", "DE"},
	    {"GHA", "GH"},
	    {"GIB", "GI"},
	    {"GRC", "GR"},
	    {"GRL", "GL"},
	    {"GRD", "GD"},
	    {"GLP", "GP"},
	    {"GUM", "GU"},
	    {"GTM", "GT"},
	    {"GGY", "GG"},
	    {"GIN", "GN"},
	    {"GNB", "GW"},
	    {"GUY", "GY"},
	    {"HTI", "HT"},
	    {"HMD", "HM"},
	    {"VAT", "VA"},
	    {"HND", "HN"},
	    {"HUN", "HU"},
	    {"ISL", "IS"},
	    {"IND", "IN"},
	    {"IDN", "ID"},
	    {"IRN", "IR"},
	    {"IRQ", "IQ"},
	    {"IRL", "IE"},
	    {"IMN", "IM"},
	    {"ISR", "IL"},
	    {"ITA", "IT"},
	    {"JAM", "JM"},
	    {"JPN", "JP"},
	    {"JEY", "JE"},
	    {"JOR", "JO"},
	    {"KAZ", "KZ"},
	    {"KEN", "KE"},
	    {"KIR", "KI"},
	    {"PRK", "KP"},
	    {"KOR", "KR"},
	    {"KWT", "KW"},
	    {"KGZ", "KG"},
	    {"LAO", "LA"},
	    {"LVA", "LV"},
	    {"LBN", "LB"},
	    {"LSO", "LS"},
	    {"LBR", "LR"},
	    {"LBY", "LY"},
	    {"LIE", "LI"},
	    {"LTU", "LT"},
	    {"LUX", "LU"},
	    {"MKD", "MK"},
	    {"MDG", "MG"},
	    {"MWI", "MW"},
	    {"MYS", "MY"},
	    {"MDV", "MV"},
	    {"MLI", "ML"},
	    {"MLT", "MT"},
	    {"MHL", "MH"},
	    {"MTQ", "MQ"},
	    {"MRT", "MR"},
	    {"MUS", "MU"},
	    {"MYT", "YT"},
	    {"MEX", "MX"},
	    {"FSM", "FM"},
	    {"MDA", "MD"},
	    {"MCO", "MC"},
	    {"MNG", "MN"},
	    {"MNE", "ME"},
	    {"MSR", "MS"},
	    {"MAR", "MA"},
	    {"MOZ", "MZ"},
	    {"MMR", "MM"},
	    {"NAM", "NA"},
	    {"NRU", "NR"},
	    {"NPL", "NP"},
	    {"NLD", "NL"},
	    {"ANT", "AN"},
	    {"NCL", "NC"},
	    {"NZL", "NZ"},
	    {"NIC", "NI"},
	    {"NER", "NE"},
	    {"NGA", "NG"},
	    {"NIU", "NU"},
	    {"NFK", "NF"},
	    {"MNP", "MP"},
	    {"NOR", "NO"},
	    {"OMN", "OM"},
	    {"PAK", "PK"},
	    {"PLW", "PW"},
	    {"PSE", "PS"},
	    {"PAN", "PA"},
	    {"PNG", "PG"},
	    {"PRY", "PY"},
	    {"PER", "PE"},
	    {"PHL", "PH"},
	    {"PCN", "PN"},
	    {"POL", "PL"},
	    {"PRT", "PT"},
	    {"PRI", "PR"},
	    {"QAT", "QA"},
	    {"REU", "RE"},
	    {"ROU", "RO"},
	    {"RUS", "RU"},
	    {"RWA", "RW"},
	    {"BLM", "BL"},
	    {"SHN", "SH"},
	    {"KNA", "KN"},
	    {"LCA", "LC"},
	    {"MAF", "MF"},
	    {"SPM", "PM"},
	    {"VCT", "VC"},
	    {"WSM", "WS"},
	    {"SMR", "SM"},
	    {"STP", "ST"},
	    {"SAU", "SA"},
	    {"SEN", "SN"},
	    {"SRB", "RS"},
	    {"SYC", "SC"},
	    {"SLE", "SL"},
	    {"SGP", "SG"},
	    {"SVK", "SK"},
	    {"SVN", "SI"},
	    {"SLB", "SB"},
	    {"SOM", "SO"},
	    {"ZAF", "ZA"},
	    {"SGS", "GS"},
	    {"SSD", "SS"},
	    {"ESP", "ES"},
	    {"LKA", "LK"},
	    {"SDN", "SD"},
	    {"SUR", "SR"},
	    {"SJM", "SJ"},
	    {"SWZ", "SZ"},
	    {"SWE", "SE"},
	    {"CHE", "CH"},
	    {"SYR", "SY"},
	    {"TWN", "TW"},
	    {"TJK", "TJ"},
	    {"TZA", "TZ"},
	    {"THA", "TH"},
	    {"TLS", "TL"},
	    {"TGO", "TG"},
	    {"TKL", "TK"},
	    {"TON", "TO"},
	    {"TTO", "TT"},
	    {"TUN", "TN"},
	    {"TUR", "TR"},
	    {"TKM", "TM"},
	    {"TCA", "TC"},
	    {"TUV", "TV"},
	    {"UGA", "UG"},
	    {"UKR", "UA"},
	    {"ARE", "AE"},
	    {"GBR", "GB"},
	    {"USA", "US"},
	    {"UMI", "UM"},
	    {"URY", "UY"},
	    {"UZB", "UZ"},
	    {"VUT", "VU"},
	    {"VEN", "VE"},
	    {"VNM", "VN"},
	    {"VIR", "VI"},
	    {"WLF", "WF"},
	    {"ESH", "EH"},
	    {"YEM", "YE"},
	    {"ZMB", "ZM"},
	    {"ZWE", "ZW"},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(tab[i][0], code))
			return tab[i][1];
	}
	return NULL;
}

int
main(void)
{
	assert(!strcmp(convert("USA"), "US"));
	assert(!strcmp(convert("AUS"), "AU"));
	assert(!strcmp(convert("BIH"), "BA"));
	assert(!strcmp(convert("ISL"), "IS"));
	assert(!strcmp(convert("FSM"), "FM"));
	assert(!strcmp(convert("SYC"), "SC"));

	assert(!strcmp(convert("UMI"), "UM"));
	assert(!strcmp(convert("SPM"), "PM"));
	assert(!strcmp(convert("GUF"), "GF"));
	assert(!strcmp(convert("ATF"), "TF"));
	assert(!strcmp(convert("HKG"), "HK"));
	assert(!strcmp(convert("IOT"), "IO"));

	return 0;
}
