/*

Ah, Tinder . . . the app that takes the code golf approach to online dating. With just a few well-chosen right swipes and a bit of luck (or a cute puppy pic), you too could have more matches than /(?!)/.

This code-golf challenge involves Tinder dates of a very different kind. Given a Tinder version number as input, hook me up with the date on which that version was released. You may use any convenient formats for input and output (e.g. string, list of integers, date object). Refer to this table*:

+-------------+--------------+
| Version no. | Release date |
+-------------+--------------+
|   11.19.0   |  2020-07-10  |
|   11.18.0   |  2020-06-18  |
|   11.17.0   |  2020-06-04  |
|   11.16.0   |  2020-05-26  |
|   11.15.0   |  2020-05-11  |
|   11.14.0   |  2020-04-27  |
|   11.13.0   |  2020-04-13  |
|   11.12.0   |  2020-03-27  |
|   11.11.1   |  2020-03-21  |
|   11.11.0   |  2020-03-20  |
|   11.10.4   |  2020-03-06  |
|   11.10.3   |  2020-03-02  |
|   11.10.2   |  2020-02-29  |
|   11.10.1   |  2020-02-28  |
|   11.9.0    |  2020-02-13  |
|   11.8.0    |  2020-01-30  |
|   11.7.2    |  2020-01-24  |
|   11.7.1    |  2020-01-20  |
|   11.7.0    |  2020-01-19  |
|   11.6.1    |  2020-01-04  |
|   11.6.0    |  2019-12-16  |
|   11.5.0    |  2019-12-06  |
|   11.4.0    |  2019-11-22  |
|   11.3.0    |  2019-11-10  |
|   11.2.1    |  2019-11-01  |
|   11.1.1    |  2019-10-16  |
|   11.1.0    |  2019-10-11  |
|   11.0.2    |  2019-10-09  |
|   11.0.1    |  2019-09-27  |
|   11.0.0    |  2019-09-20  |
|   10.20.0   |  2019-09-10  |
|   10.19.1   |  2019-09-03  |
|   10.19.0   |  2019-08-28  |
|   10.18.0   |  2019-08-15  |
|   10.17.0   |  2019-07-24  |
|   10.16.0   |  2019-06-24  |
|   10.15.1   |  2019-06-08  |
|   10.15.0   |  2019-06-05  |
|   10.14.0   |  2019-06-04  |
|   10.13.0   |  2019-05-16  |
|   10.12.1   |  2019-05-02  |
|   10.12.0   |  2019-04-28  |
|   10.11.0   |  2019-04-13  |
|   10.10.1   |  2019-04-10  |
|   10.10.0   |  2019-04-02  |
|   10.9.1    |  2019-03-23  |
|   10.9.0    |  2019-03-18  |
|   10.8.1    |  2019-03-15  |
|   10.8.0    |  2019-03-06  |
|   10.7.0    |  2019-02-16  |
|   10.6.0    |  2019-02-12  |
|   10.5.0    |  2019-01-22  |
|   10.4.1    |  2019-01-08  |
|   10.4.0    |  2018-12-17  |
|   10.3.0    |  2018-11-29  |
|   10.2.1    |  2018-11-20  |
|   10.2.0    |  2018-11-15  |
|   10.1.1    |  2018-11-02  |
|   10.1.0    |  2018-10-31  |
|   10.0.2    |  2018-10-25  |
|   10.0.1    |  2018-10-19  |
|   10.0.0    |  2018-10-17  |
|    9.9.2    |  2018-10-12  |
|    9.9.1    |  2018-10-11  |
|    9.9.0    |  2018-10-09  |
|    9.8.1    |  2018-10-03  |
|    9.8.0    |  2018-09-21  |
|    9.7.2    |  2018-09-14  |
|    9.7.1    |  2018-09-06  |
|    9.7.0    |  2018-08-29  |
|    9.6.1    |  2018-08-23  |
|    9.6.0    |  2018-08-21  |
|    9.5.0    |  2018-08-06  |
|    9.4.1    |  2018-08-03  |
|    9.4.0    |  2018-07-24  |
|    9.3.0    |  2018-06-22  |
|    9.2.0    |  2018-06-11  |
|    9.1.0    |  2018-05-29  |
|    9.0.1    |  2018-05-17  |
|    9.0.0    |  2018-05-14  |
|    8.13.0   |  2018-05-03  |
|    8.12.1   |  2018-04-28  |
|    8.12.0   |  2018-04-26  |
|    8.11.0   |  2018-04-12  |
|    8.10.0   |  2018-04-05  |
|    8.9.0    |  2018-03-15  |
|    8.8.0    |  2018-02-28  |
|    8.7.0    |  2018-02-16  |
|    8.6.0    |  2018-02-05  |
|    8.5.0    |  2018-01-22  |
|    8.4.1    |  2018-01-02  |
|    8.4.0    |  2017-12-15  |
|    8.3.1    |  2017-12-08  |
|    8.3.0    |  2017-11-29  |
|    8.2.0    |  2017-11-03  |
|    8.1.0    |  2017-10-17  |
|    8.0.1    |  2017-10-09  |
|    8.0.0    |  2017-09-25  |
|    7.8.1    |  2017-09-08  |
|    7.8.0    |  2017-09-05  |
|    7.7.2    |  2017-08-23  |
|    7.7.1    |  2017-08-15  |
|    7.7.0    |  2017-08-14  |
|    7.6.1    |  2017-07-24  |
|    7.6.0    |  2017-07-14  |
|    7.5.3    |  2017-06-22  |
|    7.5.2    |  2017-06-09  |
|    7.5.1    |  2017-06-02  |
|    7.5.0    |  2017-05-30  |
|    7.4.1    |  2017-05-17  |
|    7.4.0    |  2017-05-09  |
|    7.3.1    |  2017-04-19  |
|    7.3.0    |  2017-04-13  |
|    7.2.2    |  2017-04-03  |
|    7.2.1    |  2017-04-01  |
|    7.2.0    |  2017-03-30  |
|    7.1.1    |  2017-03-16  |
|    7.1.0    |  2017-03-06  |
|    7.0.1    |  2017-02-19  |
|    7.0.0    |  2017-02-16  |
|    6.9.4    |  2017-02-06  |
|    6.9.3    |  2017-01-27  |
|    6.9.2    |  2017-01-25  |
|    6.9.1    |  2017-01-17  |
|    6.9.0    |  2017-01-12  |
|    6.8.1    |  2017-01-03  |
|    6.8.0    |  2016-12-19  |
|    6.7.0    |  2016-11-30  |
|    6.6.1    |  2016-11-18  |
|    6.6.0    |  2016-11-16  |
|    6.5.0    |  2016-11-07  |
|    6.4.1    |  2016-11-01  |
|    6.4.0    |  2016-10-26  |
|    6.3.2    |  2016-10-19  |
|    6.3.1    |  2016-10-12  |
|    6.3.0    |  2016-10-04  |
|    6.2.0    |  2016-09-27  |
|    6.1.0    |  2016-09-20  |
|    5.5.3    |  2016-09-12  |
|    5.5.2    |  2016-09-08  |
|    5.5.1    |  2016-09-03  |
|    5.5.0    |  2016-08-31  |
|    5.4.1    |  2016-08-25  |
|    5.4.0    |  2016-08-18  |
|    5.3.2    |  2016-07-29  |
|    5.3.1    |  2016-07-21  |
|    5.3.0    |  2016-07-19  |
|    5.2.0    |  2016-06-27  |
|    5.1.1    |  2016-06-07  |
|    5.1.0    |  2016-06-06  |
|    5.0.2    |  2016-05-13  |
|    5.0.1    |  2016-04-29  |
|    5.0.0    |  2016-04-21  |
|    4.8.2    |  2016-03-02  |
|    4.8.1    |  2016-01-30  |
|    4.8.0    |  2016-01-27  |
|    4.7.2    |  2015-12-17  |
|    4.7.1    |  2015-11-13  |
|    4.7.0    |  2015-11-11  |
|    4.6.1    |  2015-09-23  |
|    4.6.0    |  2015-09-04  |
|    4.5.0    |  2015-07-07  |
|    4.4.6    |  2015-05-18  |
|    4.4.5    |  2015-05-12  |
|    4.4.4    |  2015-05-05  |
|    4.4.3    |  2015-04-28  |
|    4.4.1    |  2015-04-16  |
|    4.4.0    |  2015-04-15  |
|    4.3.0    |  2015-03-02  |
|    4.1.4    |  2015-02-13  |
|    4.1.3    |  2015-02-06  |
|    4.1.1    |  2015-02-02  |
|    4.0.9    |  2014-10-09  |
|    4.0.8    |  2014-09-27  |
|    4.0.7    |  2014-09-19  |
|    4.0.6    |  2014-09-18  |
|    4.0.4    |  2014-07-17  |
|    4.0.3    |  2014-06-26  |
|    4.0.2    |  2014-06-17  |
|    4.0.1    |  2014-06-06  |
|    4.0.0    |  2014-06-05  |
|    3.0.4    |  2014-03-12  |
|    3.0.3    |  2014-02-26  |
|    3.0.2    |  2013-12-19  |
|    3.0.1    |  2013-11-28  |
|    3.0.0    |  2013-11-21  |
|    2.2.3    |  2013-11-20  |
|    2.2.2    |  2013-09-25  |
|    2.2.1    |  2013-09-24  |
|    2.2.0    |  2013-09-14  |
|    2.1.1    |  2013-06-07  |
|    2.1.0    |  2013-05-23  |
|    2.0.3    |  2013-04-01  |
|    2.0.2    |  2013-03-29  |
|    2.0.1    |  2013-03-28  |
|    1.1.4    |  2013-02-08  |
|    1.1.3    |  2013-02-06  |
|    1.1.2    |  2013-01-21  |
|    1.1.1    |  2013-01-11  |
|    1.1.0    |  2013-01-08  |
|    1.0.6    |  2012-11-24  |
|    1.0.5    |  2012-11-16  |
|    1.0.4    |  2012-11-06  |
|    1.0.3    |  2012-09-20  |
|    1.0.2    |  2012-08-29  |
|    1.0.1    |  2012-08-15  |
|    1.0.0    |  2012-08-03  |
+-------------+--------------+

*Source, with four modifications to unify the version number format (1.03 → 1.0.3, 4.3 → 4.3.0, 4.4 → 4.4.0, iOS 8.4.0 → 8.4.0).

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const char *const *p;
	const char *s;
	int v[3], V[3];
	size_t i;

	s = a;
	p = b;

	if (sscanf(s, "%d.%d.%d", v, v + 1, v + 2) != 3)
		return -1;
	sscanf(p[0], "%d.%d.%d", V, V + 1, V + 2);

	for (i = 0; i < nelem(v); i++) {
		if (v[i] < V[i])
			return 1;
		if (v[i] > V[i])
			return -1;
	}
	return 0;
}

const char *
lookup(const char *s)
{
	static const char *tab[][2] = {
	    {"11.19.0", "2020-07-10"},
	    {"11.18.0", "2020-06-18"},
	    {"11.17.0", "2020-06-04"},
	    {"11.16.0", "2020-05-26"},
	    {"11.15.0", "2020-05-11"},
	    {"11.14.0", "2020-04-27"},
	    {"11.13.0", "2020-04-13"},
	    {"11.12.0", "2020-03-27"},
	    {"11.11.1", "2020-03-21"},
	    {"11.11.0", "2020-03-20"},
	    {"11.10.4", "2020-03-06"},
	    {"11.10.3", "2020-03-02"},
	    {"11.10.2", "2020-02-29"},
	    {"11.10.1", "2020-02-28"},
	    {"11.9.0", "2020-02-13"},
	    {"11.8.0", "2020-01-30"},
	    {"11.7.2", "2020-01-24"},
	    {"11.7.1", "2020-01-20"},
	    {"11.7.0", "2020-01-19"},
	    {"11.6.1", "2020-01-04"},
	    {"11.6.0", "2019-12-16"},
	    {"11.5.0", "2019-12-06"},
	    {"11.4.0", "2019-11-22"},
	    {"11.3.0", "2019-11-10"},
	    {"11.2.1", "2019-11-01"},
	    {"11.1.1", "2019-10-16"},
	    {"11.1.0", "2019-10-11"},
	    {"11.0.2", "2019-10-09"},
	    {"11.0.1", "2019-09-27"},
	    {"11.0.0", "2019-09-20"},
	    {"10.20.0", "2019-09-10"},
	    {"10.19.1", "2019-09-03"},
	    {"10.19.0", "2019-08-28"},
	    {"10.18.0", "2019-08-15"},
	    {"10.17.0", "2019-07-24"},
	    {"10.16.0", "2019-06-24"},
	    {"10.15.1", "2019-06-08"},
	    {"10.15.0", "2019-06-05"},
	    {"10.14.0", "2019-06-04"},
	    {"10.13.0", "2019-05-16"},
	    {"10.12.1", "2019-05-02"},
	    {"10.12.0", "2019-04-28"},
	    {"10.11.0", "2019-04-13"},
	    {"10.10.1", "2019-04-10"},
	    {"10.10.0", "2019-04-02"},
	    {"10.9.1", "2019-03-23"},
	    {"10.9.0", "2019-03-18"},
	    {"10.8.1", "2019-03-15"},
	    {"10.8.0", "2019-03-06"},
	    {"10.7.0", "2019-02-16"},
	    {"10.6.0", "2019-02-12"},
	    {"10.5.0", "2019-01-22"},
	    {"10.4.1", "2019-01-08"},
	    {"10.4.0", "2018-12-17"},
	    {"10.3.0", "2018-11-29"},
	    {"10.2.1", "2018-11-20"},
	    {"10.2.0", "2018-11-15"},
	    {"10.1.1", "2018-11-02"},
	    {"10.1.0", "2018-10-31"},
	    {"10.0.2", "2018-10-25"},
	    {"10.0.1", "2018-10-19"},
	    {"10.0.0", "2018-10-17"},
	    {"9.9.2", "2018-10-12"},
	    {"9.9.1", "2018-10-11"},
	    {"9.9.0", "2018-10-09"},
	    {"9.8.1", "2018-10-03"},
	    {"9.8.0", "2018-09-21"},
	    {"9.7.2", "2018-09-14"},
	    {"9.7.1", "2018-09-06"},
	    {"9.7.0", "2018-08-29"},
	    {"9.6.1", "2018-08-23"},
	    {"9.6.0", "2018-08-21"},
	    {"9.5.0", "2018-08-06"},
	    {"9.4.1", "2018-08-03"},
	    {"9.4.0", "2018-07-24"},
	    {"9.3.0", "2018-06-22"},
	    {"9.2.0", "2018-06-11"},
	    {"9.1.0", "2018-05-29"},
	    {"9.0.1", "2018-05-17"},
	    {"9.0.0", "2018-05-14"},
	    {"8.13.0", "2018-05-03"},
	    {"8.12.1", "2018-04-28"},
	    {"8.12.0", "2018-04-26"},
	    {"8.11.0", "2018-04-12"},
	    {"8.10.0", "2018-04-05"},
	    {"8.9.0", "2018-03-15"},
	    {"8.8.0", "2018-02-28"},
	    {"8.7.0", "2018-02-16"},
	    {"8.6.0", "2018-02-05"},
	    {"8.5.0", "2018-01-22"},
	    {"8.4.1", "2018-01-02"},
	    {"8.4.0", "2017-12-15"},
	    {"8.3.1", "2017-12-08"},
	    {"8.3.0", "2017-11-29"},
	    {"8.2.0", "2017-11-03"},
	    {"8.1.0", "2017-10-17"},
	    {"8.0.1", "2017-10-09"},
	    {"8.0.0", "2017-09-25"},
	    {"7.8.1", "2017-09-08"},
	    {"7.8.0", "2017-09-05"},
	    {"7.7.2", "2017-08-23"},
	    {"7.7.1", "2017-08-15"},
	    {"7.7.0", "2017-08-14"},
	    {"7.6.1", "2017-07-24"},
	    {"7.6.0", "2017-07-14"},
	    {"7.5.3", "2017-06-22"},
	    {"7.5.2", "2017-06-09"},
	    {"7.5.1", "2017-06-02"},
	    {"7.5.0", "2017-05-30"},
	    {"7.4.1", "2017-05-17"},
	    {"7.4.0", "2017-05-09"},
	    {"7.3.1", "2017-04-19"},
	    {"7.3.0", "2017-04-13"},
	    {"7.2.2", "2017-04-03"},
	    {"7.2.1", "2017-04-01"},
	    {"7.2.0", "2017-03-30"},
	    {"7.1.1", "2017-03-16"},
	    {"7.1.0", "2017-03-06"},
	    {"7.0.1", "2017-02-19"},
	    {"7.0.0", "2017-02-16"},
	    {"6.9.4", "2017-02-06"},
	    {"6.9.3", "2017-01-27"},
	    {"6.9.2", "2017-01-25"},
	    {"6.9.1", "2017-01-17"},
	    {"6.9.0", "2017-01-12"},
	    {"6.8.1", "2017-01-03"},
	    {"6.8.0", "2016-12-19"},
	    {"6.7.0", "2016-11-30"},
	    {"6.6.1", "2016-11-18"},
	    {"6.6.0", "2016-11-16"},
	    {"6.5.0", "2016-11-07"},
	    {"6.4.1", "2016-11-01"},
	    {"6.4.0", "2016-10-26"},
	    {"6.3.2", "2016-10-19"},
	    {"6.3.1", "2016-10-12"},
	    {"6.3.0", "2016-10-04"},
	    {"6.2.0", "2016-09-27"},
	    {"6.1.0", "2016-09-20"},
	    {"5.5.3", "2016-09-12"},
	    {"5.5.2", "2016-09-08"},
	    {"5.5.1", "2016-09-03"},
	    {"5.5.0", "2016-08-31"},
	    {"5.4.1", "2016-08-25"},
	    {"5.4.0", "2016-08-18"},
	    {"5.3.2", "2016-07-29"},
	    {"5.3.1", "2016-07-21"},
	    {"5.3.0", "2016-07-19"},
	    {"5.2.0", "2016-06-27"},
	    {"5.1.1", "2016-06-07"},
	    {"5.1.0", "2016-06-06"},
	    {"5.0.2", "2016-05-13"},
	    {"5.0.1", "2016-04-29"},
	    {"5.0.0", "2016-04-21"},
	    {"4.8.2", "2016-03-02"},
	    {"4.8.1", "2016-01-30"},
	    {"4.8.0", "2016-01-27"},
	    {"4.7.2", "2015-12-17"},
	    {"4.7.1", "2015-11-13"},
	    {"4.7.0", "2015-11-11"},
	    {"4.6.1", "2015-09-23"},
	    {"4.6.0", "2015-09-04"},
	    {"4.5.0", "2015-07-07"},
	    {"4.4.6", "2015-05-18"},
	    {"4.4.5", "2015-05-12"},
	    {"4.4.4", "2015-05-05"},
	    {"4.4.3", "2015-04-28"},
	    {"4.4.1", "2015-04-16"},
	    {"4.4.0", "2015-04-15"},
	    {"4.3.0", "2015-03-02"},
	    {"4.1.4", "2015-02-13"},
	    {"4.1.3", "2015-02-06"},
	    {"4.1.1", "2015-02-02"},
	    {"4.0.9", "2014-10-09"},
	    {"4.0.8", "2014-09-27"},
	    {"4.0.7", "2014-09-19"},
	    {"4.0.6", "2014-09-18"},
	    {"4.0.4", "2014-07-17"},
	    {"4.0.3", "2014-06-26"},
	    {"4.0.2", "2014-06-17"},
	    {"4.0.1", "2014-06-06"},
	    {"4.0.0", "2014-06-05"},
	    {"3.0.4", "2014-03-12"},
	    {"3.0.3", "2014-02-26"},
	    {"3.0.2", "2013-12-19"},
	    {"3.0.1", "2013-11-28"},
	    {"3.0.0", "2013-11-21"},
	    {"2.2.3", "2013-11-20"},
	    {"2.2.2", "2013-09-25"},
	    {"2.2.1", "2013-09-24"},
	    {"2.2.0", "2013-09-14"},
	    {"2.1.1", "2013-06-07"},
	    {"2.1.0", "2013-05-23"},
	    {"2.0.3", "2013-04-01"},
	    {"2.0.2", "2013-03-29"},
	    {"2.0.1", "2013-03-28"},
	    {"1.1.4", "2013-02-08"},
	    {"1.1.3", "2013-02-06"},
	    {"1.1.2", "2013-01-21"},
	    {"1.1.1", "2013-01-11"},
	    {"1.1.0", "2013-01-08"},
	    {"1.0.6", "2012-11-24"},
	    {"1.0.5", "2012-11-16"},
	    {"1.0.4", "2012-11-06"},
	    {"1.0.3", "2012-09-20"},
	    {"1.0.2", "2012-08-29"},
	    {"1.0.1", "2012-08-15"},
	    {"1.0.0", "2012-08-03"},
	};
	const char **p;

	p = bsearch(s, tab, nelem(tab), sizeof(*tab), cmp);
	return (p) ? p[1] : NULL;
}

void
test(const char *s, const char *r)
{
	const char *p;

	p = lookup(s);
	if (!r)
		assert(p == r);
	else
		assert(!strcmp(p, r));
}

int
main(void)
{
	test("1.0.2", "2012-08-29");
	test("4.0.7", "2014-09-19");
	test("10.20.0", "2019-09-10");
	test("11.19.0", "2020-07-10");

	return 0;
}