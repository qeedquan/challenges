/*

Rules
Given an ISO3166-1-Alpha-2 country code your task is to decide on the traffic direction for that country:

Input will be a valid country code (valid as in it's an element of the two lists provided)
Input may be a list of two characters instead of a string if it helps
You may choose to take input in lowercase
You will choose one value, say for right (your choice) and will output that value iff the traffic in that country is right-handed and anything else in the other case
You only have to handle country codes that are contained in one of these lists:
These are all countries where traffic is left-handed:

['AI', 'AG', 'AU', 'BS', 'BD', 'BB', 'BM', 'BT', 'BW', 'VG', 'BN', 'KY', 'CX', 'CC', 'CK', 'CY', 'DM', 'FK', 'FJ', 'GD', 'GG', 'GY', 'HK', 'IN', 'ID', 'IE', 'IM', 'JM', 'JP', 'JE', 'KE', 'KI', 'LS', 'MO', 'MW', 'MY', 'MV', 'MT', 'MU', 'MS', 'MZ', 'NA', 'NR', 'NP', 'NZ', 'NU', 'NF', 'PK', 'PG', 'PN', 'SH', 'KN', 'LC', 'VC', 'WS', 'SC', 'SG', 'SB', 'SO', 'ZA', 'GS', 'LK', 'SR', 'SZ', 'TH', 'TL', 'TK', 'TO', 'TT', 'TC', 'TV', 'UG', 'GB', 'TZ', 'VI', 'ZM', 'ZW']
And here are all countries where traffic is right-handed:

['AF', 'AX', 'AL', 'DZ', 'AS', 'AD', 'AO', 'AQ', 'AR', 'AM', 'AW', 'AT', 'AZ', 'BH', 'BY', 'BE', 'BZ', 'BJ', 'BO', 'BA', 'BV', 'BR', 'IO', 'BG', 'BF', 'BI', 'CV', 'KH', 'CM', 'CA', 'CF', 'TD', 'CL', 'CN', 'CO', 'KM', 'CG', 'CR', 'CI', 'HR', 'CU', 'CW', 'CZ', 'KP', 'CD', 'DK', 'DJ', 'DO', 'EC', 'EG', 'SV', 'GQ', 'ER', 'EE', 'ET', 'FO', 'FI', 'FR', 'GF', 'PF', 'TF', 'GA', 'GM', 'GE', 'DE', 'GH', 'GI', 'GR', 'GL', 'GP', 'GU', 'GT', 'GW', 'GN', 'HT', 'HM', 'VA', 'HN', 'HU', 'IS', 'IR', 'IQ', 'IL', 'IT', 'JO', 'KZ', 'KW', 'KG', 'LA', 'LV', 'LB', 'LR', 'LY', 'LI', 'LT', 'LU', 'MG', 'ML', 'MH', 'MQ', 'MR', 'YT', 'MX', 'FM', 'MC', 'MN', 'ME', 'MA', 'MM', 'NL', 'NC', 'NI', 'NG', 'NE', 'MP', 'NO', 'OM', 'PW', 'PA', 'PY', 'PE', 'PH', 'PL', 'PT', 'PR', 'QA', 'KR', 'MD', 'RE', 'RO', 'RU', 'RW', 'BL', 'MF', 'PM', 'SM', 'ST', 'SA', 'SN', 'RS', 'SL', 'BQ', 'SX', 'SK', 'SI', 'SS', 'ES', 'PS', 'SD', 'SJ', 'SE', 'CH', 'SY', 'TW', 'TJ', 'MK', 'TG', 'TN', 'TR', 'TM', 'UA', 'AE', 'UM', 'US', 'UY', 'UZ', 'VU', 'VE', 'VN', 'WF', 'EH', 'YE']

For completeness sake, here's a CSV file that contains all the values along with the country names.
https://pastebin.com/8Gs3ukHr

Testcases
Assuming you chose to output L for left-handed traffic, here are some valid test cases:

'PY' -> 'python'
'PN' -> 'L'
'CN' -> 33
'GY' -> 'L'
Note: There is a small chance that I missed a country or that there's a wrong classification and I will not change the specs because that might invalidate answers. If I made a mistake I sincerely apologize, please don't take offense!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const char *s, *t;

	s = *(const char **)a;
	t = *(const char **)b;
	return strcmp(s, t);
}

int
direction(const char *s)
{
	static const char *left[] = {
		"AG", "AI", "AU", "BB", "BD", "BM", "BN", "BS",
		"BT", "BW", "CC", "CK", "CX", "CY", "DM", "FJ",
		"FK", "GB", "GD", "GG", "GS", "GY", "HK", "ID",
		"IE", "IM", "IN", "JE", "JM", "JP", "KE", "KI",
		"KN", "KY", "LC", "LK", "LS", "MO", "MS", "MT",
		"MU", "MV", "MW", "MY", "MZ", "NA", "NF", "NP",
		"NR", "NU", "NZ", "PG", "PK", "PN", "SB", "SC",
		"SG", "SH", "SO", "SR", "SZ", "TC", "TH", "TK",
		"TL", "TO", "TT", "TV", "TZ", "UG", "VC", "VG",
		"VI", "WS", "ZA", "ZM", "ZW"
	};

	static const char *right[] = {
		"AD", "AE", "AF", "AL", "AM", "AO", "AQ", "AR", "AS", "AT", "AW", "AX",
		"AZ", "BA", "BE", "BF", "BG", "BH", "BI", "BJ", "BL", "BO", "BQ", "BR",
		"BV", "BY", "BZ", "CA", "CD", "CF", "CG", "CH", "CI", "CL", "CM", "CN",
		"CO", "CR", "CU", "CV", "CW", "CZ", "DE", "DJ", "DK", "DO", "DZ", "EC",
		"EE", "EG", "EH", "ER", "ES", "ET", "FI", "FM", "FO", "FR", "GA", "GE",
		"GF", "GH", "GI", "GL", "GM", "GN", "GP", "GQ", "GR", "GT", "GU", "GW",
		"HM", "HN", "HR", "HT", "HU", "IL", "IO", "IQ", "IR", "IS", "IT", "JO",
		"KG", "KH", "KM", "KP", "KR", "KW", "KZ", "LA", "LB", "LI", "LR", "LT",
		"LU", "LV", "LY", "MA", "MC", "MD", "ME", "MF", "MG", "MH", "MK", "ML",
		"MM", "MN", "MP", "MQ", "MR", "MX", "NC", "NE", "NG", "NI", "NL", "NO",
		"OM", "PA", "PE", "PF", "PH", "PL", "PM", "PR", "PS", "PT", "PW", "PY",
		"QA", "RE", "RO", "RS", "RU", "RW", "SA", "SD", "SE", "SI", "SJ", "SK",
		"SL", "SM", "SN", "SS", "ST", "SV", "SX", "SY", "TD", "TF", "TG", "TJ",
		"TM", "TN", "TR", "TW", "UA", "UM", "US", "UY", "UZ", "VA", "VE", "VN",
		"VU", "WF", "YE", "YT"
	};

	void *p;

	p = bsearch(&s, left, nelem(left), sizeof(*left), cmp);
	if (p)
		return 'L';

	p = bsearch(&s, right, nelem(right), sizeof(*right), cmp);
	if (p)
		return 'R';

	return -1;
}

int
main()
{
	assert(direction("PY") == 'R');
	assert(direction("PN") == 'L');
	assert(direction("CN") == 'R');
	assert(direction("GY") == 'L');

	return 0;
}
