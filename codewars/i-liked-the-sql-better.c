/*

Create an SQLite3 database /tmp/movies.db

Your database should have a table named MOVIES that contains the following data:

Name	                          Year	Rating
Rise of the Planet of the Apes	2011	  77
Dawn of the Planet of the Apes	2014	  91
Alien	                          1979	  97
Aliens	                        1986	  98
Mad Max	                        1979	  95
Mad Max 2: The Road Warrior	    1981	  100

In Haskell, both of the persistent ( https://hackage.haskell.org/package/persistent ) and esqueleto ( https://hackage.haskell.org/package/esqueleto ) modules are available...

You will be expected to create a monadic action mkMoviesDB :: IO ()

SQLDatabasesFundamentals

*/

#include <stdio.h>
#include <sqlite3.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	int year;
	int rating;
} Movie;

int
output(const char *name)
{
	static const Movie movies[] = {
		{ "Rise of the Planet of the Apes", 2011, 77 },
		{ "Dawn of the Planet of the Apes", 2014, 91 },
		{ "Alien", 1979, 97 },
		{ "Aliens", 1986, 98 },
		{ "Mad Max", 1979, 95 },
		{ "Mad Max 2: The Road Warrior", 1981, 100 },
	};

	sqlite3 *db;
	const Movie *movie;
	char sql[128];
	size_t i;
	int r;

	r = sqlite3_open(name, &db);
	if (r != SQLITE_OK)
		goto error;

	r = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS MOVIES(Name TEXT, Year INTEGER, Rating INTEGER)", NULL, NULL, NULL);
	if (r != SQLITE_OK)
		goto error;

	for (i = 0; i < nelem(movies); i++) {
		movie = movies + i;
		snprintf(sql, sizeof(sql), "INSERT INTO MOVIES VALUES ('%s', %d, %d)",
		    movie->name, movie->year, movie->rating);

		r = sqlite3_exec(db, sql, NULL, NULL, NULL);
		if (r != SQLITE_OK)
			goto error;
	}

	if (0) {
	error:
		printf("Error: %s\n", sqlite3_errstr(r));
	}

	if (db)
		sqlite3_close(db);

	return r;
}

int
main()
{
	output("/tmp/movies.db");
	return 0;
}
