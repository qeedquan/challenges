/*

Given one of the 50 U.S. state names on the left as input, output its two-letter postal code as shown to the right:

Alabama         AL
Alaska          AK
Arizona         AZ
Arkansas        AR
California      CA
Colorado        CO
Connecticut     CT
Delaware        DE
Florida         FL
Georgia         GA
Hawaii          HI
Idaho           ID
Illinois        IL
Indiana         IN
Iowa            IA
Kansas          KS
Kentucky        KY
Louisiana       LA
Maine           ME
Maryland        MD
Massachusetts   MA
Michigan        MI
Minnesota       MN
Mississippi     MS
Missouri        MO
Montana         MT
Nebraska        NE
Nevada          NV
New Hampshire   NH
New Jersey      NJ
New Mexico      NM
New York        NY
North Carolina  NC
North Dakota    ND
Ohio            OH
Oklahoma        OK
Oregon          OR
Pennsylvania    PA
Rhode Island    RI
South Carolina  SC
South Dakota    SD
Tennessee       TN
Texas           TX
Utah            UT
Vermont         VT
Virginia        VA
Washington      WA
West Virginia   WV
Wisconsin       WI
Wyoming         WY

Rules
Input and output are both case sensitive. You many not output e.g. Al for Alabama.
You may assume the input is one of the 50 state names shown above.
You may not access the internet or use built-in state data (looking at you, Mathematica).
Separate lists of inputs and outputs can be found in this snippet (please don't run it, it's just for compressing the post):

Show code snippet

(Non-scoring) Brownie points if you can also take District of Columbia as input and produce DC, Virgin Islands, etc etc.

Scoring
This is code-golf, so the shortest code in bytes in each language wins.

(Originally proposed by ETHProductions)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *state, const void *states)
{
	const char *const *record;

	record = states;
	return strcmp(state, record[0]);
}

const char *
abbreviate(const char *state)
{
	static const char *states[][2] = {
	    {"Alabama", "AL"},
	    {"Alaska", "AK"},
	    {"Arizona", "AZ"},
	    {"Arkansas", "AR"},
	    {"California", "CA"},
	    {"Colorado", "CO"},
	    {"Connecticut", "CT"},
	    {"Delaware", "DE"},
	    {"Florida", "FL"},
	    {"Georgia", "GA"},
	    {"Hawaii", "HI"},
	    {"Idaho", "ID"},
	    {"Illinois", "IL"},
	    {"Indiana", "IN"},
	    {"Iowa", "IA"},
	    {"Kansas", "KS"},
	    {"Kentucky", "KY"},
	    {"Louisiana", "LA"},
	    {"Maine", "ME"},
	    {"Maryland", "MD"},
	    {"Massachusetts", "MA"},
	    {"Michigan", "MI"},
	    {"Minnesota", "MN"},
	    {"Mississippi", "MS"},
	    {"Missouri", "MO"},
	    {"Montana", "MT"},
	    {"Nebraska", "NE"},
	    {"Nevada", "NV"},
	    {"New Hampshire", "NH"},
	    {"New Jersey", "NJ"},
	    {"New Mexico", "NM"},
	    {"New York", "NY"},
	    {"North Carolina", "NC"},
	    {"North Dakota", "ND"},
	    {"Ohio", "OH"},
	    {"Oklahoma", "OK"},
	    {"Oregon", "OR"},
	    {"Pennsylvania", "PA"},
	    {"Rhode Island", "RI"},
	    {"South Carolina", "SC"},
	    {"South Dakota", "SD"},
	    {"Tennessee", "TN"},
	    {"Texas", "TX"},
	    {"Utah", "UT"},
	    {"Vermont", "VT"},
	    {"Virginia", "VA"},
	    {"Washington", "WA"},
	    {"West Virginia", "WV"},
	    {"Wisconsin", "WI"},
	    {"Wyoming", "WY"},
	};

	const char **result;

	result = bsearch(state, states, nelem(states), sizeof(*states), cmp);
	if (!result)
		return NULL;
	return result[1];
}

int
main()
{
	printf("%s\n", abbreviate("Florida"));
	printf("%s\n", abbreviate("West Virginia"));
	printf("%s\n", abbreviate("Wyoming"));
	printf("%s\n", abbreviate("Alabama"));
	printf("%s\n", abbreviate("Colorado"));
	printf("%s\n", abbreviate("Washington"));
	printf("%s\n", abbreviate("Rhode Island"));

	return 0;
}
