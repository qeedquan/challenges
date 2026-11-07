/*

Messi's Goal Total
Use variables to find the sum of the goals Messi scored in 3 competitions

Information
Messi goal scoring statistics:

Competition     Goals
La Liga 43
Champions League        10
Copa del Rey    5

Task
Create these three variables and store the appropriate values using the table above:
laLigaGoals
championsLeagueGoals
copaDelReyGoals
Create a fourth variable named totalGoals that stores the sum of all of Messi's goals for this year.

*/

#include <stdio.h>

enum {
	laLigaGoals = 43,
	championsLeagueGoals = 10,
	copaDelReyGoals = 5,
	totalGoals = 58,
};

int
main()
{
	printf("%d\n", laLigaGoals);
	printf("%d\n", championsLeagueGoals);
	printf("%d\n", copaDelReyGoals);
	printf("%d\n", totalGoals);

	return 0;
}
